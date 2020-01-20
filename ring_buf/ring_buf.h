
#ifndef __RING_BUF__
#define __RING_BUF__

#define RING_BUF_SIZE 0x20
#define RING_MASK (RING_BUF_SIZE - 1)

#include "stdio.h"

typedef struct ring_buf
{
    unsigned int wr_ofst;
    unsigned int rd_ofst;
    unsigned char *buf;
    unsigned int size;
    int wr_avail;
    int rd_avail;
} ring_buf_t;

extern ring_buf_t ring;

static inline void ring_buf_init(unsigned char *buf, unsigned int len)
{
    ring.buf = buf;
    ring.wr_ofst = 0;
    ring.rd_ofst = 0;
    ring.size = (len > RING_BUF_SIZE) ? RING_BUF_SIZE : len;
    ring.wr_avail = len;
    ring.rd_avail = 0;
}

#define RING_IS_ABT_EMPTY() (((ring.rd_ofst & RING_MASK) ) == (ring.wr_ofst & RING_MASK))

/**
 * @brief read form ring buffer
 * 
 * @param buf   读取的数据存放缓冲区
 * @param len   读取的数据长度
 * @return int  > 0  实际读取的 大小
 *              = 0  没有可读的数据
 *              < 0  错误  
 */
static inline int ring_read(unsigned char *buf, unsigned short len)
{
    int i = 0;
    while (!RING_IS_ABT_EMPTY() && (i < len))
    {
        buf[i] = ring.buf[ring.rd_ofst];
        ring.rd_ofst = (ring.rd_ofst + 1) & RING_MASK;
        i++;
    }
    ring.wr_avail = ring.wr_avail + i;
    ring.rd_avail -=  i;
    return i;
}

/**
 * @brief 
 * 
 * @param buf   要写入的数据
 * @param len   写入的长度
 * @return int  > 0  实际读取的 大小
 *              = 0  没有可读的数据
 *              < 0  错误  
 */
static inline int ring_write(unsigned char *buf, unsigned short len)
{
    int byte_2_wr, i = 0;
    // printf ("len= %d  ring.wr_avail = %d\r\n",len,ring.wr_avail);
    if (ring.wr_avail > 0)
    {
        byte_2_wr = (len > ring.wr_avail) ? ring.wr_avail : len;
        // printf ("byte 2 write = %d\r\n",byte_2_wr);
        while (byte_2_wr)
        {
            /* code */
            ring.buf[ ring.wr_ofst & RING_MASK ] = buf[i];
            ring.wr_ofst= (ring.wr_ofst + 1) & RING_MASK ;
            i++;
            byte_2_wr--;
            // printf("i = %d\n",i);
        }
        ring.rd_avail +=  i;
        ring.wr_avail -=  i;
    }

    if (ring.wr_avail == 0)
    {
        return 0;
    }

    if(ring.wr_avail < 0)
    {
        return -1;
    }

    return byte_2_wr;
}

#endif
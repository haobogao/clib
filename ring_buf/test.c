#include "ring_buf.h"
#include "stdio.h"
#include "string.h"

ring_buf_t ring;

unsigned char g_buf[0x20];

void main(void)
{
    unsigned char buf[0x20];
    ring_buf_init(g_buf, RING_BUF_SIZE);

    ring_write("0123456789", 10);
    printf("ring buf dump\n");
    printf("ring.rd_avail = %d\nring.rd_ofst = %d\nring.size= %d\nring.wr_avail = %d\nring.wr_ofst= %d\n",
           ring.rd_avail, ring.rd_ofst, ring.size, ring.wr_avail, ring.wr_ofst);
    for (int i = 0; i < RING_BUF_SIZE; i++)
    {
        printf(" %02x ", ring.buf[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    ring_write("0123456789", 10);
    printf("ring buf dump\n");
    printf("ring.rd_avail = %d\nring.rd_ofst = %d\nring.size= %d\nring.wr_avail = %d\nring.wr_ofst= %d\n",
           ring.rd_avail, ring.rd_ofst, ring.size, ring.wr_avail, ring.wr_ofst);
    for (int i = 0; i < RING_BUF_SIZE; i++)
    {
        printf(" %02x ", ring.buf[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    ring_write("0123456789", 10);
    printf("ring buf dump\n");
    printf("ring.rd_avail = %d\nring.rd_ofst = %d\nring.size= %d\nring.wr_avail = %d\nring.wr_ofst= %d\n",
           ring.rd_avail, ring.rd_ofst, ring.size, ring.wr_avail, ring.wr_ofst);
    for (int i = 0; i < RING_BUF_SIZE; i++)
    {
        printf(" %02x ", ring.buf[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
    ring_read(buf, RING_BUF_SIZE);



    printf("read buf dump\n");
        printf("ring.rd_avail = %d\nring.rd_ofst = %d\nring.size= %d\nring.wr_avail = %d\nring.wr_ofst= %d\n",
           ring.rd_avail, ring.rd_ofst, ring.size, ring.wr_avail, ring.wr_ofst);
    for (int i = 0; i < RING_BUF_SIZE; i++)
    {
        printf(" %02x ", buf[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");



    ring_write("abcdefghij", 10);
    printf("ring buf dump\n");
    printf("ring.rd_avail = %d\nring.rd_ofst = %d\nring.size= %d\nring.wr_avail = %d\nring.wr_ofst= %d\n",
           ring.rd_avail, ring.rd_ofst, ring.size, ring.wr_avail, ring.wr_ofst);
    for (int i = 0; i < RING_BUF_SIZE; i++)
    {
        printf(" %02x ", ring.buf[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
     printf("\n");

    ring_write("klmnopqrst", 10);
    printf("ring buf dump\n");
    printf("ring.rd_avail = %d\nring.rd_ofst = %d\nring.size= %d\nring.wr_avail = %d\nring.wr_ofst= %d\n",
           ring.rd_avail, ring.rd_ofst, ring.size, ring.wr_avail, ring.wr_ofst);
    for (int i = 0; i < RING_BUF_SIZE; i++)
    {
        printf(" %02x ", ring.buf[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
     printf("\n");
    ring_read(buf, RING_BUF_SIZE);

    printf("read buf dump\n");
        printf("ring.rd_avail = %d\nring.rd_ofst = %d\nring.size= %d\nring.wr_avail = %d\nring.wr_ofst= %d\n",
           ring.rd_avail, ring.rd_ofst, ring.size, ring.wr_avail, ring.wr_ofst);
    for (int i = 0; i < RING_BUF_SIZE; i++)
    {
        printf(" %02x ", buf[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    printf("ring buf dump\n");
    printf("ring.rd_avail = %d\nring.rd_ofst = %d\nring.size= %d\nring.wr_avail = %d\nring.wr_ofst= %d\n",
           ring.rd_avail, ring.rd_ofst, ring.size, ring.wr_avail, ring.wr_ofst);
    for (int i = 0; i < RING_BUF_SIZE; i++)
    {
        printf(" %02x ", ring.buf[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}
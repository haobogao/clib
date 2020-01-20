#include "stdio.h"

#define DEVL(name,LEN)  (name)[(LEN)]

#define OF_sd_TABLE(name)						\
(	. = ALIGN(8);							\
	__##name##_of_table = .;					\
	KEEP(*(__##name##_of_table))					\
	KEEP(*(__##name##_of_table_end)))

struct bit_map{
    DEVL(a,32);
} ;




void main(void)
{
    
    struct bit_map bit;
    OF_sd_TABLE(irqchip);
}
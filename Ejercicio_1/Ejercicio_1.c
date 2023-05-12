#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    unsigned char port_a = 0x24;
    unsigned char flip_port_a = 0;
    unsigned int mask = 1;
    int i;


    printf("port_a es: %x ", port_a);  /*Muestro el Original*/


    for (i=1; i<=8; i++)
    {
        if (i<=4)
        {
            flip_port_a = flip_port_a + ((port_a & mask) << (8-2*i+1)); /*Muevo los 4 LSB*/
        }
        else
        {
            flip_port_a = flip_port_a + ((port_a & mask) >> (-8+2*i-1)); /*Muevo los 4 MSB*/
        }

        mask = mask<<1; /*Muevo la mask*/
    }


    printf(" ; flip_port_a es: %x \n", flip_port_a);  /*Muestro el Espejado*/
}

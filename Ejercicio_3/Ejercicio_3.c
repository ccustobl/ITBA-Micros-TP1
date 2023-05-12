#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char port_a = 0x24;
    double duplicado = port_a; /*Creo la variable que voy a usar en el ciclo*/
    unsigned int var1 = 0;
    double var2 = 0;
    double var3 = 0;
    unsigned int num_bin [8] = {0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int pos = 0;
    unsigned int ciclo = 1;
    int i;
    unsigned int var4;
    unsigned int capicua_port_a = 2; /*No Capicua=0 Capicua=1 Error=2*/


    printf("port_a es: %x \n" , port_a);  /*Muestro el Original*/


    while (duplicado>0) /*Calculo el numero en binario y el numero de 1s*/
    {
        var1 = duplicado/2;
        var3 = var1;
        var2 = duplicado/2;
        pos = 8-ciclo;

        if (var2>var3)
        {
            num_bin[pos] = 1;
        }
        else
        {
            num_bin[pos] = 0;
        }
    duplicado = var1;
    ciclo = ciclo +1;
    }


    printf("El numero en binario es: "); /*Muestro el Numero Binario*/
    pos = 0;
    for (i=1; i<=8; i++)
    {
        pos = 8-i;
        var4 =  num_bin[pos];
        printf("%d" , var4); /*Imprimo valor por valor del Array*/
    }
    printf("\n");


    capicua_port_a = (num_bin[0]==num_bin[7] & num_bin[1]==num_bin[6] & num_bin[2]==num_bin[5] & num_bin[3]==num_bin[4]);
    printf("Es capicua el numero?: %d\n" ,capicua_port_a);
}

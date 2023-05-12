#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    unsigned char port_b = 0x24;
    unsigned char paridad_par = 2; /*Par=0 Impar=1 Error=2*/
    unsigned int counter = 0; /*Contador de 1s*/
    double duplicado = port_b; /*Creo la variable que voy a usar en el ciclo*/
    unsigned int var1 = 0;
    double var2 = 0;
    double var3 = 0;
    unsigned int num_bin [8] = {0, 0, 0, 0, 0, 0, 0, 0};
    unsigned int ciclo = 1;
    unsigned int pos = 0;
    int i;
    unsigned int var4;


    printf("port_b es: %x \n" , port_b);  /*Muestro el Original*/


    while (duplicado>0) /*Calculo el numero en binario y el numero de 1s*/
    {
        var1 = duplicado/2;
        var3 = var1;
        var2 = duplicado/2;
        pos = 8-ciclo;

        if (var2>var3)
        {
            counter = counter+1;
            num_bin[pos] = 1;
        }
        else
        {
            counter = counter+0;
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


    var1 = counter/2;
    var3 = var1;
    var2 = counter/2;
    if (var2>var3)
    {
        paridad_par = 1;
    }
    else
    {
        paridad_par = 0;
    }
    printf("Paridad (0=par y 1=impar): %d\n" , paridad_par); /*Muestro la Paridad*/


}

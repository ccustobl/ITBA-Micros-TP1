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
    unsigned int ciclo = 1; /*Contador de ciclos*/


    // Muestro el numer original
    printf("port_b es: 0x%x \n" , port_b);


    // Calculo el numero de 1s
    while (duplicado>0)
    {
        var1 = duplicado/2;
        var3 = var1;
        var2 = duplicado/2;

        if (var2>var3)
        {
            counter = counter+1;
        }
        else
        {
            counter = counter+0;
        }

    duplicado = var1;
    ciclo = ciclo +1;
    }


    // Calculo la paridad
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
    printf("Paridad (0=par y 1=impar): 0x0%d\n" , paridad_par); /*Muestro la Paridad*/


}

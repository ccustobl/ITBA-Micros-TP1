#include <stdio.h>
#include <stdlib.h>

void main(void)
{
    double calcule = -12.345;
    signed int parte_ent;
    double parte_dec;
    int i;
    signed int num_red;
    double num_red2dec;
    int var1;
    double var2;


    // Muestro el numero original
    printf("El numero es: %f \n" , calcule);


    // Calculo parte entera
    parte_ent = calcule;
    printf("La parte entera es: %d \n" , parte_ent);


    // Calculo la parte decimal
    parte_dec = fabs(calcule - parte_ent);
    printf("La parte decimal es: %f \n" , parte_dec);


    // Calculo el numero redondeado
    if (parte_dec > 0.5  &&  calcule >= 0)
    {
        num_red = parte_ent+1;
    }
    else if (parte_dec <= 0.5  &&  calcule >= 0)
    {
        num_red = parte_ent;
    }
    else if (parte_dec <= 0.5  &&  calcule < 0)
    {
        num_red = parte_ent;
    }
    else if (parte_dec  > 0.5  &&  calcule < 0)
    {
        num_red = parte_ent-1;
    }
    printf("El numero redondeado es: %d \n" , num_red);


    // Calculo el entero superior
    printf("El entero superior es: %d\n", parte_ent+1);


    // Calculo el entero inferior
    printf("El entero inferior es: %d\n", parte_ent-1);


    // Calculo el numero redondeado con 2 decimales
    var1 = calcule*100;
    var2 = fabs(calcule*100 - var1);
    num_red2dec = var1;
    if (var2 > 0.5  &&  calcule >= 0)
    {
        num_red2dec = num_red2dec+1;
    }
    else if (var2 <= 0.5  &&  calcule >= 0)
    {
        num_red2dec = num_red2dec;
    }
    else if (var2 <= 0.5  &&  calcule < 0)
    {
        num_red2dec = num_red2dec;
    }
    else if (var2  > 0.5  &&  calcule < 0)
    {
        num_red2dec = num_red2dec-1;
    }
    printf("El numero redondeado con 2 decimales es: %.2f \n" , num_red2dec/100);

}

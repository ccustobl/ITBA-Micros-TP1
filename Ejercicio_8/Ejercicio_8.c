// Este contador tiene en cuenta los años bisiestos.

#include <stdio.h>
#include <stdlib.h>

// Defino el numero de dias de cada mes
#define d_ene 31
#define d_feb 28
#define d_feb_bis 29
// #define d_mar 31
// #define d_abr 30
// #define d_may 31
// #define d_jun 30
// #define d_jul 31
// #define d_ago 31
// #define d_sep 30
// #define d_oct 31
// #define d_nov 20
// #define d_dic 31

// Defino el numero de dias por año
#define d_anio 365
// #define d_anio_bis 366

// Defino el numero de meses por año
#define m_anio 12

// Enumero los meses
enum mes {enero = 1 , febrero , marzo , abril , mayo , junio , julio , agosto , septiembre , octubre , noviembre , diciembre};



// Funcion que chequea que esten bien las fechas introducidas
int error_fechas(char , char , int);

// Funcion que calcula el numero de dias entre 2 fechas
long int calc_days(char , char , int , char , char , int);

// Funcion que calcula dias entre el principio del año y una fecha
unsigned int dias_a_fecha(char , char , int);

// Funcion que calcula dias entre 2 años (empezando por el primer del mas bajo y terminando por el ultimo del mas alto)
unsigned int dias_totales(int , int);

// Funcion que chequea si los años son o no bisiestos
unsigned int es_bisiesto(int);



// Funcion main
void main(void)
{
    long int cant_dias;

    // Fecha inicial
    char dia_i = 29;
    char mes_i = mayo;
    int anio_i = 2020;

    // Fecha final
    char dia_f = 29;
    char mes_f = mayo;
    int anio_f = 2020;

    // Verifico las fechas
    int error_i = error_fechas((char) dia_i , (char) mes_i , (int) anio_i);
    int error_f = error_fechas((char) dia_f , (char) mes_f , (int) anio_f);
    if (error_i == 0 || error_f == 0 )
    {
        //Calculo el numero de dias
        cant_dias = calc_days((char)dia_i , (char)mes_i , (int)anio_i , (char)dia_f , (char)mes_f , (int)anio_f);
        if (cant_dias < 0) /*ERROR fecha inicial despues de la final */
        {
            printf("ERROR.\nFechas fuera del rango empleado por el programa.\nPor favor reingrese las fechas.\n");
        }
        else
        {
        printf("La cantidad de dias entre ambas fechas es de: %ld\n" , cant_dias);
        }
    }
}



// Funcion que cheque que esten bien las fechas introducidas
int error_fechas(char dia , char mes ,  int anio)
{
    int error = 0;

    if (dia > 0 && mes > 0 && anio > 0) /*Detecto si algun valor es negativo*/
    {
        // ERROR en dia
        // Error si dia en ene, mar, may, jul, ago, oct o dec mayor a 31
        if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31)
        {
            printf("ERROR.\nFechas fuera del rango empleado por el programa.\nPor favor reingrese las fechas.\n");
            error = 1;
        }
        // Error si dia_i en abr, jun, sep o nov mayor a 30
        else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11 ) && dia > 30)
        {
            printf("ERROR.\nFechas fuera del rango empleado por el programa.\nPor favor reingrese las fechas.\n");
            error = 1;
        }
        // Error para feb
        else if (mes == 2)
        {
            if (es_bisiesto(anio) == 1)
            {
                if (dia > d_feb_bis) /*Error si dia_i en feb_bis mayor a 29 */
                {
                    printf("ERROR.\nFechas fuera del rango empleado por el programa.\nPor favor reingrese las fechas.\n");
                    error = 1;
                }
                else if (dia > d_feb) /*Error si dia_i en feb mayor a 28 */
                {
                    printf("ERROR.\nFechas fuera del rango empleado por el programa.\nPor favor reingrese las fechas.\n");
                    error = 1;
                }
            }
        }

        //ERROR en año
        if (anio > 10000)
        {
            printf("ERROR.\nFechas fuera del rango empleado por el programa.\nPor favor reingrese las fechas.\n");
            error = 1;
        }

        //ERROR en mes
        if (mes > m_anio)
        {
            printf("ERROR.\nFechas fuera del rango empleado por el programa.\nPor favor reingrese las fechas.\n");
            error = 1;
        }
    }
    else
    {
        printf("ERROR.\nFechas fuera del rango empleado por el programa.\nPor favor reingrese las fechas.\n");
        error = 1;
    }
    return error;
}



// Funcion que calcula el numero de dias entre 2 fechas
long int  calc_days(char dia_i , char mes_i , int anio_i , char dia_f , char mes_f , int anio_f)
{
    long int var;

    // Dias Totales - (Dias del año - Dias a la fecha final) - Dias a la fecha inicial
    var = dias_totales((int) anio_i , (int) anio_f) - (d_anio + es_bisiesto((int) anio_f) - dias_a_fecha((char) dia_f , (char) mes_f , (int) anio_f)) - dias_a_fecha((char) dia_i , (char) mes_i , (int) anio_i);
    return var;
}



// Funcion que calcula dias entre el principio del año y una fecha
unsigned int dias_a_fecha(char dia , char mes , int anio)
{
    unsigned int var1;
    int var2;

    if (es_bisiesto((int) anio) == 1) /*Año es bisiesto*/
    {
        if (mes == 1)
        {
            var1 = dia;
        }
        else if (mes == 2)
        {
            var1 = d_ene + dia;
        }
        else if (mes >= 3 && mes <= 7)
        {
            var2 = mes/2;
            var1 = 30 * (mes - 1) + var2 - 1 + dia;
        }
        else if (mes > 8)
        {
            var2 = mes/2;
            var1 = 30 * (mes - 1) + (var2 + 1) - 1 + dia;
        }
    }
    else /*Año no es bisiesto*/
    {
        if (mes == 1)
        {
            var1 = dia;
        }
        else if (mes == 2)
        {
            var1 = d_ene + dia;
        }
        else if (mes >= 3 && mes <= 7)
        {
            var2 = mes/2;
            var1 = 30 * (mes - 1) + var2 - 2 + dia;
        }
        else if (mes > 8)
        {
            var2 = mes/2;
            var1 = 30 * (mes - 1) + (var2 + 1) - 2 + dia;
        }
    }
    return var1;
}



// Funcion que calcula dias entre 2 años (empezando por el primero del mas bajo y terminando por el ultimo del mas alto)
unsigned int dias_totales(int anio_i , int anio_f)
{
    unsigned int anios_bis = 0;
    unsigned int var;
    int i;

    for (i = anio_i ; i <= anio_f ; i++)
    {
        anios_bis += es_bisiesto((int) i);
    }
    var = (anio_f - anio_i + 1) * d_anio + anios_bis;
    return var;
}



// Funcion que chequea si los años son o no bisiestos
unsigned int es_bisiesto(int anio)
{
    int div_4;
    int div_100;
    int div_400;
    unsigned int var;

    div_4 = !(anio % 4); /*div_4 = 1 si es divisible por 4*/
    div_100 = !(anio % 100); /*div_100 = 1 si es divisible por 100*/
    div_400 = !(anio % 400); /*div_400 = 1 si es divisible por 400*/
    var = div_4 && (!div_100 || div_400); /*var=1 si el año es bisiesto, sino var=0*/
    return var;
}


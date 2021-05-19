#include <stdio.h>
#include <stdlib.h>

#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;


#endif // FECHA_H_INCLUDED


void getFecha(eFecha fecha);

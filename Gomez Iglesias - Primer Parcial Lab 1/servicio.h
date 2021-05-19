#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Input.h"

#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[25];
    float precio;
}eServicio;

#endif // SERVICIO_H_INCLUDED


void mostrarUnServicio(eServicio unServicio);
int mostrarServicios(eServicio lista[], int tam);

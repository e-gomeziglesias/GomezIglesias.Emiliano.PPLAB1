#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Input.h"

#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
}eColor;

#endif // COLOR_H_INCLUDED

int buscarColor(eColor lista[], int tam, int id);
void mostrarUnColor(eColor unColor);
int mostrarColores(eColor lista[], int tam);
int cargarDescripcionColor(int id, eColor lista[], int tam, char descripcion[]);

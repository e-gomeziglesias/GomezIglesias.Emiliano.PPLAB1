#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Input.h"

#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eMarca;


#endif // MARCA_H_INCLUDED

int buscarMarca(eMarca lista[], int tam, int id);
void mostrarUnaMarca(eMarca unaMarca);
int mostrarMarcas(eMarca lista[], int tam);
int cargarDescripcionMarca(int id, eMarca lista[], int tam, char descripcion[]);



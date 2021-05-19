#include <stdlib.h>
#include <stdio.h>
#include "color.h"
#include "marca.h"
#include "Input.h"
#include "menu.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
}eAuto;

#endif // AUTO_H_INCLUDED


int inicializarAutos(eAuto lista[], int tamLista);
int buscarLibreAuto(eAuto lista[], int tamLista);
int altaAuto(eAuto listaA[], int tamA,eColor listaC[], int tamC, eMarca listaM[], int tamM, int* pIdAuto);
void mostrarUnAuto(eAuto unAuto, eColor unColor, eMarca unaMarca);
int mostrarAutos(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);
int buscarAuto(eAuto lista[], int tam, int id);
int bajaAuto(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);
int modificarAuto(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM);


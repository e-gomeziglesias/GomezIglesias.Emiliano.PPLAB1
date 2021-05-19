#include "fecha.h"
#include "auto.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int id;
    char patente[20];
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;


#endif // TRABAJO_H_INCLUDED

int altaTrabajo(eTrabajo listaT[], int tamT, eAuto listaA[], int tamA, eServicio listaS[], int tamS, int* pNextIdTrabajo);
int buscarTrabajo((eTrabajo listaT[], int tamT, eAuto listaA[], int tamA, eServicio listaS[], int tamS,int idTrabajo);
int mostrarUnTrabajo(eTrabajo unTrabajo, eAuto unAuto, eServicio unServicio);
int motrarTrabajos(eTrabajo listaT[], int tamT, eAuto listaA[], int tamA, eServicio listaS[], int tamS);


//Npmbre: Gomez Iglesias, Emiliano
//Division 1A


#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "menu.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "servicio.h"

#define TAMA 10
#define TAMC 5
#define TAMM 5
#define TAMS 4


int main()
{
    eAuto autos[TAMA];
    eColor colores[TAMC]={{5000,"NEGRO"},{5001,"BLANCO"},{5002,"GRIS"},{5003,"ROJO"},{5004,"AZUL"}};
    eMarca marcas[TAMM]={{1000,"Renault"},{1001, "Fiat"}, {1002,"Ford"}, {1003, "Chevrolet"},{1004, "Peugeot"}};
    eServicio servicios[TAMS] = {{20000,"Lavado", 250},{20001, "Pulido", 300},{20002, "Encerado", 400},{20003, "Completo", 600}};

    inicializarAutos(autos, TAMA);

    char salir = 'N';
    int nextIdAuto = 100;

    do
    {
        system("cls");
        printf("\n");
        switch(menu())
        {
        case 'A':
            printf("ALTA AUTO\n");
            altaAuto(autos,TAMA,colores,TAMC,marcas,TAMM,&nextIdAuto);
            break;
        case 'B':
            printf("BAJA AUTO\n");
            bajaAuto(autos,TAMA,colores,TAMC,marcas,TAMM);
            break;
        case 'C':
            printf("MODIFICAR AUTO\n");
            modificarAuto(autos,TAMA,colores,TAMC,marcas,TAMM);
            break;
        case 'D':
            system("cls");
            printf("LISTAR AUTOS\n");
            mostrarAutos(autos,TAMA,colores,TAMC,marcas,TAMM);
            break;
        case 'E':
            printf("LISTAR MARCAS\n");
            mostrarMarcas(marcas,TAMM);
            break;
        case 'F':
            printf("LISTAR COLORES\n");
            mostrarColores(colores,TAMC);
            break;
        case 'G':
            printf("LISTAR SERVICIOS\n");
            mostrarServicios(servicios,TAMS);
            break;
        case 'H':
            printf("ALTA TRABAJO\n");
            //hay que refactorizar alta
            break;
        case 'I':
            printf("LISTAR TRABAJOS\n");
            break;
        case 'J':
            salir = getUpperChar("Confirma salida? S/N: ");
            break;
        default:
            printf("\n\nLa opcion ingresada es invalida.\n");
        }
        system("pause");
    }while(salir == 'N');
}

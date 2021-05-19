#include "menu.h"
#include "Input.h"

char menu(void)
{
    char opcion;
    system("cls");
    printf("    ****ABM Autos***\n\n");
    printf("A. ALTA AUTO\n");
    printf("B. MODIFICAR AUTO\n");
    printf("C. BAJA AUTO\n");
    printf("D. LISTAR AUTOS\n");
    printf("E. LISTAR MARCAS\n");
    printf("F. LISTAR COLORES\n");
    printf("G. LISTAR SERVICIOS\n");
    printf("H. ALTA TRABAJO\n");
    printf("I. LISTAR TRABAJOS\n");
    printf("J. SALIR");
    printf("\n\n");
    opcion = getUpperChar("Ingrese la opcion deseada: ");
    return opcion;
}


char menuModificar(void)
{
    char opcion;
    system("cls");
    printf("    ****Modificar Autos***\n\n");
    printf("A. Patente\n");
    printf("B. Marca\n");
    printf("C. Color\n");
    printf("D. Modelo\n");
    printf("E. SALIR");
    printf("\n\n");
    opcion = getUpperChar("Ingrese la opcion deseada: ");
    return opcion;
}

#include "servicio.h"

void mostrarUnServicio(eServicio unServicio)
{
    printf("%d %10s %.2f\n", unServicio.id, unServicio.descripcion, unServicio.precio);
}


int mostrarServicios(eServicio lista[], int tam)
{
   system("cls");
    int retorno = 0;
    if(lista != NULL && tam > 0)
    {
        printf("        Listado de Servicios\n");
        printf("ID  Descripcion Precio\n\n");

        for(int i=0; i<tam; i++)
        {
                mostrarUnServicio(lista[i]);
        }
        printf("\n\n\n");
        retorno = 1;
    }
    return retorno;
}

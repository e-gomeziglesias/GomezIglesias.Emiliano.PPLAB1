#include "marca.h"

int buscarMarca(eMarca lista[], int tam, int id)
{
    int retorno = -1;
    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].id==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
void mostrarUnaMarca(eMarca unaMarca)
{
    printf("%d %10s\n", unaMarca.id, unaMarca.descripcion);
}


int mostrarMarcas(eMarca lista[], int tam)
{
   system("cls");
    int retorno = 0;
    if(lista != NULL && tam > 0)
    {
        printf("        Listado de Marcas\n");
        printf("ID  Descripcion\n\n");

        for(int i=0; i<tam; i++)
        {
                mostrarUnaMarca(lista[i]);
        }
        printf("\n\n\n");
        retorno = 1;
    }
    return retorno;
}

int cargarDescripcionMarca(int id, eMarca lista[], int tam, char descripcion[])
{
    int retorno = 0;
    if(id>= 1000 && id<=1005 && lista != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].id==id)
            {
                strcpy(descripcion, lista[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

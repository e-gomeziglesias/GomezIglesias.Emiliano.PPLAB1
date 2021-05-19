#include "color.h"

int buscarColor(eColor lista[], int tam, int id)
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
/*int buscarColor(eColor lista[], int tam, int id)
{
    int retorno = -1;
    int id;
    if(lista != NULL && tam>0)
    {
        id = getInt("Ingrese el id del color: ", "El id ingresado es invalido. Ingrese el id: ",5000,5004);
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
}*/
void mostrarUnColor(eColor unColor)
{
    printf("%d %10s\n", unColor.id, unColor.nombreColor);
}

int mostrarColores(eColor lista[], int tam)
{
   system("cls");
    int retorno = 0;
    if(lista != NULL && tam > 0)
    {
        printf("        Listado de Colores\n");
        printf("ID  Descripcion\n\n");

        for(int i=0; i<tam; i++)
        {
                mostrarUnColor(lista[i]);
        }
        printf("\n\n\n");
        retorno = 1;
    }
    return retorno;
}

int cargarDescripcionColor(int id, eColor lista[], int tam, char descripcion[])
{
    int retorno = 0;
    if(id>= 5000 && id<=5004 && lista != NULL && tam > 0 && descripcion != NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(lista[i].id==id)
            {
                strcpy(descripcion, lista[i].nombreColor);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

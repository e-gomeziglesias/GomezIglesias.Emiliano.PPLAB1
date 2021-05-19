#include "auto.h"


int inicializarAutos(eAuto lista[], int tamLista)
{
    int retorno = 0;
    if(lista!=NULL && tamLista>0)
    {
        for (int i=0; i<tamLista; i++)
        {
            lista[i].isEmpty = 1;
        }
        retorno = 1;
    }
    return retorno;
}

int buscarLibreAuto(eAuto lista[], int tamLista)
{
    int retorno = -1;
    if(lista!=NULL && tamLista>0)
    {
        for (int i=0; i<tamLista; i++)
        {
            if(lista[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int altaAuto(eAuto listaA[], int tamA,eColor listaC[], int tamC, eMarca listaM[], int tamM, int* pIdAuto)
{
    system("cls");
    int retorno = 0;
    int indice;
    int iC;
    int iM;
    char continuar = 'S';
    if(listaA != NULL && pIdAuto != NULL && tamA>0)
    {
        indice=buscarLibreAuto(listaA,tamA);
        eAuto auxLista;
        if (indice==-1)
        {
            printf("No hay lugares disponibles\n\n");
        }
        else
        {
            do
            {
                auxLista=listaA[indice];
                auxLista.id = (*pIdAuto);
                printf("\nId asignado: %d\n", auxLista.id);
                //patente
                getStringFull(auxLista.patente,"Ingrese la patente: ","Patente ingresada invalida. Ingrese una patente valida: ",20);
                //marca
                mostrarMarcas(listaM,tamM);
                printf("\nIngreso:\n\n");
                auxLista.idMarca = getInt("Ingrese el id de la marca: ", "El id ingresado es invalido. Ingrese el id: ",1000,1004);
                iM = buscarMarca(listaM,tamM, auxLista.idMarca);
                mostrarUnaMarca(listaM[iM]);
                //color
                mostrarColores(listaC,tamC);
                printf("\nIngreso:\n\n");
                auxLista.idColor = getInt("Ingrese el id del color: ", "El id ingresado es invalido. Ingrese el id: ",5000,5004);
                iC = buscarColor(listaC,tamC,auxLista.idColor);
                mostrarUnColor(listaC[iC]);
                //modelo
                auxLista.modelo=getInt("Ingrese modelo(anio) del auto: ","El modelo ingresado es invalido. Ingrese modelo: ",1970,2021);
                auxLista.isEmpty = 0;

                listaA[indice] = auxLista;
                (*pIdAuto)=(*pIdAuto)+1;
                retorno = 1;
                continuar = getUpperChar("\nDesea dar de alta otro auto? (S/N): ");
            }while(continuar=='S');
        }
    }
    return retorno;
}

void mostrarUnAuto(eAuto unAuto, eColor unColor, eMarca unaMarca)
{
    printf("%d %10s %10s %10s %d", unAuto.id, unAuto.patente, unaMarca.descripcion, unColor.nombreColor, unAuto.modelo);
}

int mostrarAutos(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    system("cls");
    int retorno = 0;
    int flagUnoCargado = 0;
    int iC;
    int iM;

    if(listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 &&  listaM!= NULL && tamM > 0)
    {
        printf("        Listado de Autos\n");
        printf("ID Patente  Marca  Color Modelo \n\n");

        for(int i=0; i<tamA; i++)
        {
            if(!listaA[i].isEmpty)
            {
                iC=buscarColor(listaC,tamC,listaA[i].idColor);
                iM=buscarMarca(listaM,tamM,listaA[i].idMarca);
                mostrarUnAuto(listaA[i],listaC[iC],listaM[iM]);
                flagUnoCargado = 1;
            }
        }
        if(flagUnoCargado == 0)
        {
            printf("No hay autos para mostrar. \n\n");
        }
        printf("\n\n\n");
        retorno = 1;
    }
    return retorno;
}

int buscarAuto(eAuto lista[], int tam, int id)
{
    int retorno = -1;
    if(lista != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if((lista[i].isEmpty== 0) &&(lista[i].id==id))
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int bajaAuto(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    system("cls");
    int retorno=0;
    int iA;
    int iC;
    int iM;
    if(listaA != NULL && tamA > 0 && listaC != NULL && tamC > 0 &&  listaM!= NULL && tamM > 0)
    {
        int id;
        char confirmar = 'N';
        mostrarAutos(listaA,tamA,listaC, tamC, listaM, tamM);
        id = getInt("Ingrese ID del auto a borrar: ", "El ID ingresado es invalido. Ingrese ID: ",100, 1000);
        iA = buscarAuto(listaA,tamA,id);
        iC= buscarColor(listaC,tamC,listaA[iA].idColor);
        iM= buscarMarca(listaM,tamM,listaM[iA].id);
        if(iA != -1)
        {
            printf("\n\n\n");
            mostrarUnAuto(listaA[iA],listaC[iC],listaM[iM]);
            confirmar = getUpperChar("\nEstas por dar de baja el empleado. Continuar? (S/N): ");
            if(confirmar=='S')
            {
                listaA[iA].isEmpty=1;
                printf("\nBaja exitosa\n");
                retorno = 1;
            }
            else
            {
                printf("\nLa baja se cancelo por el usuario.\n");
            }
        }
    }

    return retorno;
}

int modificarAuto(eAuto listaA[], int tamA, eColor listaC[], int tamC, eMarca listaM[], int tamM)
{
    system("cls");
    int retorno=0;
    int id;
    int iA;
    int iC;
    int iM;
    char confirmar = 'N';
    char salir = 'N';
    eAuto auxLista;
    mostrarAutos(listaA,tamA,listaC,tamC,listaM,tamM);
    id = getInt("Ingrese ID del auto a modificar: ", "El ID ingresado es invalido. Ingrese ID: ",100, 1000);
    iA = buscarAuto(listaA,tamA,id);
    iC = buscarColor(listaC,tamC,listaA[iA].idColor);
    iM = buscarMarca(listaM, tamM, listaA[iA].idMarca);

    auxLista = listaA[iA];
    if(iA != -1)
    {
        printf("\n\n\n");
        mostrarUnAuto(auxLista,listaC[iC],listaM[iM]);
        confirmar = getUpperChar("\nEstas por modificar el empleado. Continuar? (S/N): ");
        system("cls");
        if(confirmar=='S')
        {
            do
            {
                printf("\n\n");
                mostrarUnAuto(auxLista,listaC[iC],listaM[iM]);
                switch(menuModificar())
                {
                case 'A':
                    printf("\nModificar patente\n\n");
                    getStringFull(auxLista.patente,"Ingrese la patente: ","Patente ingresada invalida. Ingrese una patente valida: ",20);
                    break;
                case 'B':
                    printf("\nModificar Marca\n\n");
                    mostrarMarcas(listaM,tamM);
                    printf("\nIngreso:\n\n");
                    auxLista.idMarca = getInt("Ingrese el id de la marca: ", "El id ingresado es invalido. Ingrese el id: ",1000,1004);
                    iM = buscarMarca(listaM,tamM, auxLista.idMarca);
                    mostrarUnaMarca(listaM[iM]);
                case 'C':
                    printf("\nModificar Color\n\n");
                    mostrarColores(listaC,tamC);
                    printf("\nIngreso:\n\n");
                    auxLista.idColor = getInt("Ingrese el id del color: ", "El id ingresado es invalido. Ingrese el id: ",5000,5004);
                    iC = buscarColor(listaC,tamC,auxLista.idColor);
                    mostrarUnColor(listaC[iC]);
                    break;
                case 'D':
                    printf("\nModificar Modelo\n\n");
                    //modelo
                    auxLista.modelo=getInt("Ingrese modelo(anio) del auto: ","El modelo ingresado es invalido. Ingrese modelo: ",1970,2021);
                case 'E':
                    printf("\nSalir menu modificar empleado\n\n");
                    salir = getUpperChar("\nDesea salir del menu modificar? (S/N): ");
                    break;
                }
            }while (salir == 'N');
            printf("\n\n");
            listaA[iA]=auxLista;
            mostrarUnAuto(auxLista,listaC[iC],listaM[iM]);
            printf("\nModificacion exitosa\n");
            retorno = 1;
        }
        else
        {
            printf("\nSe cancelo modificacion por el usuario.\n");
        }
    }
    else
    {
        printf("\n\nNo hay autos registrados bajo ese id.\n\n\n");
    }
    return retorno;
}

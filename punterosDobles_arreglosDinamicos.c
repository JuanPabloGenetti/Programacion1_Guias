#include <stdio.h>
#include <stdlib.h>

void demostracionPunterosDobles(int valor, int* pint, int** ppint);
void crearYcargarArr(int **arreglo,int dimension);
void cargarArregloPares(int arr[], int pares[], int dimension );

int main() {
    int valor = 5;
    int *pint = &valor;
    int **ppint = &pint;
    demostracionPunterosDobles(valor, pint, ppint);
    //
    int arr[10] = {0,4,1,7,1,2,7,1,2,5};
    int* arrPares;

    int dimensionArrPares = contar(arr,10);
    crearYcargarArr(&arrPares,dimensionArrPares);
    cargarArregloPares(arr,arrPares,10);
    free(arrPares);
    //

    return 0;
}

void demostracionPunterosDobles(int valor, int* pint, int** ppint) {
    printf("El valor es %d\n", valor);
    printf("La direccion de memoria de valor es %p\n", (void*)&valor);
    printf("El puntero pint imprime %p\n", (void*)pint);
    printf("El puntero pint imprime %p cuando uso ampersand\n", (void*)&pint);
    printf("El puntero pint imprime %d cuando uso asterisco\n", *pint);
    printf("El puntero doble ppint imprime %p\n", (void*)ppint);
    printf("El puntero doble imprime %p cuando uso ampersand\n", (void*)&ppint);
    printf("El puntero doble imprime %p cuando uso asterisco\n", (void*)*ppint);
    printf("El puntero doble imprime %d cuando uso doble asterisco\n", **ppint);
}

int contar(int arr[],int dimension){
    int i = 0;
    int contador = 0;
    while(i<dimension){
        if(arr[i]%2 == 0){
            contador++;
        }
        i++;
    }
    return contador;
}

void crearYcargarArr(int **arreglo,int dimension){
*arreglo = (int*)malloc(sizeof(int)*dimension);
}

void cargarArregloPares(int arr[], int pares[], int dimension ){
    int i = 0;
    int j = 0;
    while(i<dimension){
        if(arr[i]%2 == 0){
            pares[j] = arr[i];
            j++;
        }
        i++;
    }
}
//Esta version segun la guia debia crear el arreglo dinamicamente dentro de la funcion
    void cargarArregloParesVersion2(int arr[], int** pares, int dimension, int dimensionPares){
        *pares = (int*)malloc(sizeof(int)*dimensionPares);
        int i = 0;
        int j = 0;
        while(i<dimension){
            if(arr[i]%2 == 0){
                pares[j] = arr[i];
                j++;
            }
            i++;
        }
    }


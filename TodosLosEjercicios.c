#include <stdio.h>
#include <stdlib.h>
#include "pila.c"
#include <math.h>
#include <string.h>


//Prototipado guia pilas

void llenarPila(Pila*, int*);
void pasarPila(Pila A);
void pasarPilaOrdenada(Pila A);
int encontrarMenor(Pila* A); // Si uso un while y lo llamo desde el main es un algoritmo de seleccion
void insertarOrdenado(Pila *A, int new);
void ordenamientoPorInsercion(Pila* A); // Llamo la funcion anterior desde esta para hacer ordenacion for insercion
int sumarDosUltimos(Pila A);
int sumaDeTodaLaPila(Pila A);
int contar(Pila A);
float division(int num1,int num2);
float funcionPromedio(Pila A);
int ejercicio10(Pila A);

//Prototipado Guia Arreglos

int cargarArreglo(int A[], int size);
void mostrarArreglo(int A[], int validos);
int sumatoria(int A[], int validos);
void arregloA_pila(int A[], int validos);
int encontrar(int A[], int validos, int buscar);
void insertar_Ordenado(char A[], int *validos, char insertar);

// Prototipado matrices
// strlen( ); strcmp( );  strcmpi( ); strcpy( ); strcat( );    strstr( );  tolower( ); toupper( );     




#define X 3
#define Y 3

#define X2 3
#define Y2 5

void cargarMatriz(int A[X][Y]);
void mostrarMatriz(int A[X][Y]);
void cargarRandom(int A[X][Y]);
int suma(int A[X][Y]);
float promedioMatriz(int A[X][Y]);
int buscarValor(int A[X][Y], int buscar);
int cargarArreglo_de_palabras(char B[X2][Y2]);
int mostrarArreglo_de_palabras(char B[X2][Y2], int validos);
int buscar(char B[X2][Y2], int validos, char a_buscar);



int main() {
    int mainChoice, subChoice;

    do {

        printf("Elegir Guia:\n");
        printf("1. Guia de Pilas\n");
        printf("2. Guia de Arreglos\n");
        printf("3. Guia de Matrices\n");
        printf("4. Salir\n");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1:
                do {
                    printf("\nElegiste la guia de Pilas.\n");
                    printf("Elegir ejercicio 1-10 ( 11 para volver al menu principal):\n");
                    scanf("%d", &subChoice);

                    Pila miPila; 
                    inicpila(&miPila);
                    int size = 0;
                    // TAB 
                    switch (subChoice) {
                        case 1:
                            printf("\nHacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario. \n");
                            llenarPila(&miPila, &size);
                            mostrar(&miPila);
                            break;
                        case 2:
                            printf("\nHacer una función que pase todos los elementos de una pila a otra. \n");
                            Pila miPila2; 
                            inicpila(&miPila2);
                            apilar(&miPila2, 5);
                            apilar(&miPila2, 7);
                            mostrar(&miPila2);
                            pasarPila(miPila2);
                            break;
                        case 3:
                            printf("\nHacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.  \n");
                            Pila miPila3; 
                            inicpila(&miPila3);
                            apilar(&miPila3, 5);
                            apilar(&miPila3, 7);
                            mostrar(&miPila3);
                            pasarPilaOrdenada(miPila3);
                            break;
                        case 4:
                            printf("\nHacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.  \n");
                            Pila miPila4; 
                            inicpila(&miPila4);
                            apilar(&miPila4, 5);
                            apilar(&miPila4, 3);
                            apilar(&miPila4, 9);
                            apilar(&miPila4, 1);
                            mostrar(&miPila4);
                            int menor = 0;
                            menor = encontrarMenor(&miPila4);
                            mostrar(&miPila4);
                            printf("%d  \n", menor);
                            break;
                        case 5:
                            printf("\nHacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección) \n");
                            Pila miPila5; 
                            inicpila(&miPila5);
                            Pila miPila5_ordenada;
                            inicpila(&miPila5_ordenada);
                            apilar(&miPila5, 5);
                            apilar(&miPila5, 3);
                            apilar(&miPila5, 9);
                            apilar(&miPila5, 1);
                            mostrar(&miPila5);

                            while(!pilavacia(&miPila5)){
                                apilar(&miPila5_ordenada, encontrarMenor(&miPila5));
                            }
                            mostrar(&miPila5_ordenada);
                        break;
                        case 6:
                            printf("\nHacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.");
                            Pila miPila6; inicpila(&miPila6);
                            apilar(&miPila6,1);
                            apilar(&miPila6,3);
                            apilar(&miPila6,5);
                            apilar(&miPila6,7);
                            int elemento = 0;
                            scanf("%d", &elemento);
                            insertarOrdenado(&miPila6, elemento);
                            mostrar(&miPila6);
                            break;
                        case 7:
                            printf("\nHacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)");
                            Pila miPila7; inicpila(&miPila7);
                            apilar(&miPila7,2);
                            apilar(&miPila7,1);
                            apilar(&miPila7,6);
                            apilar(&miPila7,1);
                            apilar(&miPila7,8);
                            mostrar(&miPila7);
                            ordenamientoPorInsercion(&miPila7);
                            mostrar(&miPila7);
                            break;
                        case 8:
                            printf("\nHacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila. ");
                            Pila miPila8; inicpila(&miPila8);
                            apilar(&miPila8, 2);
                            apilar(&miPila8, 3);
                            apilar(&miPila8, 5);
                            apilar(&miPila8, 1);
                            apilar(&miPila8, 8);
                            mostrar(&miPila8);
                            printf("\nLa suma de los dos ultimos es: %d" ,sumarDosUltimos(miPila8));
                        case 9:
                            Pila miPila9; inicpila(&miPila9);
                            apilar(&miPila9, 2);
                            apilar(&miPila9, 3);
                            apilar(&miPila9, 5);
                            apilar(&miPila9, 1);
                            apilar(&miPila9, 8);
                            printf("\nHacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.");
                            printf("\n \n El promedio de los elementos de la pila es %f", funcionPromedio(miPila9));
                        case 10:
                            printf("\nTransformar una pila en un numero segun su posicion en decimales. Ej: 1;2;5;1: va a ser Mil-doscientos cincuenta y uno ");
                            Pila miPila10;inicpila(&miPila10);
                            apilar(&miPila10, 4);
                            apilar(&miPila10, 3);
                            apilar(&miPila10, 2);
                            apilar(&miPila10, 1);
                            mostrar(&miPila10);
                            printf("\n El numero asignando posiciones decimales es: %d", ejercicio10(miPila10));
                        case 11:
                            printf("\n \nVolviste al menu principal.\n");
                            break;
                        default:
                            printf("Numero de ejercicio invalido.\n");
                    }
                } while (subChoice != 10);
                break;
            case 2:
                printf("\nElegiste la guia de Arreglos.\n");
                printf("Elegir ejercicio 1-10 ( 11 para volver al menu principal):\n");
                scanf("%d", &subChoice);
                    switch (subChoice) {
                        case 1:
                            printf("\n Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos). ");
                            int tama = 10;
                            int validos = 0;
                            int arreglo[10];
                            validos = cargarArreglo(arreglo, tama);
                            printf("\n Los validos son: %d \n", validos);
                        break;
                        case 2:
                            printf("\n Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla.\n ");
                            int arreglo2[10] = {1,2,4,5};
                            int validos2 = 4;
                            mostrarArreglo(arreglo2, validos2);
                        break;
                        case 3:
                            printf("\n Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos. \n ");
                            int arreglo3[10] = {1,2,4,5};
                            int validos3 = 4;
                            printf("\n La sumatoria es %d \n \n" , sumatoria(arreglo3,validos3));
                        break;
                        case 4:
                            printf("\n Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila. \n");
                            int arreglo4[10] = {1,2,4,5};
                            int validos4 = 4;
                            arregloA_pila(arreglo4,validos4);
                        break;
                        case 5:
                            printf("\n Ejercicio 5, no valia la pena hacerlo. \n ");
                        break;
                        case 6:
                            printf("\n Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres. \n ");
                            int arreglo5[10] = {1,2,4,5};
                            int validos5 = 4;
                            int a_buscar = 2;
                             int indice = encontrar(arreglo5, validos5, a_buscar);
                              if (indice != -1) {
                                printf("El elemento %d fue encontrado en el índice %d.\n", a_buscar, indice);
                            } else {
                                printf("El elemento %d no fue encontrado en el arreglo.\n", a_buscar);
                            }
                        break;
                        case 7:
                            printf("\n Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.  \n ");
                            char arreglo6[10] = {'a', 'b', 'c', 'd'};
                            int validos6 = 4;
                            char a_Insertar = 'b';
                            insertar_Ordenado(arreglo6, &validos6,a_Insertar);
                        break;
                        case 13:
                        break;
                        default:
                        printf("\n Numero de ejercicio no valido \n");
                    }
                break;
            case 3:
                printf("You chose Function C.\n");
                // Code for Function C
                break;
            case 4:
                printf("Terminando programa.\n");
                break;
            default:
                printf("Invalido.\n");
        }
    } while (mainChoice != 4);

    return 0;
}

void llenarPila(Pila* A, int* size){
    char control = 's';
    do{

        leer(A);
        printf("desea seguir cargando la Pila s/n \n");
        (*size)++;

        // Dejo un espacio en el scanf para que el \n de el printf anterior no me llene de basura el scanf.

        scanf(" %c", &control);

    }while( control == 's');
}

void pasarPila(Pila A){
    Pila aux; inicpila(&aux);

    while(!pilavacia(&A)){
        apilar(&aux, desapilar(&A));
    }

    mostrar(&aux);
}

void pasarPilaOrdenada(Pila A){
    Pila aux; inicpila(&aux);
    

    while(!pilavacia(&A)){
        apilar(&aux, desapilar(&A));
    }

    mostrar(&aux);
    
    while(!pilavacia(&aux)){
        apilar(&A,desapilar(&aux));
    }

    mostrar(&A);
}

int encontrarMenor(Pila *A){

    Pila aux; inicpila(&aux); // menores
    Pila aux2; inicpila(&aux2); // no menores
    
    apilar(&aux, desapilar(A));

    while(!pilavacia(A)){
        if(tope(&aux) < tope(A)){
            apilar(&aux2, desapilar(A));
        }else{
            apilar(&aux2, desapilar(&aux));
            apilar(&aux,desapilar(A));
        }
    }
    
    while(!pilavacia(&aux2)){
        apilar(A, desapilar(&aux2));
    }

    int smallest = tope(&aux);

    return smallest;
}

void insertarOrdenado(Pila *A, int new){
    Pila aux; inicpila(&aux);

    while(!pilavacia(A) && tope(A) > new){
        apilar(&aux,desapilar(A));
    }
    
    apilar(A,new);
    
    while(!pilavacia(&aux)){
        apilar(A, desapilar(&aux));
    }

}

void ordenamientoPorInsercion(Pila* A){
    Pila aux; inicpila(&aux);

    while(!pilavacia(A)){
        int num = desapilar(A);
        insertarOrdenado(&aux, num);
    }

    while(!pilavacia(&aux)){
        apilar(A, desapilar(&aux));
    }
}

int sumarDosUltimos(Pila A){
return(desapilar(&A)+tope(&A));
}

int sumaDeTodaLaPila(Pila A){
    int aux = 0;
    while(!pilavacia(&A)){
        aux = desapilar(&A) + aux;
    }
    return aux;
}

int contar(Pila A){
    int aux = 0;
    while(!pilavacia(&A)){
        desapilar(&A); // Pop an element from the stack
        aux++;
    }
    return aux;
}


float division(int num1,int num2){
    if(num2 != 0){
    return (float)num1/(float)num2; // casteo: recibo dos variables enteras pero para hacer una division con resultado decimal tengo que castearlas antes.
    }else{
        printf("error division por 0");
        return 0;
    }
}

float funcionPromedio(Pila A){
    return(division(sumaDeTodaLaPila(A), contar(A))); // Esto es una funcion que recibe una copia de una pila.
}

int ejercicio10(Pila A){
    int contador = 0;
    int resultado = 0;
    Pila aux; 
    inicpila(&aux);
    
    // Move elements from A to aux and count them
    while(!pilavacia(&A)){
        apilar(&aux, desapilar(&A));   
        contador++;
    }
    
    // Construct the number from the elements in aux
    while(!pilavacia(&aux)){
        int digit = desapilar(&aux);
        resultado += digit * pow(10, contador - 1); // Build the number by placing each digit in its appropriate position
        contador--;
    }
    return resultado;
}

// FINAL FUNCIONES GUIA DE PILAS // INICIO FUNCIONES GUIA DE ARREGLOS

int cargarArreglo(int A[], int size){
    int validos = 0;
    char check = 's';
    int i = 0;
    
    do{
        printf("Ingrese un valor a su arreglo  \n");
        scanf(" %d", &A[i]);
        validos++;
        printf("Desea seguir cargando el arreglo ? \n");
        scanf(" %c", &check);
        i++;
    }while(validos<=size && check == 's');

    return validos;
}

void mostrarArreglo(int A[], int validos){
    for(int i=0; i<validos;i++){
        printf("\n Posicion %d valor: %d \n \n", i , A[i]);
    }
}

int sumatoria(int A[], int validos){
    int i=0;
    int suma = 0;
    while(i<validos){
        suma+=A[i];
        i++;
    }
    return suma;
}

void arregloA_pila(int A[], int validos){
    Pila aux; inicpila(&aux);
    for(int i=0;i<validos;i++){
        apilar(&aux,A[i]);
    }
    mostrar(&aux);
}

int encontrar(int A[], int validos, int buscar){
    int i = 0;
    while (i < validos) {
        if (A[i] == buscar) {
            return i; 
        }
        i++;
    }
    return -1;
}

void insertar_Ordenado(char A[], int *validos, char insertar) {

    int i = *validos - 1; 

    while (i > 0 && insertar <= A[i]) {
        A[i + 1] = A[i]; 
        i--;
    }

    A[i + 1] = insertar;
   
    (*validos)++;

    int j = 0;

    while (j < 10 ) {
        printf("  %c  ", A[j]);
        j++;
    }
    printf("  /n");
}

int maximo(int A[], int validos){

    int maximo = A[0];
    int i = 1;
    while(i<validos){
        if(maximo< A[i]){
            maximo = A[i];
        }
    i++;
    }
return maximo;
}

int capicua(int A[], int validos) {
    int i = 0;
    int j = validos - 1; 
    while (i < j) {
        if (A[i] != A[j]) {
            printf("No es Capicua \n");
            return 0;
        }
        i++;
        j--;
    }
    printf("Es Capicua \n");
    return 1;
}

void invertir(int A[], int validos){
    int i = 0;
    int aux;
    int j = validos - 1; 
    while (i < j) { // Esta logica evita comprar indices iguales con lo cual tampoco entra el caso del arreglo impar.
        aux = A[i];
        A[i] = A[j];
        A[j] = aux; 
        i++;
        j--;
    }
}

void ord_Seleccion(int A[]){
    int posmenor;
    int i = 0;
    int aux_realMenor = 0;
    while(i<7){  // 7 harcodeado. O validos-1; Es validos menos 1 porque en la ultima ejecucion posMenor no va a tener contra que compararse
        posmenor = posicionMenor(A, i);
        aux_realMenor = A[posmenor];
        A[posmenor] = A[i]; // Saco de la posicion del arreglo el que no va
        A[i] = aux_realMenor; // Pongo el que si va
        i++;    
    }
}
// Podriamos decir que en la funcion seleccion, ocurre la entrega de premios a mejor explorador
// donde los ganadores van pasando de una habitacion a otra
// habitacion de los ganadores, en orden del mejor al peor. 
// Especificamente esta funcion es la persona que va entre una habitacion y la otra a 
// buscar a los ganadores.
int posicionMenor(int A[], int pos){  // pos va a recibir 0 en la primera ejecucion y va a incrementar de a 1 subsecuentemente
    int menor = A[pos]; // asumo que el menor es A[O]
    int posMenor = pos; // variable auxiliar para tener el que asumo que es el menor en esta ejecucion
    int i = pos + 1; // i va a ser todas las posiciones a partir de del que asumo que es el menor
    while(i<8){ // hardcodeado 8, pero puedo ser los validos.
        if( menor > A[i]){ // 1ra ejecucion. menor tiene A[0] y A[i] tiene posicion 1.
            menor = A[i];
            posMenor = i; // Comparo a los 2. Si el anterior menor es mas grande que el que le sigue en en el array actualizo menor y posMenor a los valores segun int i;
        }
    i++; // Si no se comple la condicion del while, este i++ suma hasta salir del while. Porque, por ejemplo, si posMenor 
    } // ejecucion tras ejecucion sigue siendo el mismo, asi se sale del while sin cambiar.
return posMenor;
}

// Podriamos decir en terminos de la vida real esta funcion (posicionMenor) es un explorador de cuevas.
// Este lleva una unica bandera la cual clava cada vez que llega a una nueva profundidad maxima.
// Osea la bandera sigue clavada en la ultima posicion si el explorador sigue en la
// misma altura.
// Al final de su aventura el explorador no vuelve con su bandera, sino con las coordenadas
// de donde la clavo.

void insertar(int A[], int ultimaPos, int valor, int validos) {
    int i = ultimaPos;
    while (i >= 0 && valor < A[i]) {
        A[i + 1] = A[i];
        i--;
    }
    A[i + 1] = valor;
}

void ord_Insercion(int A[], int validos) {
    for (int i = 1; i < validos; i++) {
        insertar(A, i - 1, A[i], validos);
    }
}

void ord_Seleccion_Optimizado(int A[], int validos) {
    int i, j, min_idx, temp;

    for (i = 0; i < validos - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < validos; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }

        temp = A[i];
        A[i] = A[min_idx];
        A[min_idx] = temp;
    }
}

// Guia de matrices

void cargarMatriz(int A[X][Y]){
    for(int i = 0; i<X;i++){
        for(int j = 0; j<Y; j++){
            printf("\n cargue valor a la matrix posicion X:%d posicion Y:%d", i , j);
            scanf("%d", A[i][j] );
        }
    }
}

void mostrarMatriz(int A[X][Y]){
    for(int i = 0; i<X;i++){
        for(int j = 0; j<Y; j++){
            printf("|  %d  | ", A[i][j]);
        }
        printf("\n");
    }
}


void cargarRandom(int A[X][Y]){
    srand(time(NULL));
    for(int i = 0; i<X;i++){
        for(int j = 0; j<Y; j++){
            A[i][j] = rand()%100;
        }
    }
}

int suma(int A[X][Y]){
    int sumita = 0;
    for(int i = 0; i<X;i++){
        for(int j = 0; j<Y; j++){
            sumita += A[i][j];
        }
    }
return sumita;
}

float promedioMatriz(int A[X][Y]){
    return float(suma(A)/float(X*Y));
}

int buscarValor(int A[X][Y], int buscar){
    for(int i = 0; i<X;i++){
        for(int j = 0; j<Y; j++){
            if(buscar == A[i][j]){
                return 1;
            }
        }
    }
    return 0;
}

int cargarArreglo_de_palabras(char B[X2][Y2]){
    int validos = 0;
    printf("\n cuantas palabras desea cargar ( MAX 5)");
    fflush(stdin);
    scanf("%d", validos);
    for(int i = 0; i<validos-1;i++){
        gets(B[i]);
    }
    return validos;
}   

int mostrarArreglo_de_palabras(char B[X2][Y2], int validos){
    for(int i = 0; i<validos-1;i++){
        puts(B[i]);
    }
}  

int buscar(char B[X2][Y2], int validos, char a_buscar){
    int i = 0;
    while(i<validos){
        if(strcmp(a_buscar,B[i]) == 0){
            return 1;
        }
    i++; 
    }return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "pila.c"
#include <math.h>


void llenarPila(Pila*, int*);
void pasarPila(Pila A);
void pasarPilaOrdenada(Pila A);
int encontrarMenor(Pila* A);
void insertarOrdenado(Pila *A, int new);
void ordenamientoPorInsercion(Pila* A);
int sumarDosUltimos(Pila A);
int sumaDeTodaLaPila(Pila A);
int contar(Pila A);
float division(int num1,int num2);
float funcionPromedio(Pila A);
int ejercicio10(Pila A);




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


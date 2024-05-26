
typedef struct { 
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio; 
} stAlumno; 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

/*
Hacer una función que agregue un elemento al final de un archivo. 
Hacer una función que muestre por pantalla el contenido de un archivo. 
Hacer una función que retorne la cantidad de registros que contiene un archivo. 
Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función 
Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.
Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra. 
Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad. 
Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.
Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar
Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.
Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro. 
Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo. Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.
Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell. Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.
Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una función que muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro. Controlar no sobrepasar los límites del archivo.
Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos. La misma debe permitir modificar uno o todos los campos de la estructura y sobreescribir el registro existente en el archivo. 
Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo. No se puede usar otro archivo auxiliar ni un arreglo auxiliar. Debe trabajar sobre el archivo. Puede utilizar variables de tipo alumno auxiliares.
Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.

*/

void funcionAgregar_al_final(int dato);
void mostrarDato();
int cantidad_deRegistros();
stAlumno cargarAlumno();
void cargarArchivo_deAlumnos();
void mostrarAlumno(stAlumno alumno);
void mostrarArchivo_deAlumnos();
int calcularCantidad(char archivo[]);
Pila apilarLegajos();
int encontrarCantidadMayorA(int aBuscar);
void mostrarSoloAlgunos(char archivo[], int rango1, int rango2);
void mostrarMayorAlumno(char archivo[]);
int cantidadAlumnos(char archivo[] ,int year);
void copiarArreglo_aArchivo(char archivo[], stAlumno alumnos[], int cantidad);
void mostrarPrevioArreglo(char archivo[], int edad);
int cantidadDeRegistrosFSEEK_FTELL(char archivo[],size_t tipoDeDato);
int mostrar10(char archivo[], int aMostrar);
void modificarAlumno(stAlumno *auxiliar);
void modificarArchivoDeAlumnos(char archivo[], int numeroDeRegistro);
void invertirArchvo(char archivo[]);


int main(){
    int dato;
    printf("Ingrese un dato entero para agregar a su archivo\n");
    fflush(stdin);
    scanf("%d", &dato);
    funcionAgregar_al_final(dato);

    mostrarDato();

    printf("La cantidad de registros dentro del archivo es %d", cantidad_deRegistros());

    cargarArchivo_deAlumnos();

    mostrarArchivo_deAlumnos();
    
    return 0;
}

void funcionAgregar_al_final(int dato){
    FILE* buf;
    buf = fopen("archivo_ej1","a+b");
    if(buf){
        fwrite(&dato,sizeof(int),1,buf);
        fclose(buf);
        printf("El archivo se creo y guardo en root\n");
    }else{
        printf("No se pudo crear el archivo\n");
    }
}

void mostrarDato(){
    FILE* buf;
    buf = fopen("archivo_ej1", "rb");
    int aux;
    if(buf){
        fread(&aux,sizeof(int),1,buf);
        printf("Guardado dentro esta el numero %d \n", aux);
        fclose(buf);
    }else{
        printf("No se pudo leer el archivo\n");
    }
}


int cantidad_deRegistros() {
    FILE* buf;
    buf = fopen("archivo_ej1", "rb");
    int aux;
    int contador = 0; // Initialize the counter to 0
    if (buf) {
        while (fread(&aux, sizeof(int), 1, buf)) { // Keep reading integers until EOF
            contador++; // Increment the counter for each integer read
        }
        printf("La cantidad de registros es %d\n", contador);
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
    return contador; // Return the total count of integers
}

stAlumno cargarAlumno(){
    
    stAlumno alumno;
    printf("cargue legajo\n");
    scanf("%d",&alumno.legajo);
    printf("cargue nombre y apellido\n");
    fflush(stdin);
    fgets(alumno.nombreYapellido, sizeof(alumno.nombreYapellido), stdin);
    printf("cargue edad\n");
    scanf("%d",&alumno.edad);
    printf("cargue año\n");
    scanf("%d",&alumno.anio);

    return alumno;
}

void cargarArchivo_deAlumnos(){
    FILE* buf;
    buf = fopen("archivo_ej4", "a+b");
    stAlumno alumno;
    int i = 0;
    if (buf) {
        while(i<4){
            alumno = cargarAlumno();
            fwrite(&alumno,sizeof(stAlumno),1,buf);
            i++;
        }
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
}

void mostrarAlumno(stAlumno alumno){
    printf("%d\n",alumno.legajo);
    puts(alumno.nombreYapellido);
    printf("\n%d\n",alumno.edad);
    printf("%d\n",alumno.anio);
}

void mostrarArchivo_deAlumnos(){
    FILE* buf;
    buf = fopen("archivo_ej4", "rb");
    stAlumno alumno;
    int i = 0;
    if (buf) {
        while(i<4){
            fread(&alumno,sizeof(stAlumno),1,buf);
            mostrarAlumno(alumno);
            i++;
        }
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
}

// Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra. 

void agregarAlFinal(){
    stAlumno aux;
    aux = cargarAlumno();

    FILE* buf;
    buf = fopen("archivo_ej4", "ab");
    if (buf) {
        fwrite(&aux, sizeof(stAlumno), 1, buf);
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
}

//Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad. 

Pila apilarLegajos(){
    int cantidad = calcularCantidad("archivo");
    FILE* buf;
    buf = fopen("archivo", "rb");
    Pila legajos;
    inicpila(&legajos);
    stAlumno aux;
    if (buf) {
        int i = 0;
        while(i<cantidad){
            fread(&aux,sizeof(stAlumno),1,buf);
            apilar(&legajos,aux.legajo);
            i++;
        }
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
    return legajos;
}

int calcularCantidad(char archivo[]){
    FILE* buf;
    buf = fopen(archivo, "rb");
    stAlumno aux;
    int i = 0;
     if (buf) {
        while(fread(&aux,sizeof(stAlumno),1,buf)>0){
        i++;
        };
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
    return i;
}

//Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.

int encontrarCantidadMayorA(int aBuscar){
    int cantidad = calcularCantidad("archivo");
    FILE* buf;
    buf = fopen("archivo", "rb");
    stAlumno aux;
    int i = 0;
    int contar = 0;
    if (buf) {
        while(i<cantidad){
            fread(&aux,sizeof(stAlumno),1,buf);
            if(aBuscar == aux.edad){
                contar++;
            }
            i++;
        }
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
    return contar;
}

//  Dado un archivo de alumnos, mostrar por pantalla el nombre de todos
//   los alumnos entre un rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar

void mostrarSoloAlgunos(char archivo[], int rango1, int rango2){
    int cantidad = calcularCantidad("archivo");
    FILE* buf;
    buf = fopen(archivo, "rb");
    stAlumno aux;
    int i = 0;
     if (buf) {
        while(i<cantidad){
            fread(&aux,sizeof(stAlumno),1,buf);
            if(aux.edad >= rango1 && aux.edad <= rango2){
                mostrarAlumno(aux);
            }
            i++;
        }
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
}

// Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.

void mostrarMayorAlumno(char archivo[]){
    int cantidad = calcularCantidad("archivo");
    FILE* buf;
    buf = fopen(archivo, "rb");
    stAlumno mayor, aux;
    int i = 0;
     if (buf) {
        fread(&mayor,sizeof(stAlumno),1,buf);
        while(i<cantidad){
            fread(&aux,sizeof(stAlumno),1,buf);
            if(aux.edad > mayor.edad){
                mayor = aux;
            }
            i++;
        }
        mostrarAlumno(mayor);
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
}

//Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro. 

int cantidadAlumnos(char archivo[] ,int year){
    int cantidad = calcularCantidad("archivo");
    FILE* buf;
    buf = fopen(archivo, "rb");

    stAlumno aux;
    int contadorAlumnos = 0;
    int i = 0;

     if (buf) {
        while(i<cantidad){
            fread(&aux,sizeof(stAlumno),1,buf);
            if(aux.anio == year){
                contadorAlumnos++;
            }
            i++;
        }
        fclose(buf);
    } else {
        printf("No se pudo leer el archivo\n");
    }
    return contadorAlumnos;
}

// Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo.
// Asimismo, realice otra función que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular.

void copiarArreglo_aArchivo(char archivo[], stAlumno alumnos[], int cantidad) {
    FILE* buf = fopen(archivo, "ab");

    if (buf) {
        fwrite(alumnos, sizeof(stAlumno), cantidad, buf);
        fclose(buf);
    } else {
        printf("No se pudo abrir el archivo\n");
    }
}

void mostrarPrevioArreglo(char archivo[], int edad){
    int cantidad = calcularCantidad("archivo");
    FILE* buf;
    buf = fopen(archivo, "rb");
    if (buf) {
        stAlumno alumnos[20];
        stAlumno aux;
        int i = 0;
        int j = 0;
        while(i<cantidad && j<20){
            fread(&aux,sizeof(stAlumno),1,buf);
            if(aux.edad == edad){
                alumnos[j] = aux;
                j++;
            }
            i++;
        }
        fclose(buf);
    } else {
        printf("No se pudo abrir el archivo\n");
    }
}

//Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell.
// Puede pensar la función para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.

int cantidadDeRegistrosFSEEK_FTELL(char archivo[],size_t tipoDeDato){
    FILE* buf;
    buf = fopen(archivo, "rb");
    int cantidad = 0;                               
    if(buf){
        fseek(buf, 0, SEEK_END);
        long fileSize = ftell(buf);
        cantidad = fileSize/tipoDeDato;
    }else{
         printf("No se pudo abrir el archivo\n");
    }
    return cantidad;
}


// Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una 
//función que muestre el contenido de un registro, cuyo número (entre 0 y 9) se pase por parámetro. Controlar no sobrepasar los límites del archivo.

int mostrar10(char archivo[], int aMostrar){
    size_t miVariable = sizeof(stAlumno);
    int cantRegistros = cantidadDeRegistrosFSEEK_FTELL(archivo,miVariable);

    FILE* buf;
    buf = fopen(archivo, "rb");
    stAlumno aux;                               
    if(buf){
        if(aMostrar<10 && aMostrar>=0 ){
            if(aMostrar<cantRegistros){
                fseek(buf, aMostrar*sizeof(stAlumno), SEEK_SET);
                fread(&aux,sizeof(stAlumno),1,buf);
                mostrarAlumno(aux);
            }else{
                printf("El archivo tiene menos de 10 registros y usted quiso mostar uno mayor a la mayor posicion existente\n");
            }
        }else{
            printf("Esta funcion solo muestra registros hasta la posicion 0-9\n");
        }
    }else{
         printf("No se pudo abrir el archivo\n");
    }
}

// Realice una (o varias) funciones que permitan modificar un registro existente en el archivo de alumnos.
// La misma debe permitir modificar uno o todos los campos de la estructura y sobreescribir el registro existente en el archivo. 


void modificarAlumno(stAlumno *auxiliar){
    
    char control = 's';
    int eleccion = -1;
    while(control == 's'){
        printf("Ingrese que variable desea editar de la estructura \n");
        printf("Legajo [0], Nombre [1], Edad[2], Anio[3]\n");
        fflush(stdin);
        if(eleccion == 0){
            printf("A continuacion modifique legajo\n");
            scanf("%i", &auxiliar->legajo);
        }else if(eleccion == 1){
            printf("A continuacion modifique nombre\n");
            gets(auxiliar->nombreYapellido);
        }else if(eleccion == 2){
            printf("A continuacion modifique edad\n");
            scanf("%d", &auxiliar->edad);
        }else if(eleccion == 3){
            printf("A continuacion modifique anio\n");
            scanf("%d", &auxiliar->anio);
        }else{
            printf("Seleccion Incorrecta");
        }
        
        printf("Desea continuar modificando? (s/n): ");
        scanf("%c",&control);
    }
}

void modificarArchivoDeAlumnos(char archivo[], int numeroDeRegistro){
    FILE* buf = fopen(archivo, "rb+");
    stAlumno aux;
    if (buf) {
        fseek(buf,numeroDeRegistro * sizeof(stAlumno),SEEK_SET);
        fread(&aux,sizeof(stAlumno),1,buf);
        modificarAlumno(&aux);
        fseek(buf,numeroDeRegistro * sizeof(stAlumno),SEEK_SET);
        fwrite(&aux,sizeof(stAlumno),1,buf);
        fclose(buf);
    } else {
        printf("No se pudo abrir el archivo\n");
    }
}

//Dado un archivo de alumnos, hacer una función que invierta los elementos del mismo.
// No se puede usar otro archivo auxiliar ni un arreglo auxiliar. Debe trabajar sobre el archivo. Puede utilizar variables de tipo alumno auxiliares.


void invertirArchvo(char archivo[]){
    size_t tipo = sizeof(stAlumno);
    int cantidad = cantidadDeRegistrosFSEEK_FTELL(archivo,tipo);

    FILE* buf = fopen(archivo, "rb+");
    stAlumno aux, aux2;
    int i = 0;

    if (buf) {
        while(i<cantidad/2){
            //Leo el primero y lo guardo en aux
            fseek(buf,sizeof(stAlumno)*i,SEEK_SET);
            fread(&aux, sizeof(stAlumno),1,buf);
            //Posiciono al principio con SEEK_SET y me muevo con el total-i-1 para ir al ultimo. 
            //En la primera ejecucion seria 10-1-0. Asi posicionandome en la posicion 9 del archivo. Si estuviera en en la 10 no abria nada para leer.
            fseek(buf, (cantidad - 1 - i) * sizeof(stAlumno),SEEK_SET);
            fwrite(&aux2,sizeof(stAlumno),1,buf);
            //Vuelvo al principio para sobrescribir
            fseek(buf, i * sizeof(stAlumno), SEEK_SET);
            fwrite(&aux2, sizeof(stAlumno), 1, buf);
            //Voy al final a sobrescribir
            fseek(buf, (cantidad - 1 - i) * sizeof(stAlumno), SEEK_SET);
            fwrite(&aux, sizeof(stAlumno), 1, buf);

            i++;
        }
        fclose(buf);
    } else {
        printf("No se pudo abrir el archivo\n");
    }

}

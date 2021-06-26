/*
 * @file    : main.c
 * @author	: Marcelo Fernandez
 * @date	: 25/06/2021
 * @brief   : archivo principal tarea 1 ELO320
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "myStack.h"
#include "myABB.h"

/**
 * @brief           : reccorre el documento extrayendo los datos de cada persona
 * @param FILE*       : archivo que deseo recorrer
 * @param mi_stack       : stack a donde ingresaré cada dato
 * @return          : no retorna
 */
void recorrer_datos(FILE* texto, Stack *mi_stackk);

Nodo* primer_nodo;
Nodo* ultimo_nodo;
char encryptionTable[3][26]; //creo la doble lista


//main
int main(int argc, char **argv){

    FILE *archivo = fopen(argv[1],"r"); //ahora archivo será mi texto ya abierto
    //llamo la funcion reccorrer texto
    srand(time(NULL));

    char letra = 'A';
    for(int i=0 ; i< 26;i++){ //agrego todo el abecedario en cada posicion de la lista
        encryptionTable[1][i] = letra;
        encryptionTable[2][i] = 0;
        letra++ ;

        /** Estos 2 print sirven para verificar si se creó bien la tabla*/
        //printf("la letra de esta casilla es %c \n",encryptionTable[1][i]);
        //printf("la 2da letra de esta casilla es %c \n",encryptionTable[2][i]);
    }
    initEncryptionTable(encryptionTable); //llamo la funcion de crear tabla
    Stack *Mi_stack = getNewStack (25) ; //creo el stack
    recorrer_datos(archivo, Mi_stack); //recorro el archivo, y dentro de esta funcion agrego la stack y los muestro

}

//funciones
void recorrer_datos(FILE *texto, Stack *mi_stackk){ //funcion para recorrer el archivo y con el
    char palabra[1000];
    char *palabra_token;
    int cont = 0;
    struct HOJAS* raiz_arbol; //será la raiz del arbol que le doy a mi funcion mostrar_arbol
    while(cont <25){
        char nombre[100];
        char apellido[100];
        int nota;
        fgets (palabra, 1000 ,texto);

        //acá abajo comienzo a asignar los valores para printearlos
        palabra_token = strtok(palabra,",");
        strcpy(nombre,palabra_token); //nombre = palabra_token;
        palabra_token= strtok(NULL, ",");
        strcpy(apellido,palabra_token); //apellido =palabra_token;
        palabra_token= strtok(NULL, ",");
        nota= atoi(palabra_token);  //nota =palabra_token;
        /**si descomento lo siguiente puedo ver los alumnos sin usar stack ni ABB*/
        //printf("su palabra nombre es: %s \n",nombre);
        //printf("su palabra apellido es : %s \n",apellido);
        //printf("su palabra nota es: %d \n",nota);
        struct NODO *nuevo_nodo = crear_nodo(encrypt(nombre,encryptionTable), encrypt(apellido,encryptionTable),nota);
        push(mi_stackk,nuevo_nodo); //pusheo al stack cada nodo creado anteriormente

        cont ++;
    }

    raiz_arbol = imprimir_stack(mi_stackk,encryptionTable);
    mostrar_arbol(raiz_arbol,encryptionTable);
    destruir_arbol(raiz_arbol);
    stackDelete(mi_stackk);

}
int initEncryptionTable(char table[3][26]){ //funcion que forma la 2da lista con letras desordenadas

    for(int i=0; i<26;i++){
        int aleatorio = rand() % 26;
        if (aleatorio !=i && table[2][aleatorio] == 0 ){
            table[2][aleatorio] = table[1][i];

        }
        else i--;
    }
    /** lo siguiente me sirve para visualizar la tabla y ver si quedó bien hecha*/
    /*for(int i=0; i<26;i++){

        //printf("la letra de esta casilla es %c \n",table[1][i]);
        //printf("la 2da letra de esta casilla es %c \n",table[2][i]);

    }*/
    return 0;
}
char* encrypt(char* token, char table[3][26]){ //puse tabla tamaño 3 porque luego usé la fila [1] y [2] de la misma, por toc.
    int largo_token = strlen(token);
    for(int i=0;i<largo_token;i++){ //recorro cada letra de la palabra
        for(int j=0; j<26;j++){ //con cada letra comparo en la primera fila, y luego tomo el indice en que  se encuentre
            if(toupper(token[i])==table[1][j]){
                token[i]= table[2][j];
                break;
            }
        }
    }
    return token;
}
char* decrypt(char* token, char table[3][26]){
    int largo_token = strlen(token); //lo mismo que el  codificador pero inverso

    for(int i=0; i<largo_token; i++){   //tomo cada letra del nombre y lo comparo en la 2da fila del arreglo
        for(int j=0;j<26;j++){
            if(toupper(token[i])==table[2][j]){ //si coinciden tomo ese indice J yasí tengo la posicion de la letra  original
                token[i] = table[1][j];
                break;
            }
        }
    }
    return token;

}

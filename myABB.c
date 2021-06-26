/*
 * @file    : myABB.c
 * @author  : Marcelo Fernandez
 * @date    : 25/06/2021
 * @brief   : implementación de funciones para ABB,  tarea 1 ELO320
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myStack.h"
#include "myABB.h"
#include <ctype.h>

struct HOJAS* raiz = NULL;

struct HOJAS* insertStudent(struct NODO* nodo,char table[3][26]){ //me retorna una hoja para guardar la raíz
        struct HOJAS *nueva = malloc(sizeof(struct HOJAS));
        struct HOJAS *actual; //variable en comparación
        struct HOJAS *padre;  //padre de la actual en comparación
        strcpy(nueva->nombre, decrypt(nodo->nombre,table)); //copio los char en el nodo que agregaré,es decir le agrego la info
        strcpy(nueva->apellido,decrypt(nodo->apellido,table));
        nueva->nota = nodo->nota;
        nueva->der = NULL; //como es nuevo nodo,será una hoja y no tiene hijos
        nueva->izq = NULL;
        if(raiz==NULL){
            raiz = nueva;//si no hay raíz este nodo se tranformará en raíz
            return raiz;
        }
        else {
            actual = raiz; //uso la variable auxiliar para poder comparar los hijos
            padre = NULL;

            int condicion = 1;

            while (condicion) {
                padre = actual;

                if ( (nodo->apellido)[0] <= (padre->apellido)[0]) { //comparo la primera letra para ver a que lado debe ir
                    actual = actual->izq; //lo mando a la izquierda

                    if (actual == NULL) {//veo si hay hay mas hijos o no
                        padre->izq = nueva; //si no hay, puedo insertar el nodo, sino repite el while
                        return raiz;
                    }
                } else { //si el primer if no es correcto, entonces tiene que ir a la derecha
                    actual = actual->der;

                    if (actual == NULL) {
                        padre->der = nueva;
                        return raiz;
                    }
                }

            }
        }
}

void mostrar_arbol(struct HOJAS* raiz,char table[3][26]){ //no supe hacerlo sin recursividad...
    if(raiz != NULL){
        mostrar_arbol(raiz->izq,table); //tomo los de la derecha primero y en orden si aprobaron para mostrarlos
        aprobados(raiz,table);
        mostrar_arbol(raiz->der,table);
    }
}
void aprobados(struct HOJAS* nodo,char table[3][26]){ //la funcion toma un nodo e imprime sus datos si aprueba
    if(nodo->nota >=55){ //imprimo sus datos
        printf( "El alumno %s ", nodo->nombre);
        printf( " %s aprobó con nota: ",nodo->apellido );
        printf("%d \n ",nodo->nota);
        if(nodo->nota == 100){ //hay que felicitar a las notas máximas <3
            printf("      --WOOOW FELICIDADES %s, OBTUVISTE LA NOTA MÁXIMA!!--  \n", nodo->nombre);
        }


    }
}

void destruir_arbol(struct HOJAS* raiz){
    if(raiz !=NULL){
        destruir_arbol(raiz->der); //destruyo el lado derecho
        destruir_arbol(raiz->izq);//destruyo el lado izquierdo con recursividad :c perdón otra vez
        free(raiz);
    }

}

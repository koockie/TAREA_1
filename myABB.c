#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myStack.h"
#include "myABB.h"
#include <ctype.h>

struct HOJAS* raiz = NULL;

void insertStudent(struct NODO* nodo){
        struct HOJAS *nueva = malloc(sizeof(struct HOJAS));
        struct HOJAS *actual; //variable en comparación
        struct HOJAS *padre;  //padre de la actual en comparación
        strcpy(nueva->nombre,nodo->nombre); //copio los char en el nodo que agregaré,es decir le agrego la info
        strcpy(nueva->apellido,nodo->apellido);
        nueva->nota = nodo->nota;
        nueva->der = NULL; //como es nuevo nodo,será una hoja y no tiene hijos
        nueva->izq = NULL;
        if(raiz==NULL){
            raiz = nueva; //si no hay raíz este nodo se tranformará en raíz
        }
        else{
            actual = raiz; //uso la variable auxiliar para poder comparar los hijos
            padre = NULL;
        }
        int condicion = 1;
        while(condicion){
            padre = actual;
            char Ap_desencrip_nodo[15];//en las 4 lineas creo mis apellidos a comparar
            char Ap_desencrip_padre[15];
            strcpy(Ap_desencrip_nodo,nodo->apellido);
            strcpy(Ap_desencrip_padre,padre->apellido);

            if(Ap_desencrip_nodo[0] >= Ap_desencrip_padre[0]){ //comparo la primera letra para ver a que lado debe ir
                actual = actual->izq; //lo mando a la izquierda

                if(actual == NULL){//veo si hay hay mas hijos o no
                    padre->izq = nueva; //si no hay, puedo insertar el nodo, sino repite el while
                    return;
                }
            }
            else{ //si el primer if no es correcto, entonces tiene que ir a la derecha
                actual = actual->der;

                if(actual ==NULL){
                    padre->der = nueva;
                    return;
                }
            }

        }

}

void mostrar_arbol(struct HOJAS* raiz){ //no supe hacerlo sin recursividad...
    if(raiz != NULL){
        mostrar_arbol(raiz->der); //tomo los de la derecha primero y en orden si aprobaron para mostrarlos
        aprobados(raiz);
        mostrar_arbol(raiz->izq);
    }
}
void aprobados(struct HOJAS* nodo){ //la funcion toma un nodo e imprime sus datos si aprueba
    if(nodo->nota >=55){ //imprimo sus datos
        printf( "El alumno %s ", nodo->nombre);
        printf( " %s aprobó con nota: ",nodo->apellido);
        printf("%d \n",nodo->nota);

    }
}

void destruir_arbol(struct HOJAS* raiz){
    if(raiz !=NULL){
        destruir_arbol(raiz->der); //destruyo el lado derecho
        destruir_arbol(raiz->izq);//destruyo el lado izquierdo con recursividad :c perdón otra vez
        free(raiz);
    }
}

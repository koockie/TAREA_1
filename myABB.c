#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myStack.h"
#include "myABB.h"
#include <ctype.h>
//#include "main.c"

struct HOJAS* raiz = NULL;



void insertStudent(struct NODO* nodo){
        struct HOJAS *nueva;
        nueva = malloc(sizeof(struct HOJAS));
        strcpy(nueva->nombre,nodo->nombre);
        strcpy(nueva->apellido,nodo->apellido);
        nueva->nota = nodo->nota;
        nueva->der = NULL;
        nueva->izq = NULL;
        if(raiz==NULL){
            raiz = nueva;
        }
        else{
            struct HOJAS *anterior, *reco;
            anterior = NULL;
            reco = raiz;
            while (reco != NULL)
            {
                anterior = reco;
                if (strcmp(raiz->apellido,nodo->apellido) >= 0 ) {
                    reco = reco->izq;
                }
                else{
                    reco = reco->der;
                }

            }
            if (strcmp(anterior->apellido,nodo->apellido) >= 0) {
                anterior->izq = nueva;
            }
            else {
                anterior->der = nueva;
            }
        }
}

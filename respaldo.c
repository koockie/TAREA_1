include "myStack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Nodo* primer_nodo;
Nodo* ultimo_nodo;

int isFull (struct Stack* head_nodo){ //revisa si el stack esta lleno
    if((head_nodo)->capacidad_stack == (head_nodo)->num_nodos){
        printf("el stack esta lleno,retornare 0");
        return 0;
    }
    else{
        printf("el stack no esta lleno, retornare 1");
        return 1;
    }
}
int isEmpty(struct Stack* head_nodo){ //
    if((head_nodo) == NULL){
        printf("el stack está vacío");
        return 1;
    }
    else{
        printf("el stack no esta vacio");
        return 0;
    }
}

struct NODO *crear_nodo(char* nombreee,char* apellidooo,int notaaa){ //crea un nodo
    struct NODO* nodo_creado = (struct NODO*)malloc(sizeof(struct NODO));
    strcpy(nodo_creado->nombre,nombreee);
    strcpy(nodo_creado->apellido,apellidooo);
    nodo_creado->nota = notaaa;
    //printf("nodo creado \n");
    if (primer_nodo ==NULL){
        primer_nodo = nodo_creado;
        nodo_creado->next = NULL;
        nodo_creado->previous = NULL;
        ultimo_nodo = primer_nodo;
    }
    else{
        ultimo_nodo->next = nodo_creado;
        nodo_creado->next = NULL;
        nodo_creado->previous = ultimo_nodo;
        ultimo_nodo = nodo_creado;
    }
    return nodo_creado;
}


Stack* getNewStack (unsigned capacidad_deseada){ //crea un nuevo stack con la capacidad que se ingrese
    struct Stack* mi_stack = (struct Stack*)malloc(sizeof(struct Stack));
    mi_stack->num_nodos = 0;
    mi_stack->capacidad_stack = capacidad_deseada;
    mi_stack->header = NULL;
    return mi_stack;
}

int stackDelete(Stack** stack){ //eliminla el stack y libera la memoria
    if(*stack ==NULL){
        printf("no hay nodo que eliminar,retornaré 0");
        return 0;
    }
    else{
        free(stack);
        *stack = NULL;
        printf("stack eliminada correctamente, retornaré 1");
        return 1;

    }

}

Stack *push(Stack* stack_creado, struct NODO* nd_agregado){ //agrega un nuevo nodo al stack ya creado
    if((stack_creado)->header ==NULL){
        (stack_creado)->num_nodos++;
        (stack_creado)->header = nd_agregado;
    }
    else{
        (stack_creado)->num_nodos++;
        ((stack_creado)->header)->next = nd_agregado;
        nd_agregado->previous = (stack_creado)->header;
        (stack_creado)->header = nd_agregado;
        nd_agregado ->previous = NULL;

    }
    return stack_creado;
}

Stack *pop(Stack* head_nodo){// quita el primero elemento del stack
    struct NODO *aux = NULL;
    if((head_nodo)->header != NULL){
        aux = (head_nodo)->header;
        printf("1-voy a cambiar el header hasta el siguiente nodo \n");
        (head_nodo)->header = ((head_nodo)->header)->previous;

        free(aux);
        head_nodo->num_nodos--;
        printf("2- nodo eliminado correctamente \n");
        return head_nodo;
    }
    else{
        printf("no se ha eliminado el primer nodo, lo siento \n");
        return head_nodo;
    }
}

void imprimir_stack(struct Stack* mi_stack,char table[3][26]){
    struct NODO* imprimidor= (mi_stack)->header;

    if((imprimidor) !=NULL) {
        for (int i = 0; i < (mi_stack)->num_nodos; i++) {
            if((imprimidor)->nota >= 55) {

                printf("el nombre es: %s \n",(imprimidor)->nombre);
                /*char* nombre_desencriptado = decrypt((imprimidor)->nombre,table);
                char* apellido_desencriptado = decrypt((imprimidor)->nombre,table);
                printf("quienes aprobaron son: \n");
                printf("nombre: %s, " ,nombre_desencriptado);
                printf("apellido: %s, " ,apellido_desencriptado);
                printf("nota: %d" ,(imprimidor)->nota);*/

            }

            pop((imprimidor));
        }
    }

}
#include "myStack.h"
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

void *crear_nodo(char nombreee,char apellidooo,int notaaa){ //crea un nodo
    Nodo* nodo_creado = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nodo_creado->nombre,nombreee);
    strcpy(nodo_creado->apellido,apellidooo);
    nodo_creado->nota = notaaa;
    printf("nodo creado");
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

Stack *push(Stack** stack_creado, Nodo* nd_agregado){ //agrega un nuevo nodo al stack ya creado
    if((*stack_creado)->header ==NULL){
        (*stack_creado)->num_nodos++;
        (*stack_creado)->header = nd_agregado;
    }
    else{
        (*stack_creado)->num_nodos++;
        ((*stack_creado)->header)->previous = nd_agregado;
        nd_agregado->next = (*stack_creado)->header;
        (*stack_creado)->header = nd_agregado;
        nd_agregado ->previous = NULL;

    }
}

int pop(Stack* head_nodo){// quita el primero elemento del stack
    Nodo *aux = NULL;
    if((head_nodo)->header != NULL){
        aux = (head_nodo)->header;
        (head_nodo)->header = ((head_nodo)->header)->next;
        free(aux);
        head_nodo->num_nodos--;
        printf("primer nodo eliminado correctamente");
        return 0;
    }
    else{
        printf("no se ha eliminado el primer noso, lo siento");
        return 0;
    }
}

void imprimir_stack(Stack* mi_stack){
    Nodo* imprimidor= (mi_stack)->header;
    if(mi_stack!=NULL) {
        for (int i = 0; i < (mi_stack)->num_nodos; i++) {
            printf("el nombre de esta persona es: %s \n", imprimidor->nombre);
            printf("el apellido de esta persona es: %s \n", imprimidor->apellido);
            printf("la nota de esta persona es: %d \n", imprimidor->nota);
            imprimidor = (imprimidor)->previous;
        }
    }
}






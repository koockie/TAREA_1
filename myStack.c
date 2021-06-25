#include "myStack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myABB.h"
Nodo* primer_nodo;
Nodo* ultimo_nodo;

int isFull (struct Stack* head_nodo){ //revisa si el stack esta lleno
    if((head_nodo)->capacidad_stack == (head_nodo)->num_nodos){
        printf("el stack esta lleno,retornare 0  \n");
        return 0;
    }
    else{
        printf("el stack no esta lleno, retornare 1 \n");
        return 1;
    }
}
int isEmpty(struct Stack* head_nodo){ //
    if((head_nodo) == NULL){
        printf("el stack está vacío\n");
        return 1;
    }
    else{
        printf("el stack no esta vacio\n");
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
    //printf("tabla creada bro\n");
    mi_stack->num_nodos = 0;
    mi_stack->capacidad_stack = capacidad_deseada;
    mi_stack->header = NULL;
    return mi_stack;
}

/*int stackDelete(Stack* stack){ //eliminla el stack y libera la memoria
    if(*stack ==NULL){
        printf("no hay nodo que eliminar,retornaré 0\n");
        return 0;
    }
    else{
        free(stack);
        *stack = NULL;
        printf("stack eliminada correctamente, retornaré 1\n");
        return 1;

    }

}*/

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
        nd_agregado ->next = NULL;


    }
    return stack_creado;
}

struct HOJAS *pop(Stack* head_nodo){// quita el primero elemento del stack
    struct NODO *futura_raiz = NULL;
    if((head_nodo)->header != NULL){
        futura_raiz = (head_nodo)->header;
        //printf("1-voy a cambiar el header hasta el siguiente nodo \n");
        (head_nodo)->header = ((head_nodo)->header)->previous;

        //free(aux);
        head_nodo->num_nodos--;
        //printf("2- nodo eliminado correctamente \n");
        return futura_raiz;
    }
    else{
        printf("no se ha eliminado el primer nodo, lo siento \n");
        return futura_raiz;
    }
}

struct  HOJAS* imprimir_stack(struct Stack* mi_stack,char table[3][26]){
    struct Stack *imprimidor= (mi_stack);
    struct HOJAS* futura_raiz; //lo usaré para forzar la raíz de mi futuro arbol
    struct HOJAS* raiz_final; //será la raiz del arbol que retornaré para usar en el main
    if(((imprimidor)->header !=NULL)) {
        for (int i = 0; i < 25; i++) {
            char nombresito[20];
            strcpy(nombresito,imprimidor->header->nombre);
            char apellidisito[20];
            strcpy(apellidisito,imprimidor->header->apellido);
            if((imprimidor)->header->nota >= 55) {
                /*char nombresito[20];
                strcpy(nombresito,imprimidor->header->nombre);
                char apellidisito[20];
                strcpy(apellidisito,imprimidor->header->apellido);*/


               // printf("el nombre es: %s \n",(decrypt(nombresito,table)));
               // printf("el apellido es: %s \n",(decrypt(apellidisito,table)));
               // printf("el nota es: %d \n",((imprimidor)->header)->nota);

                //futura_raiz = pop((imprimidor));
                //raiz_final = insertStudent(futura_raiz);
            }

            futura_raiz = pop((imprimidor));
            raiz_final = insertStudent(futura_raiz,table);

        }
    }
    return raiz_final;

}






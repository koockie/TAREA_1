#define NLEN 30

typedef struct nodo {

    char nombre[NLEN];
    char apellido[NLEN];
    int nota;

    struct nodo* previous;
    struct nodo* next;
}nodo;

typedef struct Stack {
    unsigned capacidad_stack; // capacidad o total de nodos
    int num_nodos;// indicar cuantos nodos hay en la struct
    Nodo* header; // header
}Stack;


int isFull () ;// indica si el stack está lleno
int isEmpty() ;// indica si el stack está vacío
stack getNewStack () ;// genera un nuevo stack
int stackDelete() ;// elimina el stack y libera la memoria reservada
stack push();// agrega un elemento al stack
stack pop();// quita el primero elemento del stack

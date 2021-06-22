#define NLEN 30
typedef struct Nodo {

    char nombre[NLEN];
    char apellido[NLEN];
    int nota;

    struct Nodo* previous;
    struct Nodo* next;
}Nodo;

typedef struct Stack {
    unsigned capacidad_stack; // capacidad o total de nodos
    int num_nodos;// indicar cuantos nodos hay en la struct
    Nodo* header; // header
}Stack;


int isFull (struct Stack* head_nodo) ;// indica si el stack está lleno
int isEmpty(struct Stack* head_nodo) ;// indica si el stack está vacío
Stack *getNewStack (unsigned capacidad_deseada) ;// genera un nuevo stack
int stackDelete(Stack** stack) ;// elimina el stack y libera la memoria reservada
Stack *push(Stack** stack, Nodo* nodo);// agrega un elemento al stack
void *crear_nodo(char nombreee,char apellidooo,int notaaa); //crea un nodo
int pop(Stack* head_nodo);// quita el primero elemento del stack
void imprimir_stack(Stack* mi_stack);


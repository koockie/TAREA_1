#define NLEN 30
typedef struct NODO {

    char nombre[NLEN];
    char apellido[NLEN];
    int nota;

    struct NODO* previous;
    struct NODO* next;
}Nodo;

typedef struct Stack {
    unsigned capacidad_stack; // capacidad o total de nodos
    int num_nodos;// indicar cuantos nodos hay en la struct
    struct NODO* header; // header
}Stack;


int isFull (struct Stack* head_nodo) ;// indica si el stack está lleno
int isEmpty(struct Stack* head_nodo) ;// indica si el stack está vacío
Stack *getNewStack (unsigned capacidad_deseada) ;// genera un nuevo stack
int stackDelete(Stack* stack) ;// elimina el stack y libera la memoria reservada
Stack *push(Stack* stack, Nodo* nodo);// agrega un elemento al stack
struct NODO*  crear_nodo(char* nombreee,char* apellidooo,int notaaa); //crea un nodo
Stack *pop(Stack* head_nodo);// quita el primero elemento del stack
struct NODO* imprimir_stack(Stack* mi_stack,char table[3][26]);
char* decrypt(char* token, char table[3][26]);

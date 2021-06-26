/*
 * @file    : myStack.h
 * @author  : Marcelo Fernandez
 * @date    : 25/06/2021
 * @brief   : declaración de funciones y estructura para mi stack y sus nodos
 */
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

/**
 * @brief           : funcion que revisa si el stack esta lleno
 * @param head_nodo       : nodo cabecera que puedo trabajar y contiene  mi info
 * @return          : retorna 0 si eta lleno y 1 si no lo esta
 */
int isFull (struct Stack* head_nodo) ;//

/**
 * @brief           : funcion que revisa si el stack esta vacío
 * @param head_nodo       : nodo cabecera que puedo trabajar y contiene  mi info
 * @return          : retorna 1 si esta vacio y 0 si no esta vacio
 */
int isEmpty(struct Stack* head_nodo) ;// indica si el stack está vacío

/**
 * @brief           : crea un nuevo stack
 * @param capacidad_deseada       : capacidad que deseo tenga el nuevo stack
 * @return          : retorna un puntero a mi stack
 */
Stack *getNewStack (unsigned capacidad_deseada) ;// genera un nuevo stack

/**
 * @brief           : eslimina el stack y sus nodos
 * @param stack       : recibe el stack que deseo eliminar
 * @return          : retorna 1 si se elimina el nodo
 */
int stackDelete(Stack* stack) ;// elimina el stack y libera la memoria reservada

/**
 * @brief           : agrega nuevo elemento al stack
 * @param stack       :  stack al que deseo agregar un elemento
 * @param nodo       : nodo  con a informacion que quiero agregar
 * @return          : me retorna la cabecera siempre
 */
Stack *push(Stack* stack, Nodo* nodo);// agrega un elemento al stack

/**
 * @brief           : crea un nodo nuevo
 * @param nombreee       :  nombre a asignar
 * @param apellidooo     :  apellido a asignar
 * * @param notaaa      : nota correspondiente a la persona del nodo
 * @return          : me retonra el puntero al nodo creado
 */
struct NODO*  crear_nodo(char* nombreee,char* apellidooo,int notaaa); //crea un nodo

/**
 * @brief           : quita el elemento que este como cabecera
 * @param head_nodo       : nodo que voy a elliminar
 * @return          : me retorna la nueva cabecera
 */
struct HOJAS *pop(Stack* head_nodo);// quita el primero elemento del stack

/**
 * @brief           : imprime todo mi stack en orden de elementos
 * @param mi_stack       : stack que tengo que imprimir
 * @param table       : tabla para imprimir nombres desencriptados
 * @return          : me retorna la nueva cabecera
 */
struct  HOJAS* imprimir_stack(Stack* mi_stack,char table[3][26]);

/**
 * @brief           : desencripta un nombre o apellido
 * @param token       : palabra que debo desencriptar
 * @param table       : tabla para imprimir nombres desencriptados
 * @return          : retorna la palabra desencriptada
 */
char* decrypt(char* token, char table[3][26]);

/**
 * @brief           : reccorre el documento extrayendo los datos de cada persona
 * @param FILE*       : archivo que deseo recorrer
 * @param mi_stack       : stack a donde ingresaré cada dato
 * @return          : no retorna
 */
void recorrer_datos(FILE* texto, Stack *mi_stackk);

/**
 * @brief           : rellena mi tabla de encriptación con las letras aleatorias
 * @param table       : tabla a la que le debo agregar los valores aleatorios
 * @return          : retorna 0 cuando se complete la tabla
 */
int initEncryptionTable(char table[3][26]);

/**
 * @brief           : encripta los nombres y apellidos
 * @param token       : palabra que deseo encriptar
 * @param table       : tabla para imprimir nombres desencriptados
 * @return          : retorna mi palabra encriptada
 */
char* encrypt(char* token, char table[3][26]);

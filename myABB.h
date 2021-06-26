/*
 * @file    : myABB.h
 * @author  : Marcelo Fernandez
 * @date    : 25/06/2021
 * @brief   : declaración de funciones y estructura para crear arbol binario, TAREA 1 ELO320
 */
#define NLEN 30
typedef struct HOJAS {
    char nombre[NLEN];
    char apellido[NLEN];
    int nota;
    struct HOJAS *izq;
    struct HOJAS *der;
}Hoja;


/**
 * @brief           : inserta un nuevo nodo al arbol binario
 * @param nodo       : nodo que saco del stack y deseo insertar al arbol
 * @param table      : tabla de escriptación para trabajar los nombres y apellidos
 * @return          : retorna la hoja actual creada
 */
struct HOJAS* insertStudent( struct NODO* nodo,char table[3][26]);

/**
 * @brief           : me muestra el arbol binario y quienes aprobaron en orden
 * @param raiz       : raiz del arbol
 * @param table      : tabla de escriptación para trabajar los nombres y apellidos
 * @return          : no retorna
 */
void mostrar_arbol(struct HOJAS* raiz,char table[3][26]);

/**
 * @brief           : imprime por pantalla los datos de quienes aprobaron
 * @param nodo       : nodo que saco del stack que analizaré
 * @param table      : tabla de escriptación en evaluación de uso...
 * @return          : no retorna
 */
void aprobados(struct HOJAS* nodo,char table[3][26]);

/**
 * @brief           : elimina el arbol binario
 * @param raiz       : nodo raiz de mi ABB
 * @return          : no retorna
 */
void destruir_arbol(struct HOJAS* raiz);


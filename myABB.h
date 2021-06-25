

#define NLEN 30
typedef struct HOJAS {
    char nombre[NLEN];
    char apellido[NLEN];
    int nota;
    struct HOJAS *izq;
    struct HOJAS *der;
}Hoja;



struct HOJAS* insertStudent(struct NODO* nodo,char table[3][26]);
void mostrar_arbol(struct HOJAS* raiz,char table[3][26]);
void aprobados(struct HOJAS* nodo,char table[3][26]);
void destruir_arbol(struct HOJAS* raiz);


#define NLEN 30
typedef struct HOJAS {
    char nombre[NLEN];
    char apellido[NLEN];
    int nota;
    struct HOJAS *izq;
    struct HOJAS *der;
}Hoja;

void insertStudent(struct NODO* nodo);


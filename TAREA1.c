#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//declaracion de funciones
void recorrer_datos(FILE* );

int initEncryptionTable(char table[3][26]);
//main
int main(int argc, char **argv){

    FILE *archivo = fopen(argv[1],"r"); //ahora archivo será mi texto ya abierto
    /*recorrer_datos(archivo);*/
    
    char encryptionTable[3][26]; //creo la doble lista
    char letra = 'A';
    for(int i=0 ; i< 26;i++){ //agrego todo el abecedario en cada posicion de la lista
        encryptionTable[1][i] = letra;
        encryptionTable[2][i] = 0;
        letra++ ;
        //printf("la letra de esta casilla es %c \n",encryptionTable[1][i]);
        //printf("la 2da letra de esta casilla es %c \n",encryptionTable[2][i]);
    }
    initEncryptionTable(encryptionTable);
}

//funciones
void recorrer_datos(FILE *texto){ //funcion para recorrer el archivo
    char palabra[1000];
    char *palabra_token;
    printf("hola \n"); 
    fgets (palabra, 1000 ,texto);
    palabra_token = strtok(palabra, ",");
    int cont = 0;
    while(cont <75){

        if( cont%3 == 0 && cont!=0){
            fgets (palabra, 1000 ,texto);
            palabra_token = strtok(palabra,",");
        }
        printf("su palabra o token es: %s \n",palabra_token);
        palabra_token= strtok(NULL, ",");
        cont ++;
    }

}
int initEncryptionTable(char table[3][26]){ //funcion que forma la 2da lista con letras desordenadas

    for(int i=0; i<26;i++){
        int aleatorio = rand() % 26;
        if (aleatorio !=i && table[2][aleatorio] == 0 ){
            table[2][aleatorio] = table[1][i];

        }
        else i--;
    }
    for(int i=0; i<26;i++){
        printf("la letra de esta casilla es %c \n",table[1][i]);
        printf("la 2da letra de esta casilla es %c \n",table[2][i]);
    }
return 0;
}


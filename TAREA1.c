#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
char encryptionTable[3][26]; //creo la doble lista
//declaracion de funciones
void recorrer_datos(FILE* );
int initEncryptionTable(char table[3][26]);
char* encrypt(char* token, char table[3][26]);
//main
int main(int argc, char **argv){

    FILE *archivo = fopen(argv[1],"r"); //ahora archivo será mi texto ya abierto
     //llamo la funcion reccorrer texto
    srand(time(NULL));
    //char encryptionTable[3][26]; //creo la doble lista
    char letra = 'A';
    for(int i=0 ; i< 26;i++){ //agrego todo el abecedario en cada posicion de la lista
        encryptionTable[1][i] = letra;
        encryptionTable[2][i] = 0;
        letra++ ;
        //printf("la letra de esta casilla es %c \n",encryptionTable[1][i]);
        //printf("la 2da letra de esta casilla es %c \n",encryptionTable[2][i]);
    }
    initEncryptionTable(encryptionTable); //llamo la funcion de crear tabla
    recorrer_datos(archivo);

}

//funciones
void recorrer_datos(FILE *texto){ //funcion para recorrer el archivo
    char palabra[1000];
    char *palabra_token;
    fgets (palabra, 1000 ,texto);
    palabra_token = strtok(palabra, ",");
    int cont = 0;
    while(cont <75){
        //encrypt(palabra_token,encryptionTable);
        if( cont%3 == 0 && cont!=0){
            fgets (palabra, 1000 ,texto);
            palabra_token = strtok(palabra,",");
            //encrypt(palabra_token,encryptionTable);
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
char* encrypt(char* token, char table[3][26]){
    int largo_token = strlen(token);
    printf("su token original es:  %s \n",token);
    for(int i=0;i<largo_token;i++){
        for(int j=0; j<26;j++){
            if(toupper(token[i])==table[1][j]){
                token[i]= table[2][j];
            }
        }
    }
    printf("su token codificado es %s \n", token);
    return token;
}

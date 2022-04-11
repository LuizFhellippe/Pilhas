
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>


typedef struct pilha{
    char letra;
    struct pilha *proximo;
}Pilha;

Pilha *topo=NULL;
char palavra[50],comparativo[50];
int tamanho;

void inserirPilha(char caractere){
    Pilha *newLetra = (Pilha*)malloc(sizeof(Pilha));
    newLetra->letra = caractere;
    newLetra->proximo = topo;
    topo = newLetra;
}

void desimpilhar(){
    Pilha *aux = (Pilha*)malloc(sizeof(Pilha));
    aux = topo->proximo;
    comparativo[tamanho] = topo->letra;
    free(topo);
    topo = aux;
    tamanho++;
}


int main(){
    tamanho=0;
    int aux=0;
    printf("Digite a palavra\n");
    gets(palavra);
    for(int i=0;i<50;i++){
        if(palavra[i]!='\0'){
            inserirPilha(palavra[i]);
            aux++;
        }
    }
    while(topo!=NULL){
        desimpilhar();
    }
    bool resultado =true;
    for(int i=0;i<aux;i++){
        if(palavra[i]!=comparativo[i]){
            resultado=false;
            break;
        }
    }
    if(resultado){
        printf("E palindromo\n");
    }
    else{
        printf("Nao e palindromo\n");
    }
    return 0;
}
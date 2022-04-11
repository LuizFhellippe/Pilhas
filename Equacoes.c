#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char caractere;
    struct no *proximo;
}No;

No* empilhar(No *pilha, char valor){
    No *new = malloc(sizeof(No));

    if(new){
        new->caractere = valor;
        new->proximo = pilha;
        return new;
    }else{
        printf("Erro ao alocar memoria\n");
    }
    return NULL;
}

No* desempilhar(No **pilha){
    No *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }else{
        printf("Erro ao alocar memoria\n");
    }
    return remover;
}

void imprimir(No *pilha){
    printf("=================Pilha=================\n");
    while(pilha){
        printf("%c", pilha->caractere);
        pilha = pilha->proximo;
    }
}

int formaPar(char f, char d){
    switch(f){
        case ')':
            if(d == '('){
                return 1;
            }else{
                return 0;
            }
            break;
        case ']':
            if(d == '['){
                return 1;
            }else{
                return 0;
            }
            break;
        case '}':
            if(d == '{'){
                return 1;
            }else{
                return 0;
            }
            break;
    }
}

int identificaFormacao(char x[]){
    int i = 0;
    No *remover, *pilha = NULL;
    while(x[i] != '\0'){
        if(x[i] == '[' || x[i] == '(' || x[i] == '{'){
            pilha = empilhar(pilha, x[i]);
        }else if(x[i] == ']' || x[i] == ')' || x[i] == '}'){
            remover = desempilhar(&pilha);
            if(formaPar(x[i], remover->caractere) == 0){
                printf("Expressao mal formada\n");
                return 1; 
            }
            free(remover);
        }
        i++;
    }
    imprimir(pilha);
    if(pilha){
        printf("Expressao mal formada\n");
        return 1;
    }else{
        printf("Expressao bem formada\n");
        return 0;
    }
}

int main(){
    char exp[50];

    printf("Digite uma epressao: ");
    scanf("%49[^\n]", exp);
    printf("Expressao: %s\nRetorno: %d\n", exp, identificaFormacao(exp));

    return 0;
}
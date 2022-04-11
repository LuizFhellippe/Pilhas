#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia, mes, ano;
}Data;

typedef struct{
    char nome[50];
    Data data;
}Pessoa;

typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

Pessoa lerPessoa(){
    Pessoa p;
    printf("Digite o nome e data de nascimento dd mm aaaa: \n");
    fflush(stdin);
    scanf("%49[^\n]%d %d %d", p.nome, &p.data.dia, &p.data.mes, &p.data.ano);
    return p;
}

void imprimirPessoa(Pessoa p){
    printf("Nome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

No* empilhar(No *topo){
    No *new = malloc(sizeof(No));

    if(new){
        new->p = lerPessoa();
        new->proximo = topo;
        return new;
    }else{
        printf("Erro ao alocar memoria");
    }
    return NULL;
}

No* desempilhar(No **topo){
    if(*topo){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }else{
        printf("Pilha vazia\n");
    }
    return NULL;
}

void imprimir(No *topo){
    printf("===========Pilha===========\n");

    while(topo){
        imprimirPessoa(topo->p);
        topo = topo->proximo;
    }

    printf("===========Fim pilha===========\n");
}

int main(){
    No *remover, *topo = NULL;
    int opcao;

    do{
        printf("0 - Sair\n1 - Empilhar\n2 - Desempilhar\n3 - Imprimir\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                topo = empilhar(topo);
                break;
            case 2:
                remover = desempilhar(&topo);
                if(remover){    
                    printf("Elemento demovido com sucesso!\n");
                    imprimirPessoa(remover->p);
                }else{
                    printf("Sem no a remover\n");
                }
                break;
            case 3:
                imprimir(topo);
                break;
            default:
                if(opcao != 0){
                    printf("Opacao invalida\n");
                }
        }
    }while(opcao != 0);
}
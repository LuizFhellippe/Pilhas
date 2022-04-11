#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    float valor;
    struct no *proximo;
}Pilha;

Pilha* empilhar(Pilha *pilha, float num){
    Pilha *new = malloc(sizeof(Pilha));

    if(new){
        new->valor = num;
        new->proximo = pilha;
        return new;
    }else{
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
}

Pilha* desempilhar(Pilha **pilha){
    Pilha *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->proximo;
    }else{
        printf("Pilha vazia\n");
    }
    return remover;
}

float Operacao(float n1, float n2, char x){
    switch(x){
        case '+':
             return n1 + n2;
            break;
        case '-':
            return n1 - n2;
            break;
        case '/':
            return n1 / n2;
            break;
        case '*':
            return n1 * n2;
            break;
        default:
            return 0.0;
    }
}

float ResolverExpressao(char caracteres[]){
    char *pt;
    float num;
    Pilha *n1, *n2, *pilha = NULL;

    pt = strtok(caracteres, " ");
    while(pt){
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = Operacao(n2->valor, n1->valor, pt[0]);
            pilha = empilhar(pilha, num);
            free(n1);
            free(n2);
        }else{
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = desempilhar(&pilha);
    num = n1->valor;
    free(n1);
    return num;
}

int main(){
    char exp[50] = {"51 13 12 * +"};

    // printf("Digite a expressao\n");
    // fflush(stdin);
    // fgets(&exp, 50, stdin);
    printf("Restultado de %s:\t", exp);
    printf("%.2lf\n", ResolverExpressao(exp));
}
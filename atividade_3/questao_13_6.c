#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* criaNo(int valor){
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->esq = NULL;
    no->dir = NULL;
    return no;
}

int ehEstritamenteBin(No* no){
    if(node == NULL){
        return 1;
    }
    if(no->esq == NULL && no->dir == NULL){
        return 1;
    }
    if(no->esq == NULL || no->dir == NULL){
        return 0;
    }

    return ehEstritamenteBin(no->esq) && ehEstritamenteBin(no->dir);
}

int main(){
    No* raiz = criaNode(1);
    raiz->esq = criaNo(2);
    raiz->dir = criaNo(3);
    raiz->esq->esq = criaNo(4);
    raiz->esq->dir = criaNo(5);
    raiz->dir->esq = criaNo(6);

    if (ehEstritamenteBin(raiz)) {
        printf("A arvore e estritamente binaria.\n");
    } else {
        printf("A arvore nao e estritamente binaria.\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

No* novoNo(int valor){
    struct No* No = (struct No*)malloc(sizeof(struct No));
    No->valor = valor;
    No->esq = NULL;
    No->dir = NULL;
    return No;
};

bool ehCompleta(No* raiz){
    if (raiz == NULL){
        return true;
    }

    if (raiz->esq == NULL && raiz->dir == NULL){
        return true;
    }
    else if (raiz->esq != NULL && raiz->dir != NULL) {
        return ehCompleta(raiz->esq) && ehCompleta(raiz->dir);
    }
    else {
        return false;
    }
}

int main(){
    No* raiz = novoNo(1);
    raiz->esq = novoNo(2);
    raiz->dir = novoNo(3);
    raiz->esq->esq = novoNo(4);
    raiz->esq->dir = novoNo(5);
    raiz->dir->esq = novoNo(6);
    raiz->dir->dir = novoNo(7);
    raiz->esq->esq->esq = novoNo(8);

    printf("A arvore eh %s\n", ehCompleta(raiz) ? "completa" : "incompleta");


    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define fmt "%d"

typedef struct no{
    char valor;
    struct no* esq;
    struct no* dir;
} No;

No* criarNo(char valor){
    No* newNo = (No*) malloc(sizeof(No));
    newNo -> valor = valor;
    newNo -> esq = NULL;
    newNo -> dir = NULL;
    return newNo;
}

No* inserirNo(No *raiz, char valor){
    if (raiz == NULL){
        return criarNo(valor);
    }
    if (valor < raiz -> valor){
        raiz -> esq = inserirNo(raiz -> esq, valor);
    } else {
        raiz -> dir = inserirNo(raiz -> dir, valor);
    }
    return raiz;
}

No* construirArvoreAltura3(){
    No *raiz = criarNo(1);
    raiz->esq = criarNo(2);
    raiz->dir = criarNo(3);
    raiz->esq->esq = criarNo(4);
    raiz->esq->dir = criarNo(5);
    raiz->dir->esq = criarNo(6);
    raiz->dir->dir = criarNo(7);
    raiz->esq->esq->esq = criarNo(8);
    raiz->esq->esq->dir = criarNo(9);
    raiz->esq->dir->esq = criarNo(10);
    raiz->esq->dir->dir = criarNo(11);
    raiz->dir->esq->esq = criarNo(12);
    raiz->dir->esq->dir = criarNo(13);
    raiz->dir->dir->esq = criarNo(14);
    raiz->dir->dir->dir = criarNo(15);
    return raiz;
}

int nos(No *raiz){
    if (raiz == NULL){
        return 0;
    }
    return 1 + contarNos(raiz -> esq) + contarNos(raiz -> dir);
}

int folhas(No *raiz){
    if (raiz == NULL){
        return 0;
    }
    if (raiz -> esq == NULL && raiz -> dir == NULL){
        return 1;
    }
    return contarFolhas(raiz -> esq) + contarFolhas(raiz -> dir);
}

int altura(No *raiz){
    if (raiz == NULL){
        return -1;
    }
    int alturaEsq = calcularAltura(raiz -> esq);
    int alturaDir = calcularAltura(raiz -> dir);
    if (alturaDir > alturaEsq){
        return alturaDir + 1;
    } else {
        return alturaEsq + 1;
    }
}

No* tem(No* raiz, int valor){
    if (raiz == NULL || raiz -> valor == valor){
        return raiz;
    }
    if (valor < raiz -> valor){
        return tem(raiz -> esq, valor);
    } else {
        return tem(raiz -> dir, valor);
    }
}


void preOrdem(No *raiz){
    if (raiz == NULL){
        return 0;
    };
    printf(fmt,raiz);
    preOrdem(raiz -> esq);
    preOrdem(raiz -> dir);
}

void printarArvore(No *raiz){
    if(raiz == NULL){
        return;
    }
    printf("<%d>", raiz-> valor);
    printarArvore(raiz -> esq);
    printarArvore(raiz -> dir);
}

int main(){
    No *raiz = construirArvoreAltura3();
    int totalNos = nos(raiz);
    int totalFolhas = folhas(raiz);
    int alturaArvore = altura(raiz);
    printf("Total de nós: %d\n", totalNos);
    printf("Total de folhas: %d\n", totalFolhas);
    printf("Altura da árvore: %d\n", alturaArvore);

    int valor = 10;
    No* resultado = tem(raiz, valor);
    if (resultado == NULL){
        printf("Item não encontrado");
    } else {
        printf("Item encontrado");
    }
    return 0;
}

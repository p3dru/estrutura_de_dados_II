/*
Printar árvore de busca em ordem decrescente
Basta realizar o inordem, porém alterando os
lados onde a pesquisa começa. Na função
descrescente, pedimos para que o nó busque
sempre o valor mais à direita da árvore e o
print. Depois, ele volta e busca o valor à
esquerda do mais à direita e o novo nó se torna
o novo nó à direita, assim, substitui sempre o
mais à direita por um valor anterior à ele e
podemos printar de forma reversa.
*/


#include <stdio.h>
#include <stdlib.h>

//cria a estrutura de árvore
typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

//criar nós
struct No* novoNo(int valor){
    struct No* No = (struct No*)malloc(sizeof(struct No));
    No->valor = valor;
    No->esq = NULL;
    No->dir = NULL;
    return No;
};

void descrescente(struct No* No){
    if (No != NULL){
        descrescente(No->dir);
        printf("%d", No->valor);
        descrescente(No->esq);
    }
};


int main(){
    struct No* raiz = novoNo(5);
    raiz->esq = novoNo(3);
    raiz->dir = novoNo(7);
    raiz->esq->esq = novoNo(2);
    raiz->esq->esq->esq = novoNo(1);
    raiz->esq->dir = novoNo(4);
    raiz->dir->esq = novoNo(6);
    raiz->dir->dir = novoNo(8);

    printf("Ordem decrescente: ");
    descrescente(raiz);
    printf('\n');

    return 0;
}

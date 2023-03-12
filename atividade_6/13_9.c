/*
Printar �rvore de busca em ordem decrescente
Basta realizar o inordem, por�m alterando os
lados onde a pesquisa come�a. Na fun��o
descrescente, pedimos para que o n� busque
sempre o valor mais � direita da �rvore e o
print. Depois, ele volta e busca o valor �
esquerda do mais � direita e o novo n� se torna
o novo n� � direita, assim, substitui sempre o
mais � direita por um valor anterior � ele e
podemos printar de forma reversa.
*/


#include <stdio.h>
#include <stdlib.h>

//cria a estrutura de �rvore
typedef struct No{
    int valor;
    struct No* esq;
    struct No* dir;
} No;

//criar n�s
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

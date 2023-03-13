#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct arv {
	char info;
    struct arv *esq;
	struct arv *dir;
}Arv;


Arv *arvore(char x,Arv *e,Arv *d){
	Arv *novo=(Arv *)malloc(sizeof(Arv));
	novo->esq=e;
	novo->dir=d;
	novo->info=x;
	return novo;

}

void imprime(Arv *n){

			if (n!=NULL){

				cout<<"<"<<n->info;
				imprime(n->esq);
				imprime(n->dir);
				cout<<">";
			   }
			   else
			     cout<<"<>";
			}

int calculaQuantNos(Arv *no){

		}

int calculaQuantNosFolha(Arv *no){

		}



int alturaArvore(Arv *no){


		}

int procura(Arv *no, char valor){

		}

// remove o nó procurado. Se o nó tiver filhos, remova também os filhos
int removeSubArvore(Arv *no, char valor){
    if (no == NULL) {
        return no;
    }
    // Busca o nó a ser removido na subárvore esquerda
    if (valor < no->info) {
        no->esq = removeSubArvore(no->esq, valor);
    }
    // Busca o nó a ser removido na subárvore direita
    else if (valor > no->info) {
        no->dir = removeSubArvore(no->dir, valor);
    }
    // Nó a ser removido foi encontrado
    else {
        // Caso 1: o nó não tem filhos ou é uma folha
        if (no->esq == NULL && no->dir == NULL) {
            free(no);
            no = NULL;
        }
        // Caso 2: o nó tem apenas um filho, à esquerda ou à direita
        else if (no->esq == NULL) {
            Arv* temp = no;
            no = no->dir;
            free(temp);
        }
        else if (no->dir == NULL) {
            Arv* temp = no;
            no = no->esq;
            free(temp);
        }
        // Caso 3: o nó tem dois filhos
        else {
            // Busca o menor elemento da subárvore direita
            Arv* temp = findMin(no->dir);
            // Substitui o valor do nó a ser removido pelo valor do menor elemento da subárvore direita
            no->info = temp->info;
            // Remove o menor elemento da subárvore direita
            no->dir = removeSubArvore(no->dir, temp->info);
        }
    }
    return root;
}


main(){

 Arv *c = arvore('c',NULL,NULL);
 Arv *z = arvore('z',0,0);
 Arv *o = arvore('o',0,0);




}

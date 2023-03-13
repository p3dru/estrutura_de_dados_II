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

// remove o n� procurado. Se o n� tiver filhos, remova tamb�m os filhos
int removeSubArvore(Arv *no, char valor){
    if (no == NULL) {
        return no;
    }
    // Busca o n� a ser removido na sub�rvore esquerda
    if (valor < no->info) {
        no->esq = removeSubArvore(no->esq, valor);
    }
    // Busca o n� a ser removido na sub�rvore direita
    else if (valor > no->info) {
        no->dir = removeSubArvore(no->dir, valor);
    }
    // N� a ser removido foi encontrado
    else {
        // Caso 1: o n� n�o tem filhos ou � uma folha
        if (no->esq == NULL && no->dir == NULL) {
            free(no);
            no = NULL;
        }
        // Caso 2: o n� tem apenas um filho, � esquerda ou � direita
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
        // Caso 3: o n� tem dois filhos
        else {
            // Busca o menor elemento da sub�rvore direita
            Arv* temp = findMin(no->dir);
            // Substitui o valor do n� a ser removido pelo valor do menor elemento da sub�rvore direita
            no->info = temp->info;
            // Remove o menor elemento da sub�rvore direita
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

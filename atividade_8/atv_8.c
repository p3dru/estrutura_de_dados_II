#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó na árvore
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para verificar se uma árvore binária é cheia
bool isFullBinaryTree(Node* root) {
    // Se a árvore está vazia, ela é uma árvore binária cheia
    if (root == NULL) {
        return true;
    }

    int height = 0;
    Node* current = root;

    // Descobre a altura da árvore
    while (current != NULL) {
        height++;
        current = current->left;
    }

    // Percorre a árvore em ordem de largura
    for (int i = 1; i < height; i++) {
        // Verifica se o nó atual tem ambos os filhos
        if (root->left != NULL && root->right != NULL) {
            // Recursivamente verifica se os subárvores esquerda e direita são árvores binárias cheias
            return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
        } else {
            // Se o nó atual não tem ambos os filhos, a árvore não é uma árvore binária cheia
            return false;
        }
    }

    // Se a árvore passou em todas as verificações, ela é uma árvore binária cheia
    return true;
}

// Exemplo de uso
int main() {
    // Cria a árvore binária cheia
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Verifica se a árvore é uma árvore binária cheia
    if (isFullBinaryTree(root)) {
        printf("A arvore e uma arvore binaria cheia.\n");
    } else {
        printf("A arvore nao e uma arvore binaria cheia.\n");
    }

    return 0;
}

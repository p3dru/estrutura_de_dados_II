#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Fun��o para criar um novo n� na �rvore
Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fun��o para verificar se uma �rvore bin�ria � cheia
bool isFullBinaryTree(Node* root) {
    // Se a �rvore est� vazia, ela � uma �rvore bin�ria cheia
    if (root == NULL) {
        return true;
    }

    int height = 0;
    Node* current = root;

    // Descobre a altura da �rvore
    while (current != NULL) {
        height++;
        current = current->left;
    }

    // Percorre a �rvore em ordem de largura
    for (int i = 1; i < height; i++) {
        // Verifica se o n� atual tem ambos os filhos
        if (root->left != NULL && root->right != NULL) {
            // Recursivamente verifica se os sub�rvores esquerda e direita s�o �rvores bin�rias cheias
            return isFullBinaryTree(root->left) && isFullBinaryTree(root->right);
        } else {
            // Se o n� atual n�o tem ambos os filhos, a �rvore n�o � uma �rvore bin�ria cheia
            return false;
        }
    }

    // Se a �rvore passou em todas as verifica��es, ela � uma �rvore bin�ria cheia
    return true;
}

// Exemplo de uso
int main() {
    // Cria a �rvore bin�ria cheia
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // Verifica se a �rvore � uma �rvore bin�ria cheia
    if (isFullBinaryTree(root)) {
        printf("A arvore e uma arvore binaria cheia.\n");
    } else {
        printf("A arvore nao e uma arvore binaria cheia.\n");
    }

    return 0;
}

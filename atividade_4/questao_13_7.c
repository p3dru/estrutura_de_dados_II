#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}


int areEqualTrees(Node* a, Node* b) {
    if (a == NULL && b == NULL) {
        return 1;
    }
    if (a == NULL || b == NULL) {
        return 0;
    }
    if (a->value != b->value) {
        return 0;
    }
    return areEqualTrees(a->left, b->left) && areEqualTrees(a->right, b->right);
}

int main() {
    Node* treeA = createNode(1);
    treeA->left = createNode(2);
    treeA->right = createNode(3);
    treeA->left->left = createNode(4);
    treeA->left->right = createNode(5);
    treeA->right->left = createNode(6);

    Node* treeB = createNode(1);
    treeB->left = createNode(2);
    treeB->right = createNode(3);
    treeB->left->left = createNode(4);
    treeB->left->right = createNode(5);
    treeB->right->left = createNode(6);

    if (areEqualTrees(treeA, treeB)) {
        printf("As arvores sao iguais.\n");
    } else {
        printf("As arvores nao sao iguais.\n");
    }

    return 0;
}

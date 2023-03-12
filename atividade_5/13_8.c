/*
Questão: Validar expressão numérica em uma árvore binária.
Nesse código, percorremos em pós-ordem, onde visita os filhos esquerdos,
depois os direitos e depois a raiz.
A raiz, deve ser a operação que une as duas expressões menores, nesse caso,
A raiz é o *, pois ela une as expressões menores ((5 + 3) / 4) e (6 - 2),
A raiz da segunda expressão mais importante em pós órdem é o /, pois une
as expressões menores (5 + 3) e ao final (5 + 3) / 4.
Como o algoritmo é pós-ordem, ele verifica primeiro o filho mais à esquerda
da árvore que é o 5, depois vai pro filho "emparelhado" à ele mas à direita
que é o 3, e por fim visita a raiz da subárvore que é o +.
Assim que executa, essa expressão que temos como resultado 8. O 8 se torna o
nó mais à esquerda da árvore.
Realizando novamente o pós ordem, pegamos o mais à esquerda que é 8, o
"emparelhado" à ele que é o 4 e a raiz da subárvore que é o /, assi, formamos
8 / 4 e o resultado 2. 2 se torna o nó mais à esquerda da árvore.
A parte esquerda da árvore foi resolvida, agora, passará para a direita,
com o 6 sendo o nó mais à esquerda e que não possui filhos, pega o "emparelhado"
à ele, o 1 e como temos na raiz da subárvore o -, basta realizar o 6 - 2 e como
resultado 5.
Por fim, seguindo pós ordem: 2 * 4 = 8.

O código pega os dados como char, mas na linha 47, ele transforma em int,
diminuindo por 0, porém, só faz isso, se o nó não tiver nenhum filho, pois
assim, temos certeza que é um inteiro

Caso não apareça resultado, é porquê a expresão montada, está inválida
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó na árvore
struct Node* newNode(char data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para avaliar uma expressão numérica na árvore
int evalExprTree(struct Node* node) {
    // Se o nó for uma folha, retorna o valor numérico correspondente
    if (node->left == NULL && node->right == NULL) {
        return node->data - '0'; // Converte de caractere para inteiro
    }

    // Avalia as subárvores esquerda e direita recursivamente
    int leftValue = evalExprTree(node->left);
    int rightValue = evalExprTree(node->right);

    // Realiza a operação aritmética correspondente ao nó atual
    switch (node->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
    }

    return 0; // Caso de erro
}

int main() {
    // Cria a árvore para a expressão "((5 + 3) / 4 * (6 + 1)"
    struct Node* root = newNode('*');
    root->left = newNode('/');
    root->left->left = newNode('+');
    root->left->right = newNode('4');
    root->left->left->left = newNode('5');
    root->left->left->right = newNode('3');
    root->right = newNode('-');
    root->right->left = newNode('6');
    root->right->right = newNode('2');

    // Avalia a expressão e imprime o resultado
    int result = evalExprTree(root);
    printf("Resultado da expressao: %d\n", result);

    return 0;
}


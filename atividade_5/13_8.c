/*
Nesse c�digo, percorremos em p�s-ordem, onde visita os filhos esquerdos,
depois os direitos e depois a raiz.
A raiz, deve ser a opera��o que une as duas express�es menores, nesse caso,
A raiz � o *, pois ela une as express�es menores ((5 + 3) / 4) e (6 - 2),
A raiz da segunda express�o mais importante em p�s �rdem � o /, pois une
as express�es menores (5 + 3) e ao final (5 + 3) / 4.
Como o algoritmo � p�s-ordem, ele verifica primeiro o filho mais � esquerda
da �rvore que � o 5, depois vai pro filho "emparelhado" � ele mas � direita
que � o 3, e por fim visita a raiz da sub�rvore que � o +.
Assim que executa, essa express�o que temos como resultado 8. O 8 se torna o
n� mais � esquerda da �rvore.
Realizando novamente o p�s ordem, pegamos o mais � esquerda que � 8, o
"emparelhado" � ele que � o 4 e a raiz da sub�rvore que � o /, assi, formamos
8 / 4 e o resultado 2. 2 se torna o n� mais � esquerda da �rvore.
A parte esquerda da �rvore foi resolvida, agora, passar� para a direita,
com o 6 sendo o n� mais � esquerda e que n�o possui filhos, pega o "emparelhado"
� ele, o 1 e como temos na raiz da sub�rvore o -, basta realizar o 6 - 2 e como
resultado 5.
Por fim, seguindo p�s ordem: 2 * 4 = 8.

O c�digo pega os dados como char, mas na linha 47, ele transforma em int,
diminuindo por 0, por�m, s� faz isso, se o n� n�o tiver nenhum filho, pois
assim, temos certeza que � um inteiro

Caso n�o apare�a resultado, � porqu� a expres�o montada, est� inv�lida
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

// Fun��o para criar um novo n� na �rvore
struct Node* newNode(char data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fun��o para avaliar uma express�o num�rica na �rvore
int evalExprTree(struct Node* node) {
    // Se o n� for uma folha, retorna o valor num�rico correspondente
    if (node->left == NULL && node->right == NULL) {
        return node->data - '0'; // Converte de caractere para inteiro
    }

    // Avalia as sub�rvores esquerda e direita recursivamente
    int leftValue = evalExprTree(node->left);
    int rightValue = evalExprTree(node->right);

    // Realiza a opera��o aritm�tica correspondente ao n� atual
    switch (node->data) {
        case '+': return leftValue + rightValue;
        case '-': return leftValue - rightValue;
        case '*': return leftValue * rightValue;
        case '/': return leftValue / rightValue;
    }

    return 0; // Caso de erro
}

int main() {
    // Cria a �rvore para a express�o "((5 + 3) / 4 * (6 + 1)"
    struct Node* root = newNode('*');
    root->left = newNode('/');
    root->left->left = newNode('+');
    root->left->right = newNode('4');
    root->left->left->left = newNode('5');
    root->left->left->right = newNode('3');
    root->right = newNode('-');
    root->right->left = newNode('6');
    root->right->right = newNode('2');

    // Avalia a express�o e imprime o resultado
    int result = evalExprTree(root);
    printf("Resultado da expressao: %d\n", result);

    return 0;
}


/**
 * Este arquivo 'header' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo guardar as declarações de funções e estruturas necessárias para construção e manipulação de árvores binárias de busca.
*/
#pragma once

/**
 * Estrutura de Nó que compõe uma Árvore Binária.
 */
struct TreeNode
{
    int iPayload;
    struct TreeNode* ptrLeft;
    struct TreeNode* ptrRight;
};

/**
 * Função que cria um novo TreeNode sem filhos
 * 
 * @param iData Valor inteiro que será a carga do TreeNode.
 * @return Ponteiro para a struct TreeNode criada.
*/
struct TreeNode* newTreeNode(int iData);

/**
 * Função recursiva de inserção de nós em árvores binárias de busca.
 * 
 * @param ptrCurrentNode Ponteiro para o nó raiz da árvore a ser modificada.
 * @param iData Valor inteiro que será a carga do nó inserido.
 * @return Ponteiro para o nó raiz da árvore já modificada, equivalente a `ptrCurrentNode`.
*/
struct TreeNode* insertTreeNode(struct TreeNode* ptrCurrentNode, int iData);

/**
 * Função que imprime recursivamente o conteúdo de uma árvore binária usando o método de travessia Pré-Ordem.
 * 
 * Imprime primeiro o nó atual, depois os descendentes à esquerda, depois os descendentes à direita.
 * 
 * @param ptrStartingNode Ponteiro para o nó raiz da árvore ou sub-árvore a partir do qual deve-se imprimir o conteúdo.
*/
void traversePreOrder(struct TreeNode* ptrStartingNode);

/**
 * Função que imprime recursivamente o conteúdo de uma árvore binária usando o método de travessia Em Ordem.
 * 
 * Imprime primeiro os descendentes à esquerda, depois o nó atual, depois os descendentes à direita.
 * @param ptrStartingNode Ponteiro para o nó raiz da árvore ou sub-árvore a partir do qual deve-se imprimir o conteúdo.
*/
void traverseInOrder(struct TreeNode* ptrStartingNode);

/**
 * Função que imprime recursivamente o conteúdo de uma árvore binária usando o método de travessia Pós-Ordem.
 * 
 * Imprime primeiro os descendentes à esquerda, depois os descendentes à direita, e depois o nó atual.
 * @param ptrStartingNode Ponteiro para o nó raiz da árvore ou sub-árvore a partir do qual deve-se imprimir o conteúdo.
*/
void traversePostOrder(struct TreeNode* ptrStartingNode);

/**
 * Função recursiva que busca um valor numa árvore binária de busca.
 * 
 * Caso o valor não seja encontrado, retorna um nullptr.
 * Caso haja mais de uma ocorrência do valor, retorna o mais raso.
 * 
 * @param ptrCurrentNode Ponteiro para o nó raiz da árvore ou sub-árvore na qual será realizada a busca.
 * @param iData Valor numérico a ser procurado na árvore.
 * @return Ponteiro para o nó que contém o valor desejado.
*/
struct TreeNode* searchNode(struct TreeNode* ptrCurrentNode, int iData);

/**
 * Função auxiliar de deleteTreeNode. Busca o melhor substituto para um nó.
 * 
 * Em árvores de busca, o melhor nó para substituir outro nó X, é o nó mais à esquerda possível na sub-árvore direita de X.
 * 
 * @param ptrNode Ponteiro para o nó que será substituído.
 * @return Ponteiro para o melhor substituto descendente de `ptrNode`, já removido do fundo da árvore. 
*/
struct TreeNode* bestSubstitute(struct TreeNode* ptrNode);

/**
 * Função que remove um valor de uma árvore binária de busca.
 * 
 * Se o valor não for encontrado, a árvore será retornada inalterada.
 * Se existir mais de um nó com o valor desejado, será removido somente o mais raso.
 * 
 * @param ptrCurrentNode Ponteiro para a raiz da árvore da qual o nó será deletado.
 * @param iData Valor inteiro a ser deletado da árvore.
 * @return Ponteiro para a raiz da árvore modificada.  
*/
struct TreeNode* deleteTreeNode(struct TreeNode* ptrCurrentNode, int iData);

/**
 * Função que deleta uma árvore binária de busca.
 * 
 * @param ptrRoot Ponteiro para a raiz da árvore a ser deletada.
 * @param ptrNodeDelete Ponteiro para o nó a ser deletado.
*/
void deleteTree(struct TreeNode** ptrRoot, struct TreeNode* ptrNodeDelete);

/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada, ordenada em preOrder
 * 
 * @param ptrList Ponteiro para a lista duplamente encadeada que receberá os valores da árvore.
 * @param ptrNode Ponteiro para um nó da árvore a ser convertida.
*/
void treeToDoublyList(struct DoublyList* ptrList, struct TreeNode* ptrNode);

/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada,
 * ordena com bubble sort e printa o resultado na tela
 * 
 * @param ptrNode Ponteiro para a raíz da árvore a ser convertida.
*/
void bubbleSortTree(struct TreeNode* ptrRoot);

/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada,
 * ordena com selection sort e printa o resultado na tela
 * 
 * @param ptrNode Ponteiro para a raíz da árvore a ser convertida.
*/
void selectionSortTree(struct TreeNode* ptrRoot);

/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada,
 * ordena com insertion sort e printa o resultado na tela
 * 
 * @param ptrNode Ponteiro para a raíz da árvore a ser convertida.
*/
void insertionSortTree(struct TreeNode* ptrRoot);

/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada,
 * ordena com shell sort e printa o resultado na tela
 * 
 * @param ptrNode Ponteiro para a raíz da árvore a ser convertida.
*/
void shellSortTree(struct TreeNode* ptrRoot);
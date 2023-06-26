/**
 * Este arquivo 'header' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo guardar as declarações de funções e estruturas necessárias para construção e manipulação de árvores binárias de busca
*/

/**
 * Estrutura de Árvore Binária de Busca
*/
struct BinaryTree
{
    struct TreeNode* ptrRoot; 
};

/**
 * Estrutura de Nó que compõe uma struct BinaryTree
 */
struct TreeNode
{
    int iPayload;
    struct TreeNode* ptrLeft;
    struct TreeNode* ptrRight;
};

/**
 * Cria uma nova BinaryTree vazia
 * 
 * @return Ponteiro para a struct BinaryTree criada
*/
struct BinaryTree* newTree();

/**
 * Cria um novo TreeNode sem filhos
 * 
 * @param iData Valor inteiro que será a carga do TreeNode
 * @return Ponteiro para a struct TreeNode criada
*/
struct TreeNode* newTreeNode(int iData);

/**
 * Função recursiva de inserção de nós em árvores binárias de busca
 * 
 * @param currentNode Ponteiro para o nó raiz da árvore a ser modificada
 * @param iData Valor inteiro que será a carga do nó inserido
 * @return Ponteiro para o nó raiz da árvore já modificada, equivalente a `currentNode`
*/
struct TreeNode* insertTreeNode(struct TreeNode* currentNode, int iData);
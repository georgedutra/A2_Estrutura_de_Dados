/**
 * Este arquivo 'header' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo guardar as declarações de funções e estruturas necessárias para construção e manipulação de listas duplamente encadeadas.
*/
#pragma once

/**
 * Estrutura de nó que compõe uma lista duplamente encadeada.
*/
struct ListNode
{
    int iData;
    struct ListNode* ptrNext;
    struct ListNode* ptrPrev;
};

/**
 * Estrutura de Lista Duplamente Encadeada
*/
struct DoublyList
{
    struct ListNode* ptrHead;
    struct ListNode* ptrTail;
};

/**
 * Função que cria um nó de lista duplamente encadeada.
 * 
 * O nó é criado contendo nullptrs, ou seja, não aponta para ninguém.
 * 
 * @param iVal Valor numérico inteiro que será a carga do nó
 * @return Ponteiro para o nó criado.
*/
struct ListNode* createListNode(int iVal);

/**
 * Função que cria uma lista vazia.
 * 
 * @return Ponteiro para a lista vazia criada.
*/
struct DoublyList* createList();

/**
 *  Função que insere um nó no início de uma lista duplamente encadeada.
 * 
 * @param ptrList Ponteiro para a lista na qual o nó será inserido
 * @param ptrNewNode Ponteiro para o nó que será inserido na lista
*/
void insertFront(struct DoublyList* ptrList, struct ListNode* ptrNewNode);

/**
 * Função que insere um nó no final de uma lista duplamente encadeada.
 * 
 * @param ptrList Ponteiro para a lista na qual o nó será inserido
 * @param ptrNewNode Ponteiro para o nó que será inserido na lista
*/
void insertEnd(struct DoublyList* ptrList, struct ListNode* ptrNewNode);

/**
 * Função que imprime no terminal o conteúdo dos nós de uma lista duplamente encadeada.
 * 
 * @param ptrList Ponteiro para a lista que será impressa
*/
void printList(struct DoublyList* ptrList);

/**
 * Função que apaga o primeiro elemento de uma lista duplamente encadeada.
 * 
 * @param ptrList Ponteiro para a lista que será modificada
*/
void deleteFirst(struct DoublyList* ptrList);

/**
 * Função que apaga o último elemento de uma lista duplamente encadeada.
 * 
 * @param ptrList Ponteiro para a lista que será modificada
*/
void deleteLast(struct DoublyList* ptrList);

/**
 * Função que insere um nó logo após o outro passado.
 * 
 * O novo nó `ptrNewNode` será inserido logo após o `ptrLoc`, que obviamente precisa pertencer à lista referenciada por `ptrList`.
 * 
 * @param ptrList Ponteiro para a lista que será alterada.
 * @param ptrLoc Ponteiro para o nó que servirá de referência para inserir o novo.
 * @param ptrNewNode Ponteiro para o nó que será inserido.
*/
void insertAfter(struct DoublyList* ptrList, struct ListNode* ptrLoc, struct ListNode* ptrNewNode);

/**
 * Função que deleta um nó específico da lista.
 * 
 * O nó passado `ptrDelete` precisa pertencer à `ptrList`.
 * 
 * @param ptrList Ponteiro para a lista que será alterada.
 * @param ptrDelete Ponteiro para o nó que será apagado.
*/
void deleteNode(struct DoublyList* ptrList, struct ListNode* ptrDelete);

/**
 * Função que remove um nó de uma lista e o retorna.
 * 
 * Diferente de suas contrapartes "delete", a função pop tira um nó de uma lista e não libera a memória ocupada por ele.
 * Perceba que o nó retornado ainda aponta para os antigos vizinhos na lista.
 * 
 * @param ptrList Ponteiro para a lista que será alterada.
 * @param ptrDelete Ponteiro para o nó que será removido.
 * @return Ponteiro para o nó removido da lista. Equivale ao `ptrDelete`.
*/
struct ListNode* popNode(struct DoublyList* ptrList, struct ListNode* ptrDelete);

/**
 * Função que retorna o tamanho de uma lista duplamente encadeada.
 * 
 * @param ptrList Lista alvo.
 * @return Tamanho da lista (inteiro).
*/
int getLenght(struct DoublyList* ptrList);

/**
 * Função que troca de lugar dois Nodes na estrutura de lista duplamente encadeada.
 * 
 * Ambos os nós passados PRECISAM pertencer à `ptrList`.
 * 
 * @param ptrList Lista que será alterada.
 * @param ptrNode1 Primeiro nó a ser alterado. Trocará de lugar com `ptrNode2`.
 * @param ptrNode2 Segundo nó a ser alterado. Trocará de lugar com `ptrNode1`.
*/
void swapNodes(struct DoublyList* ptrList, struct ListNode* ptrNode1, struct ListNode* ptrNode2);

/**
 * Função que implementa o algoritmo de Bubble Sorting para listas duplamente encadeadas.
 * 
 * @param ptrList Lista que será ordenada.
*/
void bubbleSort(struct DoublyList* ptrList);

/**
 * Função que implementa o algoritmo recursivo de Selection Sorting para listas duplamente encadeadas.
 * 
 * @param ptrList Lista que será ordenada.
 * @param ptrHead Ponteiro para o nó Head da lista.
*/
void selectionSort(struct DoublyList* ptrList, struct ListNode* ptrHead);

/**
 * Função que implementa o algoritmo de Insertion Sorting para listas duplamente encadeadas.
 * 
 * @param ptrList Lista que será ordenada.
*/
void insertionSort(struct DoublyList* ptrList);

/**
 * Função que implementa o algoritmo de Shell Sorting para listas duplamente encadeadas.
 * 
 * ATENÇÃO: O algoritmo de Shell é otimizado para estruturas com capacidade de indexação.
 * Esse NÃO é o caso de listas encadeadas, portanto o algoritmo NÃO é otimizado.
 * 
 * @param ptrList Lista que será ordenada.
 * @param iLenght Quantidade de elementos na lista passada.
*/
void shellSort(DoublyList* ptrList, int iLenght);
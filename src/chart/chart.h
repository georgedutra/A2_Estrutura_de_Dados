#pragma once

/**
 * Calcula o valor máximo de uma lista duplamente encadeada.
 * Auxilia na impressão gráfica.
 * 
 * @param ptrList Ponteiro para a lista que será analisada.
 * @return Valor máximo da lista.
*/
int iMax(struct DoublyList* ptrList);

/**
 * Função que limpa o vetor de caracteres que será usado para a impressão gráfica.
 * 
 * @param arriGrapich Vetor de caracteres que será limpo.
*/
void clearGraphic(char arriGrapich[20][120]);

/**
 * Função que cálcula a altura em que cada nó será impresso e atualiza o vetor de caracteres.
 * 
 * @param ptrList Ponteiro para a lista que será analisada.
 * @param arriGrapich Vetor de caracteres que será atualizado.
 * @param iMax Valor máximo da lista.
*/
void calcNodes(struct DoublyList* ptrList, char arriGrapich[20][120], int iMax);

/**
 * Função que imprime o gráfico no terminal.
 * 
 * @param arriGrapich Vetor de caracteres que será impresso.
*/
void drawGrapich(char arriGrapich[20][120]);

/**
 * Função que configura o terminal para a impressão gráfica.
*/
void config();

/**
 * Função que imprime um frame do gráfico.
 * 
 * @param ptrList Ponteiro para a lista que será impressa.
 * @param arriGrapich Vetor de caracteres que será impresso.
 * @param iMaxCalc Valor máximo da lista.
 * @param ptrCurrentNode Ponteiro para o nó que está sendo analisado.
 * @param ptrNext Ponteiro para o nó que está sendo comparado.
*/
void drawFrame(struct DoublyList* ptrList, char arriGrapich[20][120], int iMaxCalc,
                 struct ListNode* ptrCurrentNode, struct ListNode* ptrNext);

/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada,
 * ordena com bubble sort e printa um gráfico representando o processo
 * 
 * @param ptrNode Ponteiro para a raíz da árvore a ser convertida.
*/
void graphicBubbleSort(struct TreeNode* ptrRoot);

/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada,
 * ordena com selection sort e printa um gráfico representando o processo
 * 
 * @param ptrNode Ponteiro para a raíz da árvore a ser convertida.
*/
void graphicSelectionSort(struct TreeNode* ptrRoot);

/**
 * Função que imprime um frame do gráfico do insertion sort quando um nó foi removido.
 * 
 * @param ptrList Ponteiro para a lista que será impressa.
 * @param arriGrapich Vetor de caracteres que será impresso.
 * @param iMaxCalc Valor máximo da lista.
 * @param iLenght Tamanho da lista.
 * @param ptrCurrentNode Ponteiro para o nó que foi excluído.
 * @param ptrNext Ponteiro para o nó que está sendo comparado.
*/
void drawFramePop(struct DoublyList* ptrList, char arriGrapich[20][120], int iMaxCalc,
                        int iLenght, struct ListNode* ptrCurrentNode, struct ListNode* ptrNext);

/**
 * Função que imprime um frame do gráfico do insertion sort quando o nó foi inserido.
 * 
 * @param ptrList Ponteiro para a lista que será impressa.
 * @param arriGrapich Vetor de caracteres que será impresso.
 * @param iMaxCalc Valor máximo da lista.
 * @param iLenght Tamanho da lista.
 * @param ptrCurrentNode Ponteiro para o nó que foi excluído.
 * @param ptrNext Ponteiro para o nó que está sendo comparado.
*/
void drawFrameInsertion(struct DoublyList* ptrList, char arriGrapich[20][120], int iMaxCalc,
                        int iLenght, struct ListNode* ptrCurrentNode, struct ListNode* ptrNext);
/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada,
 * ordena com insertion sort e printa um gráfico representando o processo
 * 
 * @param ptrNode Ponteiro para a raíz da árvore a ser convertida.
*/
void graphicInsertionSort(struct TreeNode* ptrRoot);

/**
 * Função que converte uma árvore binária de busca em uma lista duplamente encadeada,
 * ordena com shell sort e printa um gráfico representando o processo
 * 
 * @param ptrNode Ponteiro para a raíz da árvore a ser convertida.
*/
void graphicShellSort(struct TreeNode* ptrRoot);

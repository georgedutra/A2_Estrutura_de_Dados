/**
 * Este arquivo 'header' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 *
 * Tem como objetivo guardar as declarações de funções e estruturas necessárias para análise de árvores binárias de busca.
 */
#pragma once

/**
 * Funçao recursiva que verifica se uma árvore binária de busca é completa.
 *
 * @param ptrTree Ponteiro para um nó da árvore a ser verificada
 * @return true se a árvore for completa, false caso contrário
 */
bool isComplete(struct TreeNode *ptrTree);

/**
 * Funçao recursiva que verifica se uma árvore binária de busca é perfeita.
 *
 * @param ptrTree Ponteiro para um nó da árvore a ser verificada
 * @param iHeight Altura da árvore
 * @param iActualLevel Nível atual da árvore
 *
 * @return true se a árvore for perfeita, false caso contrário
 */
bool isPerfect(struct TreeNode *ptrTree, int iHeight, int iActualLevel);

/**
 * Funçao recursiva que retorna a altura de uma árvore binária de busca.
 *
 * @param ptrTree Ponteiro para um nó da árvore a ser verificada
 * @return Altura da árvore
 */
int getHeight(struct TreeNode *ptrTree);

/**
 * Funçao recursiva que retorna o tamanho de uma árvore binária de busca.
 *
 * @param ptrTree Ponteiro para um nó da árvore a ser verificada
 * @return Tamanho da árvore
 */
int getSize(struct TreeNode *ptrTree);
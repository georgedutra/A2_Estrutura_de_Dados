/**
 * Este arquivo 'header' é parte do projeto {{ A2_Estrutura_de_Dados }}.
 * 
 * Tem como objetivo guardar as declarações de funções e estruturas necessárias para interação do usuário com o programa.
*/
#pragma once

/**
 * Função de interface que invoca um construtor de árvore binária de busca.
 * 
 * O usuário deve digitar no terminal um número inteiro por vez, ou digitar texto para encerrar a construção.
*/
struct TreeNode* userCreateTree();

/**
 * Função de interface que insere um valor inserido pelo usuário.
 * 
 * @param ptrTree Ponteiro para o nó raiz da árvore onde o valor será inserido.
*/
struct TreeNode* userInsertNode(struct TreeNode* ptrTree);

/**
 * Função de interface que remove um valor inserido pelo usuário.
 * 
 * Se o valor 
 * 
 * @param ptrTree Ponteiro para o nó raiz da árvore de onde o valor será removido.
*/
struct TreeNode* userDeleteNode(struct TreeNode* ptrTree);
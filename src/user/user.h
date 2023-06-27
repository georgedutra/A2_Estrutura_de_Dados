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
 * @return Ponteiro para o nó raiz da árvore criada.
*/
struct TreeNode* userCreateTree();

/**
 * Função de interface que insere um valor inserido pelo usuário.
 * 
 * @param ptrTree Ponteiro para o nó raiz da árvore onde o valor será inserido.
 * @return Ponteiro para o nó raiz da árvore alterada.
*/
struct TreeNode* userInsertNode(struct TreeNode* ptrTree);

/**
 * Função de interface que remove um valor inserido pelo usuário.
 * 
 * Se o valor não for encontrado, retorna a árvore inalterada.
 * Caso haja mais de uma ocorrência do valor, deleta o mais raso.
 * 
 * @param ptrTree Ponteiro para o nó raiz da árvore de onde o valor será removido.
 * @return Ponteiro para o nó raiz da árvore alterada.
*/
struct TreeNode* userDeleteNode(struct TreeNode* ptrTree);

/**
 * Função de interface que busca e retorna um ponteiro para o nó que possui o valor inserido pelo usuário.
 * 
 * Caso o valor não seja encontrado, retorna um nullptr.
 * Caso haja mais de uma ocorrência do valor, retorna o mais raso.
 * 
 * @param ptrTree Ponteiro para o nó raiz da árvore onde será procurado o valor inserido.
 * @return Ponteiro para o nó que possui o valor desejado.
*/
struct TreeNode* userSearchNode(struct TreeNode* ptrTree);

/** 
 * Função de interface que busca arquivos na pasta \data para construir uma árvore binária de busca.
 * 
 * Caso o arquivo não seja encontrado, retorna um nullptr.
 * 
 * @return Ponteiro para o nó raiz da árvore criada.
*/
struct TreeNode* userReadFile();
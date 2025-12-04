/*
    Revisando conceitos iniciais de árvore de decisão binária.
    Revision start concepts of the binary tree.

    Esse código é composto pelas seguintes funções:
        - Inserir Nó
        - Listagem de dados com Pre-Ordem, In-Ordem e Pos-Ordem
        - Quantidade de nós e folhas
        - Altura da árvore
        - Nó com maior e melhor valor

    This code is compost with this functions:
        - Insert Node
        - View data with Pre-order, In-order and Pos-order
        - Quantity of nodes and leafs
        - Length of tree

    Talvez esse script seja atualizado em breve, caso tenha novas informações para estudar
    Maybe this script will be atualizate soon, case have new informations to study
*/  

#include <stdio.h>
#include <stdlib.h>

/*
    Estrutura da árvore de decisão binária
    Binary decision tree struct 
*/
typedef struct No{
    int conteudo;
    struct No *esquerda;
    struct No *direita;
}ArvoreBinaria;



/*
    En: The goal of this code is to implement the logic for removing a node 
        from a Binary Search Tree (BST).
    Pt-br: O objetivo deste código é implementar a lógica para remover um nó 
          de uma Árvore Binária de Busca (ABB).
*/

/*
    En: DEFINE THE REQUIRED LIBRARIES.
    Pt-br: DEFINE AS BIBLIOTECAS NECESSÁRIAS.
*/
#include <stdio.h>
#include <stdlib.h> // Added stdlib for the 'free' function

/*
    En: CREATE THE BINARY SEARCH TREE (BST) STRUCTURE.
    Pt-br: CRIA A ESTRUTURA DA ÁRVORE BINÁRIA DE BUSCA (ABB).
*/
typedef struct Node{
    int content; 
    struct Node *left;
    struct Node *right;
}Arv;

/**
 * @brief Recursively removes a node with the specified content from the BST.
 * * @param arv The current root of the subtree being analyzed.
 * @param searchContent The value of the node to be removed.
 * @return Arv* The new root of the subtree after removal.
 */
Arv *removeNode(Arv *arv, int searchContent){
    
    // --- 1. SEARCH PHASE (TRAVERSAL) ---

    /*
        En: If the current subtree is empty (base case for recursion), return NULL.
        Pt-br: Se a subárvore atual estiver vazia (caso base para a recursão), retorna NULL.
    */
    if(arv == NULL){
        return NULL; 
    }
    
    /*
        En: If the search content is LOWER than the current node's content, 
            continue the search in the LEFT subtree.
        Pt-br: Se o conteúdo procurado for MENOR que o do nó atual, 
               continua a busca na subárvore ESQUERDA.
    */
    if(searchContent < arv->content){
        arv->left = removeNode(arv->left, searchContent);

    /*
        En: If the search content is BIGGER than the current node's content, 
            continue the search in the RIGHT subtree.
        Pt-br: Se o conteúdo procurado for MAIOR que o do nó atual, 
               continua a busca na subárvore DIREITA.
    */
    } else if(searchContent > arv->content){ // Correction: Must be '>' for BST search
        arv->right = removeNode(arv->right, searchContent);

    // --- 2. NODE FOUND (arv->content == searchContent) ---
    } else { 
        /*
            En: The value was found. Now, handle the three removal cases based on the number of children:
                - Case A: Node has 0 children (is a leaf).
                - Case B: Node has 1 child.
                - Case C: Node has 2 children.
        */
        
        // CASE A: Node has 0 children (is a leaf)
        if(arv->left == NULL && arv->right == NULL){
            /*
                En: Just free the memory and return NULL to the parent pointer.
                Pt-br: Apenas libera a memória e retorna NULL para o ponteiro pai.
            */
            free(arv);
            return NULL;
        }

        // CASE B: Node has 1 child
        if(arv->left == NULL || arv->right == NULL){
            Arv *temp;
            /*
                En: Check which side the single child is on.
                Pt-br: Verifica em qual lado está o único filho.
            */
            if(arv->left != NULL){
                temp = arv->left; // The child is the left one
            }else{
                temp = arv->right; // The child is the right one
            }
            /*
                En: Free the current node and return the child node to its parent.
                Pt-br: Libera o nó atual e retorna o nó filho para o seu pai.
            */
            free(arv);
            return temp;
        }

        // CASE C: Node has 2 children
        else{
            /*
                En: Find the in-order successor (the node with the MINIMAL content 
                    in the RIGHT subtree).
                Pt-br: Encontra o sucessor in-order (o nó com o MENOR valor 
                       na subárvore DIREITA).
            */
            Arv *temp = arv->right;
            
            // Traverse all the way to the left to find the minimal value.
            while(temp->left != NULL){
                temp = temp->left;
            }
            
            /*
                En: Copy the successor's content to the current node.
                Pt-br: Copia o conteúdo do sucessor para o nó atual.
            */
            arv->content = temp->content;

            /*
                En: Recursively remove the original successor node from the RIGHT subtree.
                Pt-br: Remove recursivamente o nó sucessor original da subárvore DIREITA.
            */
            arv->right = removeNode(arv->right, temp->content);
        }
    }

    // --- 3. RETURN PHASE ---
    return arv;
}
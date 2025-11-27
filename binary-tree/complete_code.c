// Importing the required libraries
#include <stdio.h> // Necessary to use the function (printf)
#include <stdlib.h> // Necessary to use the function (malloc) for dinamic memory allocation

// Binary tree struct
typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right; 
}BinaryTree; // Using "Node" for self-referencing within the binary tree

// Initializing the binary tree with NULL
BinaryTree *binary_tree_inicialization(){
    return NULL;
}

// Function responsible for creating a node with dinamic memory allocation
BinaryTree *create_node(int value){
    BinaryTree *node = (BinaryTree *)malloc(sizeof(BinaryTree));
    if(node == NULL){
        printf("Dynamic memory allocation error!\n");
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function responsible for inserting the created node into the binary tree
BinaryTree *insert_node(BinaryTree *root, int value){
    if(root == NULL){
        return create_node(value);
    }
    if(value < root->value){
        root->left = insert_node(root->left, value);
    }else if(value >= root->value){
        root->right = insert_node(root->right, value);
    }
    return root;
}

// Paths to view a binary tree

// Pos-order
// Most commonly used to copy the binary tree
void pos_order(BinaryTree *root){
    if(root != NULL){
        printf("%d ",root->value);
        pos_order(root->left);
        pos_order(root->right);
    }
}

// In-order
// Most commonly used to view the binary tree values in order
void in_order(BinaryTree *root){
    if(root != NULL){
        in_order(root->left);
        printf("%d ",root->value);
        in_order(root->right);
    }
}

// Pre-order
void pre_order(BinaryTree *root){
    if(root != NULL){
        pre_order(root->left);
        pre_order(root->right);
        printf("%d ",root->value);
    }
}

// Search a node
BinaryTree *search_node(BinaryTree *root, int value){
    if(root == NULL){
        return root;
    }
    if(value < root->value){
        return search_node(root->left, value);
    }else if(value >= root->value){
        return search_node(root->right, value);
    }
}

// Quantity of nodes
int quantity_of_nodes(BinaryTree *root){
    if(root == NULL){
        return 0;
    }
    return 1 + quantity_of_nodes(root->left) + quantity_of_nodes(root->right);
}

// Quantity of leafs
int quantity_of_leafs(BinaryTree *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return quantity_of_leafs(root->left) + quantity_of_leafs(root->right);
}

int main(){
    BinaryTree *tree;
    tree = binary_tree_inicialization();
    tree = insert_node(tree, 20);
    tree = insert_node(tree, 2);
    tree = insert_node(tree, 7);
    tree = insert_node(tree, 76);
    tree = insert_node(tree, 132);
    pos_ordem(tree);
    printf("\n");
    in_ordem(tree);
    printf("\n");
    pre_ordem(tree);
}
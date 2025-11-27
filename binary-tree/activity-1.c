// Importing required libraries
#include <stdio.h>
#include <stdlib.h>

// Defining the binary tree struct
typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
}BinaryTree;

// Function to initialize the binary tree
BinaryTree *initialize_binary_tree(){
    return NULL;
}

// Function to create a node with dynamic memory allocation
BinaryTree *create_node(int value){
    BinaryTree *node = (BinaryTree *)malloc(sizeof(BinaryTree));
    if(node == NULL){
        // Added '\n' for better terminal output
        printf("Dynamic Memory Allocation error!\n"); 
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a node into the binary tree (Binary Search Tree logic)
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

// Function to calculate the total quantity of nodes
int quantity_of_nodes(BinaryTree *root){
    if(root == NULL){
        return 0;
    }
    return 1 + quantity_of_nodes(root->left) + quantity_of_nodes(root->right);
}

// Function to calculate the quantity of leaf nodes
int quantity_of_leafs(BinaryTree *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return quantity_of_leafs(root->left) + quantity_of_leafs(root->right);
}

// Function to find the node with the maximum value (rightmost node)
BinaryTree *node_with_max_value(BinaryTree *root){
    // Safety check: return NULL if the tree is empty
    if(root == NULL){
        return NULL;
    }
    
    BinaryTree *runner = root;
    // Iterate until the rightmost node is found
    while(runner->right != NULL){ 
        runner = runner->right;
    }
    return runner;
}

// Function to calculate the height of the binary tree
// Height is defined as the number of edges from the root to the deepest leaf
int height_binary_tree(BinaryTree *root){
    if(root == NULL){
        return -1; // -1 ensures that a single-node tree returns height 0
    }

    int left_height = height_binary_tree(root->left);
    int right_height = height_binary_tree(root->right);

    // Returns 1 plus the height of the taller subtree
    if(left_height > right_height){
        return 1 + left_height;
    }else{
        return 1 + right_height;
    }
}

int main(){
    BinaryTree *tree;
    tree = initialize_binary_tree(); 
    

    tree = insert_node(tree, 50);
    tree = insert_node(tree, 30);
    tree = insert_node(tree, 70);
    tree = insert_node(tree, 20);
    tree = insert_node(tree, 40);
    tree = insert_node(tree, 80);
    
    printf("--- Binary Tree Statistics ---\n");
    printf("Total nodes: %d\n", quantity_of_nodes(tree));
    printf("Leaf nodes: %d\n", quantity_of_leafs(tree));
    printf("Height of the tree: %d\n", height_binary_tree(tree));
    
    BinaryTree *max_node = node_with_max_value(tree);
    if (max_node != NULL) {
        printf("Node with maximum value: %d\n", max_node->value);
    } else {
        printf("Tree is empty.\n");
    }

    
    return 0;
}
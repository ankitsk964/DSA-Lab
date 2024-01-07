#include <stdio.h>
#include <stdlib.h>
typedef struct BST{ // Created Structure of node of binary tree
    int data;
    struct BST *left, *right; 
}node;
node *p, *rootnode; // rootnode pointer is used to store rootnode address and P pointer is used for Traversal
void buildtree(node *nnode, int num);
void inorder(node *p);
void preorder(node *p);
void postorder(node *p);
void main(){
    rootnode = NULL;
    int invalue,no1;
    char ch = 'Y';
    printf("\n Enter a value :-  ");
    scanf("%d", &invalue); // To get input for rootnode from user
    rootnode = (node*)malloc(sizeof(node));
    if(rootnode == NULL){ // Condition to check whetherrootnode is created or not
        printf("\n Memory cant be allocated ");
        exit(1);
    }
    rootnode->data = invalue;
    rootnode->left = NULL;
    rootnode->right = NULL;
    
    do{ // To get input for nodes from user
        printf("\n Next value :- ");
        scanf("%d", &no1);
        buildtree(rootnode, no1); // Called buildtree function to build the Binary Search Tree
        printf("\n Do you want to continue ?");
        printf("\n Enter Y for YES and N for NO :- ");
        scanf(" %c", &ch);
    }while(ch == 'y' || ch == 'Y');

    printf("\n Inorder Traversal :- ");
    inorder(rootnode); // Called Inorder fucntion for Inorder traversal
    printf("\n Preorder Traversal :- ");
    preorder(rootnode); // Called Preorder function for Perorder travaersal
    printf("\n Postorder Traversal :- ");
    postorder(rootnode); // Called Postorder function for Postorder traversal
}
void buildtree(node *nnode, int num){ // Function to build the Binary Search Tree
    node *newnode = NULL;
    newnode = (node*)malloc(sizeof(node)); // To allocated memory for newnode 
    newnode->data = num;
    newnode->left = NULL;
    newnode->right = NULL;
    if(newnode == NULL){ // Condition to check whether the memory is allocated or not for newnode.
        printf("\n Memory cant be allocated :- ");
        exit(1);
    }
    if(num < nnode->data){ // Condition to check whether the input number is less than the rootnode data
        if(nnode->left == NULL){ // Condition to check whether the left part of the rootnode is empty or not
            nnode->left = newnode;
        }
        else{
            buildtree(nnode->left, num); // Recursive call to jump to the next node on left side of rootnode
        }
    }
    else{
        if(num > nnode->data){ // Condition to check whether the input number is greater than the rootnode data
            if(nnode->right == NULL){ // Condition to check whether the right side of the rootnode is empty or not
                nnode->right = newnode;
            }
            else{
                buildtree(nnode->right, num); // Recursive call to jump to the next node on right side of rootnode
            }
        }
    }
    if(num == nnode->data){ // Condition to check if the user have entered duplicate data 
        printf("\n Duplicate node ");
    }
}
void inorder(node *p){ // Function for Inorder Traversal
    if(p!=NULL){
        inorder(p->left);
        printf("\n %d", p->data);
        inorder(p->right);
    }
}
void preorder(node *p){ // Function for Preorder Traversal
    if(p!=NULL){
        printf("\n %d", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void postorder(node *p){ // Function for Postorder Traversal
    if(p!=NULL){
        postorder(p->left);
        postorder(p->right);
        printf("\n %d", p->data);
    }
}
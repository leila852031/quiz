/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 6

struct node{
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node TreeNode;
TreeNode *buildTree (int str[]);
void insert(TreeNode **node, TreeNode *item);
void *flatten(TreeNode *root);
void printout(TreeNode *node);

int main()
{
    int str[SIZE]={1,2,3,4,5,6};
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root = buildTree(str);
    printout(root);
    flatten(root);
    printout(root);
    return 0;
}

TreeNode *buildTree(int str[])
{   
    int i;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    TreeNode *node;
    root->value=str[0];
    for(i=1; i<SIZE; i++){
	node = (TreeNode *)malloc(sizeof(TreeNode));
	node->right=NULL;
	node->left=NULL;
	node->value=str[i];
	insert(&root, node);
    }
    return root;	
}

void *flatten(TreeNode *root)
{
    if(root==NULL)
	return;
    while(root){
        if(root->left){
	    TreeNode *rightMost=root->left;
	    while(rightMost->right) rightMost = rightMost->right;
	        rightMost->right = root-> right;
	        root->right = root->left;
  	        root->left = NULL;
        }  
	root = root->right;
    }

}



void insert(TreeNode **node, TreeNode *item){
    if((*node)==NULL){
	*node = item;
	return;
    }
    if((item->value)<((*node)->value))
	insert(&(*node)->left, item);
    else
 	insert(&(*node)->right, item);
}


void printout(TreeNode *node)
{
     if(node->left!=NULL)
	printout(node->left);
        printf("%d\n", node->value);
     if(node->right!=NULL)
	printout(node->right);
}

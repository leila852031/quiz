/* FIXME: Implement! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};
typedef struct node TreeNode;
void *flatten(TreeNode *root);
void printout(TreeNode *node, int level, char side);

int main()
{
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    root->value = 1;
    root->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->value = 2;
    root->left->left = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->left->value = 3;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->left->right->value = 4;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->value = 5;
    root->right->right = (TreeNode *)malloc(sizeof(TreeNode));
    root->right->right->value = 6;
    root->right->right->right = NULL;
    root->right->right->left = NULL;
    printout(root, 0, ' ');
    flatten(root);
    printout(root, 0, ' ');
    return 0;
}


void *flatten(TreeNode *root)
{
    while(root) {
        if(root->left) {
            TreeNode *rightMost=root->left;
            while(rightMost->right) rightMost = rightMost->right;
            rightMost->right = root-> right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;

    }

}

void printout(TreeNode *node, int level, char side)
{
    int i;
    for(i=0; i<level; i++) {
        printf("  %c", side);
    }
    printf("%d\n", node->value);
    if(node->left)
        printout(node->left, level+1, 'L');
    if(node->right)
        printout(node->right, level+1, 'R');
}

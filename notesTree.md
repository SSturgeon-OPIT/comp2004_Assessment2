#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
/* Prototypes for utility functions */
int search(int arr[], int strt, int end, int value);
struct node* newNode(int data);
 
struct node* buildTree(int in[], int pre[], int inStrt, int inEnd)
{
    static int preIndex = 0;
 
    if (inStrt > inEnd)
        return NULL;
 
    struct node* tNode = newNode(pre[preIndex]);
    preIndex += 1;
    
    if (inStrt == inEnd)
        return tNode;
 
    int inIndex = search(in, inStrt, inEnd, tNode->data);
 
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
 
    return tNode;
}
 
int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
}
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}

void printInorder(struct node* node)
{
    if (node != NULL){
        printInorder(node->left);
        printf("%d ", node->data); 
        printInorder(node->right);
    }
 
}
 
int main()
{
    int pre[] = { 8, 15, 6, 18, 12, 4, 21, 2, 7, 3, 1};
    int in[] = {18, 6, 12, 15, 21, 4, 2, 8, 3, 7, 1};
    int len = sizeof(in) / sizeof(in[0]);
    struct node* root = buildTree(in, pre, 0, len - 1);
 
    printf("Inorder traversal: ");
    printInorder(root);
    printf("\n");
}
#ifndef STURGEON_2_1_H
#define STURGEON_2_1_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct BinaryTree *Tree;

struct BinaryTree
{
    ElementType Element;
    Tree Left;
    Tree Right;
    int lCount;
    int rCount;
};

void MakeEmpty(Tree t);

int isPerfectTree (int n);

Tree Insert (ElementType X, Tree t);

void PrintTree(Tree t);

Tree makeTree(int n, int *arr);

Tree removeNullNodes(Tree t);

ElementType count_nodes( BinaryTree T );

ElementType sum_elements( BinaryTree T );

ElementType max_element( BinaryTree T );

void print_below( BinaryTree T, ElementType v );



#endif
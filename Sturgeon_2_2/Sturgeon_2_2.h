#ifndef STURGEON_2_2_H
#define STURGEON_2_2_H

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

int height (Tree T);

#endif

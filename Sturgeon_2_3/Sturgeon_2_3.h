#ifndef STURGEON_2_3_H
#define STURGEON_2_3_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void MakeEmpty(Tree T);

int isPerfectTree (int n);

Tree Insert (ElementType X, Tree T);

void PrintTree(Tree T);

Tree makeTree(int n, int *arr);

Tree removeNullNodes(Tree T);

bool struct_same (Tree T1, Tree T2 );

bool struct_valsame ( Tree T1, Tree T2 );

#endif

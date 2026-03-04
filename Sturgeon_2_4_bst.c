#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

struct TreeNode
{
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};


SearchTree
MakeEmpty( SearchTree T )
{
    if( T != NULL )
    {
        MakeEmpty( T->Left );
        MakeEmpty( T->Right );
        free( T );
    }
    return NULL;
}

Position
Find( ElementType X, SearchTree T )
{
    if( T == NULL )
        return NULL;
    if( X < T->Element )
        return Find( X, T->Left );
    else
    if( X > T->Element )
        return Find( X, T->Right );
    else
        return T;
}

Position
FindMin( SearchTree T )
{
    if( T == NULL )
        return NULL;
    else
    if( T->Left == NULL )
        return T;
    else
        return FindMin( T->Left );
}

Position
FindMax( SearchTree T )
{
    if( T != NULL )
        while( T->Right != NULL )
            T = T->Right;

    return T;
}

SearchTree
Insert( ElementType X, SearchTree T )
{
/* 1*/      if( T == NULL )
    {
        /* Create and return a one-node tree */
/* 2*/          T = malloc( sizeof( struct TreeNode ) );
/* 3*/          if( T == NULL )
        {
/* 4*/              printf( "Out of space!!!" );
            exit(1);
        }
        else
        {
/* 5*/              T->Element = X;
/* 6*/              T->Left = T->Right = NULL;
        }
    }
    else
/* 7*/      if( X < T->Element )
/* 8*/          T->Left = Insert( X, T->Left );
    else
/* 9*/      if( X > T->Element )
/*10*/          T->Right = Insert( X, T->Right );
    /* Else X is in the tree already; we'll do nothing */

/*11*/      return T;  /* Do not forget this line!! */
}

SearchTree
Delete( ElementType X, SearchTree T )
{
    Position TmpCell;

    if( T == NULL )
    {
        printf( "Out of space!!!" );
        exit(1);
    }
    else
    if( X < T->Element )  /* Go left */
        T->Left = Delete( X, T->Left );
    else
    if( X > T->Element )  /* Go right */
        T->Right = Delete( X, T->Right );
    else  /* Found element to be deleted */
    if( T->Left && T->Right )  /* Two children */
    {
        /* Replace with smallest in right subtree */
        TmpCell = FindMin( T->Right );
        T->Element = TmpCell->Element;
        T->Right = Delete( T->Element, T->Right );
    }
    else  /* One or zero children */
    {
        TmpCell = T;
        if( T->Left == NULL ) /* Also handles 0 children */
            T = T->Right;
        else if( T->Right == NULL )
            T = T->Left;
        free( TmpCell );
    }

    return T;
}


ElementType
Retrieve( Position P )
{
    return P->Element;
}

void PrintTree(SearchTree T)
{
    if ( T!= NULL )
    {
        PrintTree(T->Left);
        printf("%d ", Retrieve(T));
        PrintTree(T->Right);    }
}
/*
ReturnType function(Tree T)
{
    if (T == NULL)
        return base_value;

    ReturnType left = function(T->Left);
    ReturnType right = function(T->Right);

    return combine(T->Element, left, right);
}

Question	Pattern	Formula
count_nodes	Add everything	1 + left + right
sum_keys	Add everything	root + left + right
max_key	Biggest value	max(root,left,right)
print_below	Visit nodes	print if condition
height	Biggest path	1 + max(left,right)
path_cost	Biggest path	root + max(left,right)
structural identical	Boolean check	left && right
identical tree	Boolean check	value && left && right

| Problem        | Base value                      |
| -------------- | ------------------------------- |
| Count nodes    | `0`                             |
| Sum of keys    | `0`                             |
| Maximum value  | `-1` (given in your assignment) |
| Height         | `-1`                            |
| Path cost      | `0`                             |
| Boolean checks | `true`                          |

*/
#include <stdio.h>
#include <stdlib.h>
#include "Sturgeon_2_1.h"

void MakeEmpty(Tree T)
{

    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
}

int isPerfectTree (int n)
{
    n = n + 1;
    while (n % 2 == 0)
        n /= 2;
    
    if ( n == 1)
        return 1;
    else
        return 0;
}

Tree Insert (ElementType X, Tree T)
{
    if (T == NULL)
    {
        Tree temp_node = malloc(sizeof(struct BinaryTree));
        temp_node -> Element = X;
        temp_node -> Left = NULL;
        temp_node -> Right = NULL;
        temp_node -> lCount = temp_node -> rCount = 0;
        return temp_node;
    }
    else
    {
        if (T -> lCount == T -> rCount)
        {
            T -> Left = Insert ( X, T -> Left); 
            T -> lCount+=1;
        }
        else 
            if (T -> rCount < T -> lCount)
                if (isPerfectTree(T->lCount)) 
                {
                    T -> Right = Insert ( X, T -> Right); 
                    T -> rCount+=1;        
                }
                else
                {
                    T -> Left = Insert ( X, T -> Left); 
                    T -> lCount+=1;         
                }
    }
    return T;
}

void PrintTree(Tree T)
{
    if (T != NULL){
        PrintTree( T->Left );
        printf("%d ", T->Element);
        PrintTree( T->Right);
        printf("%d ", T->Element);
    }
 
}

Tree makeTree(int n, int *arr)
{
   
    Tree r = NULL;

    for (int i = 0; i < n; i++)
        r = Insert(arr[i], r);

    return r;
}

Tree removeNullNodes(Tree T)
{
    if (T != NULL)
    {
        T -> Left = removeNullNodes(T -> Left);
        T -> Right = removeNullNodes(T -> Right);
        if ( T -> Element == -1)
        {
            //free (T);
            return NULL;
        }
    }
    return T;
}
/* a)	The height of a tree is the maximum number of edges on a path from 
the root to a leaf node. Write a C function int height(BinaryTree T) that 
returns the height of a binary tree.*/
int height ( Tree T )
{
    /* If BinaryTree empty, return -1 */
    if ( T == NULL )
    {
        return -1;
    }
    /* if only root, return 0 (no children = height of 0 )*/
    else if (( T->Left == NULL ) && ( T->Right == NULL ))
    {
        return 0;
    }
    /* Recursively traverse down each side of tree*/
    else 
    {
        int lHeight = height( T->Left );
        int rHeight = height( T->Right );
        
        /* Compare left side of tree height to right side, returning greatest, and adding 1 to count for distance from first child to root */
        if (lHeight > rHeight)
        {
            return lHeight + 1;
        }
            else
                {
                    return rHeight + 1;
                }
    }
}
/* b) The cost of a path in a tree is sum of the keys of the nodes 
participating in that path. Write a C function int path_cost(BinaryTree T) 
that returns the cost of the most expensive path from the root to a leaf node.*/ 
int path_cost( Tree T )
{
    /* If BinaryTree empty, return 0 */
    if ( T == NULL )
    {
        return 0;
    }

    int lvCost = path_cost(T->Left);
        lvCost =+ T->Left->Element;
    int rvCost = path_cost(T->Right);
        rvCost =+ T->Right->Element;
    
    if ( lvCost > rvCost )
        return lvCost;
    else
    {
        return rvCost;
    }
}
// Uncomment the main method below to run this program on its own 
/*
int main(void)
{
    int arr [] = {9, 6, 11, 8, 5, 14, 2};

    Node r = NULL;

    for (int i = 0; i < (int) sizeof(arr)/sizeof(int); i++)
        r = Insert(arr[i], r);

    PrintTree(r);
    MakeEmpty(r);

}
 * 
*/
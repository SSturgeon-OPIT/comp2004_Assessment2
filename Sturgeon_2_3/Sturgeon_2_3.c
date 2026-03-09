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
#include <stdbool.h> // for boolean true false 
#include "Sturgeon_2_3.h"
int globaldebug;
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
        {
            if (T -> rCount < T -> lCount)
            {
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
        }
                
    }
    return T;
}

void PrintTree(Tree T)
{
    // printf("Print func %d\n",++globaldebug);
    if (T != NULL){
        PrintTree( T->Left );
        printf("%d ", T->Element);
        PrintTree( T->Right);
    }
 
}

Tree makeTree(int n, int *arr)
{
   
    Tree r = NULL;
    // printf("In Make Tree\n");
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

/* a)	Given two binary trees, return true if and only if they are structurally identical (they have the same shape, but their nodes can have different values). */ 
bool struct_same ( Tree T1, Tree T2 )
{
    if ( T1 == NULL && T2 == NULL )
        return true;

    else if ( T1 == NULL || T2 == NULL )
        return false;

    else
        {
            bool leftComp = struct_same ( T1->Left, T2->Left );
            bool rightComp = struct_same ( T2->Right, T2->Right );
            printf("\nr and l have been compared\n");
            return ( leftComp && rightComp );
        
        }
}

/* b)	Given two binary trees, return true if they are identical (they have nodes with the same values, arranged in the same way).
*/
bool struct_valsame ( Tree T1, Tree T2 )
{
    if ( T1 == NULL ^ T2 == NULL )
        return false;

    else if ( T1 == NULL && T2 == NULL )
        {
            return true;
           // T1->Element == T2->Element ? true : false;     
        }

    /*  else if ( T1 == NULL ^ T2 == NULL )
        return false; */

    else
        {
            bool leftComp = struct_valsame ( T1->Left, T2->Left );
            bool rightComp = struct_valsame ( T2->Right, T2->Right );
            \\printf("\nr and l have been compared\n");
            //return ( leftComp && rightComp );
            return ( t1->Element == t2->Element )
        
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
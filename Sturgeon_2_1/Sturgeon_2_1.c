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

/* a) Counts and Returns number of items in binary tree*/
ElementType count_nodes( Tree T )
{
    /* sumLeft = 0;
    sumRight = 0; */
    /* If tree is empty, return 0 bc empty tree = 0 nodes */
    if ( T == NULL ) 
        return 0;

    else
    {
        T->lCount = count_nodes( T->Left ); // count all nodes on left 
        T->rCount = count_nodes( T->Right ); // count all nodes on right
 
        return ( 1 + T->lCount + T->rCount ); // add left and right nodes, plus root node 
    }
}

/* b) Returns sum of all the elements in binary tree */
ElementType sum_elements( Tree T )
{
    /* Empty Tree, return 0  */
    if ( T == NULL )
        return 0;
    /* If only one element, return element */
    else if ( T->Left == NULL && T->Right == NULL )
        return T->Element;

    else 
    {
    /* Declaration of two int variables to store left and right values */
    int leftSum = 0;
    int rightSum = 0; 

    /* Recursively go down tree until T = NULL*/
    leftSum = sum_elements( T->Left );
    rightSum = sum_elements( T->Right ); 

    return (T->Element + leftSum + rightSum); // return root element + all left children elements + all right children elements
    }   
}
/* c) returns maximum value of all the elements in binary tree */
ElementType max_element( Tree T )
{
    if ( T == NULL )
        return -1; // empty tree, so return -1 (per assessment instructions)

    /* int maxLeft; // to store the highest value 
    int maxRight; */

    /* Compare elements on left side of the binary tree */
    int leftMax = max_element( T->Left );
        if ( T->Left->Element > T->Element )
        T->Left->Element = leftMax;
            else
            {
                T->Element = leftMax;
            }
    /* Compare elements on right side of the binary tree */
    int rightMax = max_element( T->Right );
        if ( T->Right->Element > T->Element )
            T->Right->Element = leftMax;
            else
            {
                T->Element = rightMax;
            }

/* Compare left side highest value to right side highest value, returning whichever is higher */
    if (leftMax > rightMax )
            return leftMax;
        else
            return rightMax;
}

/* d) prints all elements less than a given value v in binary tree */
void print_below( Tree T, ElementType v )

/* If statement in the case tree is empty */
    if ( T == NULL )
        printf("The tree is empty... ");
{
    else if ( T =! NULL )

    print_below( T->Left, v );
        if ( T->Left->Element < v )
            printf("%d ", T->Left->Element);

    print_below( T->Right, v );
        if ( T->Right->Element < v )
            printf("%d ", T->Right->Element)

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
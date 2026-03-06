/*
ReturnType function(Tree T)
{
    if (T == NULL)
        return base_value;

    ReturnType left = function(T->Left);
    ReturnType right = function(T->Right);

    return combine(T->Element, left, right);
}
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
 
        return ( 1 + T->lCount, T->rCount ); // add left and right nodes, plus root node 
    }
}

/* b) Returns sum of all the elements in binary tree */
ElementType sum_elements( Tree T )
{
    if ( T == NULL )
    return T->Element;

    int leftSum =+ T->Left->Element;
    int rightSum =+ T->Right->Element;

    leftSum = sum_elements( T->Left ); // what to do when T->Left = NULL? If statement?
    rightSum = sum_elements( T->Right ); // what to do when T->Right = NULL? If statement?

    return T->Element + leftSum + rightSum; // return root element + all left children elements + all right children elements
        
}
/* c) returns maximum value of all the elements in binary tree */
ElementType max_element( Tree T )
{
    if ( T == NULL )
    return -1; // empty tree, so return -1 (per assessment instructions)

    int leftMax = 0;
    int rightMax = 0;
    int max = 0; // to store the max element 

    

    /* 
    while ( T != NULL )
        {
            leftMax = max_element( T->Left->Element);
            rightMax = max_element( T->Right->Element );
        }
    if (max_element( T->Left->Element) > max_element(T->Right->Element) )
        return max_element( T->Left->Element);
    else
        return max_element( T->Right->Element );
    */
}

/* d) prints all elements less than a given value v in binary tree */
void print_below( Tree T, ElementType v )
{
    /* If statement in the case tree is empty */
    if ( T == NULL )
        printf("The tree is empty... ");
   
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
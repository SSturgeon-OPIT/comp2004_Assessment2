/* 
Question 2 (30 points;15 points for each part)
As in Question 1, make a copy COMP2004_Assignment2_driver.c and rename the copy to <Your Lastname>_2_2.c
Add functions to the COMP2004_Assignment2_Q2.c file for each of the sub-parts given below. 
Write a menu driven interface for your program to call the functions and print the returned value, as shown below:
Enter the number of data elements in the tree: 9
Enter the tree data elements (space separated integers representing a complete binary tree): 12 8 3 4 -1 5 -1 -1 7 

Enter a choice:
[1] Tree Height
[2] Max Path Cost
[3] Exit

a)	The height of a tree is the maximum number of edges on a path from the root to a leaf node. Write a C function int height(BinaryTree T) that returns the height of a binary tree.
b)	The cost of a path in a tree is sum of the keys of the nodes participating in that path. Write a C function int path_cost(BinaryTree T) that returns the cost of the most expensive path from the root to a leaf node.
*/

/*
git add .
git commit -m "Message"
git push
*/
#include <stdio.h>
#include <stdlib.h>
#include "binary_tree_from_list.c"

int main()
{   
    int n;
    printf("Enter the number of nodes in the tree: ");
    scanf ("%d", &n);
    int *arr = (int *) malloc(sizeof(int)*n);
    printf("Enter the level-order data elements of the tree (positive ints separated by space):");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    Tree r = makeTree(n, arr);
    r = removeNullNodes(r);

    printf("Inorder traversal: ");
    PrintTree(r);
    printf("\n");

    // Enter the function calls to the code for the 
    // different questions for Assignment 2 below this line


    MakeEmpty(r);
}
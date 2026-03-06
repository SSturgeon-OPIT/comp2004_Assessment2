/*
Question 3 (30 points; 15 points for each part)
Once again, make a copy COMP2004_Assignment2_driver.c and rename the copy to <Your Lastname>_2_3.c
Add functions to the COMP2004_Assignment2_Q3.c file for each of the sub-parts given below. 
Write a menu driven interface for your program to call the functions and print the returned value, as shown below:
Enter the number of data elements in the first tree: 9
Enter the tree data elements (space separated integers representing a complete binary tree): 12 8 3 4 -1 5 -1 -1 7 

Enter the number of data elements in the second tree: 5
Enter the tree data elements (space separated integers representing a complete binary tree): 3 8 12 5 4 

Enter a choice:
[1] Structure Identical Check
[2] Structure and Value Identical Check
[3] Exit
.
a)	Given two binary trees, return true if and only if they are structurally identical (they have the same shape, but their nodes can have different values).
b)	Given two binary trees, return true if they are identical (they have nodes with the same values, arranged in the same way).
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
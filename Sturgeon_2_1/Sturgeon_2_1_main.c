/* Question 1 (60 points; 15 points for each part) 
Make a copy COMP2004_Assignment2_driver.c and rename the copy to 
<Your Lastname>_2_1.c
Add functions to the COMP2004_Assignment2_Q1.c file for each of the 
sub-parts given 
below. 
Write a menu driven interface for your program to call the functions 
and print the 
returned value, as shown below:
Enter the number of data elements in the tree: 9
Enter the tree data elements (space separated integers representing a 
complete binary 
tree): 12 8 3 4 -1 5 -1 -1 7 

Enter a choice:
[1] Count Nodes
[2] Sum Keys
[3] Max Key
[4] Print Below (this choice should prompt the user to input the value 
’v’)
[5] Exit

a)	Write a function ElementType count_nodes(BinaryTree T) that counts 
and returns the number of items in a binary tree.
b)	Write a function ElementType sum_keys(BinaryTree T) that returns 
the sum of all 
the keys in a binary tree.
c)	Write a function ElementType max_key(BinaryTree T) that returns 
the maximum value 
of all the keys in a binary tree. Assume all values are nonnegative; 
return -1 if the 
tree is empty.   
d)	Write a function void print_below(BinaryTree T, ElementType v) 
that prints all the 
keys less than a given value v in a binary tree. 
*/

/*
git add .
git commit -m "Message"
git push
*/

#include <stdio.h>
#include <stdlib.h>
#include "Sturgeon_2_1.h"
// #include "binary_tree_from_list.c"

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
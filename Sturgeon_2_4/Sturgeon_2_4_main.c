/*
Question 4 (80 points: 20 points for part a), 20 points for part b), 40 points for part c))
For this question you should use the code discussed in the BST module (bst.h, bst.c and test_bst.c).
Add functions to the bst.c file for each of the sub-parts given below. For each function, remember to add the corresponding function prototype in bst.h file. Also include a menu driven interface for your code, as shown below: 
Enter a choice:
[1] Insert (this choice should prompt the user to input the data element of the node)
[2] findMin_K (this choice should prompt the user to input the value ’k’)
[2] numLeafNodes
[3] LevelOrder
[4] Exit

a)	Write a function Position findMin_K(SearchTree T, int k) to find the kth smallest element in the binary search tree.
b)	Write a function int numLeafNodes(SearchTree T)which returns the number of leaf nodes in a binary search tree 
c)	To traverse a binary tree in level order means to start at the root, and then visit all nodes one node away from the root (starting with the left node, if not null); and then visit all nodes two nodes away from the root (again, left-most to right-most), as they exist; and then visit all nodes 3 nodes away from the root and so on. Write a function ElementType* LevelOrder(SearchTree T) that returns a queue of the keys of the binary search tree in level order. 
*/

/*
git add .
git commit -m "Message"
git push
*/
#include "Sturgeon_2_4_bst.h"
#include <stdio.h>

int main()
{
    SearchTree t;
    
    t = Insert (6, t);
    t = Insert (7, t);
    t = Insert (4, t);
    t = Insert (2, t);
    t = Insert (5, t);
    t = Insert (3, t);
    t = Insert (9, t);
    t = Insert (8, t);
  
    printf("InOrder: ");
    PrintTree(t);
    printf("\n");
    
    printf("FindMin: %d\n", Retrieve(FindMin(t)));
    printf("FindMax: %d\n", Retrieve(FindMax(t)));
    printf("Find 3: %d\n", Retrieve(Find(3, t)));

    t = Insert (10, t);  
    printf("InOrder: ");
    PrintTree(t);
    printf("\n");
    
    t = Delete(6, t);
    printf("InOrder: ");
    PrintTree(t);
    printf("\n");
    
    MakeEmpty(t);
    
}

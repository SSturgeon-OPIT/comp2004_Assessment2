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

typedef int ElementType;


#ifndef _BST_H
#define _BST_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
Position FindMin( SearchTree T );
Position FindMax( SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
SearchTree Delete( ElementType X, SearchTree T );
ElementType Retrieve( Position P );

void PrintTree(SearchTree T);

#endif  /* _BST_H */

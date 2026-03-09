
#ifndef STURGEON_2_4_BST_H
#define STURGEON_2_4_BST_H

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

struct TreeNode
{
    ElementType Element;
    SearchTree  Left;
    SearchTree  Right;
};


SearchTree MakeEmpty( SearchTree T );

Position Find( ElementType X, SearchTree T );

Position FindMin( SearchTree T );

Position FindMax( SearchTree T );

SearchTree Insert( ElementType X, SearchTree T );

SearchTree Delete( ElementType X, SearchTree T );

ElementType Retrieve( Position P );

void PrintTree(SearchTree T);

Position findMin_K( SearchTree T, int k);

int numLeafNodes( SearchTree T );

ElementType *LevelOrder( SearchTree T );

#endif  /* _BST_H */

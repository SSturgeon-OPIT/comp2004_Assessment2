#include "bst.h"
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

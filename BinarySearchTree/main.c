#include "BinarySearchTree.h"

void Trav(item_t data)
{
    printf("%d\t", data);
}

int main(void)
{
    tree_t tree = CreateTree();
    printf("Create a tree with root item: 3.\n");
    tree->data = 3;
    printf("\n");

    printf("Insert 4 items: 1, 2, 4, 5\n");
    Insert(tree, 1);
    Insert(tree, 2);
    Insert(tree, 4);
    Insert(tree, 5);
    printf("\n");

    printf("PRE_ORDER:\n");
    Traversal(tree, PRE_ORDER, Trav);
    printf("\nIN_ORDER:\n");
    Traversal(tree, IN_ORDER, Trav);
    printf("\nPOST_ORDER:\n");
    Traversal(tree, POST_ORDER, Trav);
    printf("\nLEVEL_ORDER:\n");
    Traversal(tree, LEVEL_ORDER, Trav);
    printf("\n\n");

    tree_t min = FindMin(tree);
    printf("Min: %d\n", min->data);
    tree_t max = FindMax(tree);
    printf("Max: %d\n", max->data);
    printf("\n");

    DestroyTree(tree);
    printf("Destroy tree.\n");

    return 0;
}

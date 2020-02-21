#include "BinaryTree.h"

int main(void)
{
    tree_t A = CreateTree();
    tree_t B = (tree_t)malloc(sizeof(struct tree));
    tree_t C = (tree_t)malloc(sizeof(struct tree));
    tree_t D = (tree_t)malloc(sizeof(struct tree));

    A->data = 'A';
    A->left = B;
    A->right = C;

    B->data = 'B';
    B->left = D;
    B->right = NULL;

    C->data = 'C';
    C->left = NULL;
    C->right = NULL;

    D->data = 'D';
    D->left = NULL;
    D->right = NULL;

    Insert(A, 'E');

    printf("\nPRE_ORDER:\n");
    Traversal(A, PRE_ORDER);
    printf("\nIN_ORDER:\n");
    Traversal(A, IN_ORDER);
    printf("\nPOST_ORDER:\n");
    Traversal(A, POST_ORDER);
    printf("\nLEVEL_ORDER:\n");
    Traversal(A, LEVEL_ORDER);

    getchar();
    return 0;
}

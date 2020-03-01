#include "BinarySearchTree.h"

tree_t CreateTree(void)
{
    tree_t tree = (tree_t)malloc(sizeof(struct tree));
    if (tree == NULL)
    {
        fprintf(stderr, "ERROR: There was not enough memory.\n");
        exit(-2);
    }

    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

void Traversal(tree_t tree, int type)
{
    if (tree)
    {
        switch (type)
        {
            // 先序遍历
            case PRE_ORDER:
                {
                    printf("%d ", tree->data);
                    Traversal(tree->left, PRE_ORDER);
                    Traversal(tree->right, PRE_ORDER);
                    break;
                }
            // 中序遍历
            case IN_ORDER:
                {
                    Traversal(tree->left, IN_ORDER);
                    printf("%d ", tree->data);
                    Traversal(tree->right, IN_ORDER);
                    break;
                }
            // 后序遍历
            case POST_ORDER:
                {
                    Traversal(tree->left, POST_ORDER);
                    Traversal(tree->right, POST_ORDER);
                    printf("%d ", tree->data);
                    break;
                }
            // 层次遍历
            case LEVEL_ORDER:
                {
                    queue_t Q = CreateQueue();
                    tree_t T;
                    if (tree == NULL)
                    {
                        return;
                    }
                    AddQ(Q, tree);
                    while (!IsEmpty(Q))
                    {
                        T = DeleteQ(Q);
                        printf("%d ", T->data);
                        if (T->left)
                        {
                            AddQ(Q, T->left);
                        }
                        if (T->right)
                        {
                            AddQ(Q, T->right);
                        }
                    }
                    break;
                }
            default:
                {
                    printf("Error type!\n");
                    break;
                }
        }
    }
}

tree_t Find(tree_t tree, item_t data)
{
    tree_t current = tree;

    while (current)
    {
        if (data > current->data)
        {
            current = current->right;
        }
        else if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            return current;
        }
    }

    return NULL;
}

tree_t FindMin(tree_t tree)
{
    tree_t current = tree;

    if (current)
    {
        while (current->left)
        {
            current = current->left;
        }
    }

    return current;
}

tree_t FindMax(tree_t tree)
{
    tree_t current = tree;

    if (current)
    {
        while (current->right)
        {
            current = current->right;
        }
    }

    return current;
}

tree_t Insert(tree_t tree, item_t data)
{
    if (!tree)
    {
        tree = (tree_t)malloc(sizeof(struct tree));
        tree->data = data;
        tree->left = NULL;
        tree->right = NULL;
    }
    else
    {
        if (data < tree->data)
        {
            tree->left = Insert(tree->left, data);
        }
        else if (data > tree->data)
        {
            tree->right = Insert(tree->right, data);
        }
    }

    return tree;
}

tree_t Delete(tree_t tree, item_t data)
{
    tree_t tmp;

    if (!tree)
    {
        printf("Error: There was no item %d", data);
    }
    else
    {
        if (data < tree->data)
        {
            tree->left = Delete(tree->left, data);
        }
        else if (data > tree->data)
        {
            tree->right = Delete(tree->right, data);
        }
        else
        {

            if (tree->left && tree->right)
            {
                tmp = FindMin(tree->right);
                tree->data = tmp->data;
                tree->right = Delete(tree->right, tree->data);
            }
            else
            {
                tmp = tree;
                if (!tree->left)
                {
                    tree = tree->right;
                }
                else
                {
                    tree = tree->left;
                }
                free(tmp);
            }
        }
    }

    return tree;
}

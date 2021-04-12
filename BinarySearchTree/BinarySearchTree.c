#include "BinarySearchTree.h"

/*******************************
Helper functions implementation.
*******************************/

/*******************************
Interface functions implementation.
*******************************/

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

void DestroyTree(tree_t tree)
{
    if (tree)
    {
        DestroyTree(tree->left);
        DestroyTree(tree->right);
        free(tree);
        tree = NULL;
    }
}

void Traversal(tree_t tree, traversal_t type, void (*pTrav)(item_t data))
{
    if (tree)
    {
        switch (type)
        {
            // 先序遍历
            case PRE_ORDER:
            {
                pTrav(tree->data);
                Traversal(tree->left, PRE_ORDER, pTrav);
                Traversal(tree->right, PRE_ORDER, pTrav);
                break;
            }
            // 中序遍历
            case IN_ORDER:
            {
                Traversal(tree->left, IN_ORDER, pTrav);
                pTrav(tree->data);
                Traversal(tree->right, IN_ORDER, pTrav);
                break;
            }
            // 后序遍历
            case POST_ORDER:
            {
                Traversal(tree->left, POST_ORDER, pTrav);
                Traversal(tree->right, POST_ORDER, pTrav);
                pTrav(tree->data);
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
                Enqueue(Q, tree);
                while (!IsEmpty(Q))
                {
                    T = Dequeue(Q);
                    pTrav(T->data);
                    if (T->left)
                    {
                        Enqueue(Q, T->left);
                    }
                    if (T->right)
                    {
                        Enqueue(Q, T->right);
                    }
                }
                DestroyQueue(Q);
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

tree_t Find(const tree_t tree, item_t data)
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

tree_t FindMin(const tree_t tree)
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

tree_t FindMax(const tree_t tree)
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
        if (tree == NULL)
        {
            fprintf(stderr, "ERROR: There was not enough memory.\n");
            exit(-2);
        }
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

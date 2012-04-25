#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

typedef struct node {
        int data;
        struct node *left;
        struct node *right;
} NODE;

NODE *root = NULL;

NODE * newnode (int data)
{
        NODE * n = NULL;
        if (n = (NODE *) malloc (sizeof (NODE))) {
                n->data = data;
                n->right = n->left = NULL;
        } else {
                printf("%d - %d - unalbe to create new node \n", __LINE__, data);
        }

        return n;
}

NODE * getnode(NODE * n, int data)
{
        if (n == NULL)
                return NULL;

        if (n->data == data)
                return n;

        if (data < n->data)     {
                return getnode (n->left, data);
        }

        if (data > n->data) {
                return getnode (n->right, data);
        }

        return NULL;
}

NODE * insert (NODE * node, int data, int *dup)
{
    NODE * n = NULL;

    if (node != NULL) {
        if (getnode(node, data) != NULL) {
            /* element already present in the tree..
               so set the dup and return the root */
            *dup = 1;
            return node;
        }
    }

    if (node == NULL) {
        n = newnode(data);
        return (n);
    }

    if (data <= node->data)
        node->left = insert(node->left, data, dup);
    else
        node->right = insert(node->right, data, dup);

    return node;
}

NODE * deletetree(NODE * from)
{
    if (from != NULL) {
        deletetree(from->left);
        deletetree(from->right);
        //printf("deleting %d \n", from->data);
        free(from);
    }
    return NULL;
}

int main()
{
    int sum = 35;
    int X[] = {1,2,3,4,5,6,7,8,9,1,2,3,4,5};
    int Y[] = {1,2,8,9,11};
    int i, dup = 0;

    int xlen = sizeof(X)/sizeof(X[0]);
    int ylen = sizeof(Y)/sizeof(Y[0]);

    printf("len of X is : %d \n", xlen);
    printf("len of Y is : %d \n", ylen);

    NODE * root1 = NULL;

    for (i=0; i<xlen; i++) {
        root = insert(root, X[i], &dup);
    }

    for (i=0; i<ylen; i++) {
        dup = 0;
        root = insert(root, Y[i], &dup);
        if (dup == 1) {
            printf("%d ", Y[i]);
        }
    }

    printf("\n");
    root = deletetree(root);

    return 0;
}

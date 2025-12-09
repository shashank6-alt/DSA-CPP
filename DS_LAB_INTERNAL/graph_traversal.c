#include <stdio.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Recursive Traversals
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Non-Recursive Inorder (using stack)
void inorderNR(struct node *root)
{
    struct node *stack[20];
    int top = -1;

    while(1)
    {
        while(root != NULL)
        {
            stack[++top] = root;
            root = root->left;
        }

        if(top == -1)
            break;

        root = stack[top--];
        printf("%d ", root->data);
        root = root->right;
    }
}

int main()
{
    // Simple fixed tree
    struct node n1 = {1, NULL, NULL};
    struct node n2 = {2, NULL, NULL};
    struct node n3 = {3, NULL, NULL};
    struct node n4 = {4, NULL, NULL};
    struct node n5 = {5, NULL, NULL};

    /*
            1
          /   \
         2     3
        / \
       4   5
    */

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;

    printf("Recursive Traversals:\n");
    printf("Inorder   : "); inorder(&n1);
    printf("\nPreorder  : "); preorder(&n1);
    printf("\nPostorder : "); postorder(&n1);

    printf("\n\nNon-Recursive Traversal:\n");
    printf("Inorder   : "); inorderNR(&n1);

    return 0;
}

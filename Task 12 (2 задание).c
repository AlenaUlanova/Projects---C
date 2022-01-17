#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int key;
    struct tree* left;
    struct tree* right;
    struct tree* parent;
} Node;

Node* Add(Node* root, int key)
{
    Node* root2 = root, *root3 = NULL;
    Node* tmp = malloc(sizeof(Node));
    tmp -> key = key;
    while (root2 != NULL)
    {
        root3 = root2;
        if (key < root2 -> key)
            root2 = root2 -> left;
        else
            root2 = root2 -> right;
    }
    tmp -> parent = root3;
    tmp -> left = NULL;
    tmp -> right = NULL;
    if (key < root3 -> key) root3 -> left = tmp;
    else root3 -> right = tmp;
    return root;
}

Node* Create (Node* root, int key)
{
    Node* tmp = malloc(sizeof(Node));
    tmp -> key = key;
    tmp -> parent = NULL;
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}

Node* Search(Node* root, int key)
{
    if ((root == NULL) || (root -> key == key))
        return root;
    if (key < root -> key)
        return Search(root -> left, key);
    else return Search(root -> right, key);
}

void preorder(Node* root)
{
    if (root == NULL)
        return;
    if (root -> key)
        printf("%d ", root -> key);
    preorder(root -> left);
    preorder(root -> right);
}

int main()
{
    Node* root = malloc(sizeof(Node));
    Create(root, 8);
    Add(root, 3);
    Add(root, 10);
    Add(root, 1);
    Add(root, 6);
    Add(root, 4);
    Add(root, 7);
    Add(root, 14);
    Add(root, 13);
    printf("%d", Search(root, 10)->parent->key);
    return 0;
}

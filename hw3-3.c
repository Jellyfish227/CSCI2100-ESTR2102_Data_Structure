#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int count = 0;

int height(struct Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node* newNode(int data)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->key   = data;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node at leaf
    return(node);
}

struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    count++;
    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left),
                    height(y->right)) + 1;
    x->height = max(height(x->left),
                    height(x->right)) + 1;

    // Return new root
    return x;
}

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    count++;
    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left),
                    height(x->right)) + 1;
    y->height = max(height(y->left),
                    height(y->right)) + 1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node* insert(struct Node* node, int data)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(data));

    if (data < node->key)
        node->left  = insert(node->left, data);
    else if (data > node->key)
        node->right = insert(node->right, data);
    else // Equal keys are not allowed in BST
        return node;

    /* Update height of ancestor node */
    node->height = 1 + max(height(node->left),
                        height(node->right));

    /* check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // 4 cases of unbalance
    // Left Left Case
    if (balance > 1 && data < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

void freeTree(struct Node * node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        count = 0;
        struct Node *root = NULL;
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int k;
            scanf("%d", &k);
            root = insert(root, k);
        }
        printf("%d\n", count);
        freeTree(root);
    }
    
#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %.9f", totalTime);
#endif
    return 0;
}

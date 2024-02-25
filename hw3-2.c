#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * construct(int arr[], int m, int idx) {
    if (idx > m)
        return NULL;
    int num = arr[idx - 1];
    if (num == 0)
        return NULL;
    struct Node * newNode = malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->left = construct(arr, m, idx << 1);
    newNode->right = construct(arr, m, (idx << 1) + 1);
    return newNode;
}

void freeTree(struct Node* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

void inorder(struct Node * root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int const ROOT = 1;
        int m;
        scanf("%d", &m);
        int arr[m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[j]);
        }
        struct Node* root = construct(arr, m, ROOT);
        inorder(root);
        putchar('\n');
        freeTree(root);
    }
    
#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %.9f", totalTime);
#endif
    return 0;
}

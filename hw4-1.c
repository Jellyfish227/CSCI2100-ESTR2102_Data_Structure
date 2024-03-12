//4.13
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node *newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}

struct Node *minNode(struct Node *x, struct Node *y){
    return (x->data < y->data) ? x : y;
}

void swap(struct Node *l, struct Node *r){
    struct Node *temp;
    temp->left = r->left;
    temp->right = r->right;
    r->left = l->left;
    r->right = l->right;
    l->left = temp->left;
    l->right = temp->right;
}

int checkBreak(struct Node *node){
    if (node == NULL)
        return 0;
    struct Node *temp = minNode(node->left, node->right);
    if (temp->data < node->data){
        swap(node, temp);
    }

}

struct Node *insert(struct Node *node, int data){
    if (node == NULL)
        return (newNode(data));
    else if (node->left == NULL)
        insert(node->left, data);
    else if (node->right == NULL)
        insert(node->right, data);

    if (data < node->data){
        node->left = newNode(data);
//        int temp = node->data;
//        node->data = node->left->data;
//        node->left->data = temp;
    }
    else if (data > node->data)
}

void freeTree(struct Node *node) {
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
    
    int k;
    int i = 0;
    scanf("%d", &k);
    int arr[k];
    int size = 0;

    char input;
    do
    {
        scanf("%c", &input);
        if (input == 'I')
        {
            int n;
            scanf("%d", &n);
            arr[size++] = n;
            checkHeap(arr, size, 1);
            // insert(n, arr, ++i, k);
        } else if (input == 'O'){
            int j = size;
            int sorted[j];
            for (int i = 0; i < j; i++)
            {
                sorted[i] = heapDequeue(arr, &size);
            }
            printf("%d\n", sorted[k-1]);
        } 
    } while (input != 'S');

#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

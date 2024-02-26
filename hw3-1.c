#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int l, int r) {
    if (l > r)
        return l;
    else
        return r;
}

int constructTree(int *tree) {
    int element = 0;
    int *t = tree;
    char str[10000];
    fgets(str, 10000, stdin);
    char *sPtr = str;
    while (*sPtr != '\0') {
        if (*sPtr == ' ') {
            sPtr++;
            continue;
        } else if (*sPtr == '\n')
            break;

        if (*sPtr == '#') {
            t[element++] = 10001;
        }
        else if (*sPtr == '-') {
            sPtr++;
            while (*sPtr != ' ' && *sPtr != '\n') {
                t[element] *= 10;
                t[element] += sPtr[0] - '0';
                sPtr++;
            }
            t[element] *= -1;
            sPtr--;
            element++;
        }
        else if (*sPtr > '0' && *sPtr < '9') {
            while (*sPtr != ' ' && *sPtr != '\n') {
                t[element] *= 10;
                t[element] += sPtr[0] - '0';
                sPtr++;
            }
            sPtr--;
            element++;
        }
        sPtr++;
    }
    return element;
}

int sumTree(int *tree,int n, int idx) {
    if (idx > n)
        return 0;
    if (tree[idx - 1] == 10001)
        return 0;
    else {
        int num = tree[idx - 1];
        return num + max(sumTree(tree, n, idx << 1), sumTree(tree, n, (idx << 1) + 1)); 
    }
}

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    
    int n;
    scanf("%d", &n);
    while (getchar() != '\n');
    for (int i = 0; i < n; i++) {
        int const ROOT = 1;
        int *treePtr = malloc(10000 * sizeof(int));
        int element = constructTree(treePtr); 
        printf("%d", sumTree(treePtr, element, ROOT));
        if (i != n - 1)
        {
            putchar('\n');
        }
        free(treePtr);
    }
    
#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %.9f", totalTime);
#endif
    return 0;
}

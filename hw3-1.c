#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int l, int r) {
    if (l > r)
        return l;
    else
        return r;
}

int checkNull(int *tree, int idx,int n) {
    if (idx > n) //check exist
        return 1;
    if (tree[idx - 1] <= -10000*10010) {
        return 1;
    } else {
        return 0;
    }
}

int constructTree(int *tree) {
    int element = 0;
    int t[10000];
    for (int i = 0; i < 10000; i++) {
        t[i] = 0;
    }
    char str[100000];
    fgets(str, 100000, stdin);
    char *sPtr = str;
    while (*sPtr != '\0') {
        if (*sPtr == ' ') {
            sPtr++;
            continue;
        } else if (*sPtr == '\n')
            break;

        if (*sPtr == '#') {
            t[element++] = -10000*10010;
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
        else if (*sPtr >= '0' && *sPtr <= '9') {
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
    for (int i = 0; i < element; i++)
    {
        *tree = t[i];
        tree++;
    }
    return element;
}

int sumTree(int *tree,int n, int idx) {
    int num = tree[idx - 1];

    if (checkNull(tree, idx << 1, n) && checkNull(tree, (idx << 1) + 1, n)) {
        return num;
    } else if (checkNull(tree, idx << 1, n)) {
        return num + sumTree(tree, n, (idx << 1) + 1);
    } else if (checkNull(tree, (idx << 1) + 1, n)) {
        return num + sumTree(tree, n, idx << 1);
    } else {
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
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

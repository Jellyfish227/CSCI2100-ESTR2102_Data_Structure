//4.13
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int min(int l, int r){
    return (l < r) ? l : r ;
}

void insert(int n, int arr[], int i, int k){
    if (i > k) {
        if (!(n < arr[k - 1]))
            return;
    }
    for (int j = 0; j < min(i, k); j++)
    {
        if (n < arr[j])
        {
            int temp = arr[j];
            arr[j] = n;
            insert(temp, arr, i, k);
        } else if (i <= k){
            if (j == i - 1)
            {
                arr[j] = n;
            }
        }
    }
    return;
}

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    
    int k;
    int i = 0;
    scanf("%d", &k);
    int arr[k];

    char input;
    do
    {
        scanf("%c", &input);
        if (input == 'I')
        {
            int n;
            scanf("%d", &n);
            insert(n, arr, ++i, k);
        } else if (input == 'O'){
            printf("%d\n", arr[k-1]);
        } 
    } while (input != 'S');

#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

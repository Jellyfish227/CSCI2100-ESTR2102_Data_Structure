//4.13
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int x, int y){
    return (x > y) ? x : y;
}

int isHeap(int arr[], int size, int idx){
    if (idx > size)
    {
        return -1;
    }
    int left = idx << 1;
    int right = (idx << 1) + 1;
    int maxNum = max(isHeap(arr, size, left), isHeap(arr, size, right));
    if (maxNum > arr[idx - 1])
    {
        maxNum = (maxNum == arr[left - 1] ? left - 1 : right - 1);
        int temp = arr[idx - 1];
        arr[idx - 1] = arr[maxNum];
        arr[maxNum] = temp;
    }
    return arr[idx - 1];
}

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    
    int k;
    int i = 0;
    scanf("%d", &k);
    int maxHeap[k];
    int size = 0;

    char input;
    do
    {
        scanf("%c", &input);
        if (input == 'I')
        {
            int n;
            scanf("%d", &n);
            size++;
            if (size <= k)
            {
                maxHeap[size - 1] = n;
            } else if (n < maxHeap[0])
            {
                maxHeap[0] = n;
            }
            isHeap(maxHeap, (size < k) ? size : k, 1);

        } else if (input == 'O'){
            
            printf("%d\n", maxHeap[0]);
        } 
    } while (input != 'S');

#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

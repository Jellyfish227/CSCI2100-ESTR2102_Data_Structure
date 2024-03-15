//4.16
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int min(int x, int y){
    return (x < y) ? x : y;
}

void swap(int heap[], int x, int y){
    int temp = heap[x];
    heap[x] = heap[y];
    heap[y] = temp;
}

void sortHeap(int heap[], int idx, int sizeOfHeap){
    if (idx > sizeOfHeap) //this element out of range
        return;
    
    //this node exist
    int const LEFT = idx << 1;
    int const RIGHT = (idx << 1) + 1;

    int minNum;
    int isBoth = 0;

    if (LEFT > sizeOfHeap){ //leaf node of the current branch
        return;
    } else if (RIGHT > sizeOfHeap){ //right node out of range
        isBoth = 0;
        sortHeap(heap, LEFT, sizeOfHeap);
        minNum = heap[LEFT - 1];
    } else { //both node exist
        isBoth = 1;
        sortHeap(heap, LEFT, sizeOfHeap);
        sortHeap(heap, RIGHT, sizeOfHeap);
        minNum = min(heap[LEFT - 1], heap[RIGHT - 1]);
    }
    if (heap[idx - 1] > minNum)
    {
        minNum = (minNum == heap[LEFT - 1]) ? LEFT : RIGHT ;
        swap(heap, idx - 1, minNum - 1);
    }
    // if (isBoth)
    // {
    //     sortHeap(heap, LEFT, sizeOfHeap);
    //     sortHeap(heap, RIGHT, sizeOfHeap);
    // } else
    //     sortHeap(heap, LEFT, sizeOfHeap);
    return;
}

void insert(int heap[], int num, int entry, int sizeOfHeap){
    int const HEAD = 1;
    //insert to heap
    if (entry < sizeOfHeap)
        heap[entry] = num;
    else {
        if (num < heap[0])
            return;
        heap[0] = num;
        sortHeap(heap, HEAD, sizeOfHeap);
    }
    return;
}

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    
    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        int minHeap[k];
        for (int j = 0; j < (n * n); j++)
        {
            int input;
            scanf("%d", &input);
            insert(minHeap, input, j, k);
        }
        printf("%d\n", minHeap[0]);
    }
    
    
#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

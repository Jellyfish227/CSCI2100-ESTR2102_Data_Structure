#include <stdio.h>
#include <time.h>


int main(){
    #ifdef DEBUG
        const clock_t begin = clock();
    #endif

    int m, n;
    int arr[1000] = {0};
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &n);
        int maxEven = 0;
        int input;
        for (int j = 0; j < n; j++) {
            scanf("%d", &input);
            if (input % 2 == 0 && input > maxEven)
                maxEven = input;
        }
        arr[i] = maxEven;
    }
    for (int i = 0; i < m; i++) {
        printf("%d\n",arr[i]);
    }

    #ifdef DEBUG
        const clock_t end = clock();
        const double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time: %.9f", totalTime);
    #endif
    return 0;
}

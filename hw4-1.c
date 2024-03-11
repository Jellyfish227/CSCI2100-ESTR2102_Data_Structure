//4.13
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int insert(int n, int arr[], int size){
    
    return 0;
}

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    
    int k;
    int i = 0;
    scanf("%d", &k);
    int arr[1000000];
    unsigned int n;
    char input;
    do
    {
        scanf("%c", &input);
        if (input == 'I')
        {
            int n;
            scanf("%d", &n);
            insert(n, arr, ++i);
        } else if (input == 'O'){
            printf("%d\n", arr[2]);
        } else if (input == 'S'){
            return 0;
        }
        
    } while (input != 'S');

#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

//4.16
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    
    
    
#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

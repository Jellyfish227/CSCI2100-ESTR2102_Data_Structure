#include <stdio.h>
#include <time.h>

int isPowerOfFive(int n) {
    double m = n;
    while (m > 1) {
        m /= 5;
    }
    return (int)m;
}

int main(){
    #ifdef DEBUG
        const clock_t begin = clock();
    #endif

    int m;
    scanf("%d", &m);
    int n[1000] = {0};
    for (int i = 0; i < m; i++) {
        scanf("%d", &n[i]);
    }

    for (int i = 0; i < m; i++) {
        printf("%s\n", isPowerOfFive(n[i]) == 1 ? "True" : "False");
    }

    #ifdef DEBUG
        const clock_t end = clock();
        const double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time: %.9f", totalTime);
    #endif
    return 0;
}
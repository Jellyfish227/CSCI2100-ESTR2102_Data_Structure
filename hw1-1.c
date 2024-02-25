#include <stdio.h>
#include <ctype.h>
#include <time.h>

int main(){
    #ifdef DEBUG
        const clock_t begin = clock();
    #endif

    int n = 0;
    scanf("%d", &n);
    char str[10][31];
    for (int i = 0; i < n; i++)
        scanf("%s", str[i]);
    for (int i = 0; i < n; i++)
    {
        const char *charPtr = &str[i][0];
        while (*charPtr != '\0')
        {
            if (isalpha(*charPtr))
                putchar(*charPtr);
            charPtr++;
        }
        putchar('\n');

    }

    #ifdef DEBUG
        const clock_t end = clock();
        const double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time: %.9f", totalTime);
    #endif
    return 0;
}

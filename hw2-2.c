#include <stdio.h>
#include <time.h>

int main()
{
#ifdef DEBUG
    clock_t begin = clock();
#endif
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int isStart = 0;
        int arr[10000];
        int back = -1;
        int head = 0;

        do
        {
            char input = getchar();
            if (input == ' ' || input == '\n')
                input = getchar();
            if (input == 'S' || input == 's')
                isStart = 1;
            else if (input == 'X' || input == 'x')
                isStart = 0;
            else if (input == 'E' || input == 'e')
                scanf("%d", &arr[++back]);
            else if (input == 'D' || input == 'd')
                head++;
        } while (isStart);

        for (int j = head; j <= back; j++) {
            putchar(arr[j] + '0');
        }
        putchar('\n');
    }

#ifdef DEBUG
    clock_t end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %.9f", totalTime);
#endif
    return 0;
}

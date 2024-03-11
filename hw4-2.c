//5.21
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int isRepeated(int sum, int ansCount, int *checkArr){
    for (int i = 0; i < ansCount; i++)
    {
        if (sum == checkArr[i])
            return 1;
    }
    return 0;
}

// int fact(int n){
//     if (n <= 2 && n != 0)
//         return n;
//     if (n == 0)
//         return 1;
    
//     return n * fact(n-1);
// }

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int arr[n][2]; //[num, q1]
        int validCount = 0;
        for (int j = 0; j < n; j++){
            int input;
            scanf("%d", &input);
            if (m % input == 0)
            {
                if (input != 0) {
                    arr[j][0] = input;
                    arr[j][1] = m / input;
                    validCount++;
                } else if (input == 0 && m == 0){
                    arr[j][0] = input;
                    arr[j][1] = 0;
                    validCount++;
                }
            }
        }

        int ansCount = 0;
        if (m == 0)
        {
            int *ansCheckArr;
            ansCheckArr = malloc(sizeof(int) * 100000);
            for (int x = 0; x < validCount - 2; x++)
            {
                for (int y = 1; y < validCount - 1; y++)
                {
                    for (int z = 2; z < validCount; z++)
                    {
                        if (arr[x][0] * arr[y][0] * arr[z][0] == m){
                            if (isRepeated(x + y + z, ansCount, ansCheckArr))
                                continue;
                            else
                                ansCheckArr[ansCount++] = x + y + z;
                        }
                    }
                }
            }
            free(ansCheckArr);
            printf("%d\n", ansCount);
            return 0;
        }
        
        int modArr[validCount][validCount];
        for (int j = 0; j < validCount; j++)
        {
            for (int k = j + 1; k < validCount; k++)
            {
                if (arr[j][1] % arr[k][0] == 0) // arr[j].q1 divisible by arr[k]
                {
                    modArr[j][k] = arr[k][0];
                }
                else
                {
                    modArr[j][k] = -1;
                }
            }
        }

        int q2[validCount][validCount];
        for (int j = 0; j < validCount; j++)
        {
            for (int k = 0; k < validCount; k++)
            {
                if (modArr[j][k] != -1)
                {
                    q2[j][k] = arr[j][1] / modArr[j][k];
                }
            }
        }

        for (int j = 0; j < validCount; j++)
        {
            for (int k = 0; k < validCount; k++)
            {
                if (q2[j][k] == arr[j][0])
                {
                    ansCount++;
                }
            }
        }

        for (int j = 0; j < validCount; j++)
        {
            for (int k = 0; k < validCount; k++)
            {
                if (arr[j][1] == q2[j][k])
                {
                    ansCount--;
                }
            }
            ansCount++;
        }
        
        printf("%d\n", ansCount);
        
    }
    

#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

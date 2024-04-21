//6.13
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    
    int cases;
    scanf("%d", &cases);
    int sizeof_m;
    int sizeof_n;
    for (int i = 0; i < cases; i++)
    {
        scanf("%d%d", &sizeof_m, &sizeof_n);
        int arrM[sizeof_m + 1];
        int arrN[sizeof_n + 1];
        
        for(int i = 0; i < sizeof_m; i++){
            scanf("%d", &arrM[i]);
        }
        arrM[sizeof_m] = 99999;
        for (int i = 0; i < sizeof_n; i++)
        {
            scanf("%d", &arrN[i]);
        }
        arrN[sizeof_n] = 99999;

        double numReturn;
        if ((sizeof_m + sizeof_n) % 2 == 0) //even number count
        {
            int num1, num2;
            int count = (sizeof_m + sizeof_n) / 2;
            int i = 0;
            int j = 0;
            while (count-- > 0)
            {
                if (arrM[i] < arrN[j])
                {
                    num1 = arrM[i];
                    i++;
                }
                else
                {
                    num1 = arrN[j];
                    j++;
                }
            }
            if (arrM[i] < arrN[j])
                num2 = arrM[i];
            else
                num2 = arrN[j];
            numReturn = (num1 + num2) / 2.0;
        } else { //odd number count
            int count = (sizeof_m + sizeof_n) / 2 + 1;
            int i = 0;
            int j = 0;
            while (count-- > 0)
            {
                if (arrM[i] < arrN[j])
                {
                    numReturn = arrM[i];
                    i++;
                } else {
                    numReturn = arrN[j];
                    j++;
                }
            }
        }
        
        printf("%.1f\n", numReturn);
    }
    
#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

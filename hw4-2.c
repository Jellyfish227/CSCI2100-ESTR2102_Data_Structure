// 5.21
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cell
{
    int thisPos;
    struct cell *nextCell;
};

int hashFunc(int num)
{
    return num % 10000;
}

void creatMap(struct cell *map[], struct cell *hash, int data)
{
    if (map[hashFunc(data)] == NULL) // not initialized
    {
        map[hashFunc(data)] = hash; // store address of element in hash array
    }
    else
    {
        hash->nextCell = map[hashFunc(data)]; // store the original cell location to nextCell
        map[hashFunc(data)] = hash;           // store the head as address of new element
    }
}

int find(int arrOut[], struct cell *map[], int k, int start)
{
    int count = 0;
    struct cell thisCell;
    if (map[hashFunc(k)] != NULL) // the number exist
    {
        thisCell = *map[hashFunc(k)]; // dereference the head into cell
        if (thisCell.thisPos > start + 1)
        {
            arrOut[count++] = thisCell.thisPos;
        }
        struct cell *next = NULL;
        if (thisCell.nextCell != NULL)
        {
            next = thisCell.nextCell;
        }

        while (next != NULL)
        {
            struct cell nextC = *next;
            if (nextC.thisPos > start)
            {
                arrOut[count++] = nextC.thisPos;
            }
            if (nextC.nextCell != NULL)
            {
                next = nextC.nextCell;
            }
        }
    }

    return count;
}

int main()
{
#ifdef DEBUG
    clock_t const begin = clock();
#endif

    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++)
    {
        int n, target;
        scanf("%d%d", &n, &target);
        int arr[n];
        struct cell *hash = malloc(sizeof(struct cell) * n);
        struct cell *hashPtr = hash;
        struct cell *hashMap[10000] = {[0 ... 9999] = NULL};
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
            hashPtr->thisPos = j + 1;
            hashPtr->nextCell = NULL;
            creatMap(hashMap, hashPtr, arr[j]);
            hashPtr++;
        }

        int count = 0;
        for (int a = 0; a < n - 2; a++)
        {
            for (int b = a + 1; b < n - 1; b++)
            {
                if (target == 0)
                {
                    for (int x = b + 1; x < n; x++)
                    {
                        if (arr[x] == 0 || arr[a] == 0 || arr[b] == 0)
                        {
                            count++;
                        }
                    }
                }
                else
                {
                    int arrFind[10];
                    int resultCnt;
                    if ((arr[a] * arr[b] <= target) && (arr[a] != 0 && arr[b] != 0) && (target % (arr[a] * arr[b]) == 0))
                    {
                        int c = target / arr[a] / arr[b];
                        resultCnt = find(arrFind, hashMap, c, b);
                        for (int t = 0; t < resultCnt; t++)
                        {
                            if (arr[arrFind[t] - 1] == c)
                            {
                                count++;
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n", count);
    }

#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

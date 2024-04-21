// 7.12
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
#ifdef DEBUG
    clock_t const begin = clock();
#endif
    const int SETA = 1;
    const int SETB = -1;
    int cases;
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++)
    {
        int nodes = 0;
        scanf("%d", &nodes);
        int nodeList[101] = {[0 ... 100] = 0};
        int isSetA = 0;
        int isBipartite = 1;
        while (1)
        {
            int input1;
            scanf("%d", &input1);
            if (input1 == -1)
                break;
            int input2;
            scanf("%d", &input2);

            //initialize unvisited node
            if (nodeList[input1] == 0 && nodeList[input2] == 0) {
                nodeList[input1] = SETA;
                nodeList[input2] = SETB;
            } else if (nodeList[input1] == 0) {
                // input2 visited, initialize input1
                nodeList[input1] = (nodeList[input2] == SETA ? SETB : SETA);
            }
            else if (nodeList[input2] == 0) {
                // input1 visited, initialize input2
                nodeList[input2] = (nodeList[input1] == SETA ? SETB : SETA);
            }

            // printf("%d %d\n", nodeList[input1], nodeList[input2]);

            if (nodeList[input1] == nodeList[input2]) {
                // collide setA, not bipartite
                isBipartite = 0;
                // break;
            }
        } //endofwhile
        
        printf("%s\n", isBipartite ? "YES" : "NO");
    }

#ifdef DEBUG
    clock_t const end = clock();
    double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime: %.9f", totalTime);
#endif
    return 0;
}

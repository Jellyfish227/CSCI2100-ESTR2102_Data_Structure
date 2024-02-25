#include <stdio.h>
#include <time.h>

int max(int num1, int num2) {
    return num1 > num2 ? num1 : num2;
}

int min(int num1, int num2) {
    return num1 < num2 ? num1 : num2;
}

int level, egg;
int status[120][209] = {0};

int optimum(int level, int egg) {
    status[level][egg]=1000000;
    for (int i = 1; i <= level; i++) {
        status[level][egg] = min(status[level][egg],max(optimum(i - 1, egg - 1),    //egg broken, test level - 1 level
                                optimum(level - 1, egg))+1);       //egg not broken, test level - i level
    }
    if (level == 0) {
        
    }
    if (egg == 0) {

    }
    return status[level][egg];
}

int main(){
    #ifdef DEBUG
        const clock_t begin = clock();
    #endif

    scanf("%d%d", level, egg);
    printf("%d", optimum(level,egg));

    #ifdef DEBUG
        const clock_t end = clock();
        const double totalTime = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("Time: %.9f", totalTime);
    #endif
    return 0;
}
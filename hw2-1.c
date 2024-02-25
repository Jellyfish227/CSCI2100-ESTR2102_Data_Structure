#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * decodeString(char * s){
    int numStk[334];
    int numTop = -1;
    char chStk[30000];
    int chTop= -1; int num = 0;

    char* strCur = s;
    while (*strCur) {
        if (*strCur >= '0' && *strCur <= '9') {
            num = num * 10 + (*strCur - '0');
        }
        else if (*strCur == '('){
            numStk[++numTop] = num;
            num = 0;
            chStk[++chTop] = *strCur;
        }
        else if (*strCur==')') {
            int times = numStk[numTop--];
            char temp[30000];
            char* tempCur = temp;
            while (chStk[chTop] != '(') {
                *tempCur++ = chStk[chTop--];
            }
            chTop--;
            while (times--) {
                for (char* k = tempCur - 1; k >= temp; k--)
                    chStk[++chTop] = *k;
            }
        }
        else {
            chStk[++chTop] = *strCur;
        }
        strCur++;
    }
    chStk[++chTop] = '\0';
    char *result = (char*)malloc(chTop + 1);
    strcpy(result,chStk);
    return result;
}

int main()
{
    int m;
    scanf("%d\n", &m);
    char str[m][10001];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", str[i]);
    }
    for (int i = 0; i < m; i++)
    {
        printf("%s\n", decodeString(str[i]));
    }

    return 0;
}


/* 1 5
 * 1 pop1 3 5
 *
 */
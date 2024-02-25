// C implementation of code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
int main()
{
	int m;
	scanf("%d", &m);
	int *s = malloc(m * sizeof(int));
	int *p = s;
	for (int i = 0; i < m; i++) {
 		scanf("%d", p++);
 	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", *s++);
	}
	free(s);
}

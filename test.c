// C implementation of code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(int arr[], int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

// Driver code
int main()
{
	int arr[3] = {1,2,3};
	int a = 0;
	int b = 2;
	swap(arr, a, b);
	printf("%d %d %d", arr[0], arr[1], arr[2]);

}

// C implementation of code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(int *left, int *right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// Driver code
int main()
{
	int arr[3] = {1,2,3};
	int idx = 1;
	int left = idx << 1;
	int right = (idx << 1) + 1;
	int *root = &arr[idx - 1];
	swap(root, &arr[right - 1]);
	printf("%d %d %d", arr[0], arr[1], arr[2]);

}

#include <stdio.h>
int main(void)
{
	int a,b;
	printf("Donnez deux nombres entiers : ");
	scanf("%d%d", &a, &b);
	printf("a/b = %lf", (double) a/b);
	return 0;
}


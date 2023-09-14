#include <stdio.h>
int main(void)
{
	int a,b,c,temp;
	a =1;
	b =2;
	c =3;
	temp = a;
	a = c;
	c = b;
	b = temp;
	printf("a,b,c = %d/%d/%d", a,b,c);
	return 0;
}


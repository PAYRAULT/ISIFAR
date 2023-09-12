#include <stdio.h>
int main(void)
{
	float x;
	int i;
	printf("Entrer un nombre réel : ");
	scanf("%f",&x);
	printf("le nombre est %f\n",x);
	i=x;
	printf("Sa conversion en int est %d\n",i);
	return 0;
}

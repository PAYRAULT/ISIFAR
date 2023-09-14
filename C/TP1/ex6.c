#include <stdio.h>
#include<math.h>
int main(void)
{
	double a,b,x,y;
	double m;
	a = 1;
	b = 0;
	m = sqrt(pow(a,2)+pow(b,2));
	x = sqrt((m+a)/2);
	y = sqrt((m-a)/2);
	if(x*y*b < 0)
		y = -y;
	printf("Racines carrees : %lf + i(%lf) et %lf + i(%lf)", x,y,-x,-y);
	return 0;

}

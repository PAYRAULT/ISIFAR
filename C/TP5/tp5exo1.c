#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void echange_faux(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}

void echange(int* p_a, int* p_b){

    int temp = *p_a;
    *p_a = *p_b;
    *p_b = temp;
}

int main(void){
int n = 0, m = 1;
printf("n=%d, m=%d\n", n, m);
echange_faux(n, m);
printf("Apres l’appel echange_faux(n,m), n=%d, m=%d\n", n, m);
echange(&n, &m);
printf("Apres l’appel echange(&n,&m), n=%d, m=%d\n", n, m);
return 0;
}
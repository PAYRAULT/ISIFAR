#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void prime_list(int l[], int n);

void prime_list(int l[], int n) {

    int size = 1000; 
    // int size = int(1.5 * n / log(n)) + 1;
    int p[size]; //tableau de bool´eens de taille size
 
    int i, j;
    // Initialiser les cellules de p `a Vrai
    for(i = 0; i < size; i++) {
        p[i] = 1;
    }
 
    //Initialiser les cellules de p d’indice pair != 2 `a Faux
    for(i = 0; i < size; i = i+2) {
        if(i != 2) {
            p[i] = 0;
        }
    }

    // Initialiser p[1] `a Faux
    p[1] = 0;

    i = 3;
    //Tant que i*i <= size
    while(i*i <= size) {
        if(p[i] == 1) {
            // Pour j de i*i `a size-1 par pas de 2*i
            for(j = i*i; j < size-1; j = j+2*i) {
                p[j] = 0;
            }
            //Fin pour
        }
        //Fin si
        i = i+2;
    }
    // Fin tant que

    // stocker dans le tableau l les n plus petits entiers premiers `a l’aide du tableau p
    int c = 0;
    for(i=2; i < size; i++) {
        if(p[i]) {
            if( c < n) {
                l[c] = i;
                c++;
            }
        }
    }
}


int main() {
    int n = 100;
    int l[n];
    int i;

    prime_list(l, n);

    for(i = 0; i < n; i++) {
        printf("%d ", l[i]);
    }

    return 0;
}

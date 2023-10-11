#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define ull unsigned long long int

ull factoriel(int n){
    ull fact;
    if(n<=1){
        return (ull)1;
    }
    else{
        fact = (ull)n*factoriel(n-1);
        return fact;
    }
}

ull binomial1(int n,int p){
    if(p>n){
        return (ull)0;
    }
    else{
        return factoriel(n)/(factoriel(p)*factoriel(n-p));
    }
}

ull binomial2(int n, int p){
    if(p == 0 || n == p){
        return (ull)1;
    }
    else if(n == 1) {
        return n;
    }
    else{
        return binomial2(n-1,p) + binomial2(n-1,p-1);
    }
}

ull binomial3(int n, int p){
    ull tab[n+1][p+1];

    for(int i = 0; i<=n; i++) {
        tab[i][0] = (ull)1;
        for(int j = 0; j<=i && j<=p; j++) {
            if(j==i || j==0){
                tab[i][j] = (ull)1;
            }
            else{
                tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
            }
        }

    } 
    return tab[n][p];
}


int main() {
    int choix;
    int n;
    int p;
    double d;
    clock_t t1, t2;
    ull res; 
    do {
        printf("Calcul de binomial(n,p): \n -1: avec les factoriels\n -2: récursif \n -3: itératif avec un tableau \n -0: quitter \n");
        scanf("%d", &choix);
        if(choix == 0) {
            return 0;
        }
        printf("Entrez un nombre n: ");
        scanf("%d",&n);
        printf("Entrez un nombre p inférieur à n: ");
        scanf("%d",&p);
        switch(choix) {
            case 1:
                t1 = clock();
                res = binomial1(n,p);
                t2 = clock();
                d = (double)(t2-t1)/CLOCKS_PER_SEC;
                printf("Calcul avec les factoriel: %llu, temps d'execution : %lf \n", res, d);
                break;
            case 2:
                t1 = clock();
                res = binomial2(n,p);
                t2 = clock();
                d = (double)(t2-t1)/CLOCKS_PER_SEC;
                printf("Calcul récursif: %llu, temps d'execution: %lf \n",res, d);
                break;
            case 3:
                t1 = clock();
                res = binomial3(n,p);
                t2 = clock();
                d = (double)(t2-t1)/CLOCKS_PER_SEC;
            printf("Calcul itératif avec un tableau: %llu, temps d'execution: %lf \n", res, d);
                break;
            default:
                printf("Erreur de saisie \n");
        } 
    } while(choix); 

  return 0;
}


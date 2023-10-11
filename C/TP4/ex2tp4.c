#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define L 8
#define C 11


void affiche(int m[][C]){
    for(int i = 0; i<L;i++){
        for(int j = 0; j<C;j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    
}

int  inf_rec(int m[][C], int a, int b, int k) {

        // fin du tableau m
        if(k == C) {
            return 0;
        }

        // Le k caractere est inferieur, donc a < b 
        if(m[a][k]< m[b][k]){
            return 1;
        }

        // Le k caractere est superieur, donc a > b 
        if(m[a][k] > m[b][k]){
            return 0;
        }
        // Le k caratere est egale, donc tester le caractere suivant
        else{
            k = k+1;
            return inf_rec(m,a,b,k);
        }

    return 0;
}

void tri_lex2(int m[][C]){
    int echange;
    int fin;
    int t;
    echange = 1;
    fin = L - 1;

    while(echange == 1) {
        echange =0;
        for(int i = 0; i< fin; i++){
                if(inf_rec(m,i,i+1,0)==1) {
                    for(int j = 0; j < C; j++) {
                        t = m[i][j];
                        m[i][j] = m[i+1][j];
                        m[i+1][j] = t;
                        
                    }

                    echange =1;
                }
        }
        fin--;
    }
}


int main(void) {
	int M[L][C];
    int i,j;
	for(i=0; i<L;i++){
        for(j=0; j<C; j++){
            M[i][j] = ((i*i+j)*i*j)%(C+L) - (C+L)/2;
        }
    }

    printf("Tableau de base : \n");
    affiche(M);
    printf("Talbeau tri_lex2 :\n");
    tri_lex2(M);
    affiche(M);

    return 0;
}
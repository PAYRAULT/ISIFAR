#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define L 8
#define C 11

void affiche(int m[][C]);
int nb_pair(int m[][C]);
int lignes_avec_v(int m[][C], int v);
int colonne_max(int m[][C]);
void tri_c(int m[][C], int k);
void tri_lex(int m[][C]);
int inf(int m[][C], int a, int b);

int main(void){
	int M[L][C];
    int i,j;
    int v = 1;

	for(i=0; i<L;i++){
        for(j=0; j<C; j++){
            M[i][j] = ((i*i+j)*i*j)%(C+L) - (C+L)/2;
        }
    }

    affiche(M);
    printf("nb_pair(M) = %d\n", nb_pair(M));
    printf("lignes_avec_1 = %d\n", lignes_avec_v(M,v));
    printf("Colone_max = %d\n", colonne_max(M));

    for(i = 0; i < L-1; i++) {
        printf("inf(M,%d,%d) = %d\n", i, i+1, inf(M, i, i+1));
    }

    tri_c(M, 3);
    affiche(M);

    for(i = 0; i < L-1; i++) {
        printf("inf(M,%d,%d) = %d\n", i, i+1, inf(M, i, i+1));
    }

    tri_lex(M);
    affiche(M);
    for(i = 0; i < L-1; i++) {
        printf("inf(M,%d,%d) = %d\n", i, i+1, inf(M, i, i+1));
    }

    return 0;
}

void affiche(int m[][C]){
    for(int i = 0; i<L;i++){
        for(int j = 0; j<C;j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    
}

int nb_pair(int m[][C]){
    int a = 0;
    for(int i = 0; i<L;i++){
        for(int j = 0; j<C;j++){
            if (m[i][j]%2 == 0) {
                a++;
            }   
        }
    }
    return a;
}

int lignes_avec_v(int m[][C], int v){
    int a = 0;
    for(int i = 0; i<L;i++){
        for(int j = 0; j<C;j++){
            if(m[i][j] == v){
                a++;
                break;
            }
        }
    }
    return a;
}

int colonne_max(int m[][C]){
    int s;
    int max_co = 0;
    int j_max_co = 0;
    //faire la somme de la premiere colonne
    for(int i = 0; i<L;i++){
        for(int j = 0; j<C;j++){
            if(m[i][j]>max_co) {
                max_co = m[i][j];
                j_max_co = j;
            }
        }
    }
    return j_max_co;
}

void tri_c(int m[][C], int k) {
    int echange = 1;
    int fin = L - 1;
    int i, j, t;
 
    while(echange == 1) {
        echange = 0;
        for(i = 0; i < fin; i++) {
            if(m[i][k] > m[i+1][k]) {
                // Echange des 2 lignes
                for(j = 0; j < C; j++) {
                    t = m[i][j];
                    m[i][j] = m[i+1][j];
                    m[i+1][j] = t; 
                }

                echange = 1;
            }
        }
        fin--;
    }
}


void tri_lex(int m[][C]) {
    int echange = 1;
    int fin = L - 1;
    int i, j, t;
 
    while(echange == 1) {
        echange = 0;
        for(i = 0; i < fin; i++) {
            if(inf(m,i+1,i)) {
                // Echange des 2 lignes
                for(j = 0; j < C; j++) {
                    t = m[i][j];
                    m[i][j] = m[i+1][j];
                    m[i+1][j] = t; 
                }

                echange = 1;
            }
        }
        fin--;
    }
}


int inf(int m[][C], int a, int b){
    int j;
    int inferieur = 0;
    for(j = 0; j < C; j++) {
        if(m[a][j] > m[b][j]) {
            inferieur = 0;
            break;
        }
        else if (m[a][j] < m[b][j]) {
            inferieur = 1;
            break;
        }
    }
    return inferieur;
}



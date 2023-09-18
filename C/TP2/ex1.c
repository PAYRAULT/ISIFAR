/*
 * @version 1.0
 * @author Bertrand Gentou <bertrand.gentou@u-paris.fr>
 *
 * random generation of an integer array,
 * display of an integer array,
 *
 * @param : none
 *
 * @returns : {boolean} 0 if no error occurs
 *
 * @requires : standard library stdio.h, stdlib.h, time.h
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

/**** Prototypes des fonctions *****************/
void initialiser_aleatoire_tableau(int [],int,int,int);
void afficher_tableau(int [],int);
void tri_selection(int[],int);
void tri_insertion(int[], int);
void tri_shell(int[], int);


/**** Fonction main ****************************/
int main(void)
{
   int size, n_min, n_max;

   printf("Saisir la longueur du tableau : ");
   scanf("%d", &size);
   int tab[size];

   printf("Saisir les bornes du tirage aléatoire : ");
   scanf("%d%d", &n_min, &n_max);

   printf("Le tableau aléatoire est :\n\n");
   afficher_tableau(tab,size);
   printf("\n");

   /* ex2 */
   initialiser_aleatoire_tableau(tab,size,n_min,n_max);
   printf("Le tableau aléatoire est :\n\n");
   afficher_tableau(tab,size);
   printf("\n");

   clock_t t;
   double el1;
   t = clock();
   tri_insertion(tab, size);
   t = clock() - t;
   el1 = ((double) t)/CLOCKS_PER_SEC;

   printf("tri par insertion :\n\n");
   afficher_tableau(tab,size);
   printf("\n");

   /* ex3 */
   initialiser_aleatoire_tableau(tab,size,n_min,n_max);
   double el2;
   t = clock();
   tri_shell(tab, size);
   t = clock() - t;
   el2 = ((double) t)/CLOCKS_PER_SEC;

   printf("tri shell :\n\n");
   afficher_tableau(tab,size);
   printf("\n");

   printf("Temps tri par insertion : %f\n", el1);
   printf("Temps tri shell : %f\n", el2);

   return 0;
}

/**** Fonction initialiser_aleatoire_tableau *****/
void initialiser_aleatoire_tableau(int t[],int s,int n_min,int n_max)
{
   srand (time (NULL));
   for (int i=0;i<s;i++){
       t[i]=n_min + rand() % (n_max-n_min+1);
   }
}

/**** Fonction afficher_tableau *****************/
void afficher_tableau(int t[],int s)
{
   for(int i=0; i<s; i++)
      printf("%d\t", t[i]);
   printf("\n\n"); //retour a la ligne + un saut de ligne
}

void tri_insertion(int t[], int s) {
    int i, j, temp;

    for(i = 1; i <= s-1; i++) {
        temp = t[i];
        j = i - 1;
        while( j >= 0 && t[j] > temp) {
            t[j+1] = t[j];
            j--;
        }
        t[j+1] = temp;
    }
}

void tri_shell(int t[], int s) {
    int h, i, temp, j;
    h = (int)(2 * s / 3);
    while(h >= 1) {
        for(i = h; i <= s-1; i++) {
            temp = t[i];
            j = i;
            while(j >= h && t[j-h] > temp) {
                t[j] = t[j-h];
                j = j - h;
            }
            t[j] = temp;
        }
        if(h == 2) {
            h = 1;
        }
        else {
            h = floor(h / 2.3);
        }
    }
}

/*
 * @version 1.0
 * @author Bertrand Gentou <bertrand.gentou@u-paris.fr>
 * TP9: lecture donnée par donnée dans un fichier texte
 * @param : none
 * @returns : {boolean} 0 if no error occurs
 * @requires : standard libraries stdio.h and stdlib.h
 *  Created by by Bertrand GENTOU on 11/11/2020.
*  Copyright © 2020 Bertrand GENTOU. All rights reserved.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define L_LINE_MAX 100
#define L_NAME_MAX 25
#define DELIM ";"

typedef struct data_st
{
   int numero_produit;
   char nom_produit[L_NAME_MAX];
   double prix_produit;
} data_t;


typedef struct{
    int len;
    data_t tab[L_LINE_MAX];
}liste_t;


// Reprise du TP5
void initialize_list(liste_t *p_l){
    p_l->len = 0;
}

void print_list(liste_t l){
    if(l.len == 0) {
        printf("liste vide\n");
    }
    else {
        for(int i=0; i<l.len; i++){
            printf("%i;%s;%lf\n",l.tab[i].numero_produit, l.tab[i].nom_produit, l.tab[i].prix_produit);
        }
        printf("\n");
    }
}

void append(liste_t *p_l, data_t d) {
    /* verifier qu'il existe au moins une place de libre */
    if(p_l->len < L_LINE_MAX) {
        /* Ajouter la valeur d a la fin et incrementer la longueur de la liste */
        p_l->tab[p_l->len].numero_produit = d.numero_produit;
        strcpy(p_l->tab[p_l->len].nom_produit, d.nom_produit);
        p_l->tab[p_l->len].prix_produit = d.prix_produit;
        p_l->len += 1;
    }
    /* Sinon ne rien faire */
    return;
}


int read_data_file(liste_t *P1, char *nom_fichier)
{
   char line[L_LINE_MAX];

   // Ouverture du fichier
   FILE *entree=fopen(nom_fichier, "r");
   if (entree == NULL) {
        fprintf(stderr,"Erreur d'ouverture en lecture du fichier %s\n", nom_fichier);
        exit(2);
   }

   while(fgets(line, L_LINE_MAX, entree) != NULL) {
      data_t d;
      char *token = strtok(line, DELIM);
      sscanf(token, "%d", &d.numero_produit); // conversion d'un string en entier

      token = strtok(NULL,DELIM);
      strcpy(d.nom_produit, token); // copie d'un string dans un autre

      token = strtok(NULL, DELIM);
      sscanf(token, "%lf", &d.prix_produit); // conversion d'un string en double

      // Ajouter la ligne a P1
      append(P1, d);
   }

   // Fermeture du fichier
   fclose(entree);

   return 1;
}

data_t *search(liste_t *Pl, int n) {
    for(int i=0; i<Pl->len; i++){
        if(Pl->tab[i].numero_produit == n) {
            return &(Pl->tab[i]);
        }
    }
    return NULL;
}

int suppress(liste_t *Pl, int n) {
    for(int i=0; i<Pl->len; i++){
        if(Pl->tab[i].numero_produit == n) {
            // decaler les valeurs dans le tableau
            for(int j = i; j<Pl->len; j++) {
               Pl->tab[j].numero_produit = Pl->tab[j+1].numero_produit;
               strcpy(Pl->tab[j].nom_produit, Pl->tab[j+1].nom_produit);
               Pl->tab[j].prix_produit = Pl->tab[j+1].prix_produit;
            }
            Pl->len -= 1;
            return 1;
        }
    }
    return 0;
}


int write_data_file(liste_t *Pl, char *nom_fichier) {
   // Ouverture du fichier
   FILE *entree=fopen(nom_fichier, "w");
   if (entree == NULL) {
        fprintf(stderr,"Erreur d'ouverture en lecture du fichier %s\n", nom_fichier);
        exit(2);
   }

   // Ecrire les lignes dans le fichier 
   for(int i =0; i <Pl->len; i++) {
      fprintf(entree, "%i;%s;%.2lf\n",Pl->tab[i].numero_produit, Pl->tab[i].nom_produit, Pl->tab[i].prix_produit);
   }

   //Fermeture du cfichier
   fclose(entree);

}

int main(void)
{
   data_t *d;
   liste_t Pl;
   // Initialisation de la liste
   initialize_list(&Pl);

   read_data_file(&Pl, "fichier2.txt");

   print_list(Pl);

   // Test de search
   int i;
   i = 77;
   d = search(&Pl, i);
   if(d == NULL) {
      printf("numero produit %d pas trouve\n", i);
   }
   else {
      printf("%i;%s;%lf\n",d->numero_produit, d->nom_produit, d->prix_produit);      
   }

   i = 856;
   d = search(&Pl, i);
   if(d == NULL) {
      printf("numero produit %d pas trouve\n", i);
   }
   else {
      printf("%i;%s;%lf\n",d->numero_produit, d->nom_produit, d->prix_produit);      
   }

   // Test de suppress
   int s;
   i = 77;
   s = suppress(&Pl, i);
   if(s == 0) {
      printf("numero produit %d pas trouve\n", i);
   }
   else {
      print_list(Pl);
   }

   i = 856;
   s = suppress(&Pl, i);
   if(s == 0) {
      printf("numero produit %d pas trouve\n", i);
   }
   else {
      print_list(Pl);
   }


   // Test add
   data_t d1;
   d1.numero_produit = 57;
   strcpy(d1.nom_produit, "Pomme de terre");
   d1.prix_produit = 2.54;
   append(&Pl, d1);

   // Test de write_data_file
   write_data_file(&Pl, "fichier4.txt");

   return 0;
}

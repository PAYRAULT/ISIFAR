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

typedef struct data_liste_st 
{
    data_t line;
    struct data_liste_st *next; 
} data_liste_t;

typedef struct liste_st 
{
    data_liste_t *debut; 
    data_liste_t *fin; 
} liste_t;


void initialize_list(liste_t *P) {
    P->debut = NULL;
    P->fin = NULL;
}

void print_list(liste_t *P){
    if(P->debut == NULL) {
        printf("Liste vide\n");
    }
    else {
        data_liste_t *L;
        L = P->debut;
        while(L != NULL){
            printf("%i;%s;%lf\n",L->line.numero_produit, L->line.nom_produit, L->line.prix_produit);
            L = L->next;
        }
        printf("\n");
    }
}

void append(liste_t *Pl, data_t d) {
    data_liste_t *L;

    // Creer une nouvelle ligne
    L = (data_liste_t*)malloc(sizeof(data_liste_t));

    // Remplir la nouvelle ligne
    L->line.numero_produit = d.numero_produit;
    strcpy(L->line.nom_produit, d.nom_produit);
    L->line.prix_produit = d.prix_produit;
    L-> next = NULL;

    if(Pl->debut == NULL) {
        // Ajouter premier de la liste
        Pl->debut = L;
        Pl->fin = L;
    }
    else {
        // Ajouter en fin de liste
        Pl->fin->next = L;
        Pl->fin = L;
    }
}

int read_data_file(liste_t *Pl, char *nom_fichier)
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

      // Ajouter la ligne a Pl
      append(Pl, d);
   }

   // Fermeture du fichier
   fclose(entree);

   return 1;
}

data_t* search(liste_t *Pl, int n) {
    data_liste_t *L;
    L = Pl->debut;
    while(L != NULL){
        if(L->line.numero_produit == n) {
            return &(L->line);
        }
        L = L->next;
    }
    return NULL;
}


int suppress(liste_t *Pl, int n) {
    data_liste_t *L1, *L2;
    L1 = Pl->debut;
    L2 = NULL;
    while(L1 != NULL){
        if(L1->line.numero_produit == n) {
            if(L1 == Pl->debut) {
                // C'est le premiere element
                Pl->debut = Pl->debut->next;
            }
            else if(L1 == Pl->fin) {
                // C'est le dernier element
                L2->next = NULL;
                Pl->fin = L2;
            }
            else {
                // Supprimer L1
                L2->next = L1->next;
            }
            // Liberer la memoire
            free(L1);
            return 1;
        }
        L2 = L1;
        L1 = L1->next;
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
    data_liste_t *L;
    L = Pl->debut;
    while(L != NULL) {
        fprintf(entree, "%i;%s;%.2lf\n",L->line.numero_produit, L->line.nom_produit, L->line.prix_produit);
        L = L->next;
    }

    //Fermeture du fichier
    fclose(entree);
}


int main(void)
{
    data_t *d;
    liste_t Pl;
    // Initialisation de la liste
    initialize_list(&Pl);

    read_data_file(&Pl, "fichier2.txt");

    print_list(&Pl);

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
        print_list(&Pl);
    }

    // Test de suppress
    i = 229;
    s = suppress(&Pl, i);
    if(s == 0) {
        printf("numero produit %d pas trouve\n", i);
    }
    else {
        print_list(&Pl);
    }

    // Test de suppress
    i = 69;
    s = suppress(&Pl, i);
    if(s == 0) {
        printf("numero produit %d pas trouve\n", i);
    }
    else {
        print_list(&Pl);
    }

    i = 856;
    s = suppress(&Pl, i);
    if(s == 0) {
        printf("numero produit %d pas trouve\n", i);
    }
    else {
        print_list(&Pl);
    }


    // Test add
    data_t d1;
    d1.numero_produit = 57;
    strcpy(d1.nom_produit, "Pomme de terre");
    d1.prix_produit = 2.54;
    append(&Pl, d1);

    // Sauvegarder dans le fichier
    write_data_file(&Pl, "fichier4.txt");

   return 0;
}

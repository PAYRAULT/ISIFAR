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
   int key;
   char name[L_NAME_MAX];
   double value;
}data_t;

int main(void)
{
   data_t d;
   char line[L_LINE_MAX];

   // Ouverture du fichier
   char nom_fichier[]= "fichier2.txt";
   FILE *entree=fopen(nom_fichier, "r");
   if (entree == NULL) {
        fprintf(stderr,"Erreur d'ouverture en lecture du fichier %s\n", nom_fichier);
        exit(2);
   }

   while(fgets(line, L_LINE_MAX, entree) != NULL) {
      char *token = strtok(line, DELIM);

      sscanf(token, "%d", &d.key); // conversion d'un string en entier
      token = strtok(NULL,DELIM);

      strcpy(d.name, token); // copie d'un string dans un autre
      token = strtok(NULL, DELIM);

      sscanf(token, "%lf", &d.value); // conversion d'un string en double
      printf("%i;%s;%lf\n",d.key,d.name,d.value);
   }

   // Fermeture du fichier
   fclose(entree);

   return 0;
}

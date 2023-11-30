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
#include<string.h>
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
   char input[] = "10;truc;10.1";
   data_t d;
   char *token = strtok(input, DELIM);
   sscanf(token, "%d", &d.key); // conversion d'un string en entier
   token = strtok(NULL,DELIM);
   strcpy(d.name, token); // copie d'un string dans un autre
   token = strtok(NULL, DELIM);
   sscanf(token, "%lf", &d.value); // conversion d'un string en double
   printf("%i;%s;%lf\n",d.key,d.name,d.value);
   return 0;
}

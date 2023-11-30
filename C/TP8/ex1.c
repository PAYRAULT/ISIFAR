/*
 * @version 1.1
 * @author Bertrand Gentou <bertrand.gentou@u-paris.fr>
 * TP9: lecture donnee par donnee dans un fichier texte
 * @param : path of file to read
 * @returns : {boolean} 0 if no error occurs
 * @requires : standard libraries stdio.h and stdlib.h
 *  Created by by Bertrand GENTOU on 11/11/2020, modified on 25/11/2023.
*  Copyright  2020 Bertrand GENTOU. All rights reserved.
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char nom_fichier[]= "fichier1.txt";
    FILE *entree=fopen(nom_fichier, "r");
    if (entree==NULL)
    {
        fprintf(stderr,"Erreur d'ouverture en lecture du fichier %s\n", nom_fichier);
        exit(2);
    }

    int l;
    //la valeur de retour de fscanf est egale au nombre de valeurs lues
    if(fscanf(entree, "%d", &l) !=1)
    {
        fprintf(stderr,"Erreur de format de fichier\n");
   	    exit(3);
    }
    int* tab = (int*)calloc(l,sizeof(int));
    if (tab == NULL)
    {
        fprintf(stderr, "Erreur d'allocation\n");
        exit(4);
    }
    int i = 0;
    do
        fscanf(entree, "%d", &tab[i++] );
    while (!feof(entree) && i<l );

    fclose(entree);

    for(int i=0;i<l;i++)
   	    printf("%d\t",tab[i]);
    printf("\n");
    return 0;
}

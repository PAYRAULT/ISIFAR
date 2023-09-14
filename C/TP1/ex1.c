/*
 * @version 1.0
 * @author Bertrand Gentou <bertrand.gentou@u-paris.fr>
 *
 * types and conversions
 *
 * @param : none
 *
 * @returns : {boolean} 0 if no error occurs
 *
 * @requires : standard library stdio.h
 */

#include <stdio.h>
int main(void)
{
	int i;
	float x;
	char c;
	printf("Entrer un nombre entier : ");
	scanf("%d", &i);
	printf("Le nombre stocke dans la variable i est %d\n", i);
	x = i; //conversion implicite
	printf("Conversion implicite par affectation a une variable de type float : %f\n", x);
	printf("Conversion explicite par l'operateur cast (float) : %f\n", (float)i);  //conversion explicite
	printf("Quel est le type de  i + 1.0 = %lf ?\n", i + 1.0);
	c = i; //conversion implicite
	printf("L'entier i a une signification comme caractere, sa valeur comme char est %c\n", i);
	printf("Sa valeur comme char est aussi %c\n", i); //conversion implicite
	printf("Sa valeur comme char est encore %c\n", (char)x);   //conversion explicite
	return 0;
}

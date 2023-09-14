/*
 * @version 1.0
 * @author Bertrand Gentou <bertrand.gentou@u-paris.fr>
 *
 * post and pre-increment
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
	int i = 10;
	printf("Valeur initiale i=%d\n", i);
	printf("Dans l'instruction contenant la post-incrementation i vaut %d\n", i++);
	printf("Apres l'instruction contenant la post-incrementation i vaut %d\n", i);
	printf("Valeur initiale i=%d\n", i = 10);
	printf("Dans l'instruction contenant la pre-incrementation i vaut %d\n", ++i);
	printf("Apres l'instruction contenant la pre-incrementation i vaut %d\n", i);
	return 0;
}
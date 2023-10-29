#include <stdio.h>

void parcours(int *tab, int s)
{
  if (tab!=NULL)
  {
    int* q=tab;
    while (q-tab < s) //pareil que (q<tab +s)                                                                                                                                                                                                                                                                                                                                                                                     
    {
      printf("%p:%d\n", q-tab, *q);
      q++;
    }
  }
}

void copie_pointeur(int *p, int **pp)
{
  *pp=p;
}

int main(void)
{
  int t[] = {1,3,2,4,5};
  int s=5;
  int *p1, *p2;

  printf("t est l'adresse d'un tableau, ce n'est pas une variable, sa valeur est : %p\n", t);
  printf("Parcours de t : \n");
  parcours(t,s);

  p1=t;
  printf("Apres p1 = t, la variable p1 contient la meme adresse que t : %p\n", p1);
  printf("Parcours de p1 : \n");
  parcours(p1,s);

  copie_pointeur(t, &p2);
  printf("Apres l'appel copie_pointeur(t, &p2), la variable p2 vaut : %p\n", p2);
  printf("Parcours de p2 : \n");
  parcours(p2,s);

  p2[2]=0;
  printf("Apres l'affectation p2[2]=0\n");
  printf("Parcours de t : \n");
  parcours(t, s);
  printf("Parcours de p1 : \n");
  parcours(p1, s);

  return 0;
}

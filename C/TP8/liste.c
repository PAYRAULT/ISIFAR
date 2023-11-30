/*
 * @version 1.1
 * @author Bertrand Gentou <bertrand.gentou@u-paris.fr>
 *
 * linked list
 *
 * @param : none
 *
 * @returns : {boolean} 0 if no error occurs
 *
 * @requires : header.h, standard libraries stdio.h, stdlib.h and string.h
 * 
 * Created by Bertrand GENTOU on 11/11/2020, modified on 25/11/2023
 * Copyright 2020 Bertrand GENTOU. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init_liste(liste_t*);
int is_empty(liste_t*);
void print_liste(liste_t*);
element_t* new_element(data_t);
element_t* push(liste_t*, data_t);
element_t* pop(liste_t*);
void empty(liste_t*);


/*********************   FONCTIONS   *************************/

void init_liste(liste_t* Pl)
{
    Pl->top = NULL;
}

int is_empty(liste_t* Pl)
{
    return Pl->top == NULL;
}

void print_liste(liste_t* Pl)
{
    element_t* current = Pl->top;
    while (current != NULL)
    {
        printf(CODE, current->v.key, current->v.name, current->v.value);
        printf("\n");
        current = current->next;
    }
}

element_t* new_element(data_t x)
{
    element_t* Pnew;
    Pnew = (element_t*)malloc(sizeof(element_t));
    if (Pnew != NULL)
    {
        Pnew->v.key = x.key;
        strcpy(Pnew->v.name,x.name);
        Pnew->v.value = x.value;
        Pnew->next = NULL;
    }
    return Pnew;
}

element_t* push(liste_t* Pl, data_t x)
{
    element_t* Pnew = new_element(x);
    if (Pnew != NULL)
    {
        Pnew->next = Pl->top;
        Pl->top = Pnew;
    }
    return Pnew;
}


element_t* pop(liste_t* Pl)
{
    if (is_empty(Pl))
        return NULL;
    element_t* Pe = Pl->top;
    Pl->top = Pl->top->next;
    Pe->next = NULL;
    return Pe;
}


void empty(liste_t* Pl)
{
    element_t* current, * next;
    current = Pl->top;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    Pl->top = NULL;
}

#include <stdlib.h>
#include <stdio.h>

typedef int data_t;
#define MAX_PILE    20


typedef struct pile_st {
    data_t pile[MAX_PILE];
    int top;
} pile_t;

void init_stack(pile_t *p){
    p->top = 0;
}

int is_empty (pile_t *p){
    return p->top == 0;
}

void print_stack(pile_t *p){
    if(is_empty(p)) {
        printf("La pile est vide\n");
    }
    else {
        for(int current = 0; current < p->top; current++){
            printf("%d\n", p->pile[current]);
        }
        printf("\n");
    }
}


void print_reversed_stack(pile_t *p){
    if(is_empty(p)) {
        printf("La pile est vide\n");
    }
    else {
        for(int current = p->top-1; current >= 0; current--){
            printf("%d\n", p->pile[current]);
        }
        printf("\n");
    }
}

int push(pile_t *p, data_t x){
    if(p->top == MAX_PILE) {
        // La pile est pleine
        return 0;
    }

    p->pile[p->top] = x;
    p->top++;
    return 1;
}

int pop(pile_t *p) {
    if (is_empty(p)) {
        // La pile est vide
        return -1;
    }
    
    p->top--;   
    return p->pile[p->top];
}

void empty(pile_t *p) {
    p->top = 0;
}


int main(void){
    pile_t p; 
    init_stack(&p);
    print_stack(&p);
    print_reversed_stack(&p);
    for(int i = 0; i<MAX_PILE+1;i++){
        if(push(&p,i) != 0){
        }
        else{
            printf("Erreur pile pleine\n");
        }
    }
    print_stack(&p);
    print_reversed_stack(&p);

    for(int i = 0; i < MAX_PILE+1;i++){
        int elep = pop(&p);
        if (elep != -1) {
            printf("Élément dépilé : %d\n", elep);
        } else {
            printf("La pile est vide \n");
        }
    }
    print_stack(&p);
    print_reversed_stack(&p);

    empty(&p);
    printf("Pile à la main\n");
    /* CONSTRUIRE UNE PILE À LA MAIN (JUSTE POUR VOIR)*/
    p.pile[0] = 1;
    p.pile[1] = 6;
    p.pile[2] = 10;
    p.top = 3;
    print_stack(&p);
    return 0;
}


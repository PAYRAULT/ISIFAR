#include <stdlib.h>
#include <stdio.h>

typedef int data_t;

typedef struct element_st {
    data_t v;
    struct element_st *next;
} element_t;

typedef struct pile_st {
    element_t *top;
} pile_t;

void init_stack(pile_t *p){
    p -> top = NULL;
}

int is_empty (pile_t *p){
    return p -> top == NULL;
}

void print_stack(pile_t *p){
    element_t *current;
    for(current = p-> top; current != NULL; current = current -> next){
        printf("%d\n", current -> v);
    }
    printf("\n");
}

void print_aux(element_t *c){
    if(c != NULL){
        print_aux(c -> next);
        printf("%d\n", c -> v);
    }
}


void print_reversed_stack(pile_t *p){
    print_aux(p -> top);
}

element_t* new_element(data_t x){
    element_t* p_n = (element_t*)malloc(sizeof(element_t));
    if(p_n != NULL){
        p_n -> v = x;
        p_n -> next = NULL;
    }
    return p_n; 
}

element_t* push(pile_t *p, data_t x){
    element_t *n = new_element(x);
    if(n != NULL){
        n -> next = p -> top;
        p -> top = n;
    }
    return n;
}

element_t* pop(pile_t *Ps) {
    if (is_empty(Ps)) {
        return NULL;
    }
    
    element_t* po = Ps->top;
    Ps->top = Ps->top->next;
    po->next = NULL;

    return po;
}

void empty(pile_t *Ps) {
    while (!is_empty(Ps)) {
        element_t *temp = pop(Ps);
        free(temp);
    }
}


int main(void){
    pile_t p; 
    init_stack(&p);
    print_stack(&p);
    print_reversed_stack(&p);
    for(int i = 0; i<3;i++){
        if(push(&p,i)!= NULL){
            print_stack(&p);
        }
        else{
            printf("Erreur d'allocation");
        }
    }
    print_stack(&p);

    element_t* elep = pop(&p);

    if (elep != NULL) {
        printf("Élément dépilé : %d\n", elep->v);
        free(elep);
    } else {
        printf("La pile est vide \n");
    }

    empty(&p);

    printf("Pile à la main");
    /* CONSTRUIRE UNE PILE À LA MAIN (JUSTE POUR VOIR)*/
    element_t e3, e2, e1;
    e3.v = 2;
    e2.v = 0;
    e1.v = 1;
    e3.next = NULL;
    e2.next = &e3;
    e1.next = &e2;
    p.top = &e1;
    print_stack(&p);
    return 0;
}


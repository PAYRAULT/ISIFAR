#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CODE "%d "

typedef int data_t;

typedef struct element_st
{
data_t v;
struct element_st *prev;
struct element_st *next;
} element_t;

typedef struct file_st {
    element_t *head;
    element_t *tail;
} file_t;

void init_queue(file_t *Pq) {
    Pq -> head = NULL;
    Pq -> tail = NULL;
}

int is_empty(file_t *Pq){
    return Pq -> head == NULL;
}

void print_queue(file_t *Pq){
    element_t *current;
    for(current = Pq->head; current != NULL; current = current->next){
        printf(CODE, current -> v);
    }
    printf("\n");    
}

void print_reversed_queue(file_t *Pq){

    element_t *current;

    for(current = Pq->tail; current != NULL; current = current->prev){
        printf(CODE, current -> v);
    }
    printf("\n");
}

element_t* new_element(data_t x){
    element_t* f_n = (element_t*)malloc(sizeof(element_t));
    if (f_n != NULL) {
        f_n->v = x;
        f_n->next = NULL;
        f_n->prev = NULL;
    }

    return f_n;
}

element_t* enqueue(file_t *Pq, data_t x) {
    element_t *new = new_element(x);
    if (new == NULL) {
        return 0;
    }

    if(is_empty(Pq)) {
        Pq->head = new;
        Pq->tail = new;
    }
    else {
        Pq->tail->next = new;
        new->prev = Pq->tail;
        Pq->tail = new;
    }

    return new; 
}


element_t* dequeue(file_t *Pq) {
    element_t *elt;

    if(is_empty(Pq)) {
        return NULL;
    }

    elt = Pq -> head;    
    Pq->head = elt->next;
    Pq->head->prev = NULL;
    elt->next = NULL;
    elt->prev = NULL;

    return elt; 
}


int main(void){
    file_t l;
    element_t *elt;

    init_queue(&l);
    print_queue(&l);
    print_reversed_queue(&l);

    elt = enqueue(&l, 34);
    printf(CODE, elt->v);
    printf("\n");
    elt = enqueue(&l, 39);
    elt = enqueue(&l, 42);
    elt = enqueue(&l, 45);
    print_queue(&l);
    print_reversed_queue(&l);

    elt = dequeue(&l);
    printf(CODE, elt->v);
    printf("\n");
    print_queue(&l);
    print_reversed_queue(&l);


    return 0;
}
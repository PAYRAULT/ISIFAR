#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CODE "%d "
#define MAX_FILE 20

typedef int data_t;

typedef struct file_st {
    int nb_elem;
    int head;
    int tail;
    data_t file[MAX_FILE];
} file_t;

void init_queue(file_t *Pq) {
    Pq->nb_elem = 0;
    Pq -> head = 0;
    Pq -> tail = 0;
}

int is_empty(file_t *Pq){
    return Pq -> nb_elem == 0;
}

int is_full(file_t *Pq){
    return Pq->nb_elem == MAX_FILE;
}

int next(int val) {
    return  (val +1) % MAX_FILE;
}

void print_queue(file_t *Pq){
    if(is_empty(Pq)) {
        printf("File vide\n");
        return;
    }
    for(int i = 0; i != Pq->nb_elem; i++) {
        printf(CODE, Pq -> file[(MAX_FILE+Pq->tail+i)%MAX_FILE]);
    }
    printf("\n");    
}

void print_reversed_queue(file_t *Pq){
    if(is_empty(Pq)) {
        printf("File vide\n");
        return;
    }
    for(int i = 0; i != Pq->nb_elem; i++) {
        printf(CODE, Pq -> file[(MAX_FILE+Pq->head-i-1)%MAX_FILE]);
    }
    printf("\n");
}

int enqueue(file_t *Pq, data_t x) {
    if(is_full(Pq)) {
        printf("File pleine\n");
        return 0;
    }

    Pq->file[Pq->head] = x;
    Pq->head = next(Pq->head);
    Pq->nb_elem++;
    return 1;
}

int dequeue(file_t *Pq) {
    if(is_empty(Pq)) {
        return -1;
    }
    int ret = Pq->tail;
    Pq->tail = next(Pq->tail);
    Pq->nb_elem--;

    return  Pq->file[ret]; 
}


int main(void){
    file_t l;
    int val;

    init_queue(&l);
    print_queue(&l);
    print_reversed_queue(&l);

    enqueue(&l, 34);
    enqueue(&l, 39);
    enqueue(&l, 42);
    enqueue(&l, 45);
    printf("%d  %d -> %d\n", l.head, l.tail, l.nb_elem);
    print_queue(&l);
    print_reversed_queue(&l);

    val = dequeue(&l);
    printf(CODE, val);
    printf("\n");
    print_queue(&l);
    print_reversed_queue(&l);


    init_queue(&l);
    print_queue(&l);
    print_reversed_queue(&l);

    for(int i=0; i<MAX_FILE; i++) {
        val = enqueue(&l, i);
    }
    print_queue(&l);
    print_reversed_queue(&l);

    for(int i=0; i<MAX_FILE/2; i++) {
        val = dequeue(&l);
    }
    print_queue(&l);
    print_reversed_queue(&l);

    for(int i=0; i<MAX_FILE/2; i++) {
        val = enqueue(&l, 20+i);
    }
    print_queue(&l);
    print_reversed_queue(&l);

    return 0;
}
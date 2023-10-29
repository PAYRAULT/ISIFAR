#include <stdio.h>

#define LEN_MAX 10

typedef struct{
    int len;
    int tab[LEN_MAX];
}list_t;


void print_list(list_t l){
    if(l.len == 0) {
        printf("liste vide\n");
    }
    else {
        for(int i=0; i<l.len; i++){
            printf("%d\t", l.tab[i]);
        }
        printf("\n");
    }
}

void initialize_list(list_t *p_l){
    p_l->len = 0;
}

void set_list(list_t *p_l){
    printf("Saisir la longueur: ");
    scanf("%d", &(p_l -> len));
    printf("Rentrez la liste: \n");
    for(int i=0; i< p_l->len; i++){
        scanf("%d", &p_l -> tab[i]);
    }
}

int index_of(list_t l, int v){
    for(int i=0; i<l.len; i++){
        if(l.tab[i] == v) {
            return i;
        }
    }
    return -1;
}

int last_index_of(list_t l, int v){
    int t = -1;
    for(int i = 0; i<l.len; i++){
        if(l.tab[i] == v) {
            t = i;
        }
    }
    return t;
}

void pop_last(list_t *p_l){
    if(p_l->len > 0) {
        /* la liste contient au moins 1 element */
        /* diminuer la longuer de 1 */
        p_l->len -= 1;
    }
    /* Sinon ne rien faire */
    return;
}

void append(list_t *p_l, int v) {
    /* verifier qu'il existe au moins une place de libre */
    if(p_l->len < LEN_MAX) {
        /* Ajouter la valeur v a la fin et incrementer la longueur de la liste */
        p_l->tab[p_l->len] = v;
        p_l->len += 1;
    }
    /* Sinon ne rien faire */
    return;
}

void pop(list_t *p_l, int i) {
    /* Test de l'indice */
    if(i >= 0 && i < p_l->len ) {
        /* Test si il y a au moins 1 element dans la liste */
        if(p_l->len > 0) {
            /* Decaler tous le elements De la liste apres i */
            for(int j = i; j + 1 < p_l->len; j++) {
                p_l->tab[j] = p_l->tab[j+1];
            }
            /* Decrementer la longueur de la liste */
            p_l->len -= 1;
        }
    }
    /* Sinon ne rien faire */
    return;
}

void insert(list_t *p_l, int v, int i) {
    /* Test si il y a de la place pour 1 element dans la liste */
    if(p_l->len < LEN_MAX) {
        /* Test de l'indice */
        if(i >= 0 && i < p_l->len ) {
            /* Decaler tous le elements De la liste apres i */
            for(int j = i; j + 1 < LEN_MAX; j++) {
                p_l->tab[j+1] = p_l->tab[j];
            }
            /* Inserer la valeur a l'indice i */
            p_l->tab[i] = v;
            /* Incrementer la longueur de la liste */
            p_l->len += 1;
        }
    }
    /* Sinon ne rien faire */
    return;
}


void concat(list_t *p_l, list_t l1, list_t l2) {
    /* Test si on peut cancatener */
    if(l1.len + l2.len <= LEN_MAX) {
        /* recopier l1 dans p_l */
        for(int i = 0; i < l1.len; i++) {
            p_l->tab[i] = l1.tab[i];
        }
        /* recopier la apres  dans p_l */
        for(int i = 0; i < l2.len; i++) {
            p_l->tab[l1.len+i] = l2.tab[i];
        }
        /* initialiser la taille */
        p_l->len = l1.len+l2.len;
    }
    /* Sinon ne rien faire */
    return;
}


void sort(list_t *p_l) {
    int i, j, temp;

    for(i = 0; i < p_l->len; i++) {
        temp = p_l->tab[i];
        j = i - 1;
        while( j >= 0 && p_l->tab[j] > temp) {
            p_l->tab[j+1] = p_l->tab[j];
            j--;
        }
        p_l->tab[j+1] = temp;
    }
}    


int main(void) {
    list_t L, L2, L3;
    int v = 1;

    initialize_list(&L);
    set_list(&L);
    print_list(L);
    printf("Saisir une valeur v : ");
    scanf("%d", &v);

    printf("Premier indice avec la valeur %d dans la liste : %d\n", v, index_of(L, v));
    printf("Dernier indice avec la valeur %d dans la liste : %d\n", v, last_index_of(L, v));

    /* retirer le dernier element d'une liste non vide */
    pop_last(&L);
    print_list(L);

    /* Retirer un element de la liste vide */
    initialize_list(&L2);
    pop_last(&L2);
    print_list(L2);

    /* test */
    append(&L2, 0);
    append(&L2, 1);
    append(&L2, 2);
    append(&L2, 3);
    append(&L2, 4);
    append(&L2, 5);
    append(&L2, 6);
    append(&L2, 7);
    append(&L2, 8);
    append(&L2, 9);
    printf("Ajout 10 elements: ");
    print_list(L2);
    printf("Ajout 11 elements: ");
    append(&L2, 10);
    print_list(L2);
    pop(&L2, 9);
    printf("Retirer dernier element : ");
    print_list(L2);
    /* mauvais i */
    pop(&L2, -3);
    pop(&L2, 9);
    pop(&L2, 4);
    printf("Retirer element 4: ");
    print_list(L2);

    initialize_list(&L2);
    pop(&L2, 1);
    printf("Retirer dans liste vide: ");
    print_list(L2);
    append(&L2, 9);
    pop(&L2, 1);
    printf("Retirer dans liste 1 element: ");
    print_list(L2);

    initialize_list(&L2);
    append(&L2, 0);
    append(&L2, 1);
    append(&L2, 2);
    append(&L2, 4);
    /* mauvais i */
    insert(&L2, 31, -2);
    insert(&L2, 31, 5);
    /* inserer 3 */
    printf("Liste de depart : ");
    print_list(L2);
    insert(&L2, 33, 3);
    printf("Inserer 33 a la position 3 : ");
    print_list(L2);

    initialize_list(&L);
    initialize_list(&L2);
    initialize_list(&L3);
    append(&L2, 0);
    append(&L2, 1);
    append(&L2, 2);
    printf("Liste L2 : ");
    print_list(L2);
    append(&L3, 3);
    append(&L3, 4);
    append(&L3, 5);
    append(&L3, 6);
    printf("Liste L3 : ");
    print_list(L3);
    concat(&L, L2, L3);
    printf("Liste L concatenation L2 et L3 : ");
    print_list(L);

    initialize_list(&L);
    append(&L, 8);
    append(&L, 3);
    append(&L, 2);
    append(&L, 5);
    append(&L, 6);
    printf("Liste L : ");
    print_list(L);
    sort(&L);
    printf("Liste L triee : ");
    print_list(L);

    return 0;
}


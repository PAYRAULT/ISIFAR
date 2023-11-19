#include <stdlib.h>
#include <stdio.h>
#define SIZE_MIN 10

typedef struct couple_st {
    int k;
    float v;
} couple_t;

typedef struct dic_st {
    int size;
    int len;
    couple_t* t;
} dic_t;


void print_dic(dic_t d){
	printf("Nombre de couples : %d\n", d.len);
    for(int i = 0; i < d.len; i++){
        printf(" (%d,%f)\n", d.t[i].k, d.t[i].v);
    }
}

void initialize_dic(dic_t *p){
    p -> size = SIZE_MIN;
    p -> len = 0;
    p -> t = (couple_t*) calloc(SIZE_MIN, sizeof(couple_t));
    if(p-> t == NULL){
        exit(1);
    }
}

void scan_dic(dic_t *p){
printf("Nombre d'entrées ? ");
    scanf("%d", &(p->len));
    if(p->size < 2*p->len) {        
        p->size = 2*p->len;
		p->t = (couple_t *) realloc(p->t, p->size*sizeof(couple_t));
		if(p->t == NULL) {
			exit(1);
		}
	}

    printf("Saisir les %d entrées \n", p-> len);
    for(int i = 0; i< p-> len; i++){
        scanf("%d%f", &(p->t[i].k), &(p->t[i].v));
    }
}

void sort_dic(dic_t *p){
    int s = p-> len;
    int i,j,h;
    couple_t temp;
    couple_t* t = p ->  t;
    for(h = 2 * s / 3 ; h > 0 ; h = (h==2) ? 1 : (int) (h/2.3))
        for(i = h ; i<s ; i++) {
            for(j = i, temp = t[i] ; j >= h && t[j-h].k > temp.k ; j = j-h)
            t[j] = t[j-h];
            t[j] = temp;
        }
}


int aux_index_of(couple_t *t, int x, int ideb, int ifin){

    if (ifin >= ideb) {
 
        int imilieu = (ideb + ifin) / 2;
        
        if(x == t[imilieu].k){
            return imilieu;
        }
        else if(x < t[imilieu].k){
            return aux_index_of(t, x, ideb, imilieu - 1);
        }
        else if(x > t[imilieu].k){
            return aux_index_of(t, x, imilieu + 1, ifin);
        }
    }

    // L'element n'est pas present
    return -1;
}


int index_of(dic_t d, int x){
    return aux_index_of(d.t, x, 0, d.len -1);
}

int index_of2(dic_t d, int x){
    int milieu;
    int ideb = 0;
    int ifin = d.len -1;

    while( ideb <= ifin) {
		milieu = (ideb + ifin)/2;
		if(d.t[milieu].k == x) {
			// Trouve
			return milieu;
		}
		else if (d.t[milieu].k > x) {
	        // x est plus petit que le milieu alors recherche dans le cote gauche
            ifin = milieu - 1;
        }
		else {
	        // x est plus grand que le milieu alors recherche dans le cote droit
	        ideb = milieu + 1;
		}
	}

	// pas trouve
	return -1;
}


int modify(dic_t *p, int x, float v){
    int ind = index_of(*p, x);
    if(ind == -1){
        return 0;
    }
    p -> t[ind].v = v;
    return 1;
    }


int search(dic_t d, int x, float *v){
    int ind = index_of(d, x);
    if(ind == -1){
        return 0;
    } 
    *v = d.t[ind].v;
    return 1;

    }


int suppress(dic_t *p, int x){
    int ind = index_of(*p,x);

    if(ind == -1){
        return 0;
    }

    for(int i = ind; i < p -> len -1; i++){
            p -> t[i] = p -> t[i +1];
        }

    p -> len = p-> len -1;

    if ((p->len) <= (1.0 / 10) * (p->size) && (p->size) > SIZE_MIN) {
        p->size /= 4;
        p->t = (couple_t *)realloc(p->t, p->size * sizeof(couple_t));
        if (p->t == NULL) {
            exit(1);
        }
    }

    return 1;

}

int insert_index(dic_t d, int x){
    int ideb = 0;
	int ifin = d.len-1;
	int mil;

	while( ideb <= ifin || ideb == d.len-1) {
		mil = (ideb+ifin)/2;
		if(d.t[mil].k < x && d.t[mil+1].k > x) {
			return mil+1;
		}
		else if (d.t[mil].k > x) {
	        
            ifin = mil - 1;
        }
		else {
	        ideb = mil + 1;
		}
	}
	return ideb;
}

int add(dic_t *p, couple_t c) {

    int ind = index_of(*p, c.k);

    if (ind != -1) {
        return 0;
    }

    if(p -> len == p -> size){
        p -> size *= 2;
        p->t = realloc(p->t, p->size*sizeof(couple_t));
        if (p->t == NULL) {
            exit(1);
        }
    }

    int ind2 = insert_index(*p,c.k);

    for (int i = p->len; i > ind2; i--) {
        p->t[i] = p->t[i - 1];
    }

    p->t[ind2] = c;

    p->len++;

	return 1;

    }


int main() {
	dic_t p;
	int x, ind, res;
	float v;
	couple_t c;

	initialize_dic(&p);
	scan_dic(&p);

    printf("Dictionnaire initial.\n");
	print_dic(p);

    printf("Dictionnaire trie.\n");
	sort_dic(&p);
	print_dic(p);

	x = 6;
	ind = index_of(p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
    else {
		printf("cle %d n'existe pas\n", x);
    }

	x = 1;
	ind = index_of(p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
    else {
		printf("cle %d n'existe pas\n", x);
    }

	x = 5;
	ind = index_of(p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
    else {
		printf("cle %d n'existe pas\n", x);
    }

	x = 6;
	ind = index_of2(p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
    else {
		printf("cle %d n'existe pas\n", x);
    }

	x = 1;
	ind = index_of2(p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
    else {
		printf("cle %d n'existe pas\n", x);
    }

	x = 2;
	ind = index_of2(p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
    else {
		printf("cle %d n'existe pas\n", x);
    }

	x = 3;
    printf("Modification de la cle 3.\n");
	res = modify(&p, x, 5.999);
	if(res == 1) {
		print_dic(p);
	}
    else {
        printf("cle %d non trouve.\n", x);
    }

	x = 7;
    printf("Modification de la cle 7.\n");
	res = modify(&p, x, 5.999);
	if(res == 1) {
		print_dic(p);
	}
    else {
        printf("cle %d non trouve.\n", x);
    }

	x = 3;
	v = 0.0;
	res = search(p, x, &v);
	printf("recherche de %d, res : %d, v = %f\n", x, res, v);
	v = 0.0;
	x = 7;
	res = search(p, x, &v);
	printf("recherche de %d, res : %d, v = %f\n", x, res, v);


	x = 3;
    printf("Suppression de la cle %d.\n", x);
	res = suppress(&p, x);
	if(res == 1) {
		print_dic(p);
	}
    else {
        printf("cle %d non trouve.\n", x);
    }
	x = 7;
    printf("Suppression de la cle %d.\n", x);
	res = suppress(&p, x);
	if(res == 1) {
		print_dic(p);
	}
    else {
        printf("cle %d non trouve.\n", x);
    }

	c.k = 3;
	c.v = 4.567;
    printf("Ajout de la cle (%d,%f).\n", c.k, c.v);
	res = add(&p, c);
	if(res == 1) {
		print_dic(p);
	}

	c.k = 6;
	c.v = 8.989;
    printf("Ajout de la cle (%d,%f).\n", c.k, c.v);
	res = add(&p, c);
	if(res == 1) {
		print_dic(p);
	}
}


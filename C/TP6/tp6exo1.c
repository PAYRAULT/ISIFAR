#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE_MIN	10

typedef struct  couple_st {
	int k;
	float v;
} couple_t;

typedef struct dic_st {
	int size;
	int len;
	couple_t *t;
} dic_t;


void print_dic(dic_t d) {
	printf("Nombre de couples : %d\n", d.len);
	for(int i = 0; i < d.len; i++) {
		printf("	%d : %f\n", d.t[i].k, d.t[i].v);
	}
}


void initialize_dic(dic_t *p) {
	if(p != NULL) {
		p->size = SIZE_MIN;
		p->len = 0;
		p->t = (couple_t *) calloc(SIZE_MIN, sizeof(couple_t));
	}
}


void scan_dic(dic_t *p) {
    printf("Saisir le nombre d'elements: ");
    scanf("%d", &(p->len));
	if(p->size < 2*p->len) {
        p->size = 2*p->len;
		p->t = (couple_t *) realloc(p->t, p->size*sizeof(couple_t));
		if(p->t == NULL) {
			exit(-1);
		}
	}

    for(int i=0; i< p->len; i++){
	    printf("Saisir cle %d : ", i);
        scanf("%d", &p->t[i].k);
	    printf("Saisir valeur %d : ", i);
        scanf("%f", &p->t[i].v);
    }
}


void sort_dic(dic_t *p) {
	couple_t *t = p->t; 
	int s = p->len;

    int h, i, temp_k, j;
	float temp_v;
    h = (int)(2 * s / 3);
    while(h >= 1) {
        for(i = h; i <= s-1; i++) {
            temp_k = t[i].k;
            temp_v = t[i].v;
            j = i;
            while(j >= h && t[j-h].k > temp_k) {
                t[j].k = t[j-h].k;
                t[j].v = t[j-h].v;
                j = j - h;
            }
            t[j].k = temp_k;
            t[j].v = temp_v;
        }
        if(h == 2) {
            h = 1;
        }
        else {
            h = floor(h / 2.3);
        }
    }
}


int rech_r(couple_t *t, int g, int d, int x)
{
    if (d >= g) {
 
        // calcul du milieu
        int mil = g + (d - g) / 2;
 
        // element trouve
        if (t[mil].k == x) {
            return mil;
		}
        else if (t[mil].k > x) {
	        // x est plus petit que le milieu alors recherche dans le cote gauche
            return rech_r(t, g, mil - 1, x);
        }
		else {
	        // x est plus grand que le milieu alors recherche dans le cote droit
	        return rech_r(t, mil + 1, d, x);
		}
    }
 
    // L'element n'est pas present
    return -1;
}

int index_of_r(dic_t *p, int x) {
	return (rech_r(p->t, 0, p->len-1, x));
}


int index_of_i(dic_t *p, int x) {
	int g = 0;
	int d = p->len-1;
	int mil;

	while( g <= d) {
		mil = g + (d - g)/2;
		if(p->t[mil].k == x) {
			// Trouve
			return mil;
		}
		else if (p->t[mil].k > x) {
	        // x est plus petit que le milieu alors recherche dans le cote gauche
            d = mil - 1;
        }
		else {
	        // x est plus grand que le milieu alors recherche dans le cote droit
	        g = mil + 1;
		}
	}

	// pas trouve
	return -1;
}

int modify(dic_t *p, int x, float v) {
	int ind;

	// Recherhe l'element de cle x
	ind = index_of_r(p, x);
	if(ind == -1) {
		// Pas trouve
		return 0;
	}
	else {
		// Trouve
		p->t[ind].v = v;
		return 1;
	}
}

int search(dic_t *p, int x, float *v) {
	int ind;
	
	// Recherhe l'element de cle x
	ind = index_of_r(p, x);
	if(ind == -1) {
		// Pas trouve
		return 0;
	}
	else {
		// Trouve
		*v = p->t[ind].v;
		return 1;
	}
}


int suppress(dic_t *p, int x) {
	int ind;
	
	// Recherhe l'element de cle x
	ind = index_of_r(p, x);
	if(ind == -1) {
		// Pas trouve
		return 0;
	}
	else {
		// Trouve 
		// Decrement la longueur
		p->len -= 1;
		// Decaler tous les elements vers la gauche
		for(int i = ind; i < p->len; i++) {
			p->t[i] = p->t[i+1];
		}
		if(10*p->len <= p->size) {
			p->size = p->size / 4;
		}
		return 1;
	}
}


int insert_index(dic_t *p, int x) {

	int g = 0;
	int d = p->len-1;
	int mil;

	while( g <= d || g == p->len-1) {
		mil = g + (d - g)/2;
		if(p->t[mil].k < x && p->t[mil+1].k > x) {
			// trouve
			return mil+1;
		}
		else if (p->t[mil].k > x) {
	        // x est plus petit que le milieu alors recherche dans le cote gauche
            d = mil - 1;
        }
		else {
	        // x est plus grand que le milieu alors recherche dans le cote droit
	        g = mil + 1;
		}
	}
	return g;
}

int add(dic_t *p, couple_t c) {
	int ind;

	printf("cle: %d\n", c.k);

	// Recherhe l'element de cle x
	ind = index_of_r(p, c.k);
	printf("ind : %d\n", ind);
	if(ind == -1) {
		// Cle n'est pas presente dans le dictionnaire
		// verifier la taille
		if(p->len == p->size) {
			// Il faut agrandir le tableau
			p->size *= 2;
			p->t = realloc(p->t, p->size*sizeof(couple_t));
		}
		// Trouver l'indice ou inserer
		ind = insert_index(p, c.k);

		// Decaler les elements vers la droite
		for(int i = p->len; i > ind; i--) {
			p->t[i] = p->t[i-1];
		}
		// Ajouter l'element c
		p->t[ind].k = c.k;
		p->t[ind].v = c.v;
		// Incrementer la longueur
		p->len += 1;

		return 1;
	}
	else {
		// Cle est presente 
		return 0;
	}
}



int main() {
	dic_t p;
	int x, ind, res;
	float v;
	couple_t c;

	initialize_dic(&p);
	scan_dic(&p);
	print_dic(p);
	sort_dic(&p);
	print_dic(p);

	x = 6;
	ind = index_of_r(&p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
	x = 1;
	ind = index_of_r(&p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
	x = 5;
	ind = index_of_r(&p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}

	x = 6;
	ind = index_of_i(&p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
	x = 1;
	ind = index_of_i(&p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}
	x = 2;
	ind = index_of_i(&p, x);
	if(ind != -1) {
		printf("x : %d, valeur %d : %f\n", x, p.t[ind].k, p.t[ind].v);
	}

	x = 3;
	res = modify(&p, x, 5.999);
	if(res == 1) {
		print_dic(p);
	}
	x = 7;
	res = modify(&p, x, 5.999);
	if(res == 1) {
		print_dic(p);
	}

	x = 3;
	v = 0.0;
	res = search(&p, x, &v);
	printf("res : %d, v = %f\n", res, v);
	v = 0.0;
	x = 7;
	res = search(&p, x, &v);
	printf("res : %d, v = %f\n", res, v);


	x = 3;
	res = suppress(&p, x);
	if(res == 1) {
		print_dic(p);
	}
	x = 7;
	res = suppress(&p, x);
	if(res == 1) {
		print_dic(p);
	}

	c.k = 3;
	c.v = 4.567;
	res = add(&p, c);
	if(res == 1) {
		print_dic(p);
	}
	c.k = 6;
	c.v = 8.989;
	res = add(&p, c);
	if(res == 1) {
		print_dic(p);
	}
	c.k = 7;
	c.v = 14.639;
	res = add(&p, c);
	if(res == 1) {
		print_dic(p);
	}

}

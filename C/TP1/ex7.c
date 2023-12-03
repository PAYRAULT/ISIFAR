#include <stdio.h>
#include <math.h>

typedef struct {
    float re;
    float im;
} complex_t;

/* Prototype des fonctions */
complex_t sum(complex_t a, complex_t b);
complex_t prod(complex_t a, complex_t b);
complex_t inv(complex_t z);
complex_t mult(double l, complex_t z);
complex_t square_root(complex_t z);

/* Addition de 2 noombres complexes */
complex_t sum(complex_t a, complex_t b) {
    complex_t res;

    res.re = a.re + b.re;
    res.im = a.im + b.im;

    return res;
}

/* Multiplication de 2 noombres complexes */
complex_t prod(complex_t a, complex_t b) {
    complex_t res;

    res.re = a.re * b.re - a.im * b.im;
    res.im = a.re * b.im + a.im * b.re;

    return res;
}

/* Inverse d'un nombre complexe */
complex_t inv(complex_t z) {
    complex_t res;
    float diviseur = powf(z.re,2) + powf(z.im, 2);

    res.re = z.re / diviseur;
    res.im = -z.im / diviseur;

    return res;
}

/* Multiplication d'un nombre complexe par un scalaire */
complex_t mult(double l, complex_t z) {
    complex_t res;

    res.re = (float)l * z.re;
    res.im = (float)l * z.im;
    
    return res;
}


/* Question c. racine carre d'un nombre complexe */
complex_t square_root(complex_t z) {
    complex_t res;
    float norme = sqrt(z.re * z.re + z.im* z.im);

    if(z.im != 0) {
        res.re = sqrt((norme+z.re)/2);
        res.im = z.im/fabs(z.im)*sqrt((norme-z.re)/2);    
    }
    else if (z.re  >= 0) {
        res.re = sqrt(z.re);
        res.im = 0;
    }
    else {
        res.re = 0;
        res.im = sqrt(-z.re);
    }

    return res;
}

/* Ceci est le programme principal */
int main(){
    complex_t c1, c2;
    complex_t res;
    double l;

    printf("Entrez le premier nombre complexe c1: ");
    scanf("%f %f", &(c1.re), &(c1.im));
    printf("Entrez le second nombre complexe c2: ");
    scanf("%f %f", &(c2.re), &(c2.im));

    res = sum(c1, c2);
    printf("c1 + c2 = (%f, %f)\n", res.re, res.im);

    res = prod(c1, c2);
    printf("c1 * c2 = (%f, %f)\n", res.re, res.im);

    res = inv(c1);
    printf("1 / c1 = (%f, %f)\n", res.re, res.im);

    printf("Entrez un entier l: ");
    scanf("%f", &l);
    res = mult(l, c1);
    printf("l * c1 = (%f, %f)\n", res.re, res.im);

    res = square_root(c1);
    printf("sqrt(c1) = (%f, %f)\n", res.re, res.im);

    /* polynome c0x^2 + c1x + c2 = 0 */
    complex_t c0;
    complex_t d;

    printf("racine du polynome c0^2x + c1x + c2\n");
    printf("Entrez c0: ");
    scanf("%f %f", &(c0.re), &(c0.im));
    printf("Entrez c1: ");
    scanf("%f %f", &(c1.re), &(c1.im));
    printf("Entrez c2: ");
    scanf("%f %f", &(c2.re), &(c2.im));

    /* d = c1*c1 - 4c0c2 */
    d = sum(prod(c1,c1), mult(-4.0, prod(c0,c2)));

    if(d.re == 0 && d.im == 0) {
        /*Racine double : -c1 / 2c2*/
        res = prod(mult(-1.0, c1), inv(mult(2.0, c0)));
        printf("Racine double: (%f, %f)\n", res.re, res.im);
    }
    else {
        /* 2 racines */
        res = prod(sum(mult(-1.0, c1), square_root(d)), inv(mult(2.0, c0)));
        printf("Racine 1: (%f, %f)\n", res.re, res.im);
        res = prod(sum(mult(-1.0, c1), mult(-1.0, square_root(d))), inv(mult(2.0, c0)));
        printf("Racine 2: (%f, %f)\n", res.re, res.im);
    }

    return 0;
}

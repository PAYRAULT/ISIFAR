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
    res.im = z.im / diviseur;

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
complex_t square(complex_t z) {
    complex_t res;
    float norme = sqrt(powf(z.re,2) + powf(z.im, 2));

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

    c1.re = 25;
    c1.im = -7;
    res = square(c1);
    printf("sqrt(c1) = (%f, %f)\n", res.re, res.im);
    c1.re = 25;
    c1.im = 0;
    res = square(c1);
    printf("sqrt(c1) = (%f, %f)\n", res.re, res.im);
    c1.re = -25;
    c1.im = 0;
    res = square(c1);
    printf("sqrt(c1) = (%f, %f)\n", res.re, res.im);

    return 0;
}

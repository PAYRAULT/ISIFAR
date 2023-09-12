#include <stdio.h>
#include <math.h>

typedef struct {
    float re;
    float im;
} complex_t;

complex_t sum(complex_t a, complex_t b);
complex_t prod(complex_t a, complex_t b);
complex_t inv(complex_t z);
complex_t mult(double l, complex_t z);

complex_t sum(complex_t a, complex_t b) {
    complex_t res;

    res.re = a.re + b.re;
    res.im = a.im + b.im;

    return res;
}

complex_t prod(complex_t a, complex_t b) {
    complex_t res;

    res.re = a.re * b.re - a.im * b.im;
    res.im = a.re * b.im + a.im * b.re;

    return res;
}

complex_t inv(complex_t z) {
    complex_t res;
    float diviseur = powf(z.re,2) + powf(z.im, 2);

    res.re = z.re / diviseur;
    res.im = z.im / diviseur;

    return res;
}

complex_t mult(double l, complex_t z) {
    complex_t res;

    res.re = (float)l * z.re;
    res.im = l * z.im;
    
    return res;
}


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
    scanf("%Lf", &l);
    res = mult(l, c1);
    printf("l * c1 = (%f, %f)\n", res.re, res.im);

    return 0;
}
/* Zawiera implementacje funkcji wykonujących operacje 
 * dodawania, odejmowania, mnożenia, dzielenia liczb zespolonych */
#include <stdlib.h>
#include "zespolone.h"

Zespolona* dodaj_wsk(Zespolona a, Zespolona b) {
    Zespolona *z=malloc(sizeof(Zespolona));
    z->re = a.re + b.re;
    z->im = a.im + b.im;
    
    return z;
}
void dodaj_mod(Zespolona a, Zespolona *b) {
    (*b).re = a.re + (*b).re;
    (*b).im = a.im + (*b).im;
}

Zespolona* odejmij_wsk(Zespolona a, Zespolona b) {
    Zespolona *z=malloc(sizeof(Zespolona));
    z->re = a.re - b.re;
    z->im = a.im - b.im;
    
    return z;
}
void odejmij_mod(Zespolona a, Zespolona *b) {
    (*b).re = a.re - (*b).re;
    (*b).im = a.im - (*b).im;
}

Zespolona* pomnoz_wsk(Zespolona a, Zespolona b) {
    Zespolona *z=malloc(sizeof(Zespolona));
    z->re = a.re*b.re - a.im*b.im;
    z->im = a.re*b.im + a.im*b.re;
    
    return z;
}
void pomnoz_mod(Zespolona a, Zespolona *b) {
    double x, y;
    x = a.re*(*b).re - a.im*(*b).im;
    y = a.re*(*b).im + a.im*(*b).re;
    
    (*b).re=x;
    (*b).im=y;
}

Zespolona* podziel_wsk(Zespolona a, Zespolona b) {
    Zespolona *z=malloc(sizeof(Zespolona));
    if(b.re==0 && b.im==0) return NULL;
    z->re = (a.re*b.re + a.im*b.im)/(b.im*b.im + b.re*b.re);
    z->im = (a.im*b.re - a.re*b.im)/(b.im*b.im + b.re*b.re);
    
    return z;
}
void podziel_mod(Zespolona a, Zespolona *b) {
    if((*b).re==0 && (*b).im==0) return;
    double x, y;
    x = (a.re*(*b).re + a.im*(*b).im)/((*b).im*(*b).im + (*b).re*(*b).re);
    y = (a.im*(*b).re - a.re*(*b).im)/((*b).im*(*b).im + (*b).re*(*b).re);
    
    (*b).re=x;
    (*b).im=y;
}


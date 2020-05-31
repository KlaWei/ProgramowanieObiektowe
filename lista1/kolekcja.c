#include <stdio.h>
#include <stdlib.h>
#include "kolekcja.h"

/* Wstawia element do listy. */
void wstaw_lista(Lista **lh, Lista **lt, Elem e) {
    Lista *pom=(Lista*)malloc(sizeof(Lista));
    pom->el=e;
    pom->next=NULL;
    if ((*lh)==NULL) {
        (*lh)=pom;
        (*lt)=pom;
    }
    else {
        (*lt)->next=pom;
        (*lt)=pom;
    }
}

/* Wstawia element do kolejki. */
void wstaw(Kolekcja **k, Elem e) {
    if ((*k)->typ==true) {
        Lista *pom;
        for (pom=(*k)->pocz_list;pom!=NULL;pom=pom->next) {
            if(pom->el==e) return;
        }
    }
    wstaw_lista(&(*k)->pocz_list, &(*k)->kon_list, e);
}

int rozmiar(Kolekcja *k) {
    Lista *pom=k->pocz_list;
    int r=0;
    while (pom!=NULL) {
        r++;
        pom=pom->next;
    }
    return r;
}

/* Szuka elementów e w kolekcji i zwraca ich ilość. */
int szukaj(Kolekcja *k, Elem e) {
    Lista *pom=k->pocz_list;
    int n=0;
    while (pom!=NULL) {
        if(pom->el==e) n++;
        pom=pom->next;
    }
    return n;
}

void zbior(Kolekcja **k) {
    (*k)=(Kolekcja*)malloc(sizeof(Kolekcja));
    (*k)->typ=true;
    (*k)->pocz_list=NULL;
    (*k)->kon_list=NULL;
}

void torba(Kolekcja **k) {
    (*k)=(Kolekcja*)malloc(sizeof(Kolekcja));
    (*k)->typ=false;
    (*k)->pocz_list=NULL;
    (*k)->kon_list=NULL;
}



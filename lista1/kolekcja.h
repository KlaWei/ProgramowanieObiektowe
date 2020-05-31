#include <stdbool.h>

typedef int Elem;

struct lista {
	struct lista *next;
	Elem el;
}; typedef struct lista Lista;

struct kolekcja {
	Lista *pocz_list; // pierwszy element list
	Lista *kon_list; // ostatni element listy
	bool typ; // true - zbiór, false - torba
}; typedef struct kolekcja Kolekcja;

void wstaw(Kolekcja**, Elem);
int rozmiar(Kolekcja*);
int szukaj(Kolekcja*, Elem);
void zbior(Kolekcja**);
void torba(Kolekcja**);


struct zespolona {
    double im, re;
}; typedef struct zespolona Zespolona;

Zespolona* dodaj_wsk(Zespolona, Zespolona);
void dodaj_mod(Zespolona, Zespolona*);

Zespolona* odejmij_wsk(Zespolona, Zespolona);
void odejmij_mod(Zespolona, Zespolona*);

Zespolona* pomnoz_wsk(Zespolona, Zespolona);
void pomnoz_mod(Zespolona, Zespolona*);

Zespolona* podziel_wsk(Zespolona, Zespolona);
void podziel_mod(Zespolona, Zespolona*);

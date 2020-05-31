using System;

class Test {
    static void Main() {
        Wektor w = new Wektor(new float[] {9.0f, 7.4f, 2f, 2.1f});
        Wektor w2 = new Wektor(new float[] {7f, 3f, 2f, 1f});
        
        
        Wektor w4 = new Wektor(new float[] {2f, 3f});
        Wektor w5 = new Wektor(new float[] {12f,4f});
        Wektor w6 = new Wektor(new float[] {2f, 5.2f});
        Wektor w7 = new Wektor(new float[] {12.1f,9f});
        Console.Write("wektor w: ");
        w.drukujWektor();
        Console.Write("wektor w2: ");
        w2.drukujWektor();
        
        Wektor w3 = Wektor.dodaj(w, w2);
        Console.Write("wektor w+w2: ");
        w3.drukujWektor();
        Macierz m = new Macierz(new Wektor[] {w, w2, w3});
        
        Console.Write("\nmacierz m: \n");
        m.drukujMacierz();
        
        Macierz m2 = new Macierz(new Wektor[] {w4,w5,w6,w7});
        Console.Write("\nmacierz m2: \n");
        m2.drukujMacierz();
        
        Macierz wynik = Macierz.iloczynMacierzy(m, m2);
        Console.Write("\nmacierz m*m2:\n");
        wynik.drukujMacierz();
        
        Macierz dod = Macierz.sumaMacierzy(m, m);
        Console.Write("\nmacierz m+m:\n");
        dod.drukujMacierz();
        
        Wektor v = Macierz.ilocznynMacierzWek(m, w3);
        Console.Write("\nwektor m*(w+w2): ");
        v.drukujWektor();
        
        Macierz.sumaMacierzy(m, m2);
        Wektor.dodaj(w, w4);
    }
}
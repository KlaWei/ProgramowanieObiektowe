using System;

public class Wektor {
    public float[] wektor;
    int wektorSz;
    
    public Wektor(int n) {
        wektorSz=n;
        wektor = new float[n];
    }
    
    public Wektor(float[] coords) {
        wektorSz=coords.Length;
        wektor=coords;
        int i;
        for(i=0; i<wektorSz; i++) wektor[i]=coords[i];
    }
    
    public void drukujWektor() {
        int i;
        for(i=0; i<this.wektorSz; i++) {
            Console.Write("{0} ", this.wektor[i]);
        }
        Console.Write("\n");
    }
    public static Wektor dodaj(Wektor v, Wektor w) {
        if(v.wektorSz!=w.wektorSz) {
            Console.WriteLine("\nWektory roznej dlugosci. Nie mozna dodac");
            return null;
        }
        float[] newCoords = new float[v.wektorSz];
        int i;
        for(i=0; i<v.wektorSz; i++) {
            newCoords[i]=v.wektor[i]+w.wektor[i];
        }
        return new Wektor(newCoords);
    }
    public static float iloczynSkalarny(Wektor v, Wektor w) {
        if(v.wektorSz!=w.wektorSz) {
            Console.WriteLine("\nWektory roznej dlugosci. Nie mozna obliczyc ilocznu.");
            return 0f;
        }
        float iloczyn=0f;
        int i;
        for(i=0; i<v.wektorSz; i++) {
            iloczyn+=v.wektor[i]*w.wektor[i];
        }
        return iloczyn;
    }
    public int vectorSize() {
        return this.wektorSz;
    }
}

public class Macierz {
    Wektor[] macierz;
    int rows;
    int cols;
    
    public Macierz(int r, int c) {
        macierz = new Wektor[r];
        int i;
        for(i=0; i<r; i++) {
            macierz[i]=new Wektor(c);
        }
        rows=r;
        cols=c;
    }
    
    public Macierz(Wektor[] wektory) {
        macierz=wektory;
        rows=wektory.Length;
        cols=wektory[0].vectorSize();
    }
    
    public void drukujMacierz() {
        int i, j;
        for(i=0; i<rows; i++) {
            for(j=0; j<cols; j++) {
                Console.Write("{0, -7} ", macierz[i].wektor[j]);
            }
            Console.Write("\n");
        }
    }
    // m1*m2
    public static Macierz iloczynMacierzy(Macierz m1, Macierz m2) {
        Macierz wynik = new Macierz(m1.rows, m2.cols);
        int i, j, k;
        float w=0f;
        for(i=0; i<m1.rows; i++) {
            for(j=0; j<m2.cols; j++) {
                w=0f;
                // iloczyn skalarny i-tego wiersza m1 i j-tej kol. m2
                for(k=0; k<m1.cols; k++) {
                    w+=m1.macierz[i].wektor[k]*m2.macierz[k].wektor[j];
                }
                wynik.macierz[i].wektor[j]=w;
            }
        }
        return wynik;
    }
    public static Macierz sumaMacierzy(Macierz m1, Macierz m2) {
        if(m1.cols!=m2.cols || m1.rows!=m2.rows) {
            Console.WriteLine("\nMacierze roznych rozmiarow. Nie mozna dodac.");
            return null;
        }
        Macierz wynik = new Macierz(m1.rows, m1.cols);
        int i, j;
        for(i=0; i<m1.rows; i++) {
            for(j=0; j<m1.cols; j++) {
                wynik.macierz[i].wektor[j]=m1.macierz[i].wektor[j]+m2.macierz[i].wektor[j];
            }
        }
        return wynik;
    }
    
    public static Wektor ilocznynMacierzWek(Macierz m, Wektor w) {
        if(w.vectorSize()!=m.cols) {
            Console.WriteLine("\nNie mozna przemnozyc macierzy przez wektor.");
            return null;
        }
        int i;
        Wektor wynik = new Wektor(m.rows);
        for(i=0; i<m.rows; i++) {
            wynik.wektor[i]=Wektor.iloczynSkalarny(m.macierz[i], w);
        }
        return wynik;
    }
}

// zadanie 4 lista 2
using System;
using System.Collections.Generic;

public class ListaLeniwa {
    protected int sz;
    protected List<int> lista;
    Random rnd;
    
    public ListaLeniwa() { // konstruktor
        rnd = new Random();
        lista = new List<int>();
        sz=0;
    }
    protected int blednyArg(int i) {
        Console.WriteLine("Niepoprawny argument(={0}) funkcji element.", i);
        return 0;
    }
    public virtual int element(int n) {
        // jeśli n mniejsze niż rozmiar listy, zwraca wartość el.
        // elementy numerowane od 1
        if(n<=0) return blednyArg(n); 
        if(n<=sz) return lista[n-1];
        else {
            int i=sz;
            while (i<=n) {
                lista.Add(rnd.Next());
                i++;
            }
            sz=n;
            return n;
        } 
    }
    
    public int size() {
        return sz;
    }
    
}

public class Pierwsze : ListaLeniwa {
    
    private bool czyPierwsza(int x) {
        for(int i=2; i<=Math.Sqrt(x); i++) {
            if(x%i==0) return false;
        }
        return true;
    }
    // oblicza kolejną liczbę pierwszą po x
    private int kolejnaPierwsza(int x) {
        for(int i=x+1; i<int.MaxValue; i++) {
            if(czyPierwsza(i)) return i;
        }
        return 0;
    }
    
    public override int element(int i) {
        if(i<=0) return blednyArg(i);
        if(sz==0) {
            lista.Add(2);
            sz++;
        }
        if(i<=sz) return lista[i-1];
        else {
            
            int j=sz, p, prev=lista[j-1];
            while(j<i) {
                p=kolejnaPierwsza(prev);
                if(p!=0) {
                    lista.Add(p);
                    prev=p;
                }
                else {
                    Console.WriteLine("Nie mozna wyznaczyc {0} liczby pierwszej.", i);
                    return 0;
                }
                j++;
                //sz++;
            }
            sz=i;
            return lista[sz-1];
        }
    }
}


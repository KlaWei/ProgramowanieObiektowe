/*  Zadanie 1 lista 2. */
using System;

/* Kolejne liczby pierwsze. */
public class IntStream {
    protected int prev;
    public IntStream() {
        prev=-1;
    }
    public virtual int next() {
        if (prev==int.MaxValue) return -1;
        else {
            prev++;
            return prev;
        }
    }
    public bool eos() { // koniec strumienia
        if(prev==int.MaxValue) return true;
        else return false;
    }
    public virtual void reset() {
        prev=-1;
    }
}

/* Kolejne liczby pierwsze */
public class PrimeStream : IntStream {
    public PrimeStream() {
        prev=1;
    }
    private bool isPrime(int x) {
        for(int i=2; i<=Math.Sqrt(x); i++) {
            if(x%i==0) return false;
        }
        return true;
    }
    public override int next() {
        if(this.eos()) return -1;
        for (int i=prev+1; i<int.MaxValue; i++) {
            if(isPrime(i)) {
                prev=i;
                return i;
            }
        }
        return -1;
    }
    public override void reset() {
        prev=1;
    }
    
}

public class RandomStream : IntStream {
    Random rnd = new Random();
    public override int next() {
        return rnd.Next();
    }
}

public class RandomWordStream {
    PrimeStream ps;
    RandomStream rnd;
    string chars="abcdefghijklmnopqrstuvwyxzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()<>?;}{";
    
    public string next() {
        string wynik=null;
        int x=ps.next();
        for (int i=0; i<x; i++) {
            wynik+=chars[(rnd.next())%chars.Length];
        }
        return wynik;
    }
    
    public void reset() {
        ps.reset();
        rnd.reset();
    }
    
    public RandomWordStream() {
        rnd = new RandomStream();
        ps = new PrimeStream();
    }
}

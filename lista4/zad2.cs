using System;
using System.Collections;

class PrimeEnum : IEnumerator {
    int prime;
    
    public PrimeEnum() {
        prime = 1;
    }
    private bool isPrime(int x) {
       for (int i=2; i<=Math.Sqrt(x); i++) {
          if(x%i==0) return false;
       }
       return true;
    }
    
    public bool MoveNext() {
        if (prime==int.MaxValue) return false;
        while(!(isPrime(++prime)));
        return prime <= int.MaxValue;
    }
    public object Current {
        get {
            return prime;
        }
    }
    public void Reset() {
        prime = 1;
    }
}

public class PrimeCollection : IEnumerable {
    
    public IEnumerator GetEnumerator() {
        return new PrimeEnum();
    }
}

class Test {
    static void Main() {
        PrimeCollection pc = new PrimeCollection();
        foreach (int p in pc) {
            Console.WriteLine(p);
        }
        var enumerator = pc.GetEnumerator();
        Console.WriteLine("current: {0}", enumerator.Current);
        int i;
        for (i=0; i<20; i++) {
            enumerator.MoveNext();
            Console.WriteLine("{1} prime: {0}", enumerator.Current, i+1);
        }
        Console.WriteLine("\nreset enumerator\n");
        enumerator.Reset();
        for (i=0; i<10; i++) {
            enumerator.MoveNext();
            Console.WriteLine("{0} prime {1}", i+1, enumerator.Current);
        }
    }
}

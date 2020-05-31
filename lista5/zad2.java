import java.util.*;

abstract class Wyrazenie {
    public abstract int oblicz();
    public abstract String toString();
}

class Dodaj extends Wyrazenie {
    Wyrazenie a, b;
    
    public Dodaj(Wyrazenie a, Wyrazenie b) {
        this.a=a;
        this.b=b;
    }
    
    public int oblicz() {
        return a.oblicz()+b.oblicz();
    }
    
    public String toString() {
        return a.toString()+"+"+b.toString();
    }
}

class Odejmij extends Wyrazenie {
    Wyrazenie a, b;
    public Odejmij(Wyrazenie a, Wyrazenie b) {
        this.a=a;
        this.b=b;
    }
    public int oblicz() {
        return a.oblicz()-b.oblicz();
    }
    public String toString() {
        return a.toString()+"-"+b.toString();
    }
}

class Pomnoz extends Wyrazenie {
    Wyrazenie a, b;
    public Pomnoz(Wyrazenie a, Wyrazenie b) {
        this.a=a;
        this.b=b;
    }
    public int oblicz() {
        return a.oblicz()*b.oblicz();
    }
    public String toString() {
        return "("+a.toString()+")*("+b.toString()+")";
    }
}

class Stala extends Wyrazenie {
    int val;
    
    public int oblicz() {
        return val;
    }
    public Stala(int val) {
        this.val=val;
    }
    public String toString() {
        return ""+val;
    }
}

class Zmienna extends Wyrazenie {
    int val;
    String nazwa;
    
    public Zmienna(String nazwa, Hashtable<String,Integer> htab) {
        this.nazwa=nazwa;
        this.val=htab.get(nazwa);
    }
    public int oblicz() {
        return val;
    }
    public String toString() {
        return nazwa;
    }
}

class Test {
    public static void main(String[] args) {
        Hashtable<String,Integer> htab = new Hashtable<String,Integer>();
        htab.put("x", 3);
        htab.put("y", 7);
        htab.put("z", 12);
        htab.put("p", 13);
        
        Wyrazenie w = new Odejmij(new Dodaj(new Stala(5), new Zmienna("x", htab)), new Zmienna("y", htab));
        System.out.println("w, wartosc: "+w.oblicz());
        System.out.println("w, napis"+w.toString());
        Wyrazenie w2 = new Pomnoz(w, new Zmienna("z", htab));
        System.out.println("w2, wartosc: "+w2.oblicz());
        System.out.println("w2, napis: "+w2.toString());
        Wyrazenie w3 = new Dodaj(w, w2);
        System.out.println("w3=w+w2, wartosc: "+w3.oblicz());
        System.out.println("w3, napis: "+w3.toString());
    }
}
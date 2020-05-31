// zadanie 1 lista 3
using System;

public class ElementListy<T> {
    private T elem;
    private ElementListy<T> next;
    private ElementListy<T> prev;
    
    public ElementListy(T el) {
        this.elem=el;
        this.next=null;
        this.prev=null;
    }
    public void drukujElem() {
        if(this!=null) Console.Write("{0} ", this.elem);
    }
    public ElementListy<T> Next {
        get{ return this.next; }
        set{ this.next = value; }
    }
    public ElementListy<T> Prev {
        get{ return this.prev; }
        set{ this.prev = value; }
    }
    public T Elem() {
        return this.elem;
    }
}

public class Lista<T> {
    private ElementListy<T> pocz;
    private ElementListy<T> kon;
    private int iloscEl;
    
    public Lista() {
        this.pocz = null;
        this.kon = null;
        this.iloscEl = 0;
    }
    public void dodajKon(T elem) {
        if(this.pocz==null) {
            this.pocz = new ElementListy<T>(elem);
            this.kon = pocz;
        }
        else {
            ElementListy<T> newEl = new ElementListy<T>(elem);
            newEl.Prev=this.kon;
            this.kon.Next=newEl;
            this.kon=newEl;
        }
        iloscEl++;
    }
    public void dodajPocz(T elem) {
        if(this.pocz==null) {
            this.pocz = new ElementListy<T>(elem);
            this.kon = pocz;
        }
        else {
            ElementListy<T> newEl = new ElementListy<T>(elem);
            this.pocz.Prev=newEl;
            newEl.Next=this.pocz;
            this.pocz=newEl;
        }
        iloscEl++;
    }
    
    public T usunKon() {
        T temp;
        if(iloscEl==0) {
            Console.WriteLine("Lista pusta. Nie mozna usunac el.");
            return default(T);
        }
        if(iloscEl==1) {
            temp=pocz.Elem();
            this.pocz=null;
            this.kon=null;
        }
        else {
            temp=this.kon.Elem();
            this.kon=this.kon.Prev;
            this.kon.Next=null;
            
        }
        iloscEl--;
        return temp;
    }
    public T usunPocz() {
        T temp;
        if(iloscEl==0) {
            Console.WriteLine("Lista pusta. Nie mozna usunac el.");
            return default(T);
        }
        if(iloscEl==1) {
            temp=pocz.Elem();
            pocz=null; kon=null;
        }
        else {
            temp=pocz.Elem();
            pocz=pocz.Next;
            pocz.Prev=null;
        }
        iloscEl--;
        return temp;
    }
    public bool empty() {
        return iloscEl==0 ? true : false;
    }
    public void drukujListe() {
        ElementListy<T> temp=pocz;
        int i=0;
        Console.WriteLine("il elem = {0}", iloscEl);
        
        while(i<iloscEl) {
            temp.drukujElem();
            temp=temp.Next;
            i++;
        }
        Console.Write("\n");
    }
}

import java.lang.Exception;

class EmptyCollectionException extends Exception {
    public EmptyCollectionException(String msg) {
        super(msg);
    }
}

public class Kolekcja<T extends Comparable<T>> {
    Element<T> first, last;
    // element kolekcji
    private class Element<T extends Comparable<T>> {
        T elem;
        Element<T> next;
        Element(T e) {
            elem=e;
            next=null;
        }
    }
    
    public Kolekcja() {
        first=null;
        last=null;
    }
    
    public void add(T elem)  {
        Element<T> nowy = new Element<T>(elem);
        if(first==null) {
            first=nowy;
            last=nowy;
        }
        // element mniejszy od pierwszego
        else if(elem.compareTo(first.elem)<0) {
            nowy.next=first;
            first=nowy;
        }
        else {
            Element<T> prev=first;
            Element<T> nxt=first.next;
            while (nxt!=null) {
                if(elem.compareTo(nxt.elem)<0) {
                    prev.next=nowy;
                    nowy.next=nxt;
                    break;
                }
                prev=nxt;
                nxt=nxt.next;
            }
        }
    }
    
    public T remove() throws EmptyCollectionException {
        if(first==null) throw new EmptyCollectionException("Kolekcja pusta!");
        T e=this.first.elem;
        if(this.first!=null) this.first=this.first.next;
        return e;
    }
    
    public void printAll() {
        Element<T> pom=this.first;
        while (pom!=null) {
            System.out.println(pom.elem);
            pom=pom.next;
        }
    }
}

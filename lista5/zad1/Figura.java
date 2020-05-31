
public abstract  class Figura implements Comparable<Figura> {
    public abstract double pole();
    
    public int compareTo(Figura F) {
        if(F.pole()==this.pole()) return 0;
        else if(F.pole()<this.pole()) return 1;
        else return -1;
    }
}

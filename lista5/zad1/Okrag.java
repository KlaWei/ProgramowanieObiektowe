
public class Okrag extends Figura {
    double r;
    String name;
    public Okrag(double r, String name) {
        this.r=r;
        this.name=name;
    }
    public double pole() {
        return Math.PI*r*r;
    }
    public String toString() {
        return "Okrag: "+name+", pole: "+pole();
    }
}
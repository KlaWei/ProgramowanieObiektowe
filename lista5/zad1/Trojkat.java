
public class Trojkat extends Figura {
    double a, h;
    String name;
    public Trojkat(double a, double h, String name) {
        this.a=a;
        this.h=h;
        this.name=name;
    }
    public double pole() {
        return (a*h)/2;
    }
    public String toString() {
        return "Trojkat: "+name+", pole: "+pole();
    }
}
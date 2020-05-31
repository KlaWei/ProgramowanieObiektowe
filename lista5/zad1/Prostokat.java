
public class Prostokat extends Figura {
    double a, b;
    String name;
    public Prostokat(double a, double b, String name) {
        this.a=a;
        this.b=b;
        this.name=name;
    }
    public double pole() {
        return a*b;
    }
    public String toString() {
        return "Prostokat: "+name+", pole: "+pole();
    }
}
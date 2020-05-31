
public class Kwadrat extends Figura {
    double a;
    String name;
    
    public Kwadrat(double a, String name) {
        this.a=a;
        this.name=name;
    }
    public double pole() {
        return a*a;
    }
    public String toString() {
        return "Kwadrat: "+name+", pole: "+pole();
    }
}
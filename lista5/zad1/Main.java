
class Main {
    public static void main(String[] args) {
        Kolekcja<String> k = new Kolekcja<String>();
        k.add("z");
        k.add("b");
        k.add("k");
        k.add("eee");
        System.out.println("Posortowana kolekcja napisow: ");
        k.printAll();
        
        String e;
        try {
            e=k.remove();
            System.out.println("Usuniety: "+e);
            e=k.remove();
            System.out.println("Usuniety: "+e);
            e=k.remove();
            System.out.println("Usuniety: "+e);
            e=k.remove();
            System.out.println("Usuniety: "+e);
            e=k.remove();
            System.out.println("Usuniety: "+e);
            
        } catch (EmptyCollectionException ex) {
            System.out.println(ex.getMessage());
        }
        
        Kolekcja<Figura> kf = new Kolekcja<Figura>();
        kf.add(new Okrag(3.5, "o1"));
        kf.add(new Kwadrat(7, "k1"));
        kf.add(new Kwadrat(6, "k2"));
        kf.add(new Trojkat(2, 9, "t1"));
        kf.add(new Prostokat(2, 2, "p1"));
        kf.add(new Trojkat(2.3, 4, "t2"));
        System.out.println("\nPosortowana kolekcja figur: \n");
        kf.printAll();
    }
}
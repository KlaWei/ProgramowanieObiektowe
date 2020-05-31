using System;

class Przyklad {
    static void Main() {
        int i;
        ListaLeniwa list = new ListaLeniwa();
        Console.WriteLine(list.element(10));
        for(i=1; i<=10; i++) {
            Console.WriteLine(list.element(i));
        }
        list.element(100);
        for(i=5; i<=40; i++) {
            Console.WriteLine("{0} element: {1}", i, list.element(i));
        }
        Console.WriteLine("rozmiar listy leniwej: {0}", list.size());
        Console.WriteLine(list.element(1));
        
        Pierwsze p = new Pierwsze();
        
        Console.WriteLine(p.size());
        Console.WriteLine(p.element(1));
        Console.WriteLine(p.element(0));
        Console.WriteLine(p.element(4));
        Console.WriteLine(p.element(3));
        p.element(20);
        
        for(i=1;i<=30;i++) {
            Console.WriteLine("{0} liczba pierwsza = {1}", i, p.element(i));
        }
        
        Console.WriteLine("rozmiar listy liczb pierwszych: {0}", p.size());
    }
}
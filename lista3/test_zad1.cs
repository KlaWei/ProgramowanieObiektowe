using System;

class Test {
    static void Main() {
        Lista<int> lista= new Lista<int>();
        lista.usunKon();
        lista.usunPocz();
        lista.drukujListe();
        
        int i, j;
        
        for(i=0; i<15; i++) lista.dodajKon(i);
        lista.drukujListe();
        for(i=0; i<15; i++) lista.dodajPocz(i);
        lista.drukujListe();
        
        for(i=0;i<7;i++) {
            j=lista.usunKon();
            Console.WriteLine("1. usuniety elem = {0}", j);
        }
        
        for(i=0;i<6;i++) {
            j=lista.usunPocz();
            Console.WriteLine("2. usuniety elem = {0}", j);
        }
        while (!lista.empty()) {
            j=lista.usunKon();
        }
        
    }
}
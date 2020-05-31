using System;

class Przyklad {
    static void Main() {
        int i;
        PrimeStream ps = new PrimeStream();
        IntStream ins = new IntStream();
        RandomStream rnd = new RandomStream();
        RandomWordStream rndws = new RandomWordStream();
        Console.WriteLine(rnd.next());
        Console.WriteLine(rnd.next());
        Console.WriteLine(rnd.next());
        Console.WriteLine(ins.next());
        Console.WriteLine(ps.next());
        Console.WriteLine(ps.next());
        Console.WriteLine(ps.next());
        
        Console.WriteLine(rndws.next());
        Console.WriteLine(rndws.next());
        Console.WriteLine(rndws.next());
        
        rnd.reset();
        ins.reset();
        ins.next();
        for(i=0;i<10;i++) {
            Console.WriteLine("{0} losowa liczba: {1}", ins.next(), rnd.next());
        }
        
        rndws.reset();
        ps.reset();
        for(i=0; i<15; i++) {
            Console.WriteLine("slowo o dl = {0}: {1}", ps.next(),rndws.next());
        }
        ps.reset();
        for(i=0; i<30; i++) {
            Console.WriteLine("{0} liczba pierwsza = {1}", i+1, ps.next());
        }
        ins.reset();
        int p=0;
        while(!ins.eos()) {
            p=ins.next();
        }
        Console.WriteLine("najwieksza liczba typu int = {0}", p);
    }
}

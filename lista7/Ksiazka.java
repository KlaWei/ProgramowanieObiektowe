import java.io.*;

public class Ksiazka implements Serializable {
    private static final long serialVersionUID=3167653491020364677L;
    public String autor, tytul;
    public  int rok_wyd;
    public Ksiazka(String autor, String tytul, int rok_wyd) {
        this.autor=autor;
        this.tytul=tytul;
        this.rok_wyd=rok_wyd;
    }
    public Ksiazka() {
        autor="Autor";
        tytul="Tytul";
        rok_wyd=1000;
    }
    public String toString() {
        return autor+"\n"+tytul+"\n"+rok_wyd+"\n";
    }
    
    
}
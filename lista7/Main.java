import java.awt.*;
import javax.swing.*;

public class Main {
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable(){
            public void run() {
                JFrame jf;
                if (args[1].equals("Ksiazka")) {
                        jf = new InterfejsKsiazka(args[0]);
                        jf.setVisible(true);
                }
            }
        });
    }
}
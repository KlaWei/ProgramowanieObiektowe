import javax.swing.*;
import java.util.*;
import java.io.*;
import java.awt.event.*;
import java.awt.*;

public class InterfejsKsiazka extends JFrame implements Serializable, ActionListener {
    private static final long serialVersionUID = 1L;
    public JButton zapisz, otworz; // do zapisywania i otwierania z pliku
    public JTextField autor, tytul, rok;
    Ksiazka ksiazka;
    
    public InterfejsKsiazka(String f) {
        //System.out.print("nowy interfejs\n");
        inicjalizacjaUI();
        
        ksiazka = new Ksiazka();
        if(f!="") {
            File file = new File(f);
            readFromFile(file);
        }
    }
    
    void readFromFile(File f) {
        try {
            FileReader fr = new FileReader(f);
            BufferedReader br = new BufferedReader(fr);
            ksiazka.autor = br.readLine();
            ksiazka.tytul = br.readLine();
            ksiazka.rok_wyd = Integer.parseInt(br.readLine());
            
            autor.setText(ksiazka.autor);
            tytul.setText(ksiazka.tytul);
            rok.setText(Integer.toString(ksiazka.rok_wyd));
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    void writeToFile(File f) {
        try {
            
            FileWriter fw = new FileWriter(f, true);
            BufferedWriter bw = new BufferedWriter(fw);
            ksiazka = new Ksiazka(autor.getText(), tytul.getText(), Integer.parseInt(rok.getText()));
            bw.write(ksiazka.toString());
            bw.close();
            fw.close();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    public void actionPerformed(ActionEvent e) {
        Object src = e.getSource();
        if (src==zapisz) {
            JFileChooser file_chooser = new JFileChooser();
            int res = file_chooser.showSaveDialog(zapisz);
            if (res == JFileChooser.APPROVE_OPTION) {
                File f = file_chooser.getSelectedFile();
                writeToFile(f);
            }
            
        }
        if (src==otworz) {
            JFileChooser file_chooser = new JFileChooser();
            int res = file_chooser.showOpenDialog(otworz);
            if (res==JFileChooser.APPROVE_OPTION) {
                File f = file_chooser.getSelectedFile();
                readFromFile(f);
            }
        }
    }
    void inicjalizacjaUI() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300,300);
        setLocation(50,50);
        setLayout(new GridLayout(4,2));
        
        JLabel author = new JLabel("Autor:" );
        add(author);
        autor = new JTextField("");
        autor.setBounds(200,10,200,30);
        add(autor);
        
        JLabel title = new JLabel("Tytul:" );
        add(title);
        tytul = new JTextField("");
        tytul.setBounds(200,10,200,30);
        add(tytul);
        
        JLabel year = new JLabel("Rok wydania:" );
        add(year);
        rok = new JTextField("");
        rok.setBounds(200,10,200,30);
        add(rok);
        
        zapisz = new JButton("Zapisz do pliku");
        otworz = new JButton("Otwórz z pliku");
        zapisz.setBounds(0, 10, 200, 30);
        otworz.setBounds(0, 50, 200, 30);
        add(zapisz);
        add(otworz);
        
        zapisz.addActionListener(this);
        otworz.addActionListener(this);
        
        setVisible(true);
    }
}
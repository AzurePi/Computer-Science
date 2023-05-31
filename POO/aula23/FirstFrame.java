package aula23;

import javax.swing.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class FirstFrame extends JFrame {

    public FirstFrame() {

        //se não quisermos definir uma classe separada para tratar o evento, podemos criar uma classe anônima
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

}

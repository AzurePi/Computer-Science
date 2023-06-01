package aula23_24;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class FirstFrame extends JFrame {

    public FirstFrame(String name) {
        setTitle(name);
        setSize(300, 200);
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        Container contentPane = getContentPane();
        contentPane.add(new MyWorkPanel());

        //se não quisermos definir uma classe separada para tratar o evento, podemos criar uma classe anônima
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

}

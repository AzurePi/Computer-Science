package aula20_21_22;

import javax.swing.*;
import java.awt.*;

public class GridLayoutExample {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                createAndShowGUI();
            }
        });
    }

    private static void createAndShowGUI() {
        JFrame f = new JFrame("Swing Hello World!");
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setSize(400, 200);
        f.setVisible(true);

        GridLayout gridLayout = new GridLayout(2, 3, 5, 5);
        f.setLayout(gridLayout);

        String[] names = {"one", "two", "three", "four", "five", "six"};
        JButton[] buttons = new JButton[names.length];

        for (int i = 0; i < names.length; i++) {
            buttons[i] = new JButton(names[i]);
            f.add(buttons[i]);
        }
    }
}

package aula20_21_22;

import javax.swing.*;
import java.awt.*;

public class BorderLayoutExample {
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

        BorderLayout borderLayout = new BorderLayout(5, 5);
        f.setLayout(borderLayout);

        String[] names = {"Hide North", "Hide South", "Hide East", "Hide West", "Hide Center"};
        JButton[] buttons = new JButton[names.length];

        for (int i = 0; i < names.length; i++)
            buttons[i] = new JButton(names[i]);

        f.add(buttons[0], BorderLayout.NORTH);
        f.add(buttons[1], BorderLayout.SOUTH);
        f.add(buttons[2], BorderLayout.EAST);
        f.add(buttons[3], BorderLayout.WEST);
        f.add(buttons[4], BorderLayout.CENTER);
    }
}

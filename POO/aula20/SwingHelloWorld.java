package aula20;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;

public class SwingHelloWorld {
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
        f.setSize(300, 300);
        f.setVisible(true);

        JLabel label;
        label = new JLabel("Text-only label");
        label.setHorizontalTextPosition(SwingConstants.CENTER);
        f.add(label);

        f.setLayout(new FlowLayout());

        JTextField tField1, tField2, tField3;
        tField1 = new JTextField(10);
        tField2 = new JTextField("Enter text here");
        tField3 = new JTextField("Uneditable text field", 21);
        tField3.setEditable(false);
        f.add(tField1); f.add(tField2); f.add(tField3);

        JPasswordField passField = new JPasswordField("Hidden text");
        f.add(passField);

        String name = tField1.getText();
        char[] pass = passField.getPassword();

        JButton b1, b2, b3;
        b1 = new JButton("Disable middle button");
        b1.setVerticalTextPosition(AbstractButton.CENTER);
        b1.setHorizontalTextPosition(AbstractButton.LEADING);
        b1.setMnemonic(KeyEvent.VK_D); //cria um atalho para o botão

        b2 = new JButton("Middle button");
        b2.setVerticalTextPosition(AbstractButton.BOTTOM);
        b2.setHorizontalTextPosition(AbstractButton.CENTER);
        b2.setMnemonic(KeyEvent.VK_M);

        b3 = new JButton("Enable middle button");
        b3.setMnemonic(KeyEvent.VK_E);
        b3.setEnabled(false);

        f.add(b1); f.add(b2); f.add(b3);

    }
}

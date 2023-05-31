package aula23;

import javax.swing.*;
import java.awt.*;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

public class MyPanelFocus extends JPanel {
    private final JButton yellowButton = new JButton("Yellow");
    private final JButton blueButton = new JButton("Blue");
    private final JButton redButton = new JButton("Red");

    public MyPanelFocus() {
        this.add(yellowButton);
        this.add(blueButton);
        this.add(redButton);

        yellowButton.addFocusListener(new FocusListener());
        blueButton.addFocusListener(new FocusListener());
        redButton.addFocusListener(new FocusListener());

        yellowButton.addKeyListener(new KeyboardListener());
        blueButton.addKeyListener(new KeyboardListener());
        redButton.addKeyListener(new KeyboardListener());
    }

    class FocusListener extends FocusAdapter {
        public void focusGained(FocusEvent e){
            Object source = e.getComponent();

            if(source == yellowButton)
                setBackground(Color.YELLOW);
            else if (source == blueButton)
                setBackground(Color.BLUE);
            else if (source == redButton)
                setBackground(Color.RED);
        }
    }

    class KeyboardListener extends KeyAdapter {
        public void keyPressed(KeyEvent e) {
            if(e.getKeyCode() == KeyEvent.VK_Y)
                setBackground(Color.YELLOW);
            else if (e.getKeyCode() == KeyEvent.VK_R)
                setBackground(Color.RED);
            else if(e.getKeyCode() == KeyEvent.VK_B)
                setBackground(Color.BLUE);
            else if (e.getKeyCode() == KeyEvent.VK_P)
                setBackground(Color.MAGENTA);
        }
    }

}

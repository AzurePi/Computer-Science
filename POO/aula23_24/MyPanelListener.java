package aula23_24;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyPanelListener extends JPanel implements ActionListener {
    private final JButton yellowButton = new JButton("Yellow");
    private final JButton blueButton = new JButton("Blue");
    private final JButton redButton = new JButton("Red");

    public MyPanelListener() {
        this.add(yellowButton);
        this.add(blueButton);
        this.add(redButton);

        yellowButton.addActionListener(e -> setBackground(Color.YELLOW)); //faz a ação direta
        blueButton.addActionListener(this);
        redButton.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent evt) {
        Object source = evt.getSource();

        if (source == blueButton)
            setBackground(Color.BLUE);
        else if (source == redButton)
            setBackground(Color.RED);
    }
}

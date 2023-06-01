package aula23_24;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MulticastPanel extends JPanel implements ActionListener {
    private int counter = 0;
    private JButton closeAllButton = new JButton("Close All");
    private JButton newButton = new JButton("New");

    public MulticastPanel() {
        this.add(newButton);
        this.add(closeAllButton);
        newButton.addActionListener(this);
        closeAllButton.addActionListener(this);
    }

    public int getCounter() {
        return counter;
    }

    public void setCounter(int counter) {
        this.counter = counter;
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == closeAllButton)
            counter = 0;
        else if (e.getSource() == newButton){
            SimpleFrame f = new SimpleFrame();
            counter++;
            f.setTitle("Window " + this.counter);
            f.setBounds(30 * counter, 30 * counter, 200, 150);
            f.setVisible(true);
            closeAllButton.addActionListener(f);
        }
    }
}

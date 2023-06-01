package aula23_24;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MyWorkPanel extends JPanel {
    private final JButton edtButton = new JButton("EDT");
    private final JButton swButton = new JButton("SwingWorker");
    private final int sleepTime = 5000;

    public MyWorkPanel() {
        this.add(edtButton);
        this.add(swButton);

        edtButton.addActionListener(new ButtonListener());
        swButton.addActionListener(new ButtonListener());
    }

    private class ButtonListener implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent e) {
            Object source = e.getSource();

            if (source == edtButton) {
                setBackground(Color.YELLOW);

                try {
                    Thread.sleep(sleepTime);
                    JOptionPane.showMessageDialog(null,
                            "Finished. Sleep time: " + sleepTime,
                            "Event dispatch example",
                            JOptionPane.INFORMATION_MESSAGE);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }

            } else if (source == swButton) {
                setBackground(Color.BLUE);

                ButtonWorker bw = new ButtonWorker(sleepTime);
                bw.execute();
            }
        }
    }
}

package aula23_24;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class MouseEventExample extends JFrame {
    private JLabel positionLabel;

    public MouseEventExample() {
        setTitle("Mouse Event Events");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        positionLabel = new JLabel("Position: ");
        add(positionLabel, BorderLayout.SOUTH);

        //classe anônima que implementa MouseListener
        addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int x = e.getX();
                int y = e.getY();
                int clickCount = e.getClickCount();
                int button = e.getButton();

                System.out.println("Mouse clicked at (" + x + ", " + y + ")");
                System.out.println("Click count: " + clickCount);
                System.out.println("Button: " + button);
            }

            @Override
            public void mousePressed(MouseEvent e) {
            }

            @Override
            public void mouseReleased(MouseEvent e) {
            }

            @Override
            public void mouseEntered(MouseEvent e) {
            }

            @Override
            public void mouseExited(MouseEvent e) {
            }
        });

        //classe anônima que implementa MouseMotionListener
        addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
            }

            @Override
            public void mouseMoved(MouseEvent e) {
                int x = e.getX();
                int y = e.getY();

                positionLabel.setText("Position: (" + x + ", " + y + ")");
            }
        });
    }

}

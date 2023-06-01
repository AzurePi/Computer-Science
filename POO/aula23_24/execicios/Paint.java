package aula23_24.execicios;

import javax.swing.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class Paint {

    public static void main(String[] args){
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                PaintGUI();
            }
        });
    }

    private static void PaintGUI() {
        JFrame f = new JFrame("Paint");
        JPanel p = new JPanel();

        p.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
                //armazenar os ponto clicados
                //atualizar a cor do background
            }

            @Override
            public void mouseMoved(MouseEvent e) {
            }
        });



    }
}

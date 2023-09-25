package aula23_24;

import javax.swing.*;

public class Main {
    public static void main(String[] args){
        /*          Janela que muda de Cor
        JFrame frame = new JFrame("Color changer");

        //MyPanelListener panel = new MyPanelListener();
        MyPanelFocus panel = new MyPanelFocus();
        frame.add(panel);
        */

        /*          Janela com mouse tracker
        JFrame frame = new MouseEventExample();
        */

        /*          Janelas com multicast
        JFrame frame = new JFrame("Teste de Multicast");
        JPanel panel = new MulticastPanel();
        frame.add(panel);
        */

        JFrame frame = new FirstFrame("");

        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300,300);
        frame.setVisible(true);
    }
}

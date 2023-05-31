package aula23;

import javax.swing.*;

public class Main {
    public static void main(String[] args){
        JFrame frame = new JFrame("Color changer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //MyPanelListener panel = new MyPanelListener();
        MyPanelFocus panel = new MyPanelFocus();
        frame.add(panel);

        frame.setSize(300,300);
        frame.setVisible(true);
    }
}

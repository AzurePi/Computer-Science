package aula20_21_22;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.KeyEvent;
import java.io.File;

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
        f.setSize(580, 600);
        f.setVisible(true);

        JLabel label;
        label = new JLabel("Text-only label");
        label.setHorizontalTextPosition(SwingConstants.CENTER);
        f.add(label);

        FlowLayout flowLayout = new FlowLayout();
        flowLayout.setAlignment(FlowLayout.CENTER);
        f.setLayout(flowLayout);

        /*  Cross-platform look & feel
        try{
            UIManager.setLookAndFeel(UIManager.getCrossPlatformLookAndFeelClassName());
        }catch (UnsupportedLookAndFeelException | ClassNotFoundException | IllegalAccessException |
                InstantiationException e){
            throw new RuntimeException(e);
        }
        */

        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (UnsupportedLookAndFeelException | ClassNotFoundException | InstantiationException |
                 IllegalAccessException e) {
            throw new RuntimeException(e);
        }

        /*
        try {
            UIManager.setLookAndFeel("com.sun.java.swing.plaf.motif.MotifLookAndFeel");
        } catch (UnsupportedLookAndFeelException | ClassNotFoundException | InstantiationException |
                 IllegalAccessException e) {
            throw new RuntimeException(e);
        }
        */

        /*
        try {
            for (UIManager.LookAndFeelInfo info : UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (UnsupportedLookAndFeelException | ClassNotFoundException | InstantiationException |
                 IllegalAccessException e) {
            throw new RuntimeException(e);
        }
        */

        JTextField tField1, tField2, tField3;
        tField1 = new JTextField(10);
        tField2 = new JTextField("Enter text here");
        tField3 = new JTextField("Uneditable text field", 21);
        tField3.setEditable(false);
        f.add(tField1);
        f.add(tField2);
        f.add(tField3);

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

        f.add(b1);
        f.add(b2);
        f.add(b3);

        JRadioButton birdButton = new JRadioButton("Bird");
        birdButton.setMnemonic(KeyEvent.VK_B);

        JRadioButton catButton = new JRadioButton("Cat");
        catButton.setMnemonic(KeyEvent.VK_C);
        catButton.setSelected(true);

        JRadioButton pigButton = new JRadioButton("Pig");
        pigButton.setMnemonic(KeyEvent.VK_R);

        f.add(birdButton);
        f.add(catButton);
        f.add(pigButton);

        ButtonGroup radioGroup = new ButtonGroup();
        radioGroup.add(birdButton);
        radioGroup.add(catButton);
        radioGroup.add(pigButton);

        //Aula 21 ---------------------------------------------------------------

        if (birdButton.isSelected())
            System.out.println("Bird button is selected");
        else if (catButton.isSelected())
            System.out.println("Cat button is selected");
        else if (pigButton.isSelected())
            System.out.println("Rabbit button is selected");

        radioGroup.clearSelection();

        JCheckBox chinButton = new JCheckBox("Chin");
        chinButton.setMnemonic(KeyEvent.VK_C);
        chinButton.setSelected(true);

        JCheckBox noseButton = new JCheckBox("Nose");
        noseButton.setMnemonic(KeyEvent.VK_N);
        noseButton.setSelected(true);

        JCheckBox foreheadButton = new JCheckBox("Forehead");
        foreheadButton.setMnemonic(KeyEvent.VK_C);
        foreheadButton.setSelected(true);

        f.add(chinButton);
        f.add(noseButton);
        f.add(foreheadButton);

        String[] petStrings = {"Bird", "Cat", "Pig"};
        JComboBox<String> petCombo = new JComboBox<>(petStrings);
        petCombo.setSelectedIndex(2);

        f.add(petCombo);

        DefaultListModel<String> listModel = new DefaultListModel<>();
        listModel.addElement("Jane Doe");
        listModel.addElement("John Smith");
        listModel.addElement("Kathy Green");

        JList<String> list = new JList(listModel);
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.setLayoutOrientation(JList.VERTICAL_WRAP);

        f.add(list);

        String[] colNames = {"Name", "Sport", "Years", "Vegetarian"};

        Object[][] data = {
                {"Kathy", "Snowboarding", 5, Boolean.FALSE},
                {"John", "Rowing", 3, Boolean.TRUE},
                {"Jane", "Speed reading", 10, Boolean.FALSE}
        };

        JTable table = new JTable(data, colNames);
        table.setPreferredScrollableViewportSize(new Dimension(500, 80));
        table.setFillsViewportHeight(true);

        JScrollPane scrollPane = new JScrollPane(table);
        f.add(scrollPane);

        JPanel panel1 = new JPanel();
        JPanel panel2 = new JPanel();

        panel1.setBackground(Color.BLUE);
        panel1.setPreferredSize(new Dimension(100, 100));

        panel2.setBackground(Color.RED);
        panel2.setPreferredSize(new Dimension(200, 200));
        panel2.setBorder((BorderFactory.createTitledBorder("Red Panel")));

        f.add(panel1);
        f.add(panel2);

        JMenuBar menuBar = new JMenuBar();

        JMenu menu1 = new JMenu("A Menu");
        menu1.setMnemonic(KeyEvent.VK_A);
        menuBar.add(menu1);

        JMenuItem menuItem = new JMenuItem("A text-only menu item", KeyEvent.VK_T);
        menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_1, ActionEvent.ALT_MASK));
        menu1.add(menuItem);

        menuItem = new JMenuItem("Both text and icon", new ImageIcon("images/middle.gif"));
        menuItem.setMnemonic(KeyEvent.VK_B);
        menu1.add(menuItem);

        menu1.addSeparator();

        ButtonGroup group = new ButtonGroup();
        JRadioButtonMenuItem rbMenuItem = new JRadioButtonMenuItem("A radio button menu item");
        rbMenuItem.setSelected(true);
        group.add(rbMenuItem);
        menu1.add(rbMenuItem);
        rbMenuItem = new JRadioButtonMenuItem("Another one");
        group.add(rbMenuItem);
        menu1.add(rbMenuItem);

        menu1.addSeparator();

        JCheckBoxMenuItem cbMenuItem = new JCheckBoxMenuItem("A checkbox menu item");
        cbMenuItem.setMnemonic(KeyEvent.VK_C);
        menu1.add(cbMenuItem);

        cbMenuItem = new JCheckBoxMenuItem("Another one");
        cbMenuItem.setMnemonic(KeyEvent.VK_H);
        menu1.add(cbMenuItem);

        menu1.addSeparator();

        JMenu submenu = new JMenu("A submenu");
        submenu.setMnemonic(KeyEvent.VK_S);


        menuItem = new JMenuItem("An item in the submenu");
        menuItem.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_2, ActionEvent.ALT_MASK));
        submenu.add(menuItem);

        menuItem = new JMenuItem("Another item");
        submenu.add(menuItem);
        menu1.add(submenu);

        JMenu menu2 = new JMenu("Another menu");
        menu2.setMnemonic(KeyEvent.VK_N);
        menuBar.add(menu2);

        f.setJMenuBar(menuBar);

        //Aula 21 ---------------------------------------------------------------
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter("JPG & GIF Images", "jpg", "gif");
        chooser.setFileFilter(filter);

        int returVal = chooser.showSaveDialog(f);
        if (returVal == JFileChooser.APPROVE_OPTION) {
            File selectedFile = chooser.getSelectedFile();
            System.out.println("You chose: " + selectedFile.getName());
        }

        JOptionPane.showMessageDialog(f, "Eggs are not suposed to be green.", "Inane error", JOptionPane.ERROR_MESSAGE);
        int opt = JOptionPane.showConfirmDialog(f, "Do you understand?", "Please, answer!", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
    }
}

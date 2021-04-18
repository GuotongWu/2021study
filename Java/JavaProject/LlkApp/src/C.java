// Decompiled by Jad v1.5.7g. Copyright 2000 Pavel Kouznetsov.
// Jad home page: http://www.geocities.com/SiliconValley/Bridge/8617/jad.html
// Decompiler options: packimports(3) fieldsfirst ansi 
// Source File Name:   MUKT

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.HashMap;
import javax.swing.*;

public class C extends JFrame
    implements ActionListener
{
    static int GRAY = 14;
    static int I = 18;
    boolean MUKT;
    JToggleButton add[][];
    JToggleButton addActionListener;
    B Z;

    JMenuBar append;
    JMenu clear;
    JMenu createEmptyBorder;
    JMenuItem createHorizontalStrut;
    JMenuItem createLineBorder;
    JMenuItem createVerticalStrut;
    JMenuItem continueGame;
    JMenuItem equals;

    Timer exit;
    JProgressBar C;
    HashMap B;
    JPanel get;

    String [][] imagetext;
    boolean [][] isButtonEnable;

    public C()
    {
        isButtonEnable = new boolean[GRAY][I];
        for(int i=0; i<GRAY; ++i)
            for(int j=0; j<I; ++j)
                isButtonEnable[i][j] = true;
        imagetext = new String[GRAY][I];

        MUKT = false;
        add = new JToggleButton[GRAY][I];
        addActionListener = null;
        append = new JMenuBar();
        B = new HashMap();
        Z = new B();
        C = new JProgressBar(0, 600);
        C.setValue(0);
        C.setStringPainted(true);
        exit = new Timer(1000, new I(this));
        Rectangle rectangle = GraphicsEnvironment.getLocalGraphicsEnvironment().getMaximumWindowBounds();
        setSize(800, 600);
        setLocation(rectangle.width / 2 - 400, rectangle.height / 2 - 300);
        setResizable(false);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setTitle("JAVA GAME");
        
        Z = new B();
        clear = new JMenu("Menu");
        clear.setMnemonic('g');
        createEmptyBorder = new JMenu("Help");
        createEmptyBorder.setMnemonic('h');
        createHorizontalStrut = new JMenuItem("New Game");
        createHorizontalStrut.setAccelerator(KeyStroke.getKeyStroke(113, 0));
        createHorizontalStrut.setMnemonic('s');

        continueGame = new JMenuItem("Continue");
        continueGame.setAccelerator(KeyStroke.getKeyStroke(114, 0));
        continueGame.setMnemonic('q');

        createVerticalStrut = new JMenuItem("Hint");
        createVerticalStrut.setAccelerator(KeyStroke.getKeyStroke(116, 0));
        createVerticalStrut.addActionListener(this);
        createVerticalStrut.setEnabled(false);
        createVerticalStrut.setMnemonic('m');
        createLineBorder = new JMenuItem("Exit");
        createLineBorder.setMnemonic('x');
        equals = new JMenuItem("About");
        equals.setMnemonic('a');
        append.add(clear);
        append.add(createEmptyBorder);
        clear.add(createHorizontalStrut);
        clear.add(continueGame);
        clear.add(createVerticalStrut);
        clear.add(createLineBorder);
        createEmptyBorder.add(equals);
        clear.setFont(new Font("dialog", 0, 14));
        createEmptyBorder.setFont(new Font("Dialog", 0, 14));
        continueGame.setFont(new Font("Dialog", 0, 14));
        createHorizontalStrut.setFont(new Font("Dialog", 0, 14));
        createLineBorder.setFont(new Font("Dialog", 0, 14));
        equals.setFont(new Font("Dialog", 0, 14));
        createVerticalStrut.setFont(new Font("Dialog", 0, 14));
        setJMenuBar(append);
        createHorizontalStrut.addActionListener(this);
        createLineBorder.addActionListener(this);
        equals.addActionListener(this);
        continueGame.addActionListener(this);
    }

    public final void actionPerformed(ActionEvent actionevent)
    {
        if(actionevent.getSource() instanceof JToggleButton)
        {
            JToggleButton jtogglebutton = (JToggleButton)actionevent.getSource();
            if(MUKT)
            {
                if(addActionListener.getActionCommand().equals(jtogglebutton.getActionCommand()) && addActionListener != jtogglebutton)
                {
                    Point point = (Point)B.get(addActionListener);
                    Point point1 = (Point)B.get(jtogglebutton);
                    if(Z.I(point.x, point.y, point1.x, point1.y))
                    {
                        Z.I(point.x, point.y, 0);
                        Z.I(point1.x, point1.y, 0);
                        addActionListener.setIcon(null);
                        addActionListener.setEnabled(false);

                        isButtonEnable[point.x][point.y] = false;
                        isButtonEnable[point1.x][point1.y] = false;

                        jtogglebutton.setIcon(null);
                        jtogglebutton.setEnabled(false);
                        if(Z.C() == null)
                        {
                            Z.B();
                            I();
                        }
                        if(Z.Z())
                        {
                            JOptionPane.showMessageDialog(null, "Successful!");
        					exit.stop();
                    	}
                    }
                    MUKT = false;
                    addActionListener.setSelected(false);
                    jtogglebutton.setSelected(false);
                } else
                {
                    MUKT = false;
                    addActionListener.setSelected(false);
                    jtogglebutton.setSelected(false);
                }
            } else
            {
                addActionListener = (JToggleButton) jtogglebutton;
                MUKT = true;
                jtogglebutton.setSelected(true);
            }
        } else
        if(actionevent.getSource() instanceof JMenuItem)
        {
            JMenuItem jmenuitem = (JMenuItem)actionevent.getSource();
            if(jmenuitem == createHorizontalStrut)
                GRAY();
            else if(jmenuitem == continueGame){
                String filePath = "game.txt";
                File file = new File(filePath);
                loadGameDataFromFile(file);
            }else
            if(jmenuitem == createVerticalStrut)
            {
                if(Z.C() != null)
                    (new Z(this)).start();
                else{
                    JOptionPane.showMessageDialog(null, "no path!");
				}
            } else
            if(jmenuitem == createLineBorder) {
                int n = JOptionPane.showConfirmDialog(this, "Do you want to save the game?", "Exit", JOptionPane.YES_NO_CANCEL_OPTION);
                if(n == JOptionPane.YES_OPTION){
                    // save the game to the file
                    String filePath = "game.txt";
                    File file = new File(filePath);
                    saveGameDataToFile(file);
                    System.exit(0);
                }
                else if(n == JOptionPane.CANCEL_OPTION){
                    // return to the game
                }
                else{
                    // exit
                    System.exit(0);
                }
            }
            else
            if(jmenuitem == equals)
            {
            	JOptionPane.showMessageDialog(null, "Java Game");
            }
        }
        SwingUtilities.updateComponentTreeUI(this);
    }

    public final void GRAY()
    {
        getContentPane().add(Box.createHorizontalStrut(20), "West");
        getContentPane().add(Box.createHorizontalStrut(20), "East");
        getContentPane().add(Box.createVerticalStrut(20), "South");
        get = new JPanel();
        get.setBackground(Color.white);
        get.setBorder(BorderFactory.createLineBorder(Color.GRAY, 2));
        getContentPane().add(get, "Center");
        get.setLayout(new GridLayout(14, 18, 5, 5));
        Z.I();
        for(int i = 0; i < GRAY; i++)
        {
            for(int j = 0; j < I; j++)
            {
                if(i == 0 || j == 0 || i == GRAY - 1 || j == I - 1)
                {
                    add[i][j] = new JToggleButton();
                    add[i][j].getModel().setEnabled(false);
                    add[i][j].setActionCommand(String.valueOf(0));
                } else
                {
                    int k = Z.I(i, j);
                    String s = "/images/" + k + ".gif";

                    imagetext[i][j] = s;

                    java.net.URL url = getClass().getResource(s);
                    add[i][j] = new JToggleButton(new ImageIcon(url));
                    add[i][j].setActionCommand(String.valueOf(k));
                }
                add[i][j].setBackground(Color.white);
                add[i][j].setBorder(BorderFactory.createEmptyBorder());
                add[i][j].addActionListener(this);
                get.add(add[i][j]);
                B.put(add[i][j], new Point(i, j));
                B.put(new Point(i, j), add[i][j]);
            }

        }

        JPanel jpanel = new JPanel();
        jpanel.setBorder(BorderFactory.createLineBorder(jpanel.getBackground(), 5));
        jpanel.setLayout(new BorderLayout());
        jpanel.add(C, "Center");
        getContentPane().add(jpanel, "North");
        createVerticalStrut.setEnabled(true);
        exit.start();
        createHorizontalStrut.setEnabled(false);
    }

    public void saveGameDataToFile(File file)
    {
        try{
            FileOutputStream fileSream = new FileOutputStream(file);
            ObjectOutputStream objectSteam = new ObjectOutputStream(fileSream);
            objectSteam.writeObject(MUKT);
            objectSteam.writeObject(Z);
            objectSteam.writeObject(exit);
            objectSteam.writeObject(C);
            objectSteam.writeObject(isButtonEnable);
            objectSteam.writeObject(imagetext);
            objectSteam.close();
            fileSream.close();

            JOptionPane.showConfirmDialog(this, "Save Successfully","Exit",JOptionPane.DEFAULT_OPTION);
        }catch (Exception e){
            JOptionPane.showConfirmDialog(this, e.toString() + "\nFail to Save", "Error", JOptionPane.DEFAULT_OPTION);
        }
    }

    public void loadGameDataFromFile(File file)
    {
        try {
            FileInputStream filestream = new FileInputStream(file);
            ObjectInputStream objectStream = new ObjectInputStream(filestream);
            MUKT = (boolean) objectStream.readObject();
            Z = (B) objectStream.readObject();
            exit = (Timer) objectStream.readObject();
            C = (JProgressBar) objectStream.readObject();
            isButtonEnable = (boolean[][]) objectStream.readObject();
            imagetext = (String[][]) objectStream.readObject();
            objectStream.close();
            filestream.close();

            getContentPane().add(Box.createHorizontalStrut(20), "West");
            getContentPane().add(Box.createHorizontalStrut(20), "East");
            getContentPane().add(Box.createVerticalStrut(20), "South");
            get = new JPanel();
            get.setBackground(Color.white);
            get.setBorder(BorderFactory.createLineBorder(Color.GRAY, 2));
            getContentPane().add(get, "Center");
            get.setLayout(new GridLayout(14, 18, 5, 5));
//            Z.I();
            for(int i = 0; i < GRAY; i++) {
                for(int j = 0; j < I; j++) {
                    if(i == 0 || j == 0 || i == GRAY - 1 || j == I - 1)
                    {
                        add[i][j] = new JToggleButton();
                        add[i][j].getModel().setEnabled(false);
                        add[i][j].setActionCommand(String.valueOf(0));
                    } else
                    {
                        String s = imagetext[i][j];
                        String k = s.substring(s.indexOf("/")+ 1,s.indexOf("."));

                        java.net.URL url = getClass().getResource(s);
                        add[i][j] = new JToggleButton(new ImageIcon(url));
                        add[i][j].setActionCommand(k);
                    }
                    add[i][j].setBackground(Color.white);
                    add[i][j].setBorder(BorderFactory.createEmptyBorder());
                    add[i][j].addActionListener(this);

                    if(!isButtonEnable[i][j]) {
                        add[i][j].setIcon(null);
                        add[i][j].setEnabled(false);
                    }

                    get.add(add[i][j]);
                    B.put(add[i][j], new Point(i, j));
                    B.put(new Point(i, j), add[i][j]);
                }
            }

            JPanel jpanel = new JPanel();
            jpanel.setBorder(BorderFactory.createLineBorder(jpanel.getBackground(), 5));
            jpanel.setLayout(new BorderLayout());
            jpanel.add(C, "Center");
            getContentPane().add(jpanel, "North");
            createVerticalStrut.setEnabled(true);
            exit.start();
            createHorizontalStrut.setEnabled(false);
        } catch (Exception e) {
            JOptionPane.showConfirmDialog(this, e.toString() + "\nFail to Load Game", "Error", JOptionPane.DEFAULT_OPTION);
        }
    }

    public final void I()
    {
        B.clear();
        for(int i = 0; i < GRAY; i++)
        {
            for(int j = 0; j < I; j++)
            {
                if(i == 0 || j == 0 || i == GRAY - 1 || j == I - 1)
                {
                    add[i][j].setIcon(null);
                    add[i][j].setEnabled(false);
                    add[i][j].setActionCommand(String.valueOf(0));
                } else
                if(Z.I(i, j) == 0)
                {
                    add[i][j].setIcon(null);
                    add[i][j].setEnabled(false);
                    add[i][j].setActionCommand(String.valueOf(0));
                } else
                {
                    int k = Z.I(i, j);
                    String s = "/images/" + k + ".gif";
                    java.net.URL url = getClass().getResource(s);
                    add[i][j].setIcon(new ImageIcon(url));
                    add[i][j].setEnabled(true);
                    add[i][j].setActionCommand(String.valueOf(k));
                }
                add[i][j].setBorder(BorderFactory.createEmptyBorder());
                B.put(add[i][j], new Point(i, j));
                B.put(new Point(i, j), add[i][j]);
            }

        }

    }

}

import java.awt.Dialog;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class test{
    public static void main(String [] args){
        int sum = 0;
        for(int i=1; ;++i){
            sum += i;
            if(sum >= 8888){
                System.out.println(i-1);
                break;
            }
        }
    }   
}

class Windowmenu extends JFrame implements ActionListener{
    JMenuBar menubar;
    JMenu menu;
    JMenuItem item;
    JButton buttom = new JButton("Ok");
    JTable table;
    public Windowmenu(String s){
        init(s);
        initTable();
        setJMenuBar(menubar);
        setBounds(60, 100, 188, 108);
        setVisible(true);
        buttom.addActionListener(this);
    }
    public void initTable(){
        // DefaultTableModel tableModel = new DefaultTableModel(); 
        // jTable = new JTable(tableModel, obj, colums){
        //     public boolean isCellEditable(int row, int column){
        //         return false;}
        // };
        String [] columns = {"Rank", "Name", "Time"};
        Object [][] obj = new Object[2][3];
        for(int i=0; i<2; ++i){
            obj[i][0] = Integer.toString(i);
            obj[i][1] = "hhh123";
            obj[i][2] = "32.1 sec";
        }
        // table.add(columns, obj);
        table = new JTable(obj, columns);
        table.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
    }
    public void init(String s){
        menubar = new JMenuBar();
        menu = new JMenu(s);
        item = new JMenuItem("hello");
        menu.add(item);
        menubar.add(menu);
        add(buttom);
    }
    @Override
    public void actionPerformed(ActionEvent e) {
        // TODO Auto-generated method stub
        JScrollPane js = new JScrollPane(table); // in case the tablehead is not showing
        JDialog sonjFrame = new JDialog();
        sonjFrame.add(js);
        sonjFrame.setBounds(
            new Rectangle(
                (int)this.getBounds().getX() + 50,
                (int)this.getBounds().getY() + 50,
                (int)this.getWidth(),
                (int)this.getHeight()
            ));
        sonjFrame.setModalityType(Dialog.ModalityType.APPLICATION_MODAL);
        sonjFrame.setVisible(true);
    }
}
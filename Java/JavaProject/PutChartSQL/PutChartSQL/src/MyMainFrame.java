import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;


public class MyMainFrame extends JFrame implements ActionListener {
    MyCanvas myCanvas;
    JPanel panelNorth,panelPreview;
    Button start,preview,set,rank;
    Container container;
    JTable rankTable;

    public MyMainFrame() {//≥ı πªØ
        container=this.getContentPane();
        start=new Button("Start");
        start.addActionListener(this);
        preview=new Button("Preview");
        preview.addActionListener(this);
        set = new Button("Setting");
        set.addActionListener(this);
        rank = new Button("rank");
        rank.addActionListener(this);

        panelPreview=new JPanel();
        panelPreview.setLayout(null);
        Icon icon=new ImageIcon( this.getClass().getResource( "picture/pic_"+MyCanvas.pictureID+".jpg" ) );
        JLabel label=new JLabel(icon);
        label.setBounds(0,0,300,300);
        panelPreview.add(label);


        panelNorth=new JPanel();
        panelNorth.setBackground(Color.red);
        panelNorth.add(start);
        panelNorth.add(preview);
        panelNorth.add(set);
        panelNorth.add(rank);

        myCanvas=new MyCanvas();
        container.add(myCanvas,BorderLayout.CENTER);
        container.add(panelNorth,BorderLayout.NORTH);
        this.setTitle("PUTCHART GAME");
        this.setLocation(300,200);
        this.setSize(308,365);
        this.setResizable(false);
        this.setVisible(true);

        this.setDefaultCloseOperation(3);
    }
    public static void main(String[] args) {
        new MyMainFrame();

    }
    public void actionPerformed(ActionEvent arg0) {
        Button button=(Button)arg0.getSource();
        if(button==start){
            myCanvas.Start();
        }else if(button==preview){
            if(button.getLabel()=="Preview"){
                container.remove(myCanvas);
                container.add(panelPreview);
                panelPreview.updateUI();
                container.repaint();

                button.setLabel("Return");
            }else{
                container.remove(panelPreview);
                container.add(myCanvas);
                container.repaint();
                button.setLabel("Preview");
            }
        }else if(button==set){
            Choice pic = new Choice();
            pic.add("Cat");
            pic.add("Pig");
            pic.add("Cloud");
            pic.add("QQ");
            pic.add("Cartoon");
            pic.add("Flower");

            int i=JOptionPane.showConfirmDialog(this, pic, "CHOOSE PICTURES", JOptionPane.OK_CANCEL_OPTION);
            if(i==JOptionPane.YES_OPTION){
                MyCanvas.pictureID=pic.getSelectedIndex()+1;
                myCanvas.reLoadpicture();
                Icon icon=new ImageIcon( this.getClass().getResource( "picture/pic_"+MyCanvas.pictureID+".jpg") );
                JLabel label=new JLabel(icon);
                label.setBounds(0,0,300,300);
                panelPreview.removeAll();
                panelPreview.add(label);
                panelPreview.repaint();
            }
        }else if(button==rank) {
//            panelRank = new JPanel();
            Object[][] obj;
            String[] name = {"Rank", "Player", "Time"};
            Query findRecord = new Query();
            findRecord.setDatabaseName("putchart");
            findRecord.setSQL("select * from player order by utime");
            obj = findRecord.getRecord();
            rankTable = new JTable(obj, name);
            rankTable.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
            JScrollPane js = new JScrollPane(rankTable);
            JDialog rankDialog = new JDialog();
            rankDialog.setTitle("Rank Table");
            rankDialog.add(js);
            rankDialog.setBounds(
                    new Rectangle(
                            (int) this.getBounds().getX() + 50,
                            (int) this.getBounds().getY() + 50,
                            (int) this.getWidth(),
                            (int) this.getHeight()*2/3
                    )
            );
            rankDialog.setModalityType(Dialog.ModalityType.APPLICATION_MODAL);
            rankDialog.setVisible(true);
        }
    }

}
//1
/*
 * Cell类是继承的按钮类，并加上相应图形，形成方格
 *MyCanvas是一个面板，加载Cell类的对象（方格），是这三个类中的核心
 *
 */

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;


public class MyMainFrame extends JFrame implements ActionListener {
    MyCanvas myCanvas;
    JPanel panelNorth,panelPreview;//定义上方的面板，及Preview所需的面板
    Button start,preview,set,rank;//定义Start，Preview，设定按钮
    Container container;//容器，得到内容面板
    JTable rankTable;

    public MyMainFrame() {//初使化
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
        this.setTitle("拼图小游戏");
        this.setLocation(300,200);
        this.setSize(308,365);
        this.setResizable(false);
        this.setVisible(true);

        this.setDefaultCloseOperation(3);
    }
    public static void main(String[] args) {
        // TODO 自动生成方法存根
        new MyMainFrame();

    }
    public void actionPerformed(ActionEvent arg0) {//对三个按钮事件的处理
        // TODO 自动生成方法存根
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
        }else if(button==set){//修改所选图片
            Choice pic = new Choice();
            pic.add("Cat");
            pic.add("Pig");
            pic.add("Cloud");
            pic.add("QQ");
            pic.add("Cartoon");
            pic.add("Flower");

            int i=JOptionPane.showConfirmDialog(this, pic, "选择图片", JOptionPane.OK_CANCEL_OPTION);
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
            Object[][] obj = new Object[10][3];
            String[] name = {"Rank", "Player", "Time"};
//              read data.txt
            Player[] players = myCanvas.readRecord();
//              initial obj
            for (int i = 0; i < 10 && i<players.length; ++i) {
                obj[i][0] = i+1;
                obj[i][1] = players[i].getUsername();
                obj[i][2] = Double.toString(players[i].getMiliseconds()/1000.0) + " sec";
            }
            rankTable = new JTable(obj, name);
            rankTable.setAutoResizeMode(JTable.AUTO_RESIZE_ALL_COLUMNS);
            JScrollPane js = new JScrollPane(rankTable);
            JDialog rankDialog = new JDialog();
            rankDialog.setTitle("排行榜（Rank 10）");
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
//1
/*
 * Cell类是继承的按钮类，并加上相应图形，形成方格
 *MyCanvas是一个面板，加载Cell类的对象（方格），是这三个类中的核心
 *
 */

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Choice;
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;


public class MyMainFrame extends JFrame implements ActionListener {
    MyCanvas myCanvas;
    JPanel panelNorth,panelPreview;//定义上方的面板，及Preview所需的面板
    Button start,preview,set;//定义Start，Preview，设定按钮
    Container container;//容器，得到内容面板

    public MyMainFrame() {//初使化
        container=this.getContentPane();
        start=new Button("Start");
        start.addActionListener(this);
        preview=new Button("Preview");
        preview.addActionListener(this);
        set = new Button("Setting");
        set.addActionListener(this);
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

                button.setLabel("返回");
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
        }
    }

}
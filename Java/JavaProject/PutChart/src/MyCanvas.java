import java.awt.Rectangle;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.Date;

public class MyCanvas extends JPanel implements MouseListener {
    boolean hasAddActionListener=false;//设置方格的动作监听器的标志位，TRUE为已经添加上动作事件，FALSE是尚未添加动作事件
    Cell cell[];//定义方格
    Rectangle cellNull;//定义空方格区域
    public static int pictureID=1;//当前选择的图片代号
    Date startTime;
    Date finishTime;
    Player player = new Player();
    String usrname = new String("HERO");

    public MyCanvas() {
        this.setLayout(null);
        this.setSize(400,400);
        cellNull=new Rectangle(200,200,100,100);//空方格区域在第三行每三列
        cell=new Cell[9];
        Icon icon;

        for ( int i = 0; i < 3; i++ ) {//为9个方格加载图片，并初使化坐标，形成三行三列
            for ( int j = 0; j < 3; j++ ) {
                icon = new ImageIcon( this.getClass().getResource( "picture/pic_" + pictureID + "_" + (i*3+j+1) + ".jpg" ) );

                cell[i*3+j]=new Cell(icon);
                cell[i*3+j].setLocation(j*100,i*100);
                this.add(cell[i*3+j]);
            }
        }
        this.remove(cell[8]);//移除最后一个多余的方格
    }

    public void reLoadpicture(){//当选择其它图形进行拼图时，需重新加载新图片
        Icon icon;
        for (int i = 0; i < 3; i++) {
            for(int j=0;j<3;j++){
                icon=new ImageIcon( this.getClass().getResource( "picture/pic_"+pictureID+"_"+(i*3+j+1)+".jpg") );

                cell[i*3+j].setIcon(icon);
            }
        }
    }
    public boolean isFinish(){//判断是否拼合成功
        for(int i=0;i<8;i++){
            int x=cell[i].getBounds().x;
            int y=cell[i].getBounds().y;
            if(y/100*3+x/100!=i)
                return false;
        }
        return true;
    }

    public void Start(){//对方格进行重新排列，打乱顺序

        while(cell[0].getBounds().x<=100&&cell[0].getBounds().y<=100){//当第一个方格距左上角较近时
            int x=cellNull.getBounds().x;
            int y=cellNull.getBounds().y;
            int direction=(int)(Math.random()*4);//产生0-4，对应空方格的上下左右移动
            if(direction==0){//空方格左移动，与左侧方格互换位置，左侧方格右移动
                x-=100;
                if(test(x,y)){
                    for(int j=0;j<8;j++){
                        if((cell[j].getBounds().x==x)&&(cell[j].getBounds().y==y)){//依次寻找左侧的按钮
                            cell[j].move("RIGHT",100);
                            cellNull.setLocation(x,y);
                            break;//找到后跳出for循环
                        }
                    }
                }
            }else if(direction==1){//RIGHT
                x+=100;
                if(test(x,y)){
                    for(int j=0;j<8;j++){
                        if((cell[j].getBounds().x==x)&&(cell[j].getBounds().y==y)){
                            cell[j].move("LEFT",100);
                            cellNull.setLocation(x,y);
                            break;
                        }
                    }
                }
            }else if(direction==2){//UP
                y-=100;
                if(test(x,y)){
                    for(int j=0;j<8;j++){
                        if((cell[j].getBounds().x==x)&&(cell[j].getBounds().y==y)){
                            cell[j].move("DOWN",100);
                            cellNull.setLocation(x,y);
                            break;
                        }
                    }
                }
            }else{//DOWN
                y+=100;
                if(test(x,y)){
                    for(int j=0;j<8;j++){
                        if((cell[j].getBounds().x==x)&&(cell[j].getBounds().y==y)){
                            cell[j].move("UP",100);
                            cellNull.setLocation(x,y);
                            break;
                        }
                    }
                }
            }

        }

        if(!hasAddActionListener)//如果尚未添加动作事件，则添加
            for(int i=0;i<8;i++)//为第个方格添加动作事件，这样单击按钮就能移动了
                cell[i].addMouseListener(this);
        hasAddActionListener=true;

        startTime = new Date();
    }
    private boolean test(int x,int y){
        if((x>=0&&x<=200)||(y>=0&&y<=200))
            return true;
        else
            return false;
    }
//	public void paint(Graphics g){
//
//		for(int i=0;i<=300;i+=100)
//			g.drawLine(0, i, 300, i);
//		for(int i=0;i<=300;i+=100)
//			g.drawLine(i, 0, i, 300);
//		for(int i=0;i<8;i++)
//			cell[i].repaint();
//	}

    public void writeRecord(){
        File file = new File("out/file.txt");
        try {
            Player [] temp = readRecord();
            Player [] players;
            FileOutputStream fileOut = new FileOutputStream(file);
            ObjectOutputStream objectOut = new ObjectOutputStream(fileOut);
            if(temp==null) {
                players = new Player[1];
                players[0] = player;
            }
            else {
                players = new Player[temp.length + 1];
                for (int i = 0; i < players.length; ++i)
                    players[i] = new Player();
                int i = 0,j = 0;
                for (; i < players.length;) {
                    if (j == temp.length || player.getMiliseconds() < temp[j].getMiliseconds()) {
                        player.setRank(i);
                        players[i++] = player;
                        break;
                    } else {
                        players[i++] = temp[j++];
                    }
                }
                for(; i<players.length;)
                    players[i++] = temp[j++];
            }
            objectOut.writeObject(players);
            objectOut.close();
        }catch (IOException event){
            System.out.println("1 "+event);
        }
//        catch(FileNotFoundException event){
//            FileOutputStream fileOut = new FileOutputStream(file);
//
//        }
    }

    public Player [] readRecord(){
        try{
            File file = new File("out/file.txt");
            FileInputStream fileIn = new FileInputStream(file);
            ObjectInputStream objectIn = new ObjectInputStream(fileIn);
            Player [] playArry = (Player[])objectIn.readObject();
            objectIn.close();
            return playArry;
        }catch(IOException event){
            System.out.println("3 "+event);
            return null;
        }catch(ClassNotFoundException event){
            System.out.println("2 "+event);
            return null;
        }
    }

    public void mouseClicked(MouseEvent arg0) {	}
    public void mouseEntered(MouseEvent arg0) {	}
    public void mouseExited(MouseEvent arg0) 	{	}
    public void mouseReleased(MouseEvent arg0) {	}
    public void mousePressed(MouseEvent arg0) {//方格的鼠标事件，因为用到了MyCanvas中的一些方法，因此没有在Cell类中处理鼠标事件
        Cell button=(Cell)arg0.getSource();
        int x1=button.getBounds().x;//得到所单击方格的坐标
        int y1=button.getBounds().y;

        int x2=cellNull.getBounds().x;//得到空方格的坐标
        int y2=cellNull.getBounds().y;

        if(x1==x2&&y1-y2==100)//进行比较，如果满足条件则进行交换
            button.move("UP",100);
        else if(x1==x2&&y1-y2==-100)
            button.move("DOWN",100);
        else if(x1-x2==100&y1==y2)
            button.move("LEFT",100);
        else if(x1-x2==-100&&y1==y2)
            button.move("RIGHT",100);
        else
            return;//不满足就不进行任何处理

        cellNull.setLocation(x1,y1);
        this.repaint();
        if(this.isFinish()){//进行是否完成的判断if(true){
            finishTime = new Date();
            player.setMiliseconds(finishTime.getTime() - startTime.getTime());
            usrname = JOptionPane.showInputDialog(this,
                    "恭喜你完成拼图,加油！\n 请输入您的名字：",
                    "游戏通关！",
                    JOptionPane.PLAIN_MESSAGE);
            if (usrname.equals(""))
                usrname = "HERO";
            player.setUsername(usrname);
            writeRecord();
            for(int i=0;i<8;i++)
                cell[i].removeMouseListener(this);//如果已完成，撤消鼠标事件，鼠标单击方格不在起作用
            hasAddActionListener=false;
        }
    }


}
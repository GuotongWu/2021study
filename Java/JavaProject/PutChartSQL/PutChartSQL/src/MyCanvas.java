import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.*;
import java.util.Date;

public class MyCanvas extends JPanel implements MouseListener {
    boolean hasAddActionListener=false;
    Cell cell[];
    Rectangle cellNull;
    public static int pictureID=1;
    Date startTime;
    Date finishTime;
    String usrname;
    double seconds;

    public MyCanvas() {
        this.setLayout(null);
        this.setSize(400,400);
        cellNull=new Rectangle(200,200,100,100);
        cell=new Cell[9];
        Icon icon;

        for ( int i = 0; i < 3; i++ ) {
            for ( int j = 0; j < 3; j++ ) {
                icon = new ImageIcon( this.getClass().getResource( "picture/pic_" + pictureID + "_" + (i*3+j+1) + ".jpg" ) );

                cell[i*3+j]=new Cell(icon);
                cell[i*3+j].setLocation(j*100,i*100);
                this.add(cell[i*3+j]);
            }
        }
        this.remove(cell[8]);
    }

    public void reLoadpicture(){
        Icon icon;
        for (int i = 0; i < 3; i++) {
            for(int j=0;j<3;j++){
                icon=new ImageIcon( this.getClass().getResource( "picture/pic_"+pictureID+"_"+(i*3+j+1)+".jpg") );

                cell[i*3+j].setIcon(icon);
            }
        }
    }
    public boolean isFinish(){
        for(int i=0;i<8;i++){
            int x=cell[i].getBounds().x;
            int y=cell[i].getBounds().y;
            if(y/100*3+x/100!=i)
                return false;
        }
        return true;
    }

    public void Start(){

        while(cell[0].getBounds().x<=100&&cell[0].getBounds().y<=100){
            int x=cellNull.getBounds().x;
            int y=cellNull.getBounds().y;
            int direction=(int)(Math.random()*4);
            if(direction==0){
                x-=100;
                if(test(x,y)){
                    for(int j=0;j<8;j++){
                        if((cell[j].getBounds().x==x)&&(cell[j].getBounds().y==y)){
                            cell[j].move("RIGHT",100);
                            cellNull.setLocation(x,y);
                            break;
                        }
                    }
                }
            }else if(direction==1){
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
            }else if(direction==2){
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

        if(!hasAddActionListener)
            for(int i=0;i<8;i++)
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

    public void writeRecord(String uname, double utime){
        Query write = new Query();
        write.setDatabaseName("putchart");
        String sql = "insert into player(uname, utime) values (\"" + uname + "\"," + Double.toString(utime) + ")";
        // System.out.println(sql);
        write.setSQL(sql);
        write.startWrite();
    }

    public void mouseClicked(MouseEvent arg0) {	}
    public void mouseEntered(MouseEvent arg0) {	}
    public void mouseExited(MouseEvent arg0) 	{	}
    public void mouseReleased(MouseEvent arg0) {	}
    public void mousePressed(MouseEvent arg0) {
        Cell button=(Cell)arg0.getSource();
        int x1=button.getBounds().x;
        int y1=button.getBounds().y;

        int x2=cellNull.getBounds().x;
        int y2=cellNull.getBounds().y;

        if(x1==x2&&y1-y2==100)
            button.move("UP",100);
        else if(x1==x2&&y1-y2==-100)
            button.move("DOWN",100);
        else if(x1-x2==100&y1==y2)
            button.move("LEFT",100);
        else if(x1-x2==-100&&y1==y2)
            button.move("RIGHT",100);
        else
            return;

        cellNull.setLocation(x1,y1);
        this.repaint();
        if(this.isFinish()){
        // if(true){
            finishTime = new Date();
            seconds = (finishTime.getTime() - startTime.getTime()) / 1000.0;
            usrname = JOptionPane.showInputDialog(this,
                    "Congradulations! Your have spent " + Double.toString(seconds) + " secs to finish it!\n Please enter your name: ",
                    "Game Finished",
                    JOptionPane.PLAIN_MESSAGE);
            if (usrname.equals(""))
                usrname = "HERO";
            writeRecord(usrname, seconds);
            for(int i=0;i<8;i++)
                cell[i].removeMouseListener(this);
            hasAddActionListener=false;
        }
    }


}
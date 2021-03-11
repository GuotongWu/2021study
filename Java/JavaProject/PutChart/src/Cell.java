import javax.swing.Icon;
import javax.swing.JButton;

public class Cell extends JButton {
    Cell(Icon icon){//实际为ICON
        super(icon);
        this.setSize(100,100);
    }

    public void move(String direction,int sleep){//方格的移动
        if(direction=="UP"){
            this.setLocation(this.getBounds().x,this.getBounds().y-100);
        }else if(direction=="DOWN"){
            this.setLocation(this.getBounds().x,this.getBounds().y+100);
        }else if(direction=="LEFT"){
            this.setLocation(this.getBounds().x-100,this.getBounds().y);
        }else{
            this.setLocation(this.getBounds().x+100,this.getBounds().y);
        }
    }

}
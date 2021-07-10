import java.util.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.event.*;

class myMenuReview extends JFrame implements ActionListener{
	JMenuBar menubar;  //菜单条，菜单要放到菜单条中
	JMenu menu1,menu2;  //菜单
	JMenuItem item1_open,item1_save,item1_close,item2_copy,item2_paste;//菜单项，菜单项要放到菜单中
	public myMenuReview(){
		menubar=new JMenuBar();
		menu1=new JMenu("文件");
		menu2=new JMenu("编辑");
		item1_open=new JMenuItem("打开");
		item1_save=new JMenuItem("保存");
		item1_close=new JMenuItem("关闭");
		item2_copy=new JMenuItem("复制");
		item2_paste=new JMenuItem("黏贴");
		
		menu1.add(item1_open);
		menu1.add(item1_save);
		menu1.add(item1_close);
		
		menu2.add(item2_copy);
		menu2.add(item2_paste);
		item1_close.addActionListener(this);
		menubar.add(menu1);
		menubar.add(menu2);
		setSize(200,210);
		setJMenuBar(menubar);
		setVisible(true);
		validate();
		
	}
	
	public void actionPerformed(ActionEvent e) {
		if(e.getSource().equals(item1_close)) {
			System.exit(0);
		}
	}
}



public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		myMenuReview myapp=new myMenuReview();
	}

}
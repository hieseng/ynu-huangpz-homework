package 商品信息管理系统;

import javax.swing.*;
import java.awt.event.*;

class UsingExit extends JFrame implements ActionListener{
	JLabel Info=new JLabel("确认退出？");
	JButton JExit=new JButton("确认");
	JButton Cancel=new JButton("取消");
	public UsingExit(){
		this.setTitle("退出界面");
		this.setLayout(null);
		Info.setBounds(180,50,100,20);
		this.add(Info);
		JExit.setBounds(100,100,100,20);
		this.add(JExit);
		JExit.addActionListener(this);
		Cancel.setBounds(220,100,100,20);
		this.add(Cancel);
		Cancel.addActionListener(this);
		this.setVisible(true);
		this.setBounds(10,10,400,250);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new UsingExit();
	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==JExit)
			System.exit(0);
		else if(e.getSource()==Cancel)
			setVisible(false);
	}
}

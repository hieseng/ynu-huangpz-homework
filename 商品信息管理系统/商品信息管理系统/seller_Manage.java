package 商品信息管理系统;

import java.awt.event.*;
import 商品信息管理系统.UsingExit;
import 商品信息管理系统.AddGoods;
import 商品信息管理系统.DeleteGoods;
import 商品信息管理系统.SetGoods;
import 商品信息管理系统.GetGoods;
import javax.swing.*;

class seller_Manage extends JFrame implements ActionListener{
	JMenu cm=new JMenu("请选择您要进行的操作：");
	JButton cm1=new JButton("增加商品信息");
	JButton cm2=new JButton("删除商品信息");
	JButton cm3=new JButton("修改商品信息");
	JButton cm4=new JButton("查询商品信息");
	JButton cm5=new JButton("退出");
	
	public seller_Manage(){
		this.setTitle("商品管理");
	    this.setLayout(null);
	    cm.setBounds(100,50,150,20);
	    this.add(cm);
	    cm1.setBounds(100,100,120,20);
	    this.add(cm1);
	    cm1.addActionListener(this);
	    cm2.setBounds(100,150,120,20);
	    this.add(cm2);
		cm2.addActionListener(this);
	    cm3.setBounds(100,200,120,20);
	    this.add(cm3);
	    cm3.addActionListener(this);
	    cm4.setBounds(100,250,120,20);
	    this.add(cm4);
	    cm4.addActionListener(this);
	    cm5.setBounds(100,300,120,20);
	    this.add(cm5);
	    cm5.addActionListener(this);
	    this.setVisible(true);
		this.setBounds(10,10,350,400);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new seller_Manage();		
	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==cm1)new AddGoods();
		else if(e.getSource()==cm2)new DeleteGoods();
		else if(e.getSource()==cm3)new SetGoods();
		else if(e.getSource()==cm4)new GetGoods();
		else if(e.getSource()==cm5)this.setVisible(false);
	}
}

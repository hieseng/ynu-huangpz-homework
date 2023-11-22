package 商品信息管理系统;

import java.awt.event.*;
import 商品信息管理系统.UsingExit;
import javax.swing.*;

class custom_Manage extends JFrame implements ActionListener{
	JMenu cm=new JMenu("请选择您需要的操作：");
	JButton cm1=new JButton("商品信息查询");
	JButton cm2=new JButton("退出登录");
	
	public custom_Manage(){
		this.setTitle("顾客操作");
	    this.setLayout(null);
	    cm.setBounds(100,50,150,20);
	    this.add(cm);
	    cm1.setBounds(100,100,120,20);
	    this.add(cm1);
	    cm1.addActionListener(this);
	    cm2.setBounds(100,150,100,20);
	    this.add(cm2);
		cm2.addActionListener(this);
	    this.setVisible(true);
		this.setBounds(10,10,350,300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new custom_Manage();		
	}
	public void actionPerformed(ActionEvent e){
		 if(e.getSource()==cm1)new SetGoods();
		else if(e.getSource()==cm2)	this.setVisible(false);

	}
}
/*1、问题描述
超市中商品分为四类，分别是食品、化妆品、日用品和饮料。每种商品都包含商品名称、价格、库存量和生产厂家、品牌等信息。
主要完成对商品的销售、统计和简单管理。
这个题目相对简单，可以用一张表实现信息的保存和处理，因此不再给出数据库设计参考。
2、功能要求
（1）销售功能。购买商品时，先输入类别，然后输入商品名称，并在库存中查找该商品的相关信息。如果有库存量，输入购买的数量，进行相应计算。如果库存量不够，给出提示信息，结束购买。
（2）商品简单管理功能。
添加功能：主要完成商品信息的添加。
查询功能：可按商品类别、商品名称、生产厂家进行查询。若存在相应信息，输出所查询的信息，若不存在该记录，则提示“该记录不存在！”。
修改功能：可根据查询结果对相应的记录进行修改。
删除功能：主要完成商品信息的删除。先输入商品类别，再输入要删除的商品名称，根据查询结果删除该物品的记录，如果该商品不在物品库中，则提示“该商品不存在”。
（3）统计功能。
输出当前库存中所有商品的总数及详细信息；可按商品的价格、库存量、生产厂家进行统计，输出统计信息时，要按从大到小进行排序。
（7）商品信息存盘：将当前程序中的商品信息存入文件中。
（8）读出信息：从文件中将商品信息读入程序。
3、问题的解决方案
根据系统功能要求，可以将问题解决分为以下步骤： 
（1）应用系统分析，建立该系统的功能模块框图以及界面的组织和设计；
（2）分析系统中的各个实体及它们之间的关系； 
（3）根据问题描述，设计系统的类层次； 
（4）完成类层次中各个类的描述； 
（5）完成类中各个成员函数的定义； 
（6）完成系统的应用模块； 
（7）功能调试；
（8）完成系统总结报告。*/


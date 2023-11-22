package 商品信息管理系统;

import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import javax.swing.*;

class AddGoods extends JFrame implements ActionListener {
	JLabel JL = new JLabel("添加基本信息：");
	JLabel number = new JLabel("商品编号");
	JTextField Number = new JTextField();
	
	JLabel JClass=new JLabel("类别");
	String str[]={"食品","化妆品","日用品","饮料"};
	JComboBox jcb=new JComboBox(str);
	
	JLabel name = new JLabel("商品名称");
	JTextField Name = new JTextField();
	JLabel price=new JLabel("商品价格");
	JTextField Price = new JTextField();
	JLabel storage= new JLabel("库存量");
	JTextField Storage = new JTextField();
	JLabel brand= new JLabel("品牌");
	JTextField Brand = new JTextField();
	JLabel vender = new JLabel("生产厂家");
	JTextField Vender = new JTextField();
	
	JTextField jt=new JTextField(10);
	JButton Add = new JButton("添加");
	JButton Reset = new JButton("重置");
	JButton Exit = new JButton("退出");
	String sql = "";
	public AddGoods(){
		this.setTitle("商品管理");
		this.setLayout(null);
		JL.setBounds(100,50, 100, 20);
		this.add(JL);
		number.setBounds(100,100,100,20);
		this.add(number);
		Number.setBounds(200,100,100,20);
		this.add(Number);
		JClass.setBounds(100,150,100,20);
		this.add(JClass);
		jcb.setBounds(200,150,100,20);
		this.add(jcb);
		name.setBounds(100,200,100,20);
		this.add(name);
		Name.setBounds(200,200,100,20);
		this.add(Name);
		price.setBounds(100,250,100,20);
		this.add(price);
		Price.setBounds(200,250,100,20);
		this.add(Price);
		storage.setBounds(100,300,100,20);
		this.add(storage);
		Storage.setBounds(200,300,100,20);
		this.add(Storage);
		brand.setBounds(100,350,100,20);
		this.add(brand);
		Brand.setBounds(200,350,100,20);
		this.add(Brand);
		vender.setBounds(100,400,100,20);     
		this.add(vender);
		Vender.setBounds(200,400,100,20);
		this.add(Vender);
		Add.setBounds(100,450,60,20);
		this.add(Add);
		Add.addActionListener(this);
		Reset.setBounds(200,450,60,20);
		this.add(Reset);     
		Reset.addActionListener(this);
		Exit.setBounds(300, 450,60, 20);
		this.add(Exit);
		Exit.addActionListener(this);
		this.setVisible(true);
		this.setBounds(10,10,450,540);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new AddGoods();
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==Add) {
			String snumber=Number.getText();
			String svender=Vender.getText();
			String sname=Name.getText();
			String sprice=Price.getText();
			String sstorage=Storage.getText();
			String sbrand=Brand.getText();
			try {
				Connection cot=ConnectionFactory.getConnection();
				Statement stm=cot.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE ,ResultSet.CONCUR_UPDATABLE );
				int s=jcb.getSelectedIndex();
				String jc=null;
				if(s==0)
					jc="食品";
				else if(s==1)
					jc="化妆品";
				else if(s==2)
					jc="日用品";
				else if(s==3)
					jc="饮料";
				sql="insert into goods values('"+snumber+"','"+jc+"','"+sname+"',"+sprice+","+sstorage+",'"+sbrand+"','"+svender+"')";
				int n=stm.executeUpdate(sql);
				if(n!=0)JOptionPane.showMessageDialog(null,"添加成功！");
				else JOptionPane.showMessageDialog(null,"该商品已存在！");
			}catch(Exception ee) {
				ee.printStackTrace();
			}
		}
		if(e.getSource()==Reset) {
			Number.setText(null);
			Name.setText(null);
			Vender.setText(null);
			Price.setText(null);
			Storage.setText(null);
			Brand.setText(null);
		}
		if(e.getSource()==Exit) {
			this.setVisible(false);
		}
	}
}
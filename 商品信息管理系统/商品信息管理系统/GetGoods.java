package 商品信息管理系统;

import java.awt.event.*;
import java.sql.*;
import javax.swing.*;

class GetGoods extends JFrame implements ActionListener{
	JLabel JL = new JLabel("修改商品信息", JLabel.CENTER);
	JLabel number = new JLabel("请输入您要修改的商品编号");
	JTextField Number = new JTextField();
	
	JLabel massage = new JLabel("请输入您要修改的商品信息");
	JTextField Massage = new JTextField();
	
	JLabel afterget=new JLabel("您想要将该列信息修改为：");
	JTextField Afterget = new JTextField();
	
	JTextField jt=new JTextField(10);
	JButton Get = new JButton("修改");
	JButton Reset = new JButton("重置");
	JButton Exit = new JButton("退出");
	String sql = "";
	public GetGoods(){
		this.setTitle("顾客管理系统");
		this.setLayout(null);
		JL.setBounds(150, 50, 100, 20);
		this.add(JL);
		number.setBounds(100,100,180,20);
		this.add(number);
		Number.setBounds(280,100,100,20);
		this.add(Number);
		
		massage.setBounds(100,150,180,20);
		this.add(massage);
		Massage.setBounds(280,150,100,20);
		this.add(Massage);
		
		afterget.setBounds(100,200,180,20);
		this.add(afterget);
		Afterget.setBounds(280,200,100,20);
		this.add(Afterget);
		Get.setBounds(100,250,60,20);
		this.add(Get);
		Get.addActionListener(this);
		Reset.setBounds(200,250,60,20);
		this.add(Reset);     
		Reset.addActionListener(this);
		Exit.setBounds(300, 250,60, 20);
		this.add(Exit);
		Exit.addActionListener(this);
		this.setVisible(true);
		this.setBounds(10,10,450,390);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public void actionPerformed(ActionEvent e){
		if(e.getSource()==Get){
			Statement stm=null;
			Connection cot;
			try{
				cot=ConnectionFactory.getConnection();
				stm=cot.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE ,ResultSet.CONCUR_UPDATABLE );
				sql="update goods set "+Massage.getText()+"='"+Afterget.getText()+"' where number='"+Number.getText()+"'";
				int n=stm.executeUpdate(sql);
				if(n!=0)JOptionPane.showMessageDialog(null,"修改成功！");
				else JOptionPane.showMessageDialog(null,"修改失败！");
			}catch(Exception er){
				er.printStackTrace();
			}
		}
		if(e.getSource()==Reset){
			Number.setText(null);
			Massage.setText(null);
			Afterget.setText(null);
		}
		if(e.getSource()==Exit) {
			this.setVisible(false);
		}
	}
	public static void main(String args[]) {
		new GetGoods();
	}
}

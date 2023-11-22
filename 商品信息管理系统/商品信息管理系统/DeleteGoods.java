package 商品信息管理系统;

import java.awt.event.*;


import java.sql.*;
import javax.swing.*;

class DeleteGoods extends JFrame implements ActionListener {
	JMenu JL = new JMenu("删除基本信息");
	JLabel number = new JLabel("商品编号");
	JTextField Number = new JTextField();
	JButton Del = new JButton("删除");
	JButton Reset = new JButton("重置");
	JButton Exit = new JButton("退出");
	String sql = "";
	public DeleteGoods(){
		this.setTitle("商品管理");
		this.setLayout(null);
		JL.setBounds(170, 50, 100, 20);
		this.add(JL);
		number.setBounds(130,100,100,20);
		this.add(number);
		Number.setBounds(200,100,100,20);
		this.add(Number);
		Del .setBounds(100,150,60,20);
		this.add(Del );     
		Del .addActionListener(this);
		Reset.setBounds(200,150,60,20);
		this.add(Reset);     
		Reset.addActionListener(this);
		Exit.setBounds(300, 150,60, 20);
		this.add(Exit);
		Exit.addActionListener(this);
		this.setVisible(true);
		this.setBounds(10,10,450,300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new DeleteGoods();
	}
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == Del) {
			Statement stm=null;
			Connection cot;
			try {
				cot=ConnectionFactory.getConnection();
				stm= cot.prepareStatement(sql,ResultSet.TYPE_SCROLL_SENSITIVE ,ResultSet.CONCUR_UPDATABLE );
				sql ="delete from goods where number='"+Number.getText()+"'";
				int n = stm.executeUpdate(sql);
				if (n!=0)
					JOptionPane.showMessageDialog(null, "删除成功！");
				else
				JOptionPane.showMessageDialog(null, "删除失败！");
			} catch (SQLException e1) {
				JOptionPane.showMessageDialog(null, "此商品不存在！");
				e1.printStackTrace();
			}
		}
		if (e.getSource() == Reset) {
			Number.setText(null);
		}
		if (e.getSource() == Exit)
			this.setVisible(false);
	}
}

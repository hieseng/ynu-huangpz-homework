package 商品信息管理系统;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Purchase extends JFrame implements ActionListener{
	JLabel JL = new JLabel("确认购买？", JLabel.CENTER);
	JButton yes = new JButton("确认");
	JButton no = new JButton("取消");
	public Purchase(){
		this.setTitle("购买");
		this.setLayout(null);
		JL.setBounds(135,50, 100, 20);
		this.add(JL);
		yes.setBounds(100,100,80,20);
		this.add(yes);
		yes.addActionListener(this);
		no.setBounds(200,100,80,20);
		this.add(no);
		no.addActionListener(this);
		this.setVisible(true);
		this.setBounds(10,10,350,210);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
	public static void main(String[] args) {
		new Purchase();
	}
	public void actionPerformed(ActionEvent e) {
		if(e.getSource()==yes) {
			JOptionPane.showMessageDialog( null, "购买成功！");
		}
		else if(e.getSource()==no)
			this.setVisible(false);
	}
	
}

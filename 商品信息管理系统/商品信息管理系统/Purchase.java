package ��Ʒ��Ϣ����ϵͳ;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

class Purchase extends JFrame implements ActionListener{
	JLabel JL = new JLabel("ȷ�Ϲ���", JLabel.CENTER);
	JButton yes = new JButton("ȷ��");
	JButton no = new JButton("ȡ��");
	public Purchase(){
		this.setTitle("����");
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
			JOptionPane.showMessageDialog( null, "����ɹ���");
		}
		else if(e.getSource()==no)
			this.setVisible(false);
	}
	
}

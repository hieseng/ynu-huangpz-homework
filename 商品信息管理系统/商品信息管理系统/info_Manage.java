package 商品信息管理系统;
import java.awt.event.*;
import javax.swing.*;
import 商品信息管理系统.custom_Manage;
import 商品信息管理系统.seller_Manage;

public class info_Manage extends JFrame implements ActionListener{
	private JLabel username = new JLabel("用户名");
	private JTextField userName = new JTextField();	
	
	private JLabel psw = new JLabel("密码");	
	private JPasswordField Psw = new JPasswordField();
	JLabel jlp=new JLabel("身份");
	String str[]={"顾客","商家"};
	JComboBox jcb=new JComboBox(str);
	
	private JButton jb1 = new JButton("登录");
	private JButton jb2 = new JButton("取消");
	
	public info_Manage(){		
		this.setTitle("商品信息管理系统");
		this.setLayout(null);
		username.setBounds(100,50,100,20);
		this.add(username);		
		userName.setBounds(150,50,100,20);
		this.add(userName);
		psw.setBounds(100,100,100,20);
		this.add(psw);
		Psw.setBounds(150,100,100,20);
		this.add(Psw);
		jlp.setBounds(100,150,100,20);
		this.add(jlp);
		jcb.setBounds(150,150,100,20);
		this.add(jcb);
		jcb.addActionListener(this);
		jb1.setBounds(100,210,60,20);
		this.add(jb1);
		jb1.addActionListener(this);
		jb2.setBounds(200,210,60,20);
		this.add(jb2);     
		jb2.addActionListener(this);
		this.setVisible(true);
		this.setBounds(10,10,390,330);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	public static void main(String[] args) {
		new info_Manage();
	}

	public void actionPerformed(ActionEvent e) {		
		if (e.getSource() == jb1) {
			String name=userName.getText();
			String password = new String(Psw.getPassword());
			if(name.length()==0&&password.length()!=0)
				JOptionPane.showMessageDialog( null, "请输入用户名");
			else  if(name.length()!=0&&password.length()==0)
				JOptionPane.showMessageDialog( null, "请输入密码");
			else if(name.length()==0&&name.length()==0)
					JOptionPane.showMessageDialog( null, "请输入用户名和密码");
			else if(jcb.getSelectedIndex()==0&&name.length()!=0&&name.length()!=0)
				new custom_Manage();
			else if(jcb.getSelectedIndex()==1&&name.length()!=0&&password.length()!=0)
				new seller_Manage();
		}
		else if(e.getSource()==jb2)
			System.exit(0);
	}
}

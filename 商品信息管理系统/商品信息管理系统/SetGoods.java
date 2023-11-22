package 商品信息管理系统;
import java.awt.event.*;
import java.sql.*;
import javax.swing.*;
import 商品信息管理系统.Purchase;

class SetGoods extends JFrame implements ActionListener {
	JLabel JL = new JLabel("请用以下任意一种方式查询您想要的东西", JLabel.CENTER);
	JLabel number = new JLabel("商品编号");
	JTextField Number = new JTextField();
	
	JLabel JClass=new JLabel("类别");
	String str[]={"无","食品","化妆品","日用品","饮料"};
	JComboBox jcb=new JComboBox(str);
	
	JLabel name = new JLabel("商品名称");
	JTextField Name = new JTextField();
	JLabel price=new JLabel("商品价格");
	JTextField Price = new JTextField();
	JLabel brand= new JLabel("品牌");
	JTextField Brand = new JTextField();
	JLabel vender = new JLabel("生产厂家");
	JTextField Vender = new JTextField();
	
	JTextField jt=new JTextField(10);
	JButton Set = new JButton("查询");
	JButton purchase = new JButton("购买");
	JButton Reset = new JButton("重置");
	JButton Exit = new JButton("退出");
	String sql = "";
	public SetGoods(){
		this.setTitle("顾客管理系统");
		this.setLayout(null);
		JL.setBounds(100, 50,250, 20);
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
		brand.setBounds(100,300,100,20);
		this.add(brand);
		Brand.setBounds(200,300,100,20);
		this.add(Brand);
		vender.setBounds(100,350,100,20);     
		this.add(vender);
		Vender.setBounds(200,350,100,20);
		this.add(Vender);
		Set.setBounds(100,400,60,20);
		this.add(Set);
		Set.addActionListener(this);
		purchase .setBounds(160,400,60,20);
		this.add(purchase );     
		purchase .addActionListener(this);
		Reset.setBounds(220,400,60,20);
		this.add(Reset);     
		Reset.addActionListener(this);
		Exit.setBounds(280, 400,60, 20);
		this.add(Exit);
		Exit.addActionListener(this);
		this.setVisible(true);
		this.setBounds(10,10,450,540);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public static void main(String[] args) {
		new SetGoods();
	}
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == Set) {
			Statement stm=null;
			Connection cot;
			try{
				cot=ConnectionFactory.getConnection();
				stm=cot.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE ,ResultSet.CONCUR_UPDATABLE );
				if(Number.getText()!=null)
					sql="select * from goods where number='"+Number.getText()+"'";
				else if(Name.getText()!=null)
					sql="select * from goods where name='"+Name.getText()+"'";
				else if(Price.getText()!=null)
					sql="select * from goods where price='"+Price.getText()+"'";
				else if(Brand.getText()!=null)
					sql="select * from goods where brand='"+Brand.getText()+"'";
				else if(Vender.getText()!=null)
					sql="select * from goods where vender='"+Vender.getText()+"'";
				ResultSet rs=stm.executeQuery(sql);
				while(rs.next()) {
					System.out.println("商品编号: "+Number.getText());
					int s=jcb.getSelectedIndex();
					if(s==0)
						JOptionPane.showMessageDialog( null, "请选择商品类别！" );
					else if(s==1)
					    System.out.println("商品类别: 食品");
					else if(s==2)
						System.out.println("商品类别: 化妆品");
					else if(s==3)
						System.out.println("商品类别: 日用品");
					else if(s==4)
						System.out.println("商品类别: 饮料");
					System.out.println("商品名称: "+rs.getString("name"));
					System.out.println("价格: "+rs.getString("price"));
					System.out.println("库存量: "+rs.getString("storage"));
					System.out.println("品牌: "+rs.getString("brand"));
					System.out.println("生产厂家: "+rs.getString("vender"));
				}
			}catch(Exception ee){
				JOptionPane.showMessageDialog( null, "该商品不存在！" );
				ee.printStackTrace();
			}
		}
		else if(e.getSource()==purchase){
			
			new Purchase();
		}
		else if(e.getSource()==Reset){
			Number.setText(null);
			Name.setText(null);
			Vender.setText(null);
			Price.setText(null);
			Brand.setText(null);
		}
		else if(e.getSource()==Exit) {
			this.setVisible(false);
		}
	}
}
package ��Ʒ��Ϣ����ϵͳ;

import java.io.*;
import java.sql.*;
import java.util.Properties;

public class ConnectionFactory {
	//���þ�̬����飬�ڹ����౻����ʱ��ִ�������ļ��Ķ�ȡ
	private static Properties props = new Properties();
	static {		
		try {
			props.load(new FileInputStream("D:\\eclipse\\����\\src\\��Ʒ��Ϣ����ϵͳ\\database.properties"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static Connection getConnection(){
		Connection con = null;
		try {
			String driver = props.getProperty("driver");
			String url = props.getProperty("url");
			String username = props.getProperty("user");
			String password = props.getProperty("password");
			Class.forName(driver);
			con = DriverManager.getConnection(url, username, password);
		} catch (ClassNotFoundException e) {
			System.out.println("failed to register driver.");
			e.printStackTrace();
		} catch (SQLException e) {
			System.out.println("failed to execute sql.");
			e.printStackTrace();
		}
		return con;
	}
	
	public static void main(String[] args) {
		Connection con = getConnection();
		System.out.println(con);
	}
}

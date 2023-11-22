package service;

import po.User;

/**
 * 用户service层接口
 * @author Administrator
 *
 */
public interface UserService {
	//通过账号密码查询用户
	public User findUser(String usercode,String password);
	//创建客户
	public int createUser(User user);
	//通过用户名查询密码
		public String findpassword(String usercode);
}

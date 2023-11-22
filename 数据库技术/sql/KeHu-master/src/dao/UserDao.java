package dao;

import org.apache.ibatis.annotations.Param;
import po.User;

/**
 * 用户DAO层接口
 * @author Administrator
 *
 */
public interface UserDao {
	/**
	 * 通过账号密码查询用户
	 */
	public User findUser(@Param("usercode")String usercode,@Param("userpassword")String password);
	//创建客户
	public int createUser(User user);
	//通过用户名查询密码
	public String findpassword(String usercode);
}

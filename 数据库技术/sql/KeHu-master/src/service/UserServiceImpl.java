package service;

import org.springframework.beans.factory.annotation.Autowired;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import dao.UserDao;
import po.User;
import service.UserService;
/**
 * 用户service层接口实现类
 * @author Administrator
 *
 */
@Service("userService")
@Transactional
public class UserServiceImpl implements UserService {
	
	//注入UserDao
	@Autowired
	private UserDao userDao;

	@Override
	public User findUser(String usercode, String password) {
		User user = this.userDao.findUser(usercode, password);
		return user;
	}

	@Override
	public int createUser(User user) {
		// TODO Auto-generated method stub
		return userDao.createUser(user);
	}

	@Override
	public String findpassword(String usercode) {
		
		return userDao.findpassword(usercode);
	}

}

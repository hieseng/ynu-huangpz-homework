package controller;

import java.sql.Timestamp;
import java.util.Date;

import javax.servlet.http.HttpSession;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpRequest;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import po.Customer;
import po.User;
import service.UserService;
/**
 * 用户控制器类
 * @author Administrator
 *
 */
@Controller
public class UserController {
	//依赖注入
	@Autowired
	private UserService userService;
	/**
	 * 用户登录
	 */
	@RequestMapping(value="login.action",method=RequestMethod.POST)
	public String login(String usercode,String password,Model model,HttpSession session){
		//通过账号和密码查询用户
		User user = userService.findUser(usercode, password);
		if(user!=null){
			//将用户对象添加到session
			session.setAttribute("USER_SESSION", user);
			//跳转到主页
			return "redirect:/customer/list.action";
		}
		model.addAttribute("msg", "账号或者密码错误，请重新输入");
		return "login";
	}
	/**
	 * 模拟其他类中跳转到客户管理页面
	 */
	@RequestMapping(value="/toCustomer.action")
	public String toCustomer(){
		return "customer";
	}
	/**
	 * 退出登录
	 */
	@RequestMapping(value="/logout.action")
	public String loginout(HttpSession session){
		//清除session
		session.invalidate();
		//重定向到登录页面的跳转方法
		return "redirect:login.action";
	}
	/**
	 * 向用户登录页面跳转
	 */
	@RequestMapping(value="/login.action",method=RequestMethod.GET)
	public String login(){
		return "login";
	}
	
	/**
	 * 创建用户
	 */
	@RequestMapping(value="/createuser.action",method=RequestMethod.POST)
	@ResponseBody
	public String userCreate(String user_usercode,String user_username,String user_password){
		System.out.println("1111111111111111111111111111111111111111111");
		//执行Service层中的创建方法返回的受影响的行数
		User user=new User();
		user.setUser_code(user_usercode);
		user.setUser_name(user_username);
		user.setUser_password(user_password);
		userService.createUser(user);
		 
		 return "login";
	}
	
	
	@RequestMapping(value="/findpassword.action",method=RequestMethod.GET)
	@ResponseBody
	public String findpassword(String usercode,Model model){
		String password = userService.findpassword(usercode);
		if(password!=null){
			model.addAttribute("password",password);
			return "find";
		}
		model.addAttribute("msg", "账号错误，请重新输入");
		return "find";
	}
	
	
	
	
	
	
	
	
	
	
	
}

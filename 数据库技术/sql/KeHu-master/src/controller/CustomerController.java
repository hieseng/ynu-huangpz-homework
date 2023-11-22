package controller;

import java.sql.Timestamp;

import java.util.Date;
import java.util.List;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import utils.Page;
import po.BaseDict;
import po.Customer;
import po.User;
import service.BaseDictService;
import service.CustomerService;


/**
 * 客户管理控制器类
 * @author Administrator
 *
 */
@Controller
public class CustomerController {
	//依赖注入
	@Autowired
	private CustomerService customerService;
	@Autowired
	private BaseDictService baseDictService;
/*	customer.from.type=002
			customer.industry.type=001
			customer.level.type=006*/
	//springmvc加载并读取属性配置文件
	@Value("${customer.from.type}")
	private String FROM_TYPE;
	@Value("${customer.industry.type}")
	private String INDUSTRY_TYPE;
	@Value("${customer.level.type}")
	private String LEVEL_TYPE;
	/**
	 * 客户列表
	 */
	@RequestMapping(value="/customer/list.action")
	public String list(@RequestParam(defaultValue="1")Integer page,@RequestParam(defaultValue="10")Integer rows,
			String custName, String custSource,String custIndustry, String custLevel,Model model){
		//根据条件查询所以客户
		Page<Customer> customers = customerService.findCustomerList(page, rows, custName, custSource, custIndustry, custLevel);
		model.addAttribute("page", customers);
		System.out.println(customers.getSize());
		
		//查询客户来源
		List<BaseDict> fromType = baseDictService.findBaseDictByTypeCode(FROM_TYPE);
		//查询客户所属行业
		List<BaseDict> industryType = baseDictService.findBaseDictByTypeCode(INDUSTRY_TYPE);
		//查询客户级别
		List<BaseDict> levelType = baseDictService.findBaseDictByTypeCode(LEVEL_TYPE);
		model.addAttribute("fromType", fromType);
		model.addAttribute("industryType", industryType);
		model.addAttribute("levelType", levelType);
		model.addAttribute("custName", custName);
		model.addAttribute("custSource", custSource);
		model.addAttribute("custIndustry", custIndustry);
		model.addAttribute("custLevel", custLevel);
		
		return "customer";
	}
	/**
	 * 创建客户
	 */
	@RequestMapping("customer/create.action")
	@ResponseBody
	public String customerCreate(Customer customer,HttpSession session){
		//获取session中当前用户信息
		User user = (User) session.getAttribute("USER_SESSION");
		//将氮气用户的id存储用户对象中
		customer.setCust_create_id(user.getUser_id());
		//创建Date对象
		Date date = new Date();
		//得到一个timestamp格式时间，存入mysql中的时间格式"yyyy/MM/dd HH:mm:ss"
		Timestamp timestamp = new Timestamp(date.getTime());
		customer.setCust_createtime(timestamp);
		//执行Service层中的创建方法返回的受影响的行数
		int rows = customerService.createCustomer(customer);
		if(rows>0){
			return "OK";
		}else{
			return "FLASE";
		}
	}
	/*
	 * 通过id获取客户信息
	 */
	@RequestMapping("/customer/getCustomerById.action")
	@ResponseBody
	public Customer getCustomerById(Integer id){
		Customer customer = customerService.getCustomerById(id);
		return customer;
	}
	/*
	 * 更新客户
	 */
	@RequestMapping("/customer/update.action")
	@ResponseBody
	public String getCustomerById(Customer customer){
		int rows = customerService.updateCustomer(customer);
		if(rows>0){
			return "OK";
		}else{
			return "FLASE";
		}
	}
	/*
	 * 删除客户
	 */
	@RequestMapping("/customer/delete.action")
	@ResponseBody
	public String CustomerDelete(Integer id){
		int rows = customerService.deleteCustomer(id);
		if(rows>0){
			return "OK";
		}else{
			return "FLASE";
		}
	}
}
































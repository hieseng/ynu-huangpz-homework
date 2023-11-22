package service;

import utils.Page;
import po.Customer;

/**
 * 客户信息service接口
 * @author Administrator
 *
 */
public interface CustomerService {
	//查询客户列表
	public Page<Customer> findCustomerList(Integer page,Integer rows,String custName,
			String custSource,String custIndustry,String custLevel);
	//创建客户
	public int createCustomer(Customer customer);
	//通过id查询客户
	public Customer getCustomerById(Integer id);
	//更新客户
	public int updateCustomer(Customer customer);
	//删除客户
	public int deleteCustomer(Integer id);
}

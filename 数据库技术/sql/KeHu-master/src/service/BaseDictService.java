package service;

import java.util.List;


import po.BaseDict;

/**
 * 数据字典service接口
 * @author Administrator
 *
 */
public interface BaseDictService {
	//根据类别代码查询数据字典
	public List<BaseDict> findBaseDictByTypeCode(String typecode);
}

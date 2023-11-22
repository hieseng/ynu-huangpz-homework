<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>找回密码</title>

<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://" + request.getServerName() 
	                   + ":" + request.getServerPort() + path + "/";
%>
<%
	System.out.print(basePath);
%>
<!-- 引入css样式文件 -->
	<!-- Bootstrap Core CSS -->
	<link href="<%=basePath%>css/bootstrap.min.css" rel="stylesheet" />
	<!-- MetisMenu CSS -->
	<link href="<%=basePath%>css/metisMenu.min.css" rel="stylesheet" />
	<!-- DataTables CSS -->
	<link href="<%=basePath%>css/dataTables.bootstrap.css" rel="stylesheet" />
	<!-- Custom CSS -->
	<link href="<%=basePath%>css/sb-admin-2.css" rel="stylesheet" />
	<!-- Custom Fonts -->
	<link href="<%=basePath%>css/font-awesome.min.css" rel="stylesheet" type="text/css" />
	<link href="<%=basePath%>css/boot-crm.css" rel="stylesheet" type="text/css" />
</head>


</head>
<body>

<a href="#" class="btn btn-primary" data-toggle="modal" data-target="#newCustomerDialog" onclick="clearUser()">找回密码</a>
	           
<div class="modal fade" id="newCustomerDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
	<div class="modal-dialog" role="document">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close">
					<span aria-hidden="true">&times;</span>
				</button>
				<h4 class="modal-title" id="myModalLabel">找回用户密码</h4>
			</div>
			<div class="modal-body">
				<form class="form-horizontal" id="find_user_form" method="POST" action="${pageContext.request.contextPath }/findpassword.action" 
					  onsubmit="return findUser()"	>
					<div class="form-group">
						<label for="user_usercode" class="col-sm-2 control-label">
						    用户账号
						</label>
						<div class="col-sm-10">
							<input type="text" class="form-control" id="user_usercode" placeholder="用户账号" name="user_usercode" />
						</div>
					</div>
					<input type="submit" value="开始找回密码">
				</form>
			</div>
			<div class="modal-footer">
				<button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
				
			</div>
		</div>
	</div>
</div>

<!-- 从后台获取model中的值（获取数据库中的password） -->
<input type="hidden" id="password" value='${password}'>	

<!-- 引入js文件 -->
<!-- jQuery -->
<script src="<%=basePath%>js/jquery-1.11.3.min.js"></script>
<!-- Bootstrap Core JavaScript -->
<script src="<%=basePath%>js/bootstrap.min.js"></script>
<!-- Metis Menu Plugin JavaScript -->
<script src="<%=basePath%>js/metisMenu.min.js"></script>
<!-- DataTables JavaScript -->
<script src="<%=basePath%>js/jquery.dataTables.min.js"></script>
<script src="<%=basePath%>js/dataTables.bootstrap.min.js"></script>
<!-- Custom Theme JavaScript -->
<script src="<%=basePath%>js/sb-admin-2.js"></script>
<!-- 编写js代码 -->
<script type="text/javascript">
//清空新建客户窗口中的数据
	function clearUser() {
	    $("#user_usercode").val("");
	}
	// 创建客户
	function findUser() {
		var user_usercode = $("#user_usercode").val();
	    if(user_usercode==""){
	    	alert("必填项不能为空，请重新输入")
	        return false;
	    }  
	    else{
	    	
	    	var data = $("#password").val();
	    	var val = eval("("+data+")");
	    	 alert(val);
	 	    
	    }
	   
	}
	</script>
</body>
</html>
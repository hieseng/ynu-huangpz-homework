<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
    <%@ page trimDirectiveWhitespaces="true"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
 <%@ taglib prefix="itheima" uri="http://itheima.com/common/"%> 
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>用户注册页面</title>
<%
	String path = request.getContextPath();
	String basePath = request.getScheme() + "://" + request.getServerName() 
	                   + ":" + request.getServerPort() + path + "/";
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


<body>
<a href="#" class="btn btn-primary" data-toggle="modal" data-target="#newCustomerDialog" onclick="clearUser()">开始注册</a>
<a href="login.jsp" class="btn btn-primary" >返回登录</a>
<!-- 创建用户模态框 -->
<div class="modal fade" id="newCustomerDialog" tabindex="-1" role="dialog" aria-labelledby="myModalLabel">
	<div class="modal-dialog" role="document">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close">
					<span aria-hidden="true">&times;</span>
				</button>
				<h4 class="modal-title" id="myModalLabel">新建用户信息</h4>
			</div>
			<div class="modal-body">
				<form class="form-horizontal" id="new_user_form" 
				action="${pageContext.request.contextPath}/createuser.action" method="post" onsubmit="return createUser()">
					<div class="form-group">
						<label for="user_usercode" class="col-sm-2 control-label">
						    用户账号
						</label>
						<div class="col-sm-10">
							<input type="text" class="form-control" id="user_usercode" placeholder="用户账号" name="user_usercode" />
						</div>
					</div>
					<div class="form-group">
						<label for="user_username" class="col-sm-2 control-label">用户姓名</label>
						<div class="col-sm-10">
							<input type="text" class="form-control" id="user_username" placeholder="用户姓名" name="user_username" />
						</div>
					</div>
					<div class="form-group">
						<label for="user_password" class="col-sm-2 control-label">用户密码</label>
						<div class="col-sm-10">
							<input type="text" class="form-control" id="user_password" placeholder="用户密码" name="user_password" />
						</div>
					</div>
					<input type="submit" value="新建用户">
				</form>
			</div>
			<div class="modal-footer">
				<button type="button" class="btn btn-default" data-dismiss="modal">关闭</button>
				
			</div>
		</div>
	</div>
</div>
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
	    $("#user_username").val("");
	    $("#user_userpassword").val("");
	    
	}
	// 创建客户
	function createUser() {
		var user_usercode = $("#user_usercode").val();
		var user_username = $("#user_username").val();
	    var user_password = $("#user_password").val();
	    if(user_usercode=="" || user_username=="" || user_password==""){
	    	alert("必填项不能为空，请重新输入")
	        return false;
	    }  
	    else{
	    	 alert("用户创建成功！");
	 	     window.open("login.jsp"); 
	 	    return true;
	    }
	   
	}
	<%-- $.post("<%=basePath%>/create.action",
	$("#new_user_form").serialize(),function(data){
		alert(data);
	        if(data =="OK"){
	            alert("用户创建成功！");
	            window.location.reload();
	            window.open("login.jsp");
	        }else{
	            alert("用户创建失败！");
	            window.location.reload();
	        }
	    }); --%>
	
	
  
</script>
</body>
</html>
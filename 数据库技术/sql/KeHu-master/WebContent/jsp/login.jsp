<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<title>登录页面</title>
<meta http-equiv=Content-Type content="text/html; charset=utf-8">
<link href="${pageContext.request.contextPath}/css/Login.css" type=text/css rel=stylesheet>
<link href="${pageContext.request.contextPath}/css/boot-crm.css" type=text/css rel=stylesheet>
<script src="${pageContext.request.contextPath}/js/jquery-1.11.3.min.js"></script>
<meta content="MSHTML 6.00.2600.0" name=GENERATOR>

<script>
// 判断是登录账号和密码是否为空
function check(){
    var usercode = $("#usercode").val();
    var password = $("#password").val();
    if(usercode=="" || password==""){
    	alert("账号或密码不能为空，请重新输入")
        return false;
    }  
    return true;
}
</script>


</head>
<body leftMargin=0 topMargin=0 marginwidth="0" marginheight="0" background="${pageContext.request.contextPath}/images/bg2.jpg">
<div class="box">
            <h2>客户管理系统</h2>
  		<form action="${pageContext.request.contextPath }/login.action" method="post" onsubmit="return check()">
	    <div class="inputBox">
	      <input type="text" id="usercode" name="usercode" >
	      <label>用户名</label>
	    </div>
	    <div class="inputBox">
		  <input type="password" id="password" name="password" >
			<label>密码</label>
	    </div>
	    <input type="submit"  value="登录"> 
	    <p style="color:white">未有账号？<a href="register.jsp" >请您注册</a></p>
  		<p style="color:white">忘记密码？<a href="find.jsp" >点击找回</a></p>

  </form>
	</div>
</body>
</html>

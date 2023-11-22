CREATE database CS2;
USE CS2;

CREATE TABLE DEPARTMENT
(	
		 Ddnumber CHAR(10) primary key,
         Dname CHAR(16),
         Dmanager CHAR(10),
         Daddress CHAR(50),
         Dtelephone CHAR(11)
);
 
 CREATE TABLE EMPLOYEE
 (
	     Eenumber CHAR(10) PRIMARY KEY,
         Ename CHAR(10),
         Eage smallint,
         Eposition CHAR(12),
         Ewage numeric(8,2),
         Ednumber CHAR(10),
         foreign key (Ednumber) references DEPARTMENT(Ddnumber)
);

CREATE USER 王明 identified BY '123456';
CREATE USER 李勇 identified BY '123456';
CREATE USER 刘星 identified BY '123456';
CREATE USER 张新 identified BY '123456';
CREATE USER 周平 identified BY '123456';
CREATE USER 杨兰 identified BY '123456';

/*测试数据*/
INSERT INTO DEPARTMENT VALUES('BM001','部门一','经理一','地址一','12345678901');
INSERT INTO DEPARTMENT VALUES('BM002','部门二','经理二','地址二','12345678902');
INSERT INTO DEPARTMENT VALUES('BM003','部门三','经理三','地址三','12345678903');

INSERT INTO EMPLOYEE VALUES('ZG001','王明',31,'职位一',11000,'BM001');
INSERT INTO EMPLOYEE VALUES('ZG002','李勇',32,'职位二',12000,'BM002');
INSERT INTO EMPLOYEE VALUES('ZG003','刘星',33,'职位三',13000,'BM003');
INSERT INTO EMPLOYEE VALUES('ZG004','张新',34,'职位四',14000,'BM002');
INSERT INTO EMPLOYEE VALUES('ZG005','周平',35,'职位五',15000,'BM003');
INSERT INTO EMPLOYEE VALUES('ZG006','杨兰',36,'职位六',16000,'BM001');

/*王明对两个表有SELECT权限*/
GRANT SELECT
ON TABLE EMPLOYEE
TO 王明;
GRANT SELECT
ON TABLE DEPARTMENT
TO 王明;

/*李勇对两个表有INSERT和delete权限*/
GRANT insert,delete
ON TABLE EMPLOYEE
TO 李勇;
GRANT insert



       
       
			 
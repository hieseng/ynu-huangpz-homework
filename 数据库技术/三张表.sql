create database CS;
create database CS1;
USE CS1;


CREATE TABLE STUDENT         
 (	
 Sno CHAR(9) PRIMARY KEY,                      
 Sname CHAR(20) UNIQUE,          
 Ssex CHAR(2),
 Sage SMALLINT,
 Sdept CHAR(20)
 ); 
 
CREATE TABLE COURSE
 (	
 Cno CHAR(4) PRIMARY KEY,
 Cname CHAR(40),            
 Cpno CHAR(4),               	                      
 Ccredit SMALLINT,
 FOREIGN KEY (Cpno) REFERENCES  Course(Cno) 
 ); 
 
CREATE TABLE  SC
 (
 Sno CHAR(9), 
 Cno CHAR(4),  
 Grade SMALLINT,
 PRIMARY KEY (Sno,Cno),                      
 FOREIGN KEY (Sno) REFERENCES Student(Sno),  
 FOREIGN KEY (Cno)REFERENCES Course(Cno)     
 ); 
 
 
INSERT  INTO  Student (Sno,Sname,Ssex,Sdept,Sage) VALUES ('201215121','李勇','男','CS',20);
INSERT  INTO  Student (Sno,Sname,Ssex,Sdept,Sage) VALUES ('201215122','刘晨','女','CS',19);
INSERT  INTO  Student (Sno,Sname,Ssex,Sdept,Sage) VALUES ('201215123','王敏','女','MA',18);
INSERT  INTO  Student (Sno,Sname,Ssex,Sdept,Sage) VALUES ('201215125','张立','男','IS',19);
INSERT  INTO  Student (Sno,Sname,Ssex,Sdept,Sage) VALUES ('201215128','陈冬','男','IS',20);
 
SELECT * FROM STUDENT;
 
INSERT  INTO Course(Cno,Cname,Cpno,Ccredit) VALUES ('1','数据库','5',4);
INSERT  INTO Course(Cno,Cname,Cpno,Ccredit)	VALUES ('2','数学',NULL,2);
INSERT  INTO Course(Cno,Cname,Cpno,Ccredit)	VALUES ('3','信息系统','1',4);
INSERT  INTO Course(Cno,Cname,Cpno,Ccredit)	VALUES ('4','操作系统','6',3);
INSERT  INTO Course(Cno,Cname,Cpno,Ccredit)	VALUES ('5','数据结构','7',4);
INSERT  INTO Course(Cno,Cname,Cpno,Ccredit)	VALUES ('6','数据处理',NULL,2);
INSERT  INTO Course(Cno,Cname,Cpno,Ccredit)	VALUES ('7','Pascal语言','6',4);
 
UPDATE Course SET Cpno = '5' WHERE Cno = '1' ;
UPDATE Course SET Cpno = '1' WHERE Cno = '3' ;
UPDATE Course SET Cpno = '6' WHERE Cno = '4' ;
UPDATE Course SET Cpno = '7' WHERE Cno = '5' ;
UPDATE Course SET Cpno = '6' WHERE Cno = '7' ;
 
SELECT * FROM Course;
 
INSERT  INTO SC(Sno,Cno,Grade) VALUES ('201215121','1',92);
INSERT  INTO SC(Sno,Cno,Grade) VALUES ('201215122','2',85);
INSERT  INTO SC(Sno,Cno,Grade) VALUES ('201215123','3',88);
INSERT  INTO SC(Sno,Cno,Grade) VALUES ('201215125','2',90);
INSERT  INTO SC(Sno,Cno,Grade) VALUES ('201215128','3',80);
 
SELECT * FROM SC;

SET SQL_SAFE_UPDATES = 0;

DELETE
FROM SC;


create database CS3;
use cs3;

CREATE TABLE S
(SNO CHAR(2) PRIMARY KEY,
SNAME CHAR(10),
STATUSES SMALLINT,
CITY CHAR(4));

INSERT INTO S
VALUES('S1','精益',20, '天津'), ('S2','盛锡',10, '北京'),('S3', '东方红', 30, '北京'), ('S4', '丰泰盛', 20, '天津'), ('S5', '为民', 30, '上海');

CREATE TABLE P
(PNO CHAR(2) PRIMARY KEY,
PNAME CHAR(10),
COLOR CHAR(2),
WEIGHT SMALLINT);

INSERT INTO P
VALUES('P1','螺母','红', 12), ('P2', '螺栓', '绿', 17), ('P3', '螺丝刀', '蓝', 14), ('P4', '螺丝刀', '红', 14), ('P5', '凸轮', '蓝', 40), ('P6', '齿轮', '红', 30);

CREATE TABLE J
(JNO CHAR(2) PRIMARY KEY,
 JNAME CHAR(10), 
 CITY CHAR(4));
 
INSERT INTO J
VALUES('J1', '三建', '北京'), ('J2', '一汽', '长春'), ('J3', '弹簧厂', '天津'), ('J4', '造船厂', '天津'), ('J5', '机车厂', '唐山'), ('J6', '无线电厂', '常州'), ('J7', '半导体厂', '南京');

CREATE TABLE SPJ
(SNO CHAR (2),
PNO CHAR(2), 
JNO CHAR(2),
QTY INT,
primary key(SNO, PNO, JNO)
);

INSERT INTO SPJ
VALUES('S1', 'P1', 'J1', 200),
('S1', 'P1', 'J3', 100),
('S1', 'P1', 'J4', 700),
('S1', 'P2', 'J2', 100),
('S2', 'P3', 'J1', 400),
('S2', 'P3', 'J2', 200),
('S2', 'P3', 'J4', 500),
('S2', 'P3', 'J5', 400),
('S2', 'P5', 'J1', 400),
('S2', 'P5', 'J2', 100),
('S3', 'P1', 'J1', 200),
('S3', 'P3', 'J1', 200),
('S4', 'P5', 'J1', 100),
('S4', 'P6', 'J3', 300),
('S4', 'P6', 'J4', 200),
('S5', 'P2', 'J4', 100),
('S5', 'P3', 'J1', 200),
('S5', 'P6', 'J2', 200),
('S5', 'P6', 'J4', 500);

/*(3)求供应J1零件为红色的供应商号码SNO: S1 S3*/
SELECT SNO
FROM SPJ
WHERE JNO='J1'
      AND PNO IN(SELECT PNO
                 FROM P
				 WHERE COLOR='红'
                 );

/*（4）求没有使用天津供应商生产的红色零件的工程号JNO:J1 J2 J4*/
SELECT JNO
FROM SPJ
WHERE PNO IN(SELECT PNO
             FROM P
			 WHERE COLOR='红'
             )
			AND SNO NOT IN(SELECT SNO
                           FROM S
                           WHERE CITY='天津'
                           );
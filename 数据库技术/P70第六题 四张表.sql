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


USE CS1;

/*P70第六题：（1）求供应J1零件的供应商号码SNO: S1 S2 S3 S4 S5*/
SELECT SNO
FROM SPJ
WHERE JNO='J1';

/*(2)求供应J1零件P1的供应商号码SNO: S1 S3*/
SELECT SNO
FROM SPJ
WHERE JNO='J1'
	  AND PNO='P1';

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
				
/*(5)求至少用了供应商S1所供应的全部零件的工程号JNO: J4*/
SELECT distinct JNO
FROM SPJ SPJX
WHERE NOT EXISTS(
                 SELECT *
                 FROM SPJ SPJY
                 WHERE SPJY.SNO='S1'
                 AND NOT EXISTS(
                        SELECT *
                        FROM SPJ SPJZ
                        WHERE SPJZ.JNO=SPJX.JNO
                        AND SPJZ.PNO=SPJY.PNO
                        )
				 );
                           
/*------------------------------------------------------------------------------------------------------------------*/

/*P130第五题：（1）找出所有供应商的姓名和所在城市*/
SELECT SNAME,CITY
FROM S;


/*(2)找出所有零件的名称、颜色、重量*/
SELECT PNAME,COLOR,WEIGHT
FROM P;

/*(3)找出使用供应商S1所供应零件的工程号码*/
SELECT DISTINCT JNO
FROM SPJ
WHERE SPJ.SNO = 'S1';

/*（4）找出工程项目J2使用的各种零件的名称和数量*/
SELECT PNAME,QTY
FROM SPJ,P
WHERE SPJ.PNO = P.PNO AND JNO = 'J2';
				
/*(5)找出上海厂商供应的所有零件号码*/
SELECT PNO
FROM SPJ,S
WHERE SPJ.SNO = S.SNO AND S.CITY = '上海';

/*（6）找出使用上海产的零件的工程名称 */
SELECT JNAME
FROM S,J,SPJ
WHERE S.SNO = SPJ.SNO AND 
      SPJ.JNO = J.JNO AND
      S.CITY = '上海';

/*(7)找出没有使用天津产的零件的工程号码 */
SELECT DISTINCT JNO
FROM SPJ
WHERE JNO NOT IN(
      SELECT DISTINCT JNO
      FROM SPJ,S
      WHERE S.SNO = SPJ.SNO AND S.CITY = '天津'
);


/*(8)把全部红色零件的颜色改成蓝色 */
SET SQL_SAFE_UPDATES = 0;
UPDATE P
SET COLOR = '蓝'
WHERE COLOR = '红';      

/*不加SET SQL_SAFE_UPDATES = 0;这一行，报错：
you are using safe update mode and you tried to update a table
 without a WHERE that uses a KEY column To disable safe mode, 
toggle the option in Preferences -> SQL Editor and reconnect.
原因：默认的安全策略，使得更新时，如果不依靠主键列进行查询时将被提示并失败。
解决方式：SET SQL_SAFE_UPDATES = 0;
关掉该方式：SET SQL_SAFE_UPDATES = 1;
*/

/*（9）由S5供给J4的零件P6改为由S3供应，请作必要修改*/
UPDATE SPJ
SET SNO='S3'
WHERE SNO='S5' AND PNO= 'P6' AND JNO= 'J4';

/*犯了很傻的错误：拼写错误，将P167里面的SNO打成SN0了
错误一直显示Unknown column 'SNO'in'where clause'
其实就是没有找到这个拼写错的SN0。*/

/*(10)从供应商中删除S2的记录，并从供应情况中删除相应的记录*/
DELETE
FROM s
WHERE SNO = 'S2';

DELETE
FROM SPJ
WHERE SNO = 'S2';

/*(11)请将（S2,J6,P4,200）插入供应关系*/
INSERT INTO SPJ
VALUES('S2','J6','P4',200);




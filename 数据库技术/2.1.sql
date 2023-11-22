/* 今有以下两个关系模式：
职工（职工号，姓名，年龄，职务，工资，部门号）
部门（部门号，名称，经理名，地址，电话号）*/
CREATE DATABASE IF NOT EXISTS TEST3B CHARACTER SET 'utf8';
USE TEST3B;
create table Staff
(
    Stno char(10) PRIMARY KEY,
    Stname char(10),
    Stage int(2),
    Stjob char(5),
    Stwage int(10),
    Stdno char(5)
);
create table Department
(
    Dno char(5) PRIMARY KEY,
    Dname char(10),
    Dmname char(10),
    Daddress char(20),
    Dphone char(11)
);
-- 创建题中用户
CREATE ROLE wangming;
CREATE ROLE liyong;
CREATE ROLE liuxing;
CREATE ROLE zhangxin;
CREATE ROLE zhouping;
CREATE ROLE yanglan;
-- 加上视图机制
CREATE VIEW Staff_view AS SELECT * FROM Staff;
CREATE VIEW Department_view AS SELECT * FROM Department;

-- （1）加上视图机制，用户王明对两个表有SELECT权限。
GRANT SELECT ON Staff_view TO wangming;
GRANT SELECT ON Department_view TO wangming;

-- （2）加上视图机制，用户李勇对两个表有INSERT和DELETE权限。
GRANT INSERT,DELETE ON Staff_view TO liyong;
GRANT INSERT,DELETE ON Department_view TO liyong;

-- （3）每个职工只对自己的记录有SELECT权限。
CREATE VIEW Staff_view2 AS SELECT * FROM Staff_view WHERE concat(Stname,'@%') = USER();
GRANT SELECT ON Staff_view2 TO wangming,liyong,liuxing,zhangxin,zhouping,yanglan;

-- （4）加上视图机制，用户刘星对职工表有SELECT权限，对工资字段具有更新权限。
GRANT SELECT,UPDATE(Stwage) ON Staff_view TO liuxing;

-- （5）加上视图机制，用户张新具有修改这两个表的结构的权限。
GRANT ALTER ON Staff_view TO zhangxin;
GRANT ALTER ON Department_view TO zhangxin;

-- （6）加上视图机制，用户周平具有对两个表的所有权限（读、插、改、删数据），并具有给其他用户授权的权限。
GRANT ALL PRIVILEGES ON Staff_view TO zhouping WITH GRANT OPTION;
GRANT ALL PRIVILEGES ON Department_view TO zhouping WITH GRANT OPTION;

-- （7）加上视图机制，用户杨兰具有从每个部门职工中SELECT最高工资、最低工资、平均工资的权限，他不能查看每个人的工资。
CREATE VIEW Depwage_view(Dname,maxs,mins,avgs) AS SELECT Dname,max(Stwage),min(Stwage),avg(Stwage) 
FROM Staff_view,Department_view WHERE Staff_view.Stname=Department_view.Dname 
GROUP BY Staff_view.Stno,Department_view.Dno;
GRANT SELECT ON Depwage_view TO yanglan;


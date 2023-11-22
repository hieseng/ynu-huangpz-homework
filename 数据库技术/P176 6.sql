use cs2;
CREATE TABLE DEPT(
    Deptno CHAR(2),
    Deptname VARCHAR(10),
    Manager VARCHAR(10),
    PhoneNumber Char(12),
    CONSTRAINT PK_SC PRIMARY KEY(Deptno)
);

CREATE TABLE EMP(
    Empno CHAR(4),
    Ename VARCHAR(10),
    Age CHAR(2),
    CONSTRAINT C1 CHECK ( Aage<=60),
    Job VARCHAR(9),
    Sal NUMBER(7,2),
    Deptno NUMBER(2),
    CONSTRAINT FK_DEPTNO FOREIGN KEY(Deptno) REFFERENCES DEPT(Deptno)
);

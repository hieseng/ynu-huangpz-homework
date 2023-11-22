CREATE database CS4;
USE CS4;

CREATE TABLE Department
(Sdeptnum CHAR(6) PRIMARY KEY,
Dname CHAR(5) NOT NULL,
Manager CHAR(8) NOT NULL,
Address CHAR(15),
PH CHAR(11)
);
CREATE TABLE Staff(
Sno CHAR(11) PRIMARY KEY,
Sname CHAR(10) UNIQUE NOT NULL,
Sage INT,
Sjod CHAR(5),
Salary INT,
Sdeptnum CHAR(6) REFERENCES  Department(Sdeptnum)
);

GRANT SELECT
ON Staff 
TO 王明;
GRANT SELECT
ON  Department
TO 王明;

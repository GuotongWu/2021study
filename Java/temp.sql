-- 创建数据库
CREATE DATABASE SWJTU;
-- 创建表
CREATE TABLE IF NOT EXISTS student(
    sno INT UNSIGNED AUTO_INCREMENT,
    sname VARCHAR(10) NOT NULL,
    sgrade INT UNSIGNED,
    PRIMARY KEY (sno)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;
CREATE TABLE IF NOT EXISTS course(
    cno INT UNSIGNED AUTO_INCREMENT,
    cname vARCHAR(10) NOT NULL,
    PRIMARY KEY(cno)
);
CREATE TABLE IF NOT EXISTS stucourse(
    sno INT UNSIGNED,
    cno INT UNSIGNED,
    PRIMARY KEY(sno, cno) 
);
-- 插入数据
INSERT INTO student(sno,sname,sgrade, submitdate) 
VALUES
(0, "LiHua", 98, NOW()),
(0, 'MingMing', 55, NOW()),
(0, "XiaoHuang", 99, NOW()),
(0, "Jake", 67, NOW());
INSERT INTO course(cno, cname)
VALUES 
(0, "操作系统"),
(0, "计算机网络"),
(0, "数据库基础");
INSERT INTO stucourse(sno, cno)
VALUES 
(1, 2),
(1, 3),
(3, 1);
-- 查询表数据
SELECT * FROM student;
SELECT * FROM course;
SELECT * FROM stucourse;
SELECT sno, sname FROM student
WHERE sgrade<60;
SELECT sname, cname FROM student, course, stucourse
WHERE student.sno=stucourse.sno AND course.cno=stucourse.cno; 
-- 删除数据
DELETE FROM student WHERE sno>=2;
-- 表中修改列
ALTER TABLE student 
ADD COLUMN submitdate DATE AFTER sgrade;
ALTER TABLE student ADD UNIQUE(sname);
ALTER TABLE stucourse
ADD CONSTRAINT FOREIGN KEY(cno) REFERENCES course(cno);
ALTER TABLE stucourse
ADD CONSTRAINT FOREIGN KEY(sno) REFERENCES student(sno);
-- 修改表中数据
UPDATE student
SET submitdate=NOW() WHERE sno=1
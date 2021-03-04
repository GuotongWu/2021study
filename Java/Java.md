# Java

## 1. 基本数据类型

Unicode字符集

### 1.1 基本数据类型：

boolean, byte(1), short(2), int(4), long, char, float(常量后面有f), double

### 1.2 输入输出：

输入

```java
import java.util.Scanner;

Scanner reader = new Scanner(System.in);
int x = reader.nextInt();
double y = reader.nextDouble();
```

输出

`System.out.print()`和`System.out.printIn()`类似，区别在于换行，可使用`+`将变量、字符串并置输出

`System.out.printf()`用法与C语言类似

### 1.3 数组

声明：不允许在声明的`[]`中指定数组元素的个数，声明方式为`int [] a;`

```java
//与C语言不同
int size = 30;
int [] a = new int[size]
```

赋值：`a = new int[4]`，此时数组元素会赋上一个默认的值

二维数组：

```java
int [][] x = new int [4][3];
//遍历
for(int [] items: x){
	for(int item: items) 
		System.out.print(item+" ");
    System.out.print("\n");
}

int [][] b = new int[3][]; //也可
b[0] = new int[3];
b[1] = new int[12];
b[2] = new int[1]
```

length：`a.length()`

数组的引用：当对数组进行赋值时，`a = b`，系统自动释放原来a的空间

## 2. 运算符

instanceof: obj intanceof class，判断对象是否右边类的实例

```java
int sum = 0;
// int x;
Scanner reader = new Scanner(System.in);
while(reader.hasNextInt()){
	sum += reader.nextInt();
}
```

## 3. 类与对象

new的结果是一个16进制数，成为对象的引用

没有析构方法

### 3.1 参数传递

值传递：基本数据结构的参数传递都是值传递，不会影响原来的变量

引用传递：数组、对象、接口为引用传递

可变参数：

```java
public void func(int ... x){ // 可变参数必须写在参数表的最后
	x[0]++;
    for(int item: x) // 同样适用于可变参数
		System.out.print(item+" ");
    System.out.print("\n");
}
```

### 3.2  对象的组合

```java
class A{
    int x; 
}
class B{
    int y;
    A a; //刚刚创建的时候还是一个空对象，具体使用要在后面进行赋值，具体关系见书
}
```

### 3.3 实例成员和类成员

```java
class Animal{
    int x; // 实例变量
    static int number; // 类变量，可以通过类名直接访问
    int max(int a, int b){} // 实例方法，两种变量都可以操作
    static int min(int a, int b){} // 类方法，只能操作类变量，可以直接类名调用
}
```

典型的类方法有Array和Math

```java
int [] sum = {0,1,3,-9,2};
Arrays.sort(sum);
for(int item: sum)
	System.out.print(item + " ");
```

### 3.4 重载

多态：重载、重写

重载：参数的个数、参数的类型有不同存在；**注意返回类型和参数名字不参与比较**

歧义调用

### 3.5 this关键字

表示某个对象，可以出现在实例方法、构造方法中，但是不能出现在类方法中

当实例变量、类变量都在实例方法中出现时，默认格式为（方法的调用也与其类似）：

```java
class A{
    int x;
    static int y;
    void f(){
        this.x = 100;
        A.y = 200; // 在没有出现名字相同的局部变量时，二者前面的也可以忽略
    }
}
```

### 3.6 包

包编译、运行必须在上一级目录进行

```shell
cd "d:\Github\2021study\Java" ; if ($?) { java top.omysycamore.hello }
```

### 3.7 import语句

系统自动引入`java.lang`包中的类

引入自定义包中的类

```java
import top.omysycamore.*;
// 可以更新位置
set classpath = ...;
hello h = new hello();
```

### 3.8 访问权限

私有：private

共有：public

受保护：protected

友好：什么都不用修饰，只能访问**同一个包**的友好变量和方法

注意类的修饰没有protected和private

### 3.9 基本类型的类封装

Double, Float, Integer, Long, Byte, Short, Character

### 3.10 对象数组

```java
Student [] s = new Student[10];
for(Student item: s)
    item = new Student(); //还要对每一个元素进行赋值
```


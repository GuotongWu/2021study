# Python

## 1. 概述

引号：自然语言使用双引号，机器标示使用单引号

空号：模块级函数和类定义之间空两行，类成员函数之间空一行

注释：文档注释以 """ 开头和结尾, 首行不换行, 如有多行, 末行必需换行

命名：常量采用全大写，函数名一律小写，模块尽量使用小写命名，类名使用驼峰(CamelCase)命名风格，首字母大写

## 2. 基本数据类型和变量

双引号中可以包含单引号，单引号类似

类型：`type(a)`

运算符：`**`, `//`(返回商的整数部分)

关系运算符：`and, or, not`

空值：`None`

UTF-8编码读取：`# -*- coding: utf-8 -*-`

基本的数据转换

![image-20210122164546614](../source/1.png)

多变量赋值：`a, b, c = 1, 2, "liangdianshui"`

## 3. List and Tuple

### 3.1 List

**方括号访问：**

```python
a = [1,2,3,4]
print(a[0:2])
```

结果是左开右闭，显示2个：[1,2]

**元素更新**：`name.append()`

**删除**：`del name[3]`

**列表运算符**：![image-20210122165754473](..\source/2.png)

**列表方法**：![image-20210122170013905](..\source/3.png)

### 3.2 Tuple

**创建**：`tuple=()`, `tuple=(123, )`, 如果不加逗号，创建出来的就不是 元组（tuple），而是指 `123` 这个数了

**删除**：`del tuple`

**元组运算符**：![image-20210123094247810](..\source\image-20210123094247810.png)

## 4 Dict

**创建**：`dict = {key1 : value1, key2 : value2 }`

**修改**：

```python
dict1={'liangdianshui':'111111' ,'twowater':'222222' ,'两点水':'333333'}
# 新增
dict1['jack']='444444'
# 修改
dict1['liangdianshui']='555555'
```

**删除**

```python
# 通过 key 值，删除对应的元素
del dict1['twowater']
# 删除所有元素
dict1.clear()
#删除字典
del dict1
```

**遍历**

```python
animal = {'cat':1, 'dog':2, 'pig':3}

print('This is for values')
for number in animal.values():
	print(number,end=' ')
print(' ')

print('This is for keys')
for key in animal.keys():
	print(key,end=' ')
print(' ')

print('This is for items')
for key,number in animal.items():
    print(key+' : '+str(number))
```

**其他函数和方法**：

![image-20210123100533955](..\source\image-20210123100533955.png)

## 5 Set

**创建**：

使用set函数，将一个列表转换为集合 `set1=set([123,456,789])`

其中元素不允许重复，可以使用此特性将列表里重复元素去掉

**添加**：`set1.add(100)`

**删除**：`set1.remove(456)`

**运算**：

```python
# 交集
set3 = set1 & set2
# 并集
set3 = set1 | set2
#差集
set3 = set1 - set2
```

## 6. 控制语句

`range`函数: `range(n) = range(0,n)`，都是左开右闭；`range(0,10,2)`，表示每次递增2

## 7. print函数

### 7.1 %用法

```python
"""整数"""
print('%o' %20) # 八进制
# %d, %x

"""浮点数"""
print('%.3f', %1.11) # 保留3位小数，默认6位
print('%e', %1.11) # 科学计数法
print('%.7g', %1.11) # 有效数字

"""round函数"""
round(1.1123) # 四舍五入

"""字符串"""
print('%10s', %'Hello') # 右对齐
print('%-10s', %'Hello') # 左对齐
```

### 7.2 format函数

```python
>>> print('{} {}'.format('hello','world'))  # 不带字段
hello world
>>> print('{0} {1}'.format('hello','world'))  # 带数字编号
hello world
>>> print('{0} {1} {0}'.format('hello','world'))  # 打乱顺序
hello world hello
>>> print('{1} {1} {0}'.format('hello','world'))
world world hello
>>> print('{a} {tom} {a}'.format(tom='hello',a='world'))  # 带关键字
world hello world
```

< （默认）左对齐、> 右对齐、^ 中间对齐、= （只用于数字）在小数点后进行补齐

取位数“{:4s}”、"{:.2f}"等

```python
print('{0} is {0:>10.2f}'.format(1.123))
# 取2位小数，10位右对齐，前面0表示format中元素序号
'{:*^30}'.format('centered')  # 使用“*”填充
```

## 8. 函数

**实例：**

```python
def functionname( parameters ):
   "函数_文档字符串"
   function_suite
   return [expression]
```

**返回值**：Python 一次接受多个返回值的数据类型就是元组

### 8.1 参数

默认参数：**只有在形参表末尾的那些参数可以有默认参数值**

```python
def print_name(name, age=18)
	print(name+": "+str(age))
	
print_name('wgt')
print_name('吴国桐',21)
```

关键字参数：可以通过参数名来给函数传递参数，而不用关心参数列表定义时的顺序

```python
def print_user_info( name ,  age  , sex = '男' ):
   pass

print_user_info( name = '两点水' ,age = 18 , sex = '女')
print_user_info( name = '两点水' ,sex = '女', age = 18 )
```

不定长参数：

无法确定传入的参数个数

```python
def print_user_info( name ,  age  , sex = '男' , * hobby):
	# hobby其实是一个元组
    pass

print_user_info( '两点水' ,18 , '女', '打篮球','打羽毛球','跑步')
```

可变长参数也支持关键字参数（位置参数），没有被定义的关键参数会被放到一个字典里。

```python
def print_user_info( name ,  age  , sex = '男' , ** hobby ):
    pass

print_user_info( name = '两点水' , age = 18 , sex = '女', hobby = ('打篮球','打羽毛球','跑步'))
```

只接受关键字参数: 将强制关键字参数放到某个`*`参数或者单个`*`后面

```python
def print_user_info( name , *, age  , sex = '男' ):
    pass

print_user_info( name = '两点水' ,age = 18 , sex = '女' )
# 这种写法会报错，因为 age ，sex 这两个参数强制使用关键字参数
# print_user_info( '两点水' , 18 , '女' )
```

### 8.2 函数传值

**不可更改的类型**：类似 c++ 的值传递，如 整数、字符串、元组。如fun（a），传递的只是 a 的值，没有影响 a 对象本身。比如在 fun（a）内部修改 a 的值，只是修改另一个复制的对象，不会影响 a 本身。

**可更改的类型**：类似 c++ 的引用传递，如 列表，字典。如 fun（a），则是将 a 真正的传过去，修改后 fun 外部的 a 也会受影响

### 8.3 匿名函数

```python
sum = lambda num1 , num2 : num1 + num2;
```

## 9. 迭代器

[iter.py](iter.py)

**迭代方法创建list**：

```python

```




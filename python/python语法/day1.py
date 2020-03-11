#!/usr/bin/env python
# coding=utf-8

print(5//2)   #  // 代表整除
import os

os.system("date")    #调用系统库
os.system("ip a s | grep ip")

#import turtle        画图工具  用途之一：用于股票绘制分析图
#turtle.showturtle()

# 练习题
# 1.1
#print("Welcome to Python")
#print("Welcome to Computer Science")
#print("Programming is fun")

#1.2
#print("Welcome to Python" * 5)

#1.3
#print("""
#      FFFFFFF \t U \t\t U \t NN \t\t NN
#      FF \
#      """)
#1.4

#1.5
#result = (9.5 * 4.5 - 2.5 * 3) / ( 4.5 - 3.5 )
#print(result)
#print(result)
#print("sddad")

#print(":")



import keyword
# 查看关键字
print(keyword.kwlist)

# 2.
var1 = 13
print(type(var1))  #类型
print(id(var1))    #地址


#  python  变量可以改变数据类型！
#  地址赋值  ->  改变数据类型
var1 = "hello"
print(type(var1))
print(id(var1))

# 相当于把"hello"地址赋值给var2  因此var1与var2相同
var2 = "hello"
print(id(var1) == id(var2))


# 复数数据类型
com=1 + 2j
print(type(com))


# 删除数据类型
num = 3 
del num 
# print(num) 

num1 = num2 = 10
print(num1,num2) # 元组


#交互对称赋值
num1,num2 = 2,3
print(num1,num2)


R=input("请输入圆形的半径")
print(R)
print(type(R)) 
#eval(R)  # 字符串转换为数字


# 3

print(1 + 2 + 3 + 4 + 5 +
      6 + 7 + 8 + 9)

print("hello, where is your mother \
      where is your father\
      where is your sister?")


num = 3; num1 = 4; num2 = 5;
print(num,num1,num2)

num1 = 100
num2 = 20
print(num1 + num2)
print(num1 // num2)
print(num1 / num2)
print(num1 ** 0.5) # 开方


data1 = 1.5e3
print(data1)



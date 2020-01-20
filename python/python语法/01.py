# -*- coding:utf8 -*-
# Jpython -- java
# Cpython -- c   pypy --
# python的后缀名？？ 后缀名可以是任意，任意都可以执行

# 但是导入模块时  不是.py就会出错

# 这个头是啥？？
# linux   ascill 00000000   unicode 0000000000000000+
# ! /usr/bin/env python

print("这是什么？")

# 2、永远等待用户输入值，并且将输入的值赋给n
n = input("请输入用户名：")  # n为变量
print(n)

"""
    多行注释
    变量： 字母数字下划线  与c、java一样不能以数字开头、 关键字也不能使用
    ['and', 'as', 'assert', 'break', 'class', 'continue', 'def', 'del', 'elif', 
    'else', 'except', 'exec', 'finally', 'for', 'from', 'global', 'if', 'import', 'in', 'is', 
    'lambda', 'not', 'or', 'pass', 'print', 'raise', 'return', 'try', 'while', 'with', 'yield']  
    python 内置的方法   sum()

    *注意，java中经常使用驼峰式命名，python多用下划线  user_id  
"""

n1 = "alex"
n2 = "root"
print(n1)
print(n2)

# 缩进可以任意，但是最好是4个
if 1 == 1:
    print("right")
elif 2 == 3:
    print("wrong")
else:
    print("thrid")

# 如果不想执行
inp = input("请输入")
if inp == "hello":
    pass
elif inp == "world":
    print("hello world")



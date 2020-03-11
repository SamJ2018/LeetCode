#!/usr/bin/env python
# coding=utf-8

def foo():
    print("foo")
def bar():
    print("bar")

dic = {
    'foo' : foo,
    'bar' : bar,
}

while True:
    choice=input(">>:")
    if choice in dic:
        dic[choice]()




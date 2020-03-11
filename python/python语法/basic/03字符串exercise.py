# python
# 转换  bool()   str()   int()


name = "  aleX  "
name.strip()
print(name.strip().startswith('al'))
print(name.endswith('X'))

print(name.replace("l", "p"))
print(name.partition('l'))  # l也会分割出来
print(name.rsplit('l'))

sname = name.rsplit('X')
print(type(sname))

print(name.upper())
print(name.lower())
print(name[1])
print(name[2])
print(name[0:-1])

name = "zhangsen"

print(name[-2:])
print(name[-3:])
print(name[-1:])

print(name.index('e'))

print(name[:-1])

# python2 和 python3 中的range 有啥区别？

# 用下划线拼接字符串
li = "alexericrain"
print(" ".join(li))

li = ["beautiful", "hel", "my"]
print(" ".join(li))

# python2  range立即创建
# xrange  for循环的时候才一个个创建

# python3  range  for循环的时候一个个创建

# 倒叙遍历
for i in range(100, 0, -1):
    print(i)

# 简单模拟加法
"""
content = input("请输入内容：")

v1, v2 = content.split('+')
print(int(v1) + int(v2))

content = input("请输入内容：")
alcnt = 0
nucnt = 0

for item in content:
    if item.isdigit():
        nucnt += 1
    elif item.isalpha():
        alcnt += 1
print(alcnt, nucnt)
"""

content = input("请输入内容：")

if content.find("苍老师") != -1 or content.find("东京热") != -1:
    new_content1 = str.maketrans("东京热", "***")
    v = content.translate(new_content1)
    print(v)

v = content.replace("东京热", "***")
print(v)

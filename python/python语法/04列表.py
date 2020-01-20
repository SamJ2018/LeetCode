# 列表  什么类型都可以放
li = [1, 2, 3, 4, False]
# 切片 得到的也是列表
print(li[3:-1])
# for item in li:
#     print(item)

# str不能修改->数组  list->链表
li.append(2)
li.sort()
print(li)

# 修改
li[2] = [6, 3, 1, 2]
li[0:3] = [2, 3, 4]

# 删除
del li[3]
print(li)
del li[1:-1]
print(li)

# 也可以判断4在li中
print(4 in li)

#
li = [1, 2, 3, 4, "age", ["omg", ["19", 10], "sdadsad"], True]
print(li[5][1][0][1])  # 9

s = "osadijafnnewqn!!"
print(list(s))  # 用，把每个字符分开

num = 123  # 数字不能循环，所以不能用list转换！！！

print(str(li))  # 仅仅加个""

# 如果列表中只有字符串可以使用join  否则只能写for循环

li = ["age", "username"]
print(" ".join(li))
print("-------------------")
li = [1, 2, 3, 4, "age", "username"]

s = ""
for item in li:
    s += str(item)
print(s)

li = [11, 22, 33, 44]
print(li.append(5))  # None 空值，什么都不是
print(li)

# 清空列表
li.clear()
print(li)

li = [11, 22, 33, 44]
# 拷贝
v = li.copy()  # 浅拷贝
print(v)

# 计算元素出现的次数
print(li.count(22))

# 在列表中追加多个
li = [11, 22, 33, 22, 44]
li.extend([9898, "不得了"])
"""
想当于 

for item in [9898, "不得了"]:
    li.append(item)
"""

print(li)

li.extend("不得了")  # 把每个字符加到列表中

# 根据值获得当前索引
print(li.index(33))

# 在指定索引位置插入
li = [11, 22, 33, 22, 44]
li.insert(0, 99)
print(li)

#
print(li.pop())  # 删除 并且返回值
print(li.pop(2))

# 反转
li = [11, 22, 33, 22, 44]
li.reverse()
print(li)

# sort
li.sort()
print(li)



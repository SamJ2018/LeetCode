# 元祖  元素不能被修改，不能增加或删除
tu = (111, 22, 33, 44)
# 为了与函数形参区分，建议在元祖后面加逗号
tu = (111, "alex", (11, 22), [(33, 44), True, 33, 44],)

v = tu[0]
print(v)

v = tu[0:2]
print(v)

# tu[0] =123  元祖不能增加和删除

for item in tu:
    print(item)

# 转换对象问题
s = "abcdefghi10"
li = ["abcs", 123, 7, 1, 19, 24]
tu = (123, 123, "abc")

# 可以转换字符串和列表
print(tuple(s))
print(tuple(li))

# 元祖也是可迭代对象！！ join 等都需要可迭代对象
li.extend((1, 3, 5, 7,))
print(li)

tu = (111, "alex", (11, 22), [(33, 44)], True, 33, 44 ,)
# 元组 有序的
print(tu[3][0][0])

# ** 虽然元祖不能修改，但是能修改链表中元祖
tu[3][0] = 567
print(tu)

# 元祖只有两个方法  count 获取元素在元祖中出现的次数   index 获取某个值的索引



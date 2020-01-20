# 集合  不同元素组成、无序，元素不可变类型
s = {1, 2, 3, 4, 5}

# 不可变类型  字符串 数字 元祖

s = set('hello')
print(s)

# 添加
s.add('b')
s.add(3)
print(s)

# 清空
s.clear()
print(s)

s.add('bb')
s.remove('bb')
s.add('asd')

# pop()
s.pop()
print(s)

# discard 删除元素不存在不会报错
s = {'sb', 'dff'}
s.discard('sddf')

# 并交叉
p1 = {'a', 'b', 'c'}
p2 = {'a', 'c', 'd'}

# 求交集
p_s = set(p1)
p_y = set(p2)
print(p1, p2)
print(p1 & p2)  # **
print(p1.intersection(p2))

# 求并集
print(p_s.union(p_y))

# 求差集
print(p_s - p_y)
print(p_s.difference(p_y))
print(p_s.symmetric_difference(p_y))
print(p_s ^ p_y)

# 求完差集更新回去
p_s.difference_update(p_y)
print(p_s)

# 有没交集？？
print(p_s.isdisjoint(p_y))

p_s = {'a', 'c'}
# 是否子集
print(p_s.issubset(p_y))
print(p_y.issuperset(p_s))

# 变成不可变集合
f_s = frozenset(p_s)

tp = "i am {}, age {}, {}".format("seven", 18, 'alex')
print(tp)

tpl = "i am {:s},age {:d}".format("seven", 18)
print(tpl)

l = ["seven", 18]
tpl = "i am {:2},age {:d}".format(*l)
print(tpl)

# 二进制  八进制  整型  十六进制  {:b}  {:o}  {:d}  {:x}       {:%}显示百分比

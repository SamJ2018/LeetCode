name = '你好'
print(bytes(name, encoding='utf-8'))
print(bytes(name, encoding='utf-8').decode('utf-8'))

# 打印某个对象的成员方法
# print(dir(dict))

# 可以用做分页使用  商3余1
print(divmod(10, 3))

# eval
dict = {'name': 'sam'}
dict_str = str(dict)
# print(dict_str)
d1 = eval(dict_str)  # 把字符串的dict提取出来
print(d1['name'])

# 2、把字符串中的数学运算做一遍
expre = '1 + 2 * 3 + (3 / 3 - 1) - 2'
print(eval(expre))

# 可hash的数据类型即不可变数据类型，不可hash的数据类型即可变数据类型


# print(help(all))

name = "dsadsadasdasdsaas"
print(globals())  # 查看全局变量
print(locals())  # 查看局部变量
print(__file__)

# 最大 最小值   如果在字典中  按字典序
l = [1, 3, 100, -1, 2]
print(max(l))
print(min(l))

# 一一对应  多匹配少的   参数只要序列就可以了！
print(list(zip(('a', 'b', 'c'), (1, 2, 3))))

# p = {'name': 'sam', 'age': 18, 'gender': 'male'}
# print(list(zip(p.keys(), p.values())))
# print(list(p.keys()))
# print(list(p.values()))

age_dic = {'aa': 18, 'bb': 20, 'c': 33}

people = [
    {'name': 'zs', 'age': 18},
    {'name': 'lisi', 'age': 24},
    {'name': 'wangwu', 'age': 21},
    {'name': 'zl', 'age': 14},
]

# 1 按顺序打印
print(list(max(zip(age_dic.values(), age_dic.keys()))))

dc = max(people, key=lambda dic: dic['age'])  # 传入字典，按照value比较
print("max:", dc)

print(sorted(people, key=lambda dic: dic['age']))

l = [
    (5, 'e'),
    (1, 'b'),
    (3, 'a'),
    (4, 'b'),
]
print(list(max(l)))

l = ['a10', 'a2', 'a10', 100]  # 不同类型之间不能比较  需要可迭代

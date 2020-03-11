# a ->97
print(ord('a'))
# 幂
print(pow(3, 2))

print(round(3.5))

#
l = 'hello'
print(l[3:5])
s1 = slice(1, 4, 2)
print(l[s1])

print(str('1'))
print(type(str({'a': 1})))
dict_str = str({'a': 1})
print(eval(dict_str))  # 转换为字典类型

print(sum(range(5)))

msg = '123'
# type判断类型
if type(msg) is str:
    msg = int(msg)
    res = msg + 1
    print(res)


def test():
    msg = 'asfasfasfasfasf'
    print(locals())
    print(vars())



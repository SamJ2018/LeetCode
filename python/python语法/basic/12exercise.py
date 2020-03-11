l = [1, 2, 3, 4, 5]
print(list(map(str, l)))


def func(array, start, end):
    sum = 0
    for i in range(start, end + 1):
        sum += array[i] if array[i] % 7 == 0 or array[i] % 3 == 0 else 0
    return sum


l = [1, 3, 4, 5, 7, 3, 7, 3, 7]

print(func(l, 0, 8))

ret = 1 if 1 > 0 else 5

# 2
l1 = [11, 22, 33]
l2 = [22, 33, 44]

print(set(l1) & set(l2))


#
def stat_str(str):
    dic = {'capital_num': 0, 'lowercase_num': 0, 'digit_num': 0}


import re

instr = input("请输入字符串")

lowercase = re.findall(r'[a-z]', instr)
capital = re.findall(r'[A-Z]', instr)
digit = re.findall(r'[0-9]', instr)
print("小写:", len(lowercase), "大写:", len(capital), "数字:", len(digit))


'''
def func(x, *y, **z):
    print(x, y, z)


func(1, name=2, age=3)  # 1 ->name 2->age

'''


# ([xxxx])

# 如果想把列表传过去变成元祖 要加*

# 14
def func1(x=1, *y, **z):
    print(x, y, z)
    return y
    print(x)


def func2(arg):
    ret = func1(name=arg)
    print(ret)


res = func2('fuck')
print(res)

#
s = '你好'

print(type(s))

a = bytes(s, "utf8")
s.encode('utf8')

print(a)





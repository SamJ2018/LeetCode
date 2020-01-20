import time

# 字符串格式

name = "我是字符串"
name = 'alex'
name = """alex"""
name = '''alex'''

n1 = "alex"
n2 = n1 * 10  # 输出10次n1

"""
inp = input("请输入一个数：")
if int(inp) % 2 == 0:
    print("偶数")
else:
    print("奇数")
"""

#  // 表示商
print(40 // 7)

count = 0
while count < 10:
    print('ok', time.time())
    count += 1

sum = 0
cnt = 99

while cnt:
    if cnt % 2 == 0:
        sum += -cnt
    else:
        sum += cnt
    cnt -= 1
print(sum)

n = 1
while n < 10:
    if n == 7:
        n = n + 1
        continue
    else:
        print(n, end=" ")
    n += 1
print(n)

"""
n = 3
while n > 0:
    username = input("请输入用户名")
    password = input("请输入密码")
    if username != "sam" or password != '123':
        n = n - 1
        print("用户名错误,您还有%d次机会" % n)
        continue
    else:
        print("欢迎登陆")
        break
"""

# 幂  **    in  / not in
name = "zzZZ"
print("zZZ" not in name)

print(2 ** 6)

num = 123400
str = "abcd"
print(num.bit_length())
print(str.upper())
print(str)
# python3 不管数字多大 都用int类型   python2 过大的数字还是会用long
# 常见类型  dict tuple bool list

# ------------------------------------------------------------------------------------------------------
# 1、数字的常用使用方法
# (1)
a = "123"
b = int(a)  # 把字符串转换为数字
b = b + 1000
print(type(b))  # <class int>

# (2)
num = "0011"
print(int(num, base=16))

# (3)
age = 128
r = age.bit_length()  # 表示age至少用几位来表示
print(r)

# (4)
test = "alex"
v1 = test.capitalize()
print(v1)

v2 = test.casefold()  # 更牛逼 很多未知的关系都能变小写
print(v2)
v3 = test.lower()
v4 = test.center(20, "*")
print(v4)
print(test.count('ex', 2))  # 第二个参数代表从第几个参数开始找
print(test.endswith('x'))  # 以什么为结尾？
print(test.startswith('a'))  # 以什么开头
print(test.find('e', 3))  # 从前往后找，找到第一个获取位置,找不到返回-1

# (5)
test = 'i am {name}, age {a}'  # 占用符
test2 = 'i am {0} ,age {1}'  # 顺序
print(test.format(name='alex', a=3))
print(test2.format('alex', 3))
print(test.format_map({"name": 'alex', "a": 19}))

# (6)
print(test.index('a'))  # 用find好一点，因为index找不到会忽略

print(test.isalnum())  # 判断是否只包含 字母和数字

# (7) 可以填充满，进行格式化？
test = "username\tpassword\temail\nsam\t123\tsam@163.com\n"
v = test.expandtabs(20)
print(v)

# （8）
test = "abcd"
print(test.isalpha())
print(test.isdigit())  # 判断是否是数字

# (9)
test = "二"
print(test.isdecimal())
print(test.isdigit())
print(test.isnumeric())

test = "oiuuuu\t"
print(test.isprintable())  # 是否存在不可见的东西?
test = '        '
print(test.isspace())

test = 'Return Baby'
print(test.istitle())  # 是否标题？ 首字母都要大写

# (10)
test = "你是风儿我是沙"
print('_'.join(test))  # 字符串拼接？
print(test.ljust(20, "*"))  # 把内容放左边，右边放20个*
print(test.zfill(20))  # 左边填充20个字符

print(test.islower(), test.lower())
print(test.isupper(), test.upper())

# (11)
test = "  aa  ss  "
print(test.lstrip())
print(test.rstrip())
print(test.strip())

# (12)
test = "xales"
print(test.rstrip("91exxas"))  # 从右边开始把匹配到的去掉

# (13)
test = "adkchcjnakldfnklasm"
new_str = str.maketrans("aeiou", "12345")  # 定义规则
print(test.translate(new_str))  # 替换

test = "testssssdadassssee"
print(test.split('s', 2))
print(test.partition('s'))
print(test.rsplit('s'))

test = "teadasdas\tsaasd\nasdasf\n"
print(test.splitlines())

test = "aleA"
print(test.swapcase())

# (14)  join split find strip upper lower
money = "alex"
print(money[0])
print(money[0:2])  # 0<=  <1
print(money[0:-1])  # -1直接找到最后  切片
print(len(money))

# (15)
li = [11, 22, 33, 44, 55, "abcd"]
print(len(li))

"""
test = "床前明月光"
index = 0
while index < len(test):
    v = test[index]
    print(v)
    index += 1
"""

"""
count = 0
for ch in test:
    if count % 2 == 0:
        print(ch)
    else:
        print(ch + 1)
    count += 1
"""

test = "abcdefgex"
v = test.replace("ex", "ccc")
print(v)

######################################## python内部有垃圾回收机制

v = range(0, 100, 5)  # range创建连续数字，第三个参数是设置步长

test = input(">>>")
for item in range(0, len(test)):
    print(item, test[item])

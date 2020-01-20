from functools import reduce

"""
    " " :函数注释，描述
    def :定义函数的关键字
"""


def test(x):
    '''

    :param x:
    :return: y
    '''
    y = 2 * x + 1
    return y


print(test(3))


# 注意 py执行重名函数  顺序执行最后一个
# 过程 就是没有返回值的函数 打印出来就是 None
# return 的可以多个值  实际上返回()
# 位置参数    def test(x,y,z)   test(y=4,x=4,z=5)
# 参数缺一不可

# 默认参数
def handle(x, type=None):
    print(x)
    print(type)


handle("hello")


def instanll(func1=False, func2=True, func3=True):
    pass


"""
# 参数组  **字典 *列表
def test(x, *args):  # 可变长参数
    print(x)
    print(args[0])
    print(args)


test(1, 2, 3, 4, 6, 7, )
test(1, {'name': 'alex'})  # 1 , 当作一个元素


# 关键字参数
def test(x, **kwargs):
    print(x)
    print(kwargs)


test(1, 1, 2, 3, y=2, z=3, )


"""


def test2(x, *args, **kwargs):
    print(x)
    print(args)
    print(kwargs)


# test2(7, 1, 2, 1, 1, 11, 1, y=2, z=3)

test2(1, *[1, 2, 3], **{'y': 2})

name = 'sam'


def test(*args):
    global name
    name = 'xxx'  # 修改全局变量
    print(name)


test(name)
print(name)


# nonlocal 指的是上一级变量

def test(*args):
    name = "sam"

    def wewe():
        nonlocal name
        name = "hello"

    wewe()
    print(name)


test(1)


# 函数作用域
def test1():
    print("in the test1")


def test3():
    return test1


t = test3()
t()


# 匿名函数
def calc(n):
    return n ** n


print(calc(10))

# 改成
calc = lambda n: n * n
print(calc(20))

# lambda x: x+1    x想当于形参


# 高阶函数    函数的传入参数是函数名或返回值是函数名
# 面向过程  函数式  面向对象


# 函数式编程   不用变量保存状态，不修改变量
# 非函数式  全局变量多次更改 ，不安全
a = 1


def incr_test1():
    global a
    a += 1
    return a


# 函数式编程
n = 1


def incr_test2(n):
    return n + 1


def foo(n):
    print(n)


def bar(name):
    print("my name is %s" % name)


foo(bar("haha"))

"""
# 返回值包含函数
def bar():
    print('from bar')
    return foo()  # 运行完才执行结束


def foo():
    print('from foo')
    return foo


foo()
n()

"""

# 1、需求  把列表的值都变成平方
num_l = [1, 2, 10, 5, 3, 7]

res = []
for i in num_l:
    res.append(i ** 2)
print(res)


# 方法二
def substract_one(x):
    return x - 1


def map_test(fun, array):
    ret = []
    for i in array:
        res = fun(i)
        ret.append(res)
    return ret


print(map_test(substract_one, num_l))
# 使用lambda更简洁
print(map_test(lambda x: x ** 3, num_l))

# 方法三 使用内置代替  python2 不用list   python3需要list转换
res = map(lambda x: x + 3, num_l)
print(list(res))
print(list(map(substract_one, num_l)))

msg = "samgood"
print(list(map(lambda x: x.upper(), msg)))

#
movie_people = ['s_alexs', 's_wp', 'bp', 'ss']


def s_show(n):
    return n.endswith("s")


def filter_test(func, array):
    ret = []
    for p in array:
        if not func(p):
            ret.append(p)
    return ret


# print(filter_test(s_show, movie_people))
print(filter_test(lambda n: n.endswith('s'), movie_people))
print(list(filter(lambda x: not x.startswith('s'), movie_people)))

# reduce() 内置函数
num_l = [1, 2, 3, 100]


def multi(x, y):
    return x * y


def reduce_test(fun, array, init=None):
    if init is None:
        res = array.pop(0)
    else:
        res = init
    for i in array:
        res = fun(res, i)
    return res


# reduce 用于合并
print(reduce_test(lambda x, y: x * y, num_l, 100))
print(reduce(lambda x, y: x * y, movie_people, 10))

people = [
    {'name': 'sam', 'age': 18},
    {'name': 'kmp', 'age': 22},
    {'name': 'samll', 'age': 124},
]

print(list(filter(lambda x: x['age'] <= 18, people)))

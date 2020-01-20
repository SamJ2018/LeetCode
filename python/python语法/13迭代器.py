#  迭代器 协议？  只能往后走不能往前走退    对象提供一个next方法->返回迭代下一项
#  可迭代对象  实现了迭代器协议的对象

l = [1, 2, 3]
for i in l:  # for循环遵循迭代器协议的对象  遍历的都是可迭代对象? no
    # 先执行 l.__iter__()   每次都执行 i.__next__()  只要碰到stopiteration  就结束循环
    print(i)  # 没有next

"""
x = 'hello'
te = x.__iter__()  # 可迭代对象
print(te.__next__())

print(l.__iter__().__next__())


"""

# for是基于迭代器工作！

"""
index = 0
while index < len(l):
    print(l[index])
    index += 1

但是非序列的类型不能用以上方式  
"""

s = {1, 2, 3}
for i in s:
    print(i)
iter_s = s.__iter__().__next__()

dic = {'a': 1, 'b': 2}
iter_d = dic.__iter__()
print(iter_d.__next__())  # 取的key值， 这就是for循环打印的也是key值  for循环本质也是调用它

l = ['father', 'son', 'grandson']
iter_l = l.__iter__()  # 只得到一个地址  可以在其它地方传输！！
print(iter_l.__next__())

# 生成器  自动实现了迭代器协议   不用执行 x.__iter__()方法   生成器就是可迭代对象
#  生成器函数     使用yield返回取代return   只要yield返回的就是生成器 直接使用.__next__()方法  yield可以返回多次
#  生成器表达式


# 三元表达式

name = 'alex'
nn = 'sb' if name == 'alex' else 'notnot'
print(nn)

# 列表解析
egg_list = []
for i in range(10):
    egg_list.append('鸡蛋%s' % i)
print(egg_list)

l = ['鸡蛋%s' % i for i in range(10) if i > 5]  # 二元处理  三元判断
print(l)

# laomuji = ('鸡蛋%s' % i for i in range(10))  # 生成器表达式
# print(laomuji.__next__())
# print(laomuji.__next__())
# print(laomuji.__next__())
# print(laomuji.__next__())
# print(laomuji.__next__())
# print(laomuji.__next__())  # 省内存！！

# 函数yield 效果一样  也是返回生成器 generator

# map reduce sorted 等都是基于迭代器协议
# l = [1, 2, 3, 4]
# print(sum(l))  # 转换为可迭代对象

# 如果一个列表存放一千万个数据  用列表解析[] 占用内存过大    ()可以使用以下方式！
# print(sum((i for i in range(10000))))

"""
def test():
    yield 1
    yield 2
    yield 3
    yield 4


res = test()
print(res.__next__())
print(res.__next__())
print(res.__next__())
print(res.__next__())
print(res.__next__())
print(res.__next__())  # stopiteration

"""

"""
def product_bun():
    ret = []
    for i in range(100):
        ret.append('包子%s' % i)
    return ret


"""


# print(product_bun())


def product_baozi():
    for i in range(100):
        yield '一屉包子%s' % i
        print("开始卖包子")


pro_g = product_baozi()


# print(pro_g.__next__())
# print(pro_g.__next__())
# print(pro_g.__next__())
# print(pro_g.__next__())
# print(pro_g.__next__())


# 下蛋例子
def xiadan():
    ret = []
    for i in range(100):
        ret.append('鸡蛋%s' % i)  # 要把所有鸡蛋孵出来再取   改成生成器方式生一个取一个
    return ret


print(xiadan())


def get_pop():
    with open('人口普查', 'r', encoding='utf8') as p:
        for i in p:
            yield i


pop_g = get_pop()

all_pop = sum(eval(i)['population'] for i in pop_g)
print(all_pop)

for p in pop_g:
    print(eval(p))


#迭代只能迭代一次
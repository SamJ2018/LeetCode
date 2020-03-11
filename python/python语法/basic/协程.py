import time

"""
def producer():
    ret = []
    for i in range(10000):
        ret.append('包子%s' % i)
    return ret


def consumer(res):
    for index, baozi in enumerate(res):
        print('第%s个人，吃了%s' % (index, baozi))


res = producer()
consumer(res)

"""

"""
# 除了__next__() 和 next() 外  还有第三种方式 send(None)
def test():
    print('开始啦')
    first = yield 1
    print('第一次', first)
    yield 2  # 接受send传过来的值，赋值给x
    print('第二次')


t = test()
res = t.__next__()
print(res)

t.send(None)  # 把None给了yield给了first

"""
import time


def consumer(name):
    print("我是[%s],我准备开始吃包子了" % name)
    while True:
        baozi = yield
        time.sleep(1)
        print('%s 很开心的把[%s]吃掉了' % (name, baozi))


def producer():
    c1 = consumer('sss')
    c1.__next__()
    for i in range(10):
        time.sleep(1)
        c1.send('蛋黄 包子 %s' % i)


producer()




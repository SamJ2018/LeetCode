# 字典

info = {"k1": "v1", "k2": "v2", "k3": [12, [], {'kk1': 'vv1', 'kk3': (11, 22)}], True: 123, 123: "000"}  # 键值对  属于dict类
# 想嵌套多少层都可以，value可以是任何值  能作为key:列表不可以，字典，元祖可以（因为元祖不能修改）
# 字典是无序的！！
print(info)
print(info[123])
print(info['k3'][2]['kk3'][0])

# 字典不能按索引[]或切片查找
# 删除
del info['k1']
print(info)

# 字典循环？
"""
for item in info:
    print(item)  
默认循环key
"""

for item in info.keys():
    print(item)

"""

for item in info.values():
    print(item)  #循环value
"""

for k, v in info.items():
    print(k, v)  # 一步到位，获得key和value

######### clear()清空 copy浅拷贝
dic = {"k1": "v1"}
v = dict.fromkeys(["k1", 123, "9999"], 123)  # 根据序列创建字典，并指定统一值
print(v)
# 如果通过dic['k111'] 访问字典，存在不存在key出错的风险，可以用下面的方法
print(dic.get('k11111', 11111))  # 不存在指定默认值

# pop()删除一个items 并且返回value  可以用默认值代替
print(dic.pop('k3', 1111))
dic = {'k1': 123, 'k2': 44, 'k3': '2da'}
print(dic.popitem())  # 随机删除
dic.setdefault('k333', '234')  # 设置值，如果存在 获取当前key对应的值
print(dic)

# update 更新
dic.update({'k1': 2222})
dic.update(k2=3333)
print(dic)

# keys() values() items()  get() update

# 总结

"""
数字 int()
字符串  replace/find/join/strip/startswith/split/lower/format
列表 append/extend/insert 
索引，切片，循环

元祖  一级元素不能被修改删除

字典 get/update/keys/values/items

以上都可以使用in

布尔值
bool(...)
假  None  ""  ()  []  {} ==> false
"""
template = 'i am {name},age {age}'
print(template.format(**{"name": 'sam', 'age': 18}))

print('k1' in dic.values())

L = []
l1 = [11, 22, 33]
l2 = [22, 33, 44]
for i in l1:
    if i not in l2 or i not in l1:
        L.append(i)
print(L)

num = [1, 2, 3, 4, 5, 6, 7, 8]
res = []
len2 = len(num)
j = 0

i = 1
"""
while i <= 9:
    j = 1
    while j <= i:
        print("%d*%d=%d" % (j, i, j * i), end=" ")
        j += 1
    print("\n")
    i += 1
"""

for i in range(1, 10):
    for j in range(1, i + 1):
        print("%d*%d=%d" % (j, i, j * i), end=" ")
    print("\n")

li = ['alex', 'eric', 123]
v = ""
li[2] = str(li[2])
print("_".join(li))

nums1 = [2, 7, 11, 15, 1, 8, 7]
len2 = len(nums1)
res = []
"""
i = 0
j = 0
while i < len2:
    j = 0
    while j < len2 - i:
        if nums1[i] + nums1[j] == 9:
            res.append((i, j))
        j += 1
    i += 1
print(res)
"""

for i in range(len(nums1)):
    for j in range(len(nums1)):
        if nums1[i] + nums1[j] == 9:
            res.append((i, j))
print(res)



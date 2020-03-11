## 一、常见操作速览

```python
# 空字典
D = {}
D = {'food': {'ham': 1, 'egg': 2}}

# 构造
D = dict.fromkeys(['a','b'])
print(D)

D = {'spam': 2, 'eggs': 3 , 'ham' : 4}
del D['spam']
print(list(D.values())) # [3, 4]

print(list(D.items())) # [('eggs', 3), ('ham', 4)]

# 防止键不存在出错
print(D.get('hallo'))  # None
print(D.get('hello','hola')) # hala

# update 用于合并
E = {'toast':4,'muffin':5}
D.update(E)
print(D)  # {'eggs': 3, 'ham': 4, 'toast': 4, 'muffin': 5}

# pop() 删除一个键
D.pop('toast')
print(D)   # {'eggs': 3, 'ham': 4, 'muffin': 5}


Matrix = {}
# 表示三维数组的一个点的值
Matrix[(2, 3, 4)] = 88
X, Y, Z = 2, 3, 4
print(Matrix[(X, Y, Z)])  # 88

# 键不存在时返回0
try:
    print(Matrix[(2, 5, 6)])
except KeyError:
    print(0)

# 或者使用这种方式
print(Matrix.get((2, 5, 6), 'error'))

# 其它创建字典方式
D = dict(name='mel', age=45)
D = dict([('name', 'mel'), ('age', 45)])  # *
print(D)

# 一次建立一个字典的字段
D['name'] = 'mell'
D['age'] = 45

# 简单初始化
D = dict.fromkeys(['a', 'b'], 0)
print(D) # {'a': 0, 'b': 0}


```

2. zip() 函数使用

```python
L = list(zip(['a', 'b', 'c'], [1, 2, 3]))
# [('a', 1), ('b', 2), ('c', 3)]
print(L)

D = dict(zip(['a', 'b', 'c'], [1, 2, 3]))
# {'a': 1, 'b': 2, 'c': 3}
print(D)
```

3. 使用字典解析表达式

```python
D = {k: v for (k, v) in zip(['a', 'b', 'c'], [1, 2, 3])}
# {'a': 1, 'b': 2, 'c': 3}
print(D)

D = {c.lower(): c + "!" for c in ['SPAM', 'EGGS', 'HAM']}
# {'spam': 'SPAM!', 'eggs': 'EGGS!', 'ham': 'HAM!'}
print(D)

# 两种初始化形式
D = dict.fromkeys(['spam', 'eggs', 'ham'], 0)
print(D)

print({s: 0 for s in ['spam', 'eggs', 'ham']})
```

4. 字典视图

```python
#
D = dict(a=1, b=2, c=3)
print(D)

for key in D:
    print(key, end=' ')
print()

for key in D.keys():
    print(key, end=' ')
print()

for val in D.values():
    print(val, end=' ')
print()

for (x, y) in D.items():
    print(x, ":", y, end=',')
print()

# 视图支持 交集 并集
K = D.keys()
print(K | {'x': 4})
print(K & K)
print(K & {'b': 5})

# 与集合做交集
print(type(D.items()))

what = D.items() | {('a', 1), ('b', 8)}
print(type(what))  # set
print(what)  # {('b', 2), ('b', 8), ('c', 3), ('a', 1)}
```

5. 其它操作

```python
D = dict(a=1, b=2, c=3, d='hello')

# 排序方式1
ks = list(D.keys())
ks.sort()
for k in ks: print(k, end=' ')

# 排序方式2
print()
for k in sorted(ks):
    print(k, D[k])


# python3  has_key已死  使用in
if 'a' in D:
    print('yes')
    
```


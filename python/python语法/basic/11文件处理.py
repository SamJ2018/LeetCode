# 打开文件，得到句柄 open函数会去检索操作系统的编码Gbk 修改编码
"""
f = open('古诗词','r', encoding='utf8')
data = f.read()  #读
print(f.readable()
print(f.readline(),end='') #每次读一行  没了就为空
f.readlines()  #全部读到一行
print(data)

f.close()  #关

"""

# r  w  a   只读  只写  只追加


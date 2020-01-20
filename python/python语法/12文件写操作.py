"""
f = open('古诗词', 'w', encoding='utf8')
f.write('122222')  # 重新创建文件 写入
f.write('122333')  # 重新创建文件 写入
f.writelines(['555\n', '3334\n'])  # 跟上面没实质区别
f.writable()

f.close()
"""

####追加##################################################
"""
f = open('古诗词', 'r+', encoding='utf8')
# r+  既能读又能写
data = f.readlines()
print(data) #是一个列表
# 文件都没有修改一说，都是覆盖！！  在内存中直接修改 整个覆盖回磁盘
# f.write('safaf')

dsc = open('new_xx', 'w', encoding='utf8')
dsc.writelines(data[0])
dsc.close()

dsc.close()
"""

# 用with  不需要close
with open('new_xx', 'w') as f:
    f.write("sadasdas")
    f.close()

with open('new_xx', 'r', encoding='utf8') as src_f, \
        open('古诗词', 'w', encoding="utf8") as dst_f:
    data = src_f.read()
    dst_f.write(data)

# 会把文件全部加载到内存中

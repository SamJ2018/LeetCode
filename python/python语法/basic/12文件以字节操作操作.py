# f = open('new_xx', 'rb', encoding='utf8')  #以二进制读取，不能指定编码！！
"""

f = open('new_xx', 'rb')
# ‘字符串’ ——>  encode  -> bytes
#  bytes -> decode  -> 字符串
data = f.read()
print(data.decode('utf8'))


"""
"""

f = open('new_xx', 'wb')
f.write(bytes('111100\n', encoding='utf8'))
f.write('哈哈'.encode('utf-8'))
"""

#  t  -> 文本   编码无关系  二进制  b

# 文件操作的其它方法
f = open('new_xx', 'w', encoding='utf8', newline='')  # 读取文件真正的换行符
print(f.closed)
print(f.encoding)  # 文件编码
f.flush()  # 把缓冲区的字符刷新过去
# 查看当前光标所在位置
f.tell()

# 0  只要不是read  其它方法都是字节
# 从 ？ 哪里开始
f.seek(0)
f.truncate(10)  # 截取   不是w  w清空  会截取不了

f.seek(10, 1)  # seek 要以b 操作
f.tell()  # 从

f.seek(-5, 2)  # 倒数5个字节处 开始读到末尾   日志文件？ 写日志加上时间  追加到末尾


#!/usr/bin/python3
# 第一行这个可以让py文件被执行
# 以#开头到语句是注释
# http://www.pythondoc.com/pythontutorial3/index.html

#-------------------------------------------------------------------------------
# print 输出函数
#-------------------------------------------------------------------------------

print('hello, world')
# print会依次打印每个字符串，遇到逗号会输出一个空格
print('string a', 'string b', 'string c')
print('aa', end=',')
print('aa', end='\n')
print(1+2+3)
# 打印时，两个子项之间会插入空格
print('1 + 1 =', 1 + 1)

print('hello,\n world')
print(r'hello,\n world')	# \不被当作特殊字符，使用原始字符串

print(3*'un')	# ununun, *表示重复

# 下面两种都是连接字符串
print('aa' + 'bb')
print('aa' 'bb')

#-------------------------------------------------------------------------------
# intput 输入函数
#-------------------------------------------------------------------------------

# input函数返回的是字符串
print('next line input name :')
name = input()
print('hello', name)

tips = input('please enter your name: ')
print('hello', tips)

#-------------------------------------------------------------------------------
# 数据类型
#-------------------------------------------------------------------------------

type('Hello, World')    # 返回值的类型
type(17)
type(3.2)

# 整数 python可以处理任意大小的整数
a = 1
b = -2
c = 0xff2

# 浮点数
d = 1.23
e = -2.10
f = 1.23e9  # 1.23x10^9
g = 1.2e-5

# 字符串
h = 'hi'
i = "yoyo"
print('hi\tyo\n')
j = '''line1
...line2
...line3'''

# 布尔值
k = True
l = False
m = 3 > 2
n = True and True # and, or, not

# 空值
o = None # None不能理解为0，因为0是有意义的，而None是一个特殊的空值

#-------------------------------------------------------------------------------
# 变量
#-------------------------------------------------------------------------------

# 变量是一个值的引用名称。变量名以字母、下划线和数字组成，长度不限，
# 必须以字母开头。

a = 'abc'   # a指向'abc'
b = a       # b和a一样也指向'abc'
a = 'xyz'   # a指向'xyz'，b依然指向'abc'
a = 1       # 动态语言，变量类型不固定
PI = 3.1415 # 通常用全部大写的变量表示常量，其实仍然可以改变PI的值
p = 10 / 3  # 3.3333
p = 9 / 3   # 3.0
q = 10 // 3 # 3
r = 10 % 3  # 1
s = 2 ** 7	# 2^7 = 128

#-------------------------------------------------------------------------------
# 字符串
#-------------------------------------------------------------------------------

# ASCII编码     1字节
# Unicode编码   2字节
# UTF-8编码     1-6字节，主要用于存储和传输
# python3使用Unicode编码

print('包含中文的str')
ord('A')    # 获取字符的整数表示
chr(66)     # 把编码转换为对应的字符

'\u4e2d\u6587' # 中文

a = 'abc'   # str字符串类型，在内存中以Unicode表示
b = b'abc'  # 以字节为单位，用于网络传输、保存到磁盘

'abc'.encode('ascii')   # 编码为ascii b'abc'
'中文'.encode('utf-8')  # 编码为utf-8 b'\xe4\xb8\xad\xe6\x96\x87'

b'abc'.decode('ascii')      # 将字节流当作ascii编码的，解码为unicode编码
b'\xe4\xb8\xad\xe6\x96\x87' # 将字节流当作utf-8编码的，解码为unicode编码

len('中文') # 计算字符数
len(b'abc') # 计算字节数

word = 'Python'
# 索引
print(word[0])	# 'P'
print(word[-0])	# 'P'
print(word[5])	# 'n'
print(word[-1])	# 'n'
print(word[-6])	# 'P'
print(word[-7])	# string index out of range
# 切片
print(word[0:2])	# 'Py'
print(word[2:5])	# 'tho'	左开右闭区间
print(word[:2])		# 'Py'
print(word[2:])		# 'thon'
print(word[-2:])	# 'on' 倒数第二个开始
print(word[2:42])	# 'thon'
print(word[42:])	# ''

#-------------------------------------------------------------------------------
# if
#-------------------------------------------------------------------------------

# 因为python不以分号结尾，所以if语句后面要跟冒号，表示这个语句块还没结束
x = 1
if x > 0 :
	print('x is positive')
if x < 0 :
	pass	# pass表示什么也不做
if x%2 == 0 :
	print('x is even')
else :
	print('x is odd')
if x == 'a':
	pass
elif x == 'b':
	pass
else :
	pass
if x == 'a':
	if x < a:
		pass

#-------------------------------------------------------------------------------
# try except 异常捕获
#-------------------------------------------------------------------------------
try:
	f = float(a)
except:
	print('catch except')

#-------------------------------------------------------------------------------
# 列表
# 列表是可变的（字符串不可变），可以背索引和切片，可以嵌套
#-------------------------------------------------------------------------------
squares = [1, 4, 9, 16, 25]
squares.append(48)
squares[0:2] = [3, 4]	# 使用切片更改值
squares[3:4] = []		# 使用切片删除值

#-------------------------------------------------------------------------------
# for
#-------------------------------------------------------------------------------
words = ['cat', 'window', 'defenestrate']
for w in words :
	print(w, len(w))

#-------------------------------------------------------------------------------
# range
#-------------------------------------------------------------------------------
for i in range(5):	# 为了节省空间，range并不真正构造列表，只是可以返回一个序列
	print(i)		# 0, 1, 2, 3, 4
range(5, 10)	# 5, 6, 7, 8, 9
range(0, 10, 3)	# 0, 3, 6, 9
range(-10, -100, -30)	# -10, -40, -70
list(range(5))	# [0, 1, 2, 3, 4]
#-------------------------------------------------------------------------------
# 函数
#-------------------------------------------------------------------------------
max('Hello world')	# 'w' 求得列表中的最大值
min('Hello world')	# ' '
len('Hello world')	# 11

# 传值调用，这里的值是一个对象引用，而不是该对象的值
# 函数中没有return语句的，默认返回None
def fib(n):
	"""Print a Fibonacci series up to n"""
	a, b = 0, 1
	while a < n:
		print(a, end=' ')
		a, b = b, a+b
	print()
fib(2000)
f = fib
f(100)

# 函数制定默认参数值
def ask_ok(prompt, retries=4, complaint='Yes or no, please!'):
	pass

# 当默认值是可变对象时，如列表、字典等
def f2(a, L=[]):
	L.append(a)
	return L
print(f2(1))	# [1]
print(f2(2))	# [1, 2]
print(f2(3))	# [1, 2, 3]

# 关键字参数
def parrot(voltage, state='a stiff', action='voom'):
	pass
parrot(1000)
parrot(voltage=1000)	# 通过关键字参数的形式来调用
parrot(voltage=1000, action='ssss')

# *arguments 可变参数列表
# **keywords 字典参数
def cheeseshop(kind, *arguments, **keywords):
	print("kind:", kind)
	for arg in arguments:
		print(arg)
	print('-' * 40)
	keys = sorted(keywords.keys())
	for kw in keys:
		print(kw, ":", keywords[kw])
cheeseshop("Limburger",
		   "argument.0"
		   "argument.1",
		   shopkeeper="Michael",
		   client="John Cleese",
		   sketch="Cheese Shop")

# 参数列表拆分
args = [3, 6]
list(range(*args)) # *args = 3, 6
d = {"voltage": "four", "state": "bleedin", "action": "aa"}
parrot(**d)

#-------------------------------------------------------------------------------
# Lambda
#-------------------------------------------------------------------------------

# 通过lambda关键，可以创建短小的匿名函数
def make_incrementor(n):
	return lambda x: x + n
f = make_incrementor(42)	# n = 42
print(f(0))	# 42, x = 0
print(f(1))	# 43, x = 1 

#-------------------------------------------------------------------------------
# 文档字符串
#-------------------------------------------------------------------------------
def my_function():
	"""第一行，关于对象用途的见解.

	如果文档字符串有多行，第二行应该空出来，与接下来的详细描述明确分割，
	接下来的文档应该有一或多段描述对象的调用约定、边界效应等。
	"""
	pass

#-------------------------------------------------------------------------------
# 函数注解
#-------------------------------------------------------------------------------
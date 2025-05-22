# 8-Python数据类型						![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/4975/1653637301083/92de18505e7d4c559e45cc53ab453664.jpg)

Python3 中有六个标准的数据类型：Number（数字）、String（字符串）、List（列表）、Tuple（元组）、Sets（集合）、Dictionary（字典）。

Python3 的六个标准数据类型中：

* 不可变数据（3 个）：Number（数字）、String（字符串）、Tuple（元组）；
* 可变数据（3 个）：List（列表）、Dictionary（字典）、Set（集合）。

下面我们一一介绍这些数据类型的使用。

### Number（数字）

Python3 支持 int、float、bool、complex（复数）。

数字类型是顾名思义是用来存储数值的，需要记住的是，有点和 Java 的字符串味道差不多，如果改变了数字数据类型的值，将重新分配内存空间。

Python 支持三种不同的数值类型：

* 整型(Int) - 通常被称为是整型或整数，是正或负整数，不带小数点。Python3 整型是没有限制大小的，可以当作 Long 类型使用，所以 Python3 没有 Python2 的 Long 类型。
* 浮点型(float) - 浮点型由整数部分与小数部分组成，浮点型也可以使用科学计数法表示（2.5e2 = 2.5 x 102 = 250）
* 复数( (complex)) - 复数由实数部分和虚数部分构成，可以用a + bj,或者complex(a,b)表示， 复数的实部a和虚部b都是浮点型。

示例：

```
#!/usr/bin/python3
counter = 100          # 整型变量
miles   = 1000.0       # 浮点型变量
name    = "test"     # 字符串print (counter)
print (miles)
print (name)
```

数字类型转换

* int(x) 将x转换为一个整数。
* float(x) 将x转换到一个浮点数。
* complex(x) 将x转换到一个复数，实数部分为 x，虚数部分为 0。
* complex(x, y) 将 x 和 y 转换到一个复数，实数部分为 x，虚数部分为 y。x 和 y 是数字表达式。额外说明

和别的语言一样，数字类型支持各种常见的运算，不过 Python 的运算比别的大多数常见语言都更加丰富，此外，还有大量丰富的方法，提供更高效的开发。

数值运算示例：

```
print (5 + 4)  # 加法   输出 9
print (4.3 - 2) # 减法   输出 2.3
print (3 * 7)  # 乘法  输出 21
print (2 / 4)  # 除法，得到一个浮点数    输出 0.5
print (2 // 4) # 除法，得到一个整数 输出 0
print (17 % 3) # 取余   输出 2
print (2 ** 5) # 乘方  输出 32
```

### 运算符所在键盘的位置

"+" 加号的键盘位置  (shift要同时按下)

![](https://gimg2.baidu.com/image_search/src=http%3A%2F%2F5b0988e595225.cdn.sohucs.com%2Fimages%2F20171127%2F3a0225dbd26747c48aaf6db318fe9fec.png&refer=http%3A%2F%2F5b0988e595225.cdn.sohucs.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1657520375&t=e46bba85e963902b827cf7e628336791)

"-" 减号的键盘位置 (shift要同时按下)

![查看源图像](https://ask-fd.zol-img.com.cn/g5/M00/09/06/ChMkJ1ob_iiIBUi1AACqL215gzIAAigQgBvVzkAAKpH793.jpg)

"*"乘号在键盘中的位置 (shift + 数字 8  )

![](https://ss1.baidu.com/-4o3dSag_xI4khGko9WTAnF6hhy/zhidao/pic/item/562c11dfa9ec8a1397d052e2f103918fa1ecc0ee.jpg)

"/" 除号在键盘中的位置

![](https://gimg2.baidu.com/image_search/src=http%3A%2F%2Fpic.downyi.com%2Fupload%2Fcms%2Fchuhao1.jpg&refer=http%3A%2F%2Fpic.downyi.com&app=2002&size=f9999,10000&q=a80&n=0&g=0n&fmt=auto?sec=1657520723&t=aa636f48edb00c86becd7d5d02e08ff4)

### String（字符串）

创建字符串可以使用单引号、双引号、三单引号和三双引号，其中三引号可以多行定义字符串，Python 不支持单字符类型，单字符也在Python也是作为一个字符串使用。

我们定义一个 s='python'语句，它在计算机中的执行顺序是先在内存中创建一个字符串 Python ，在程序栈寄存器中创建一个变量 s，最后把 Python  的地址赋给s 。

再来看看字符串的一些常见操作：

```
s = '学习Python'
# 切片
s[0], s[-1], s[3:], s[::-1]	# '优', 'n', 'ython', 'nohtyP的习学'
# 替换，还可以使用正则表达式替换
s.replace('Python', 'Java')	# '学习Java'
# 查找，find()、index()、rfind()、rindex()
s.find('P')			# 3, 返回第一次出现的子串的下标
s.find('h', 2)			# 6, 设定下标2开始查找
s.find('23333')			# -1, 查找不到返回-1
s.index('y')			# 4, 返回第一次出现的子串的下标
s.index('P')		# 不同与find(), 查找不到会抛出异常
# 转大小写, upper()、lower()、swapcase()、capitalize()、istitle()、isupper()、islower()
s.upper()			# '学习PYTHON'
s.swapcase()			# '学习pYTHON', 大小写互换
s.istitle()			# True
s.islower()			# False
# 去空格,strip()、lstrip()、rstrip()
# 格式化
s1 = '%s %s' % ('Windrivder', 21)	# 'Windrivder 21'
s2 = '{}, {}'.format(21, 'Windridver')	# 推荐使用format格式化字符串
s3 = '{0}, {1}, {0}'.format('Windrivder', 21)
s4 = '{name}: {age}'.format(age=21, name='Windrivder')
# 连接与分割，使用 + 连接字符串，每次操作会重新计算、开辟、释放内存，效率很低，所以推荐使用join
l = ['2017', '03', '29', '22:00']
s5 = '-'.join(l)			# '2017-03-29-22:00'
s6 = s5.split('-')			# ['2017', '03', '29', '22:00']
```

以上是一些常见的操作。

另外还有一点需要注意的是字符串编码，所有的 Python 字符串都是 Unicode 字符串，当需要将文件保存到外设或进行网络传输时，就要进行编码转换，将字符转换为字节，以提高效率。

```
# encode 将字符转换为字节
str = '学习Python'
print (str.encode())			# 默认编码是 UTF-8  输出：b'\xe5\xad\xa6\xe4\xb9\xa0Python'
print (str.encode('gbk'))      # 输出  b'\xd1\xa7\xcf\xb0Python'
# decode 将字节转换为字符
print (str.encode().decode('utf8'))   # 输出 '学习Python'
print (str.encode('gbk').decode('gbk'))             # 输出 '学习Python'
```

### List（列表）

列表是写在方括号 [] 之间、用逗号分隔开的元素列表，列表可以完成大多数集合类的数据结构实现。列表中元素的类型可以不相同，它支持数字，字符串甚至可以包含列表（所谓嵌套），列表中的元素是可以改变。

示例：

```
Weekday = ['Monday','Tuesday','Wednesday','Thursday','Friday']
print(Weekday[0])   # 输出 Monday

#list 搜索
print(Weekday.index("Wednesday"))

#list 增加元素
Weekday.append("new")
print(Weekday)

# list 删除
Weekday.remove("Thursday")
print(Weekday)
```

### Tuple（元组）

元组（tuple）与列表类似，不同之处在于元组的元素不能修改。元组写在小括号 () 里，元素之间用逗号隔开，组中的元素类型也可以不相同。

示例：

```
letters = ('a','b','c','d','e','f','g')
print(letters[0])  # 输出 'a'
print(letters[0:3])  # 输出一组 ('a', 'b', 'c')
```

### Sets（集合）

集合（set）是一个无序不重复元素的序列，使用大括号 {} 或者 set() 函数创建集合，注意：创建一个空集合必须用 set() 而不是 {} ，因为 {} 是用来创建一个空字典。

集合不能被切片也不能被索引，除了做集合运算之外，集合元素可以被添加还有删除：

示例：

```
a_set = {1,2,3,4}添加a_set.add(5)
# 添加
a_set.add(5)
print(a_set)  # 输出{1, 2, 3, 4, 5}
# 删除
a_set.discard(5)
print(a_set)  # 输出{1, 2, 3, 4}
```

### Dictionary（字典）

字典是一种映射类型，它的元素是键值对，字典的关键字必须为不可变类型，且不能重复。创建空字典使用 {} 。

示例：

```
Logo_code = {
'BIDU':'Baidu',
 'SINA':'Sina',
 'YOKU':'Youku'
 }
print(Logo_code)
# 输出{'BIDU': 'Baidu', 'YOKU': 'Youku', 'SINA': 'Sina'}
print (Logo_code['SINA'])       # 输出键为 'one' 的值
print (Logo_code.keys())   # 输出所有键
print (Logo_code.values()) # 输出所有值
print (len(Logo_code))  # 输出字段长度
```

## 总结

本节给大家介绍了 Python  六种标准的数据类型，给大家演示了六种标准的数据类型的常用操作。


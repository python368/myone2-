# 6-Python的基础语法					![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/4975/1653546690013/b1c5a0ed1c314de6b2a2673c1c14295e.jpg)

Python 是一门脚本语言。

脚本语言的“优势”，其实只在于它不需要事先“编译”。所以 Python 语言不用像 Java 或者 C++ 语言需要首先进行编译，再进行运行，脚本语言可以直接读取文本文件，一边解释一边执行。

Python 是一门独特的脚本语言，快速浏览一下他的要点：

* 面向对象：每一个变量都是一个类，有其自己的属性（attribute）与方法（method）。
* 语法块：用缩进（四个空格）而不是分号、花括号等符号来标记。因此，行首的空格不能随意书写。
* 注释：行内用“#”号，行间注释写在两组连续三单引号之间：’’’
* 续行：行尾输入一个反斜杠加一个空格（’\ ‘），再换行。如果行尾语法明显未完成（比如以逗号结尾），可以直接续行。
* 打印与输入：函数 print() 与 input()，注意 print() 的 sep 与 end 参数。
* 变量：无需指定变量类型，也不需要提前声明变量。
* 删除变量：del()
* 复制变量：直接将变量a赋值给b，有时仅仅复制了一个“引用”。此后 b 与 a 的改动仍会互相影响。必要时使用 `&#x3c;span>a is b&#x3c;/span>` 来判断是否同址。
* 模块：通过 `&#x3c;span>import pandas&#x3c;/span>` 的方式加载模块（或者 `&#x3c;span>import pandas as pd&#x3c;/span>`），并用形如 `&#x3c;span>pandas.DataFrame&#x3c;/span>`（或 `&#x3c;span>pd.DataFrame&#x3c;/span>`）的方式调用模块内的方法。也可以使用 `&#x3c;span>from pandas import DataFrame&#x3c;/span>` 的方式，这样在下文可以直接使用 `&#x3c;span>DataFrame&#x3c;/span>` 作为调用名。
* 帮助：配合使用 dir() 与 help() 命令；其中前者是输出变量所有的成员。

Python 可以同一行显示多条语句，方法是用分号 ; 分开，如：

```
print("hello");print("world");
hello
world
```

## **5.1 Python 关键字**

下面的列表显示了在 Python 中的保留字。这些保留字不能用作常数或变数，或任何其他标识符名称。

所有Python的关键字只包含小写字母。

| and      | exec    | not             |
| -------- | ------- | --------------- |
| assert   | finally | or              |
| break    | for     | pass            |
| class    | from    | print           |
| continue | global  | raise           |
| def      | if      | return          |
| del      | import  | try             |
| elif     | in      | while           |
| else     | is      | with            |
| except   | lambda  | yield&#x3c;br/> |

## **5.2 缩进**

任何一种编程语言都有各自的语法和编程规范，Python 之所以以‘优雅，简单’著称，其中一个最重要的原因，就是它的“缩进”。大部分的编程语言都是使用“{}”来表示一个语句块或者代码段，而 Python 用缩进层次来组织代码块，而约定一个缩进是用‘4个空格’来表示，请务必遵守约定俗成的习惯，坚持使用4个空格的缩进。

如果是用文本编辑器或者 IDE，可以把 Tab 自动转换为4个空格，然后用 tab 键来使用缩进，确保不混用 Tab 和空格。

![image.png](https://fynotefile.oss-cn-zhangjiakou.aliyuncs.com/fynote/fyfile/4975/1653546690013/4bd1df82ebb047dca446a2776f064776.png)

缩进的空白数量是可变的，但是所有代码块语句必须包含相同的缩进空白数量，这个必须严格执行。如下所示：

```
if True:
	print("neo")
else:
	print("smile")
```

以下代码将会执行错误：

```
if True:
	print("neo")
else:
	print("smile")
      print("it")
```

因此，在 Python 的代码块中必须使用相同数目的行首缩进空格数。

## **5.3 多行语句**

Python 语句中一般以新行作为为语句的结束符。

但是我们可以使用斜杠（ \）将一行的语句分为多行显示，如下所示：

```
total = item_one + \
	item_two + \
	item_three
```

语句中包含[], {} 或 () 括号就不需要使用多行连接符。如下实例：

```
days = ['Monday', 'Tuesday', 'Wednesday',
'Thursday', 'Friday']
```

## **5.4 Python 引号**

Python 接收单引号(‘ )，双引号(“ )，三引号(‘’’ “””) 来表示字符串，引号的开始与结束必须的相同类型的。

其中三引号可以由多行组成，编写多行文本的快捷语法，常用语文档字符串，在文件的特定地点，被当做注释。

```
word = 'word'
sentence = "This is a sentence."
paragraph = """This is a paragraph. It is
made up of multiple lines and sentences."""
```

## **5.5 Python 注释**

以‘#’开头的语句是注释，不一定要出现在行首，在某些语句后面也可以加注释，注释是给人看的，可以是任意内容，解释器会忽略掉注释，但注意不要使用无意义的注释。

Python 中单行注释采用 # 开头，Python 没有块注释，所以现在推荐的多行注释也是采用的 # 比如：

注释可以在语句或表达式行末：

```
# 注释内容可以写在独自一行,或者行末
print("学习python使我快乐") # 这里是对于代码的注释内容
```

## **5.6 Python 空格和空行**

在 Python 中，为了让代码看起来更清晰，具有更好的可读性，有时会在代码中太内疚空格和空行。空格或者空行与代码缩进不同，并不是 Python 语法的一部分。

书写时不插入空格或者空行，Python 解释器运行也不会出错。但是空格或者空行的作用在于分隔两段不同功能或含义的代码，便于日后代码的维护或重构。

> 空格和空行是为了增加代码可读性。

比如在变量复制时添加空格。

```
hello = "world"
```

比如类成员函数之间空一行，模块级函数和类定义之间空两行；

```
class A:
	def __init__(self):
    		pass

	def hello(self):
   		 pass
def main():
	pass
```

## **5.7 Print 输出**

print() 默认输出是换行的，如果要实现不换行需要加上end参数。

```
x="a"
y="b"
print(x, end=' ')
print(y, end=' ')
```

## **总结**

这篇文章学习了 Python 的相关语法特点，了解到 Python 是一个简洁的脚本语言，使用缩进、空格、换行等规定语法一方面可以保障程序运行正常，也增加了程序本身的阅读性。

# JavaGuide
# **1.Java基础知识**
# 1. Java基本功  
[link](https://snailclimb.gitee.io/javaguide/#/docs/java/Java%E5%9F%BA%E7%A1%80%E7%9F%A5%E8%AF%86)
## 1.1 Java入门  
### 1.1.2 关于 JVM JDK 和 JRE 最详细通俗的解答   
不太懂:  
.class->机器码  
JIT  
AOT  
### 1.1.4. Java 和 C++的区别?  
## 1.2 Java语法  
### 1.2.4 Java中有哪些常见的关键字？
abstract, native, strictfp, synchronized, transient, volatile  
### **1.2.7. Java泛型了解么？什么是类型擦除？介绍一下常用的通配符？**
## 1.4. 方法（函数）
### 1.4.2. 为什么 Java 中只有值传递？  
总结一下 Java 中方法参数的使用情况：  
一个方法不能修改一个基本数据类型的参数（即数值型或布尔型）。  
一个方法可以改变一个对象参数的状态。  
一个方法不能让对象参数引用一个新的对象。  
### 1.4.3.2. 重写
方法的重写要遵循“两同两小一大”:  
“两同”即方法名相同、形参列表相同；  
“两小”指的是子类方法返回值类型应比父类方法返回值类型更小或相等，子类方法声明抛出的异常类应比父类方法声明抛出的异常类更小或相等；  
“一大”指的是子类方法的访问权限应比父类方法的访问权限更大或相等。

# 2. Java 面向对象
## 2.3. 修饰符
## 2.3.3. 常见关键字总结:static,final,this,super
[static,final,this,super](https://snailclimb.gitee.io/javaguide/#/do)  
private方法都隐式地指定为final  
static 静态代码块(只执行一次), static修饰类的话只能修饰内部类, 静态导包   
Java 内存区域的方法区:  
方法区与 Java 堆一样，是各个线程共享的内存区域，它用于存储已被虚拟机加载的类信息、常量、静态变量、即时编译器编译后的代码等数据。虽然Java虚拟机规范把方法区描述为堆的一个逻辑部分，但是它却有一个别名叫做 Non-Heap（非堆），目的应该是与 Java 堆区分开来。  
## 2.4. 接口和抽象类
### **2.4.1. 接口和抽象类的区别是什么？**
## 2.5. 其它重要知识点
### 2.5.1. String StringBuffer 和 StringBuilder 的区别是什么? String 为什么是不可变的?
在 Java 9 之后，String 类的实现改用 byte 数组存储字符串 private final byte[] value  
### 2.5.5. Java 序列化中如果有些字段不想进行序列化，怎么办？
对于不想进行序列化的变量，使用 transient 关键字修饰。  
### 2.5.6. 获取用键盘输入常用的两种方法
Scanner， BufferedReader  
# 3. Java 核心技术
## 3.1. 集合
[Collections 工具类和 Arrays 工具类常见方法总结](https://gitee.com/SnailClimb/JavaGuide/blob/master/docs/java/basic/Arrays,CollectionsCommonMethods.md)

## 3.2. 异常
## 3.2.1. Java 异常类层次结构图
![Java 异常类层次结构图](./Java异常类层次结构图.png)  
异常和错误的区别：异常能被程序本身处理，错误是无法处理。  
## 3.2.2. Throwable 类常用方法
getMessage(), toString(), getLocalizedMessage(), printStackTrace()  
## 3.2.3. try-catch-finally
try 块： 用于捕获异常。其后可接零个或多个 catch 块，如果没有 catch 块，则必须跟一个 finally 块。  
catch 块： 用于处理 try 捕获到的异常。  
finally 块： 无论是否捕获或处理异常，finally 块里的语句都会被执行。当在 try 块或 catch 块中遇到 return 语句时，finally 语句块将在方法返回之前被执行。  
在以下 4 种特殊情况下，finally 块不会被执行：  
在 finally 语句块第一行发生了异常。 因为在其他行，finally 块还是会得到执行  
在前面的代码中用了 System.exit(int)已退出程序。 exit 是带参函数 ；若该语句在异常语句之后，finally 会执行  
程序所在的线程死亡。  
关闭 CPU。  
## **3.2.4. 使用 try-with-resources 来代替try-catch-finally**
## 3.3. 多线程
### **3.3.2. 线程有哪些基本状态?**
## 3.4. 文件与 I\O 流
### **3.4.1. Java 中 IO 流分为几种?**
按照流的流向分，可以分为输入流和输出流;  
按照操作单元划分，可以划分为字节流和字符流；  
按照流的角色划分为节点流和处理流。  
### **3.4.1.1. 既然有了字节流,为什么还要有字符流?**
### **3.4.1.2. BIO,NIO,AIO 有什么区别?**

# **2.Java 基础知识疑难点/易错点**
# 1. 基础
## 1.1. 正确使用 equals 方法
推荐使用 java.util.Objects#equals(JDK7 引入的工具类)。 
##  **1.2. 整型包装类值的比较**
## **1.3. BigDecimal（浮点数之间的等值判断）**

# 2. 集合
## 2.1. Arrays.asList()使用指南
Arrays.asList()传递的数组必须是对象数组，而不是基本类型。 Arrays.asList()将数组转换为集合后,底层其实还是数组，不能add, remove。  
### **2.1.4. 如何正确的将数组转换为ArrayList?**
最简便的方法(推荐)： List list = new ArrayList<>(Arrays.asList("a", "b", "c"))；  
使用 Java8 的Stream(推荐)： 
```
Integer [] myArray = { 1, 2, 3 };
List myList = Arrays.stream(myArray).collect(Collectors.toList());
//基本类型也可以实现转换（依赖boxed的装箱操作）
int [] myArray2 = { 1, 2, 3 };
List myList = Arrays.stream(myArray2).boxed().collect(Collectors.toList());
```
使用 Guava(推荐):  
对于不可变集合，你可以使用ImmutableList类及其of()与copyOf()工厂方法：（参数不能为空）  
```
List<String> il = ImmutableList.of("string", "elements");  // from varargs
List<String> il = ImmutableList.copyOf(aStringArray);      // from array
```
对于可变集合，你可以使用Lists类及其newArrayList()工厂方法：  
```
List<String> l1 = Lists.newArrayList(anotherListOrCollection);    // from collection
List<String> l2 = Lists.newArrayList(aStringArray);               // from array
List<String> l3 = Lists.newArrayList("or", "string", "elements"); // from varargs
```
使用 Apache Commons Collections:
```
List<String> list = new ArrayList<String>();
CollectionUtils.addAll(list, str);
```

## **2.2. Collection.toArray()**
## **2.3.不要foreach里remove/add 元素**

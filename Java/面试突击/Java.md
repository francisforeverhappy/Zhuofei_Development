# 面试突击
1. 列表迭代器  
   迭代时，列表迭代器可以添加/删除元素
2. 抽象类  
   抽象类定义为“包含抽象方法的类”  
   抽象方法必须为public或者protected，默认为public  
   抽象类不能用来创建对象  
   子类必须实现父类的抽象方法。如果子类没有实现父类的抽象方法，则必须将子类也定义为为abstract类。  
3. String str="i"与 String str=new String("i")一样吗？  
   不一样，因为内存的分配方式不一样。String str="i"的方式，java 虚拟机会将其分配到常量池中；而 String str=new String("i") 则会被分到堆内存中。
4. final 在 java 中有什么作用？  
   final 修饰的类叫最终类，该类不能被继承。
   final 修饰的方法不能被重写。
   final 修饰的变量叫常量，常量必须初始化，初始化之后值就不能被修改。
5. 接口和抽象类有什么区别？  
   实现：抽象类的子类使用 extends 来继承；接口必须使用 implements 来实现接口。

   构造函数：抽象类可以有构造函数；接口不能有。

   main 方法：抽象类可以有 main 方法，并且我们能运行它；接口不能有 main 方法。

   实现数量：类可以实现很多个接口；但是只能继承一个抽象类。

   访问修饰符：接口中的方法默认使用 public 修饰；抽象类中的方法可以是任意访问修饰符。
6. BIO、NIO、AIO 有什么区别？  
   BIO：Block IO 同步阻塞式 IO，就是我们平常使用的传统 IO，它的特点是模式简单使用方便，并发处理能力低。

   NIO：New IO 同步非阻塞 IO，是传统 IO 的升级，客户端和服务器端通过 Channel（通道）通讯，实现了多路复用。

   AIO：Asynchronous IO 是 NIO 的升级，也叫 NIO2，实现了异步非堵塞 IO ，异步 IO 的操作基于事件和回调机制。
7. HashMap 和 Hashtable 有什么区别？

   hashMap去掉了HashTable 的contains方法，但是加上了containsValue（）和containsKey（）方法。

   hashTable同步的，而HashMap是非同步的，效率上逼hashTable要高。

   hashMap允许空键值，而hashTable不允许。
8. 如何决定使用 HashMap 还是 TreeMap？
   对于在Map中插入、删除和定位元素这类操作，HashMap是最好的选择。然而，假如你需要对一个有序的key集合进行遍历，TreeMap是更好的选择。基于你的collection的大小，也许向HashMap中添加元素会更快，将map换为TreeMap进行有序key的遍历。
9. ArrayList 和 Vector 的区别是什么？
    1.  Vector是同步的，而ArrayList不是。然而，如果你寻求在迭代的时候对列表进行改变，你应该使用CopyOnWriteArrayList。 

    2. ArrayList比Vector快，它因为有同步，不会过载。 

    3. ArrayList更加通用，因为我们可以使用Collections工具类轻易地获取同步列表和只读列表。
10. Array 和 ArrayList 有何区别？
    1.  Array可以容纳基本类型和对象，而ArrayList只能容纳对象。 

    2. Array是指定大小的，而ArrayList大小是固定的。 

    3. Array没有提供ArrayList那么多功能，比如addAll、removeAll和iterator等。
11. Iterator 和 ListIterator 有什么区别？
    1.  Iterator可用来遍历Set和List集合，但是ListIterator只能用来遍历List。 

    2. Iterator对集合只能是前向遍历，ListIterator既可以前向也可以后向。 

    3. ListIterator实现了Iterator接口，并包含其他的功能，比如：增加元素，替换元素，获取前一个和后一个元素的索引，等等。
12. 并行和并发有什么区别？  
   并发(Concurrency)的关键是你有处理多个任务的能力，不一定要同时。  
   并行(Parallelism)的关键是你有同时处理多个任务的能力。
13.  创建线程有哪几种方式？  
    继承Thread类创建线程类  
    通过Runnable接口创建线程类  
    通过Callable和Future创建线程  








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
    本质上都是Thread类
14. 线程池都有哪些状态？  
    线程池有5种状态：Running、ShutDown、Stop、Tidying、Terminated
15. 线程池中 submit()和 execute()方法有什么区别？
    接收的参数不一样；submit有返回值，而execute没有；submit方便Exception处理
16. 在 java 程序中怎么保证多线程的运行安全？  
    线程安全在三个方面体现：  
    原子性：提供互斥访问，同一时刻只能有一个线程对数据进行操作，（atomic,synchronized）；  
    可见性：一个线程对主内存的修改可以及时地被其他线程看到，（synchronized,volatile）；  
    有序性：一个线程观察其他线程中的指令执行顺序，由于指令重排序，该观察结果一般杂乱无序，  （happens-before原则）。  
17. 锁共有4种状态，级别从低到高依次为：无状态锁，偏向锁，轻量级锁和重量级锁  
18. 怎么防止死锁？  
    死锁的四个必要条件：  
    互斥条件：进程对所分配到的资源不允许其他进程进行访问，若其他进程访问该资源，只能等待，直至占有该资源的进程使用完成后释放该资源  
    请求和保持条件：进程获得一定的资源之后，又对其他资源发出请求，但是该资源可能被其他进程占有，此事请求阻塞，但又对自己获得的资源保持不放  
    不可剥夺条件：是指进程已获得的资源，在未完成使用之前，不可被剥夺，只能在使用完后自己释放  
    环路等待条件：是指进程发生死锁后，若干进程之间形成一种头尾相接的循环等待资源关系  
    这四个条件是死锁的必要条件，只要系统发生死锁，这些条件必然成立，而只要上述条件之 一不满足，就不会发生死锁。  
19. ThreadLocal 是什么？有哪些使用场景？  
    线程局部变量是局限于线程内部的变量，属于线程自身所有，不在多个线程间共享。Java提供ThreadLocal类来支持线程局部变量，是一种实现线程安全的方式。但是在管理环境下（如 web 服务器）使用线程局部变量的时候要特别小心，在这种情况下，工作线程的生命周期比任何应用变量的生命周期都要长。任何线程局部变量一旦在工作完成后没有释放，Java 应用就存在内存泄露的风险。
20. synchronized 和 volatile 的区别是什么？  
    olatile本质是在告诉jvm当前变量在寄存器（工作内存）中的值是不确定的，需要从主存中读取； synchronized则是锁定当前变量，只有当前线程可以访问该变量，其他线程被阻塞住。  
    volatile仅能使用在变量级别；synchronized则可以使用在变量、方法、和类级别的。  
    volatile仅能实现变量的修改可见性，不能保证原子性；而synchronized则可以保证变量的修改可见性和原子性。  
    volatile不会造成线程的阻塞；synchronized可能会造成线程的阻塞。  
    volatile标记的变量不会被编译器优化；synchronized标记的变量可以被编译器优化。
21. synchronized 和 Lock 有什么区别？  
    首先synchronized是java内置关键字，在jvm层面，Lock是个java类；  
    synchronized无法判断是否获取锁的状态，Lock可以判断是否获取到锁；  
    synchronized会自动释放锁(a 线程执行完同步代码会释放锁 ；b 线程执行过程中发生异常会释放锁)，Lock需在finally中手工释放锁（unlock()方法释放锁），否则容易造成线程死锁；  
    用synchronized关键字的两个线程1和线程2，如果当前线程1获得锁，线程2线程等待。如果线程1阻塞，线程2则会一直等待下去，而Lock锁就不一定会等待下去，如果尝试获取不到锁，线程可以不用一直等待就结束了；  
    synchronized的锁可重入、不可中断、非公平，而Lock锁可重入、可判断、可公平（两者皆可）；  
    Lock锁适合大量同步的代码的同步问题，synchronized锁适合代码少量的同步问题。
22. atomic 的原理？  
    Atomic包中的类基本的特性就是在多线程环境下，当有多个线程同时对单个（包括基本类型及引用类型）变量进行操作时，具有排他性，即当多个线程同时对该变量的值进行更新时，仅有一个线程能成功，而未成功的线程可以向自旋锁一样，继续尝试，一直等到执行成功。  
23. 什么是反射？  
    在运行时判断任意一个对象所属的类。  
    在运行时构造任意一个类的对象。  
    在运行时判断任意一个类所具有的成员变量和方法。  
    在运行时调用任意一个对象的方法。 
23. 动态代理是什么？  
    允许在运行期动态创建一个接口的实例；动态代理是通过Proxy创建代理对象，然后将接口方法“代理”给InvocationHandler完成的。  
24. 实现对象克隆？  
    1). 实现Cloneable接口并重写Object类中的clone()方法；  
    2). 实现Serializable接口，通过对象的序列化和反序列化实现克隆，可以实现真正的深度克隆  
25. 避免 sql 注入？  
    PreparedStatement（简单又有效的方法）  
    使用正则表达式过滤传入的参数  
26. session 和 cookie 有什么区别？  
    Servlet容器提供了Session机制以跟踪用户；默认的Session机制是以Cookie形式实现的，Cookie名称为JSESSIONID；通过读写Cookie可以在客户端设置用户偏好  
27. jsp 的 4 种作用域？  
    page代表与一个页面相关的对象和属性。  
    request代表与Web客户机发出的一个请求相关的对象和属性。一个请求可能跨越多个页面，涉及多个Web组件；需要在页面显示的临时数据可以置于此作用域。  
    session代表与某个用户与服务器建立的一次会话相关的对象和属性。跟某个用户相关的数据应该放在用户自己的session中。  
    application代表与整个Web应用程序相关的对象和属性，它实质上是跨越整个Web应用程序，包括多个页面、请求和会话的一个全局作用域。
28. jsp 和 servlet 有什么区别？  
    jsp经编译后就变成了Servlet.（JSP的本质就是Servlet，JVM只能识别java的类，不能识别JSP的代码，Web容器将JSP的代码编译成JVM能够识别的java类）  
    jsp更擅长表现于页面显示，servlet更擅长于逻辑控制。  
    Servlet中没有内置对象，Jsp中的内置对象都是必须通过HttpServletRequest对象，HttpServletResponse对象以及HttpServlet对象得到。  
    Jsp是Servlet的一种简化，使用Jsp只需要完成程序员需要输出到客户端的内容，Jsp中的Java脚本如何镶嵌到一个类中，由Jsp容器完成。而Servlet则是个完整的Java类，这个类的Service方法用于生成对客户端的响应。
29. throw 和 throws 的区别？  
    throws是用来声明一个方法可能抛出的所有异常信息，throws是将异常声明但是不处理，而是将异常往上传，谁调用我就交给谁处理。而throw则是指抛出的一个具体的异常类型。  
30. HTTP 状态码  
    https://www.cnblogs.com/starof/p/5035119.html  
31. tcp 和 udp的区别？    
    TCP面向连接（如打电话要先拨号建立连接）;UDP是无连接的，即发送数据之前不需要建立连接。  
    TCP提供可靠的服务。也就是说，通过TCP连接传送的数据，无差错，不丢失，不重复，且按序到达;UDP尽最大努力交付，即不保证可靠交付。  
    Tcp通过校验和，重传控制，序号标识，滑动窗口、确认应答实现可靠传输。如丢包时的重发控制，还可以对次序乱掉的分包进行顺序控制。  
    UDP具有较好的实时性，工作效率比TCP高，适用于对高速传输和实时性有较高的通信或广播通信。  
    每一条TCP连接只能是点到点的;UDP支持一对一，一对多，多对一和多对多的交互通信。  
    TCP对系统资源要求较多，UDP对系统资源要求较少。
32. Override and Overload?  
33. Database transaction concept:  
    ACID Feature:  
    Atomictity  
    Consistency  
    Isolation  
    Durability
34. MySQL Lock Granularity:  
    row level locking and table level locking  
35. Intention Lock:  
    
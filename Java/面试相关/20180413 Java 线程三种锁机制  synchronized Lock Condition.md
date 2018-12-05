# 20180413 Java 线程三种锁机制  synchronized Lock Condition

```java
1-当对象获取锁时，它首先使自己的高速缓存无效，这样就可以保证直接从主内存中装入变量。 同样，在对象释放锁之前，它会刷新其高速缓存，强制使已做的任何更改都出现在主内存中。 这样，会保证在同一个锁上同步的两个线程看到在 synchronized 块内修改的变量的相同值。

synchronized 的限制：   
1. 它无法中断一个正在等候获得锁的线程；
2. 也无法通过投票得到锁，如果不想等下去，也就没法得到锁；
3. 同步还要求锁的释放只能在与获得锁所在的堆栈帧相同的堆栈帧中进行，多数情况下，这没问题（而且与异常处理交互得很好），但是，确实存在一些非块结构的锁定更合适的情况。

2- ReentantLock
拥有与synchronized 相同的并发性和内存语义，但是添加了类似锁投票、定时锁等候和可中断锁等候的一些特性. 但是， 用Lock需要我们手动释放锁，所以为了保证锁最终被释放(发生异常情况)，要把互斥区放在try内，释放锁放在finally内！

3. conmdition 是基于Lock 的 缓存队列。 能解决缓冲区为空，就释放写锁，要进行写（set）。 如果缓冲区为满，就是放读锁，要进行读（put）

优点：

假设缓存队列中已经存满，那么阻塞的肯定是写线程，唤醒的肯定是读线程，相反，阻塞的肯定是读线程，唤醒的肯定是写线程。

那么假设只有一个Condition会有什么效果呢？缓存队列中已经存满，这个Lock不知道唤醒的是读线程还是写线程了，如果唤醒的是读线程，皆大欢喜，如果唤醒的是写线程，那么线程刚被唤醒，又被阻塞了，这时又去唤醒，这样就浪费了很多时间。

```



--------------------------

原文： https://blog.csdn.net/vking_wang/article/details/9952063

- http://www.infoq.com/cn/articles/java-memory-model-5  深入理解Java内存模型（五）——锁 
- http://www.ibm.com/developerworks/cn/java/j-jtp10264/  Java 理论与实践: JDK 5.0 中更灵活、更具可伸缩性的锁定机制
- http://blog.csdn.net/ghsau/article/details/7481142

## 1、synchronized

把代码块声明为 synchronized，有两个重要后果，通常是指该代码具有 **原子性（atomicity）**和 **可见性（visibility）**。****

### **1.1 原子性**

原子性意味着个时刻，只有一个线程能够执行一段代码，这段代码通过一个monitor object保护。从而防止多个线程在更新共享状态时相互冲突。

### 1.2 可见性

可见性则更为微妙，它要对付内存缓存和编译器优化的各种反常行为。它必须确保释放锁之前对共享数据做出的更改对于随后获得该锁的另一个线程是可见的 。

**作用：**如果没有同步机制提供的这种可见性保证，线程看到的共享变量可能是修改前的值或不一致的值，这将引发许多严重问题。

**原理：** 当对象获取锁时，它首先使自己的高速缓存无效，这样就可以保证直接从主内存中装入变量。 同样，在对象释放锁之前，它会刷新其高速缓存，强制使已做的任何更改都出现在主内存中。 这样，会保证在同一个锁上同步的两个线程看到在 synchronized 块内修改的变量的相同值。

一般来说，线程以某种不必让其他线程立即可以看到的方式（不管这些线程在寄存器中、在处理器特定的缓存中，还是通过指令重排或者其他编译器优化），不受缓存变量值的约束，但是如果开发人员使用了同步，那么运行库将确保某一线程对变量所做的更新先于对现有`synchronized` 块所进行的更新，当进入由同一监控器（lock）保护的另一个`synchronized` 块时，将立刻可以看到这些对变量所做的更新。类似的规则也存在于`volatile`变量上。

——volatile**只保证可见性，不保证原子性！**

### 1.3 何时要同步？

**可见性同步**的基本规则是在以下情况中必须同步： 

1. 读取上一次可能是由另一个线程写入的变量 
2. 写入下一次可能由另一个线程读取的变量

**一致性同步**：当修改多个相关值时，您想要其它线程原子地看到这组更改—— 要么看到全部更改，要么什么也看不到。

这适用于相关数据项（如粒子的位置和速率）和元数据项（如链表中包含的数据值和列表自身中的数据项的链）。

在某些情况中，您**不必用同步**来将数据从一个线程传递到另一个，因为 JVM 已经隐含地为您执行同步。这些情况包括：

1. 由静态初始化器（在静态字段上或 static{} 块中的初始化器）
2. 初始化数据时 
3. 访问 final 字段时 ——final对象呢？
4. 在创建线程之前创建对象时 
5. 线程可以看见它将要处理的对象时

### 1.4 synchronize的限制

synchronized是不错，但它并不完美。它有一些功能性的限制：

1. **它无法中断一个正在等候获得锁的线程；**
2. **也无法通过投票得到锁，如果不想等下去，也就没法得到锁；**
3. **同步还要求锁的释放只能在与获得锁所在的堆栈帧相同的堆栈帧中进行，多数情况下，这没问题（而且与异常处理交互得很好），但是，确实存在一些非块结构的锁定更合适的情况。**

## 2、ReentrantLock

`java.util.concurrent.lock` 中的`Lock` 框架是锁定的一个抽象，它允许把锁定的实现作为 Java 类，而不是作为语言的特性来实现。这就为`Lock` 的多种实现留下了空间，各种实现可能有不同的调度算法、性能特性或者锁定语义。

`ReentrantLock` 类实现了`Lock` ，它拥有与`synchronized` 相同的并发性和内存语义，但是添加了类似**锁投票**、**定时锁等候**和**可中断锁等候**的一些特性。此外，它还提供了在激烈争用情况下**更佳的性能**。（换句话说，当许多线程都想访问共享资源时，JVM 可以花更少的时候来调度线程，把更多时间用在执行线程上。）

```java
class Outputter1 {    
    private Lock lock = new ReentrantLock();// 锁对象    
  
    public void output(String name) {           
        lock.lock();      // 得到锁    
  
        try {    
            for(int i = 0; i < name.length(); i++) {    
                System.out.print(name.charAt(i));    
            }    
        } finally {    
            lock.unlock();// 释放锁    
        }    
    }    
}    
```

区别：

需要注意的是，用sychronized修饰的方法或者语句块在代码执行完之后锁自动释放，而是用Lock需要我们**手动释放锁**，所以为了保证锁最终被释放(发生异常情况)，要把互斥区放在try内，释放锁放在finally内！！

## 3、读写锁ReadWriteLock

上例中展示的是和synchronized相同的功能，那Lock的优势在哪里？

例如一个类对其内部共享数据data提供了get()和set()方法，如果用synchronized，则代码如下：

```java
class syncData {        
    private int data;// 共享数据        
    public synchronized void set(int data) {    
        System.out.println(Thread.currentThread().getName() + "准备写入数据");    
        try {    
            Thread.sleep(20);    
        } catch (InterruptedException e) {    
            e.printStackTrace();    
        }    
        this.data = data;    
        System.out.println(Thread.currentThread().getName() + "写入" + this.data);    
    }       
    public synchronized  void get() {    
        System.out.println(Thread.currentThread().getName() + "准备读取数据");    
        try {    
            Thread.sleep(20);    
        } catch (InterruptedException e) {    
            e.printStackTrace();    
        }    
        System.out.println(Thread.currentThread().getName() + "读取" + this.data);    
    }    
}    
```

然后写个测试类来用多个线程分别读写这个共享数据：

```java
public static void main(String[] args) {    
//        final Data data = new Data();    
          final syncData data = new syncData();    
//        final RwLockData data = new RwLockData();    
          
        //写入  
        for (int i = 0; i < 3; i++) {    
            Thread t = new Thread(new Runnable() {    
                @Override  
        public void run() {    
                    for (int j = 0; j < 5; j++) {    
                        data.set(new Random().nextInt(30));    
                    }    
                }    
            });  
            t.setName("Thread-W" + i);  
            t.start();  
        }    
        //读取  
        for (int i = 0; i < 3; i++) {    
            Thread t = new Thread(new Runnable() {    
                @Override  
        public void run() {    
                    for (int j = 0; j < 5; j++) {    
                        data.get();    
                    }    
                }    
            });    
            t.setName("Thread-R" + i);  
            t.start();  
        }    
    }    

```



运行结果：

```java
Thread-W0准备写入数据  
Thread-W0写入0  
Thread-W0准备写入数据  
Thread-W0写入1  
Thread-R1准备读取数据  
Thread-R1读取1  
Thread-R1准备读取数据  
Thread-R1读取1  
Thread-R1准备读取数据  
Thread-R1读取1  
Thread-R1准备读取数据  
Thread-R1读取1  
Thread-R1准备读取数据  
Thread-R1读取1  
Thread-R2准备读取数据  
Thread-R2读取1  
Thread-R2准备读取数据  
Thread-R2读取1  
Thread-R2准备读取数据  
Thread-R2读取1  
Thread-R2准备读取数据  
Thread-R2读取1  
Thread-R2准备读取数据  
Thread-R2读取1  
Thread-R0准备读取数据 //R0和R2可以同时读取，不应该互斥！  
Thread-R0读取1  
Thread-R0准备读取数据  
Thread-R0读取1  
Thread-R0准备读取数据  
Thread-R0读取1  
Thread-R0准备读取数据  
Thread-R0读取1  
Thread-R0准备读取数据  
Thread-R0读取1  
Thread-W1准备写入数据  
Thread-W1写入18  
Thread-W1准备写入数据  
Thread-W1写入16  
Thread-W1准备写入数据  
Thread-W1写入19  
Thread-W1准备写入数据  
Thread-W1写入21  
Thread-W1准备写入数据  
Thread-W1写入4  
Thread-W2准备写入数据  
Thread-W2写入10  
Thread-W2准备写入数据  
Thread-W2写入4  
Thread-W2准备写入数据  
Thread-W2写入1  
Thread-W2准备写入数据  
Thread-W2写入14  
Thread-W2准备写入数据  
Thread-W2写入2  
Thread-W0准备写入数据  
Thread-W0写入4  
Thread-W0准备写入数据  
Thread-W0写入20  
Thread-W0准备写入数据  
Thread-W0写入29  
```

现在一切都看起来很好！各个线程互不干扰！等等。。读取线程和写入线程互不干扰是正常的，但是两个读取线程是否需要互不干扰？？

**对！读取线程不应该互斥！**

我们可以用读写锁ReadWriteLock实现：

```java
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

class Data {        
    private int data;// 共享数据    
    private ReadWriteLock rwl = new ReentrantReadWriteLock();       
    public void set(int data) {    
        rwl.writeLock().lock();// 取到写锁    
        try {    
            System.out.println(Thread.currentThread().getName() + "准备写入数据");    
            try {    
                Thread.sleep(20);    
            } catch (InterruptedException e) {    
                e.printStackTrace();    
            }    
            this.data = data;    
            System.out.println(Thread.currentThread().getName() + "写入" + this.data);    
        } finally {    
            rwl.writeLock().unlock();// 释放写锁    
        }    
    }       
  
    public void get() {    
        rwl.readLock().lock();// 取到读锁    
        try {    
            System.out.println(Thread.currentThread().getName() + "准备读取数据");    
            try {    
                Thread.sleep(20);    
            } catch (InterruptedException e) {    
                e.printStackTrace();    
            }    
            System.out.println(Thread.currentThread().getName() + "读取" + this.data);    
        } finally {    
            rwl.readLock().unlock();// 释放读锁    
        }    
    }    
}    
```



测试结果：

```java
Thread-W1准备写入数据  
Thread-W1写入9  
Thread-W1准备写入数据  
Thread-W1写入24  
Thread-W1准备写入数据  
Thread-W1写入12  
Thread-W0准备写入数据  
Thread-W0写入22  
Thread-W0准备写入数据  
Thread-W0写入15  
Thread-W0准备写入数据  
Thread-W0写入6  
Thread-W0准备写入数据  
Thread-W0写入13  
Thread-W0准备写入数据  
Thread-W0写入0  
Thread-W2准备写入数据  
Thread-W2写入23  
Thread-W2准备写入数据  
Thread-W2写入24  
Thread-W2准备写入数据  
Thread-W2写入24  
Thread-W2准备写入数据  
Thread-W2写入17  
Thread-W2准备写入数据  
Thread-W2写入11  
Thread-R2准备读取数据  
Thread-R1准备读取数据  
Thread-R0准备读取数据  
Thread-R0读取11  
Thread-R1读取11  
Thread-R2读取11  
Thread-W1准备写入数据  
Thread-W1写入18  
Thread-W1准备写入数据  
Thread-W1写入1  
Thread-R0准备读取数据  
Thread-R2准备读取数据  
Thread-R1准备读取数据  
Thread-R2读取1  
Thread-R2准备读取数据  
Thread-R1读取1  
Thread-R0读取1  
Thread-R1准备读取数据  
Thread-R0准备读取数据  
Thread-R0读取1  
Thread-R2读取1  
Thread-R2准备读取数据  
Thread-R1读取1  
Thread-R0准备读取数据  
Thread-R1准备读取数据  
Thread-R0读取1  
Thread-R2读取1  
Thread-R1读取1  
Thread-R0准备读取数据  
Thread-R1准备读取数据  
Thread-R2准备读取数据  
Thread-R1读取1  
Thread-R2读取1  
Thread-R0读取1  
```

与互斥锁定相比，读-写锁定允许对共享数据进行更高级别的并发访问。虽然一次只有一个线程（*writer* 线程）可以修改共享数据，但在许多情况下，任何数量的线程可以同时读取共享数据（*reader* 线程）

从理论上讲，与互斥锁定相比，使用读-写锁定所允许的并发性增强将带来更大的性能提高。

在实践中，只有在多处理器上并且只在访问模式适用于共享数据时，才能完全实现并发性增强。——例如，某个最初用数据填充并且之后不经常对其进行修改的 collection，因为经常对其进行搜索（比如搜索某种目录），所以这样的 collection 是使用读-写锁定的理想候选者。

## 4、线程间通信Condition

Condition可以替代传统的线程间通信，**用await()替换wait()，用signal()替换notify()，用signalAll()替换notifyAll()。**

**——为什么方法名不直接叫wait()/notify()/nofityAll()？因为Object的这几个方法是final的，不可重写！**

**传统线程的通信方式，Condition都可以实现。**

注意，**Condition是被绑定到Lock上的**，要创建一个Lock的Condition**必须**用newCondition()方法。

Condition的强大之处在于它可以为多个线程间建立不同的Condition

看JDK文档中的一个例子：假定有一个绑定的缓冲区，它支持 `put` 和 `take` 方法。如果试图在空的缓冲区上执行 `take` 操作，则在某一个项变得可用之前，线程将一直阻塞；如果试图在满的缓冲区上执行 `put` 操作，则在有空间变得可用之前，线程将一直阻塞。我们喜欢在单独的等待 set 中保存`put` 线程和`take` 线程，这样就可以在缓冲区中的项或空间变得可用时利用最佳规划，一次只通知一个线程。可以使用两个[`Condition`](https://blog.csdn.net/java/util/concurrent/locks/Condition.html) 实例来做到这一点。

**——其实就是java.util.concurrent.ArrayBlockingQueue的功能**

```java
class BoundedBuffer {  
  final Lock lock = new ReentrantLock();          //锁对象  
  final Condition notFull  = lock.newCondition(); //写线程锁  
  final Condition notEmpty = lock.newCondition(); //读线程锁  
  
  final Object[] items = new Object[100];//缓存队列  
  int putptr;  //写索引  
  int takeptr; //读索引  
  int count;   //队列中数据数目  
  
  //写  
  public void put(Object x) throws InterruptedException {  
    lock.lock(); //锁定  
    try {  
      // 如果队列满，则阻塞<写线程>  
      while (count == items.length) {  
        notFull.await();   
      }  
      // 写入队列，并更新写索引  
      items[putptr] = x;   
      if (++putptr == items.length) putptr = 0;   
      ++count;  
  
      // 唤醒<读线程>  
      notEmpty.signal();   
    } finally {   
      lock.unlock();//解除锁定   
    }   
  }  
  
  //读   
  public Object take() throws InterruptedException {   
    lock.lock(); //锁定   
    try {  
      // 如果队列空，则阻塞<读线程>  
      while (count == 0) {  
         notEmpty.await();  
      }  
  
      //读取队列，并更新读索引  
      Object x = items[takeptr];   
      if (++takeptr == items.length) takeptr = 0;  
      --count;  
  
      // 唤醒<写线程>  
      notFull.signal();   
      return x;   
    } finally {   
      lock.unlock();//解除锁定   
    }   
  }   

```

优点：
假设缓存队列中已经存满，那么阻塞的肯定是写线程，唤醒的肯定是读线程，相反，阻塞的肯定是读线程，唤醒的肯定是写线程。
那么假设只有一个Condition会有什么效果呢？缓存队列中已经存满，这个Lock不知道唤醒的是读线程还是写线程了，如果唤醒的是读线程，皆大欢喜，如果唤醒的是写线程，那么线程刚被唤醒，又被阻塞了，这时又去唤醒，这样就浪费了很多时间。


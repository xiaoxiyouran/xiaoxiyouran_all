# 36 Java 抽象类

在java中用`abstract`关键字声明的类称为抽象类。 它可以有抽象和非抽象方法(带主体的方法)。

在学习java抽象类之前，先来了解java中的抽象。

## Java中的抽象

抽象是隐藏实现细节并仅向用户显示功能的过程。

另一种方式，它只向用户显示重要的事情，并隐藏内部详细信息，例如：发送短信，只需输入文本并发送消息。您也不需要知道有关邮件传递的内部处理过程。

抽象可以让你专注于对象做什么(实现的功能)，而不是它如何做。

### 实现抽象的方法

**在java中有两种实现抽象的方法，它们分别是：**

1. **抽象类(部分)**
2. **接口 (完全)**

## 1. Java中的抽象类

使用 `abstract`关键字声明的类被称为抽象类。需要扩展和实现它的方法。 它不能被实例化。

**抽象类示例**

```  Java
abstract class A{}
```

**抽象方法**

一个被声明为 `abstract` 而没有实现的方法称为抽象方法。

**抽象方法示例**

```  Java
abstract void printStatus();//no body and abstract
```

**具有抽象方法的抽象类的示例**

在这个例子中，`Bike`是一个抽象类，只包含一个抽象方法：`run()`。 它由 `Honda` 类提供实现。

```  Java
abstract class Bike {
    abstract void run();
}

class Honda4 extends Bike {
    void run() {// run 方法的实现
        System.out.println("running safely..");
    }

    public static void main(String args[]) {
        Bike obj = new Honda4();
        obj.run();
    }
}
```

上面示例中的代码执行结果如下 -

```  Java
running safely..
```

## 理解抽象类的真实应用场景

在这个例子中，`Shape`是一个抽象类，它的实现分别由`Rectangle`和`Circle`类提供。 大多数情况下，我们不知道实现类(即对最终用户隐藏)，实现类的对象由工厂方法提供。
**工厂方法**是用于返回类的实例的方法。 稍后我们将在下一节中了解和学习**工厂方法**。
在这个例子中，创建`Rectangle`类的实例，`Rectangle`类的`draw()`方法将被调用。创建一个类文件：`TestAbstraction1.java` ，它的代码如下所示 -

```  Java
abstract class Shape {
    abstract void draw();
}

// In real scenario, implementation is provided by others i.e. unknown by end
// user
class Rectangle extends Shape {
    void draw() {
        System.out.println("drawing rectangle");
    }
}

class Circle1 extends Shape {
    void draw() {
        System.out.println("drawing circle");
    }
}

// In real scenario, method is called by programmer or user
class TestAbstraction1 {
    public static void main(String args[]) {
        Shape s = new Circle1();// In real scenario, object is provided through
                                // method e.g. getShape() method
        s.draw();
    }
}

```

上面代码执行结果如下 -

```  Shell
drawing circle
```

**在java中抽象类的另一个例子**

创建一个Java文件：`TestBank.java`，代码如下所示 -

```  Java
abstract class Bank {
    abstract int getRateOfInterest();
}

class SBI extends Bank {
    int getRateOfInterest() {
        return 7;
    }
}

class PNB extends Bank {
    int getRateOfInterest() {
        return 8;
    }
}

class TestBank {
    public static void main(String args[]) {
        Bank b;
        b = new SBI();
        System.out.println("Rate of Interest is: " + b.getRateOfInterest() + " %");
        b = new PNB();
        System.out.println("Rate of Interest is: " + b.getRateOfInterest() + " %");
    }
}
```

上面代码执行结果如下 -

```  Java
Rate of Interest is: 7 %
Rate of Interest is: 8 %
```

**具有构造函数，数据成员，方法等的抽象类**

抽象类可以有数据成员，抽象方法，方法体，构造函数甚至`main()`方法。创建一个Java文件：`TestAbstraction2.java`，代码如下所示 -

```  Java
//example of abstract class that have method body  
abstract class Bike {
    Bike() {
        System.out.println("bike is created");
    }

    abstract void run();

    void changeGear() {
        System.out.println("gear changed");
    }
}

class Honda extends Bike {
    void run() {
        System.out.println("running safely..");
    }
}

class TestAbstraction2 {
    public static void main(String args[]) {
        Bike obj = new Honda();
        obj.run();
        obj.changeGear();
    }
}
```

上面代码执行结果如下 -

``` Java
bike is created
running safely..
gear changed
```

> 规则：如果**在类中有任何抽象方法，那个类必须声明为抽象的**。

```  Java
class Bike12{  
    abstract void run();  
}
```

上面的 `Bike12` 是无法编译通过的。

> 规则：**如果你继承任何具有抽象方法的抽象类，必须提供方法的实现或使这个类抽象化。**

## 抽象类的另一个真实场景

**抽象类也可以用于提供接口的一些实现**。 在这种情况下，终端用户可能不会被强制覆盖接口的所有方法。

> 注意：如果您是初学者到Java，请跳过此示例先学习[接口(interface)](http://www.yiibai.com/java/interface-in-java.html)。

```  Java
interface A {
    void a();

    void b();

    void c();

    void d();
}

abstract class B implements A {
    public void c() {
        System.out.println("I am C");
    }
}

class M extends B {  /// 可以被new 的一定是实现了接口中 所有 方法
    public void a() {
        System.out.println("I am a");
    }

    public void b() {
        System.out.println("I am b");
    }

    public void d() {
        System.out.println("I am d");
    }
}

class Test5 {
    public static void main(String args[]) {
        A a = new M();
        a.a();
        a.b();
        a.c();
        a.d();
    }
}
```

上面代码执行结果如下 -

```  Java
I am a
I am b
I am c
I am d
```






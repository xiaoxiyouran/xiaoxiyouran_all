#35 java instanceof 运算符



java `instanceof`运算符用于测试**指定对象是否是指定类型(类或子类或接口)的实例**。

java中的`instanceof`也称为类型比较运算符，因为它将类型与实例进行比较。 它返回`true`或`false`。 如果**对任何具有`null`值的变量应用`instanceof`运算符，则返回false**。

**java instanceof的简单示例**

下面来看看实例运算符的简单示例，它测试当前类。

```  Java
class Simple1 {
    public static void main(String args[]) {
        Simple1 s = new Simple1();
        System.out.println(s instanceof Simple1);// true
    }
}
```

执行上面试代码，得到以下结果 -

```Shell
true
```

子类类型的对象也是父类的类型。 例如，如果`Dog`扩展了`Animal`，那么`Dog`的对象可以通过`Dog`或`Animal`类来引用。

**java instanceof运算符的另一个例子**

```  Java
class Animal {
}

class Dog1 extends Animal {// Dog inherits Animal

    public static void main(String args[]) {
        Dog1 d = new Dog1();
        System.out.println(d instanceof Animal);// true
    }
}
```

执行上面代码，得到以下结果 -

```  Java
true
```

**instanceof测试null值的变量示例**

如果我们对具有`null`值的变量应用`instanceof`运算符，则返回`false`。来看看下面给出的例子，将`instanceof`运算符应用于具有`null`值的变量。

```  Java
class Dog2 {
    public static void main(String args[]) {
        Dog2 d = null;
        System.out.println(d instanceof Dog2);// false
    }
}
```

执行上面代码，得到以下结果 -

```  Java
false
```

**使用java instanceof运算符的向下转换**

当子类型引用父类的对象时，它被称为向下转换(downcasting)。 如果直接执行它，编译器会出现编译错误。 如果通过类型转换来执行，在运行时会抛出：`ClassCastException` 。 但是如果使用`instanceof`运算符，可以进行向下转换。

```  Java
Dog d=new Animal();//Compilation error
```

如果通过类型转换执行向下转换，则在运行时抛出：`ClassCastException`。

```  Java
Dog d=(Dog)new Animal();  
//Compiles successfully but ClassCastException is thrown at runtime
```

**使用instanceof进行向下转换**

现在看看下面这个例子，通过`instanceof`运算符进行向下转换。

```  Java
class Animal {
}

class Dog3 extends Animal {
    static void method(Animal a) {
        if (a instanceof Dog3) {
            Dog3 d = (Dog3) a;// downcasting
            System.out.println("ok downcasting performed");
        }
    }

    public static void main(String[] args) {
        Animal a = new Dog3();
        Dog3.method(a);
    }
}
```

执行上面代码，得到以下结果 -

```  Java
ok downcasting performed
```

**向下转换不使用instanceof**

也可以在不使用`instanceof`运算符的情况下执行下转换，如以下示例代码所示：

```  Java
class Animal {
}

class Dog4 extends Animal {
    static void method(Animal a) {
        Dog4 d = (Dog4) a;// downcasting
        System.out.println("ok downcasting performed");
    }

    public static void main(String[] args) {
        Animal a = new Dog4();
        Dog4.method(a);
    }
}
```

执行上面代码，得到以下结果 -

```  Java
ok downcasting performed
```

仔细看看，被引用的实际对象是`Dog`类的对象。 所以如果向下转换它，它是没有问题的。 但是，如果也可以这样写：

```  Java
Animal a=new Animal();  
Dog.method(a);  
//Now ClassCastException but not in case of instanceof operator
```

## 理解在java中使用instanceof的实例

这是一个instanceof的终极示例，通过下面的例子中的代码看看`instanceof`关键字的真正用法。

```  Java
interface Printable {
}

class A implements Printable {
    public void a() {
        System.out.println("a method");
    }
}

class B implements Printable {
    public void b() {
        System.out.println("b method");
    }
}

class Call {
    void invoke(Printable p) {// upcasting
        if (p instanceof A) {
            A a = (A) p;	  // Downcasting
            a.a();
        }
        if (p instanceof B) {
            B b = (B) p;	  // Downcasting
            b.b();
        }

    }
}// end of Call class

class Test4 {
    public static void main(String args[]) {
        Printable p = new B();
        Call c = new Call();
        c.invoke(p);
    }
}

```

执行上面代码，得到以下结果 -

```shell
b method
```


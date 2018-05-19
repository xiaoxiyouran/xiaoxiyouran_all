# 40 Java 访问修饰符



java中有两种类型的修饰符：**访问修饰符和非修饰符。**
java中的访问修饰符指定数据成员，方法，构造函数或类的辅助功能(范围)。
一共有`4`种类型的java访问修饰符：

- `private`
- `default`
- `protected`
- `public`

有许多非访问修饰符，如：`static`, `abstract`, `synchronized`, `native`, `volatile`, `transient`等修饰符。这里，我们将只学习访问修饰符。

## private访问修饰符

私有(`private`)访问修饰符只能在类中访问。

**private访问修饰符的简单示例**

在这个例子中，我们创建了两个类:`A`和`Simple`。 类包含私有数据成员和私有方法。 我们从类外访问这些私有成员，所以会产生编译时错误。

```  Java
class A {
    private int data = 40;

    private void msg() {
        System.out.println("Hello java");
    }
}

public class Simple {
    public static void main(String args[]) {
        A obj = new A();
        System.out.println(obj.data);// 私有变量，不可以从外部类中直接访问，因此有编译错误
        obj.msg();// 私有方法，不可以从外部类中直接访问，因此有编译错误
    }
}
```

## 1. private访问修饰符

如果将类的构造函数声明为私有，则**不能从类外部创建该类的实例**。 例如：

```  Java
class A {
    private A() {
    }// private constructor

    void msg() {
        System.out.println("Hello java");
    }
}

public class Simple {
    public static void main(String args[]) {
        A obj = new A();// Compile Time Error
    }
}
```

> **注意：**类不能是私有或保护，除非是嵌套类。

## 2. default访问修饰符

如果不使用任何修饰符，默认情况下将其视为`default`修饰符。`default`修饰符**只能在包内访问**。

**default访问修饰符示例**

在这个例子中，我们创建了两个包`pack`和`mypack`。从它的包外部访问`A`类，因为一个类不是`public`的，所以它不能从包外部访问。如下两个类：`A.java` 和 `B.java` 代码。

```  Java
//save by A.java  
package pack;  
class A{  
    void msg(){System.out.println("Hello");}  
}
```

`B.java` 代码的代码如下 -

```  Java
//save by B.java  
package mypack;

import pack.*;

class B {
    public static void main(String args[]) {
        A obj = new A();// Compile Time Error
        obj.msg();// Compile Time Error
    }
}
```

在上面的例子中，`A`类的范围和它的方法`msg()`是默认(`default`)的，所以**它不能从包外部访问。**



## 3. protected访问修饰符

`protected`访问修饰**符可以在包中和包外部访问，但只能通过继承。`protected`访问修饰符可以应用于数据成员，方法和构造函数。 它不能应用于类。**

**protected访问修饰符的示例**

在这个例子中，我们创建了两个包`pack`和`mypack`。 `A`类的包是`public`的，所以可以从外部访问包。 但是这个包的`msg`方法声明为`protected`，因此只能通过继承从类外面访问它。如下两个类：`A.java` 和 `B.java` 代码。

```  Java
//save by A.java  
package pack;

public class A {
    protected void msg() {
        System.out.println("Hello");
    }
}
```

`B.java` 代码如下 -

```  Java
//save by B.java  
package mypack;

import pack.*;

class B extends A {
    public static void main(String args[]) {
        B obj = new B();
        obj.msg();
    }
}
```

执行上面代码，得到如下结果 -

```  Java
Hello

```

## 4. public访问修饰符

公共(`public`)访问修饰符**可随处访问。 它在所有其他修饰符中具有最广泛的范围。**

**public访问修饰符示例**

如下两个类：`A.java` 和 `B.java` 代码。

`A.java` 的代码

```  Java
//save by A.java  

package pack;

public class A {
    public void msg() {
        System.out.println("Hello");
    }
}
```

`B.java` 的代码

```  Java
//save by B.java  

package mypack;

import pack.*;

class B {
    public static void main(String args[]) {
        A obj = new A();
        obj.msg();
    }
}
```

执行上面的代码，得到以下结果 -

```  Java
Hello
```

## 理解所有java访问修饰符

让我们通过下面的一个简单的表来理解访问修饰符。

| 访问修饰符 | 在类内 | 在包内 | 外部包只通过子类 | 外部包 |
| ---------- | ------ | ------ | ---------------- | ------ |
| Private    | Y      | N      | N                | N      |
| Default    | Y      | Y      | N                | N      |
| Protected  | Y      | Y      | Y                | N      |
| Public     | Y      | Y      | Y                | Y      |

如果你要覆盖任何方法，重写的方法(即在子类中声明)则不能声明得更严格。

```  Java
class A {
    protected void msg() {
        System.out.println("Hello java");
    }
}

public class Simple extends A {
    void msg() {
        System.out.println("Hello java");
    }// C.T.Error

    public static void main(String args[]) {
        Simple obj = new Simple();
        obj.msg();
    }
}

```

默认(`default`)修饰符比受保护的修饰符更严格。 这就是为什么有编译时错误。
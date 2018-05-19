# 22 Java 构造器 构造方法

1- 拷贝构造

在java中有很多方法可以将一个对象的值复制到另一个对象中。它们分别是：

- 通过构造函数
- 通过将一个对象的值分配给另一个对象
- 通过Object类的`clone()`方法

2- 吃惊，居然，可以有返回值

**问题1：** 构造函数有返回值 ？

**回答：** 是的，**构造函数返回当前类的实例(不能指定返回值类型，但它会返回一个值)。**

**问题2：** 可以构造函数执行其他任务而不是初始化？

**回答：** **是的，比如：对象创建，启动线程，调用方法等。你可以像在方法中执行的任何操作一样，在构造函数中也可以做到这些。**

3- 构造函数必须与类名相同；

​    方法名可相同可不相同？？？ 【居然可以与类名相同】



------

原文: https://www.yiibai.com/java/constructor.html

java中的构造方法是一种特殊类型的方法，用于初始化对象。Java构造函数在对象创建时被调用。 它构造值，即提供对象的数据，这是为什么它被称为构造函数。

## 创建java构造函数的规则

构造函数基本上定义了两个规则。它们分别如下 -

1. 构造函数名称必须**与其类名称相同**
2. 构造函数**必须没有显式返回类型**

## Java构造函数的类型

有两种类型的构造函数：

1. 默认构造函数(无参数构造函数)
2. 参数化构造函数

![img](22_01.png)

### 1. Java默认构造函数(无参数构造函数)

没有参数的构造函数称为默认构造函数。默认构造函数的语法如下：

```java
<class_name>(){}
```

**默认构造函数的示例：**

在这个例子中，在`Bike`类中创建了无参数(no-arg)构造函数。它将在对象创建时被调用。

```java
class Bike1 {
    Bike1() {
        System.out.println("Bike is created");
    }

    public static void main(String args[]) {
        Bike1 b = new Bike1();
    }
}
```

上面的示例代码运行结果如下 -

```java
Bike is created
```

> 规则：如果类中没有构造函数，编译器会自动创建一个默认构造函数。

**问题：** 默认构造函数的目的是什么？

默认构造函数根据类型为对象提供默认值，如：`0`，`null`等。

**显示默认值的默认构造函数示例**

```java
class Student3 {
    int id;
    String name;

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String args[]) {
        Student3 s1 = new Student3();
        Student3 s2 = new Student3();
        s1.display();
        s2.display();
    }
}
```

运行上面代码，得到如下结果 -

```java
0 null
0 null
```

**解释：** 在上面的类中，代码中并没有创建任何构造函数，但编译器自动提供了一个默认构造函数。默认构造函数分别为字段：`id` 和 `name` 分别提供了`0`和`null`值。

### 2. Java参数化构造函数

具有参数的构造函数称为参数化构造函数。

**问题：** 为什么使用参数化构造函数？
**回答：** 参数化构造函数用于为不同对象提供不同初始化的值。

**参数化构造函数的示例**
在这个例子中，我们创建了具有两个参数的`Student`类的构造函数。构造函数中柯有任意数量的参数。

```java
class Student4 {
    int id;
    String name;

    Student4(int i, String n) {
        id = i;
        name = n;
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String args[]) {
        Student4 s1 = new Student4(111, "Karan");
        Student4 s2 = new Student4(222, "Aryan");
        s1.display();
        s2.display();
    }
}
```

运行上面代码，得到如下结果 -

```java
111 Karan
222 Aryan
```

## Java构造函数重载

构造方法重载是Java中的一种技术，一个类可以有任何数量的参数列表不同的构造函数。编译器通过构造函数参数列表中的参数数量及其类型来区分这些构造函数。

**构造函数重载示例**

```java
class Student5 {
    int id;
    String name;
    int age;

    Student5(int i, String n) {
        id = i;
        name = n;
    }

    Student5(int i, String n, int a) {
        id = i;
        name = n;
        age = a;
    }

    void display() {
        System.out.println(id + " " + name + " " + age);
    }

    public static void main(String args[]) {
        Student5 s1 = new Student5(111, "Karan");
        Student5 s2 = new Student5(222, "Aryan", 25);
        s1.display();
        s2.display();
    }
}
```

上面示例代码，执行后输出结果如下 -

```java
111 Karan 0
222 Aryan 25
```

## java的构造函数和方法之间的区别

构造函数和方法之间有许多区别，它们如下面列出 -

| Java构造函数                                               | Java方法                                     |
| ---------------------------------------------------------- | -------------------------------------------- |
| 构造器用于初始化对象的状态(数据)。                         | 方法用于暴露对象的行为。                     |
| 构造函数不能有返回类型。                                   | 方法一般都有返回类型。                       |
| 构造函数**隐式调用**。                                     | 方法要显式调用。                             |
| 如果没有指定任何构造函数，java编译器提供一个默认构造函数。 | 在任何情况下编译器都不会提供默认的方法调用。 |
| 构造函数名称必须与类名称相同。                             | 方法名称可以或可以不与类名称相同(**随意**)。 |

## Java拷贝构造函数

在Java中没有复制构造函数。但是可以将一个对象的值复制到另一个中，就像C++中的复制构造函数。

在java中有很多方法可以将一个对象的值复制到另一个对象中。它们分别是：

- 通过构造函数
- 通过将一个对象的值分配给另一个对象
- 通过Object类的`clone()`方法

在这个例子中，使用java构造函数将一个对象的值复制到另一个对象中。

```java
class Student6 {
    int id;
    String name;

    Student6(int i, String n) {
        id = i;
        name = n;
    }

    Student6(Student6 s) {
        id = s.id;
        name = s.name;
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String args[]) {
        Student6 s1 = new Student6(111, "Karan");
        Student6 s2 = new Student6(s1);
        s1.display();
        s2.display();
    }
}
```

上面示例代码，执行后输出结果如下 -

```java
111 Karan
111 Karan
```

**不使用构造函数复制值**

可以通过将对象值分配给另一个对象，将一个对象的值复制到另一个对象中。 在这种情况下，不需要创建构造函数。

```java
class Student7 {
    int id;
    String name;

    Student7(int i, String n) {
        id = i;
        name = n;
    }

    Student7() {
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String args[]) {
        Student7 s1 = new Student7(111, "Karan");
        Student7 s2 = new Student7();
        s2.id = s1.id;
        s2.name = s1.name;
        s1.display();
        s2.display();
    }
}
```

上面示例代码，执行后输出结果如下 -

```java
111 Karan
111 Karan
```

**问题1：** 构造函数有返回值 ？

**回答：** 是的，**构造函数返回当前类的实例(不能指定返回值类型，但它会返回一个值)。**

**问题2：** 可以构造函数执行其他任务而不是初始化？

**回答：** **是的，比如：对象创建，启动线程，调用方法等。你可以像在方法中执行的任何操作一样，在构造函数中也可以做到这些。**
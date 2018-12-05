#34 Java 的静态绑定和动态绑定



将方法调用连接到方法体称为绑定。

在java中有两种类型的绑定：

- 静态绑定(也称为早期绑定)。
- 动态绑定(也称为后期绑定)。

## 了解类型

下面让我们来了解实例的类型。

### 1. 变量有一个类型

每个变量都有一个类型，它可能是原始的和非原始的。

```  Java
int data=30;
```

这里的数据变量是一个`int`类型。

### 2. 引用有一个类型

```  Java
class Dog {
    public static void main(String args[]) {
        Dog d1;// Here d1 is a type of Dog
    }
}
```

### 2. 对象有一个类型

对象是特定的`java`类的实例，但它也是其超类的实例。

```  Java
class Animal {
}

class Dog extends Animal {
    public static void main(String args[]) {
        Dog d1 = new Dog();
    }
}
```

这里`d1`是`Dog`类的一个实例，但它也是`Animal`的一个实例。

## 静态绑定

当编译时**(由编译器)确定对象的类型时，它被称为静态绑定**。如果在类中**有任何`private`，`final`或`static`方法，则有静态绑定。**

**静态绑定的示例**

```  Java
class Dog {
    private void eat() {
        System.out.println("dog is eating...");
    }

    public static void main(String args[]) {
        Dog d1 = new Dog();
        d1.eat();
    }
}
```

## 动态绑定

当在运行时确定对象的类型时，它被称为动态绑定。

**动态绑定的示例**

```  Java
class Animal {
    void eat() {
        System.out.println("animal is eating...");
    }
}

class Dog extends Animal {
    void eat() {
        System.out.println("dog is eating...");
    }

    public static void main(String args[]) {
        Animal a = new Dog();
        a.eat();
    }
}
```

执行上面示例代码输出结果如下 -

```  Shell
dog is eating...
```

在上面的例子中，对象类型不能由编译器决定，因为`Dog`的实例也是`Animal`的一个实例。**编译器不知道它的类型，只知道它的基类型**。
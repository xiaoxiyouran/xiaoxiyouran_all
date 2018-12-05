# 09  Java运算符



Java中的运算符是用于执行运算(加，减，乘，除等)操作的符号。例如：`+`， `-` ，`*`，`/`等。

Java中有许多类型的运算符，如下所示：

- 一元运算符
- 算术运算符
- 移位运算符
- 关系运算符
- 按位运算符
- 逻辑运算符
- 三元运算符
- 分配运算符

| 运算符   | 优先级                                                       |
| -------- | ------------------------------------------------------------ |
| 后缀     | `expr++`， `expr--`                                          |
| 一元     | `++expr`， `--expr`， `+expr`， `-expr`，`~`，`!`            |
| 乘、除法 | `*`, `/`,`%`                                                 |
| 加、减法 | `+`， `-`                                                    |
| 移位     | `<<`， `>>`， `>>>`                                          |
| 关系     | `<`， `>`， `<=`，`>=`， `instanceof`                        |
| 相等     | `==`， `!=`                                                  |
| 按位与   | `&`                                                          |
| 按位异或 | `^`                                                          |
| 按位或   | ![img](http://www.yiibai.com/uploads/images/201703/0203/324090329_74222.png) |
| 逻辑与   | `&&`                                                         |
| 逻辑或   | ![img](http://www.yiibai.com/uploads/images/201703/0203/211090330_42812.png) |
| 三元     | `? :`                                                        |
| 赋值     | `=`， `+=`， `-=`， `*=`， `/=`，`%=`，`&=`， `^=`， `<<=`， `>>=`， `>>>=`，![img](http://www.yiibai.com/uploads/images/201703/0203/135090332_68499.png) |

下面分别来看上述运行算的示例：

### 1. Java一元运算符示例：++ 和 —

```java
class OperatorExample{  
    public static void main(String args[]){  
        int x=10;  
        System.out.println(x++);//10 (11)  
        System.out.println(++x);//12  
        System.out.println(x--);//12 (11)  
        System.out.println(--x);//10  
    }
}
```

输出结果如下：

```java
10
12
12
10
```

### 2. Java一元运算符示例2：++ 和 —

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 10;
        int b = 10;
        System.out.println(a++ + ++a);// 10+12=22
        System.out.println(b++ + b++);// 10+11=21

    }
}
```

输出结果如下：

```java
22
21
```

### 3. Java一元运算符示例3：〜 和 ！

表面上看，一个数的位反： 就是先取负数，再减1.

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 10;
        int b = -10;
        boolean c = true;
        boolean d = false;
        System.out.println(~a);// -11 (minus of total positive value which
                                // starts from 0)  ， -10 - 1
        System.out.println(~b);// 9 (positive of total minus, positive starts
                                // from 0)  ， -(-10) - 1
        System.out.println(!c);// false (opposite of boolean value)
        System.out.println(!d);// true
    }
}
```

输出结果如下：

```java
-11
9
false
true
```

### 4. Java算术运算符示例

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 10;
        int b = 5;
        System.out.println(a + b);// 15
        System.out.println(a - b);// 5
        System.out.println(a * b);// 50
        System.out.println(a / b);// 2
        System.out.println(a % b);// 0
    }
}
```

输出结果如下：

```java
15
5
50
2
0
```

### 5. Java算术运算符示例：表达式

```java
class OperatorExample {
    public static void main(String args[]) {
        System.out.println(10 * 10 / 5 + 3 - 1 * 4 / 2);
    }
}
```

输出结果如下：

```java
21
```

### 6. java的移位运算实例：左移

```java
class OperatorExample {
    public static void main(String args[]) {
        System.out.println(10 << 2);// 10*2^2=10*4=40
        System.out.println(10 << 3);// 10*2^3=10*8=80
        System.out.println(20 << 2);// 20*2^2=20*4=80
        System.out.println(15 << 4);// 15*2^4=15*16=240
    }
}
```

输出结果如下：

```shell
40
80
80
240
```

### 7. java的移位运算实例：右移

```java
class OperatorExample {
    public static void main(String args[]) {
        System.out.println(10 >> 2);// 10/2^2=10/4=2
        System.out.println(20 >> 2);// 20/2^2=20/4=5
        System.out.println(20 >> 3);// 20/2^3=20/8=2
    }
}
```

输出结果如下：

```java
2
5
2
```

### 8. java的移位运算实例：>> 和 >>>

```java
class OperatorExample {
    public static void main(String args[]) {
        // For positive number, >> and >>> works same
        System.out.println(20 >> 2);
        System.out.println(20 >>> 2);
        // For nagative number, >>> changes parity bit (MSB) to 0
        System.out.println(-20 >> 2);
        System.out.println(-20 >>> 2);
    }
}
```

输出结果如下：

```java
5
5
-5
1073741819
```



### 9. Java AND运算符示例：逻辑&&和位＆

如果第一个条件为假(`false`)，则逻辑`&&`运算符不检查第二个条件。它只有在第一个条件为真(`true`)时才会检查第二个条件。

按位与(`&`)运算符总是检查两个条件，不管第一个条件是真还是假。

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 10;
        int b = 5;
        int c = 20;

        System.out.println(a < b && a < c);// false && true = false
        System.out.println(a < b & a < c);// false & true = false

    }
}
```

输出结果如下：

```java
false
false
```

### 10. Java与运行算实例：逻辑&&与按位＆

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 10;
        int b = 5;
        int c = 20;
        System.out.println(a < b && a++ < c);// false && true = false
        System.out.println(a);				// 10 because second condition is not checked
        System.out.println(a < b & a++ < c);// false && true = false
        System.out.println(a);				// 11 because second condition is checked
    }
}
```

输出结果如下：

```java
false
10
false
11
```

### 11. Java 或运算符示例：逻辑|| 和按位 |

逻辑`||` 如果第一个条件为真(`true`)，运算符不检查第二个条件。它只在第一个条件为假(`false`)时才会检查第二个条件。

按位或 `|` 运算符总是检查两个条件，不管第一个条件是真(`true`)还是假(`false`)。

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 10;
        int b = 5;
        int c = 20;
        System.out.println(a > b || a < c);// true || true = true
        System.out.println(a > b | a < c);// true | true = true
        // || vs |
        System.out.println(a > b || a++ < c);// true || true = true
        System.out.println(a);// 10 because second condition is not checked
        System.out.println(a > b | a++ < c);// true | true = true
        System.out.println(a);// 11 because second condition is checked
    }
}
```

输出结果如下：

```java
true
true
true
10
true
11
```

### 12. Java 或运算符示例：逻辑|| 和按位 |

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 2;
        int b = 5;
        int min = (a < b) ? a : b;
        System.out.println(min);
    }
}
```

输出结果如下：

```java
2
```

**另一个例子：**

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 10;
        int b = 5;
        int min = (a < b) ? a : b;
        System.out.println(min);
    }
}
```

输出结果如下：

```java
5
```

### 13. Java分配运算符示例

```java
class OperatorExample {
    public static void main(String args[]) {
        int a = 10;
        int b = 20;
        a += 4;// a=a+4 (a=10+4)
        b -= 4;// b=b-4 (b=20-4)
        System.out.println(a);
        System.out.println(b);
    }
}
```

输出结果如下：

```java
14
16
```

### 14. Java分配运算符示例：相加short类型数据

整型运算，总有一个自动转成 int 的 过程。

```java
class OperatorExample {
    public static void main(String args[]) {
        short a = 10;
        short b = 10;
        // a+=b;//a=a+b internally so fine
        a = a + b;// 编译时错误，因为 10+10=20 现在是 int 类型
        System.out.println(a);
    }
}
```

输出结果如下：

```
编译时错误....
```

**类型转换后：**

```java
class OperatorExample {
    public static void main(String args[]) {
        short a = 10;
        short b = 10;
        a = (short) (a + b);// 20 which is int now converted to short
        System.out.println(a);
    }
}
```

输出结果如下：

```java
20
```
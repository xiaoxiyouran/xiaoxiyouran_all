# 16 continue

Java **continue语句**用于继续循环。 它继续程序的当前流程，并在指定条件下跳过剩余的代码。在内循环的情况下，它仅继续内循环。

**语法：**

```java
jump-statement;    
continue;
```

## Java continue语句示例

**示例：**

```java
public class ContinueExample {
    public static void main(String[] args) {
        for (int i = 1; i <= 10; i++) {
            if (i == 5) {
                continue;
            }
            System.out.println(i);
        }
    }
}
```

执行上面示例代码，得到如下结果 -

```java
1
2
3
4
6
7
8
9
10
```

## Java continue语句与内循环

如果在内循环中使用`continue`语句，它将继续内循环。

**示例：**

```Java
public class ContinueExample2 {
    public static void main(String[] args) {
        for (int i = 1; i <= 3; i++) {
            for (int j = 1; j <= 3; j++) {
                if (i == 2 && j == 2) {
                    continue;
                }
                System.out.println(i + " " + j);
            }
        }
    }
}
```

执行上面示例代码，得到如下结果 -

```
1 1
1 2
1 3
2 1
2 3
3 1
3 2
3 3
```
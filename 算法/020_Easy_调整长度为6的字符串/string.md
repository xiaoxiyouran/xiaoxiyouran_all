# 020 调整长度为6的字符串

## 链接和考点

| 栏目           | 详细       |
| -------------- | ---------- |
| 爱奇艺编程测试 | 2018.09.15 |
| 考点           | string     |
| 难度           | Easy       |

<br>

## 题意

小C有一张票，这张票的ID是长度为6的字符串， 每个字符都是数字， 他想让这个ID变成他的幸运ID， 所以他就开始更改ID， 每一次操作， 他可以选择任意一个数字并且替换它。

如果这个ID的前三位数字之和等于后三位数字之和，那么这个ID就是幸运的。 你帮小C求一下，最少需要操作几次， 能使ID变成幸运ID。

**输入描述**：

>输入只有一行，是一个长度为6的字符串

示例

```
000000
```

**输出**

```
0
```

Hint

```
输入样例2
000018

输出样例2
1

样例解释： 将前三位任意一个改成9即可满足条件， 操作数为1
```

<br>

## 分析

1-  别人的方法，好像有点全遍历的思想， 有这么些情况：

- sum{前三个} 等于 sum{后三个}： 调整0次
- sum{前三个} 大于 sum{后三个}： 调整后三个，最少调整一次， 最多调整3次
- sum{前三个} 小于 sum{后三个}： 调整前三个，最少调整一次， 最多调整3次

<br>

## 测试

A了100%

<br>

## 参考答案

java代码如下，

```java
import java.util.Scanner;

/**
 * Created by ShuaiLiu on 2018/9/15 10:54
 */
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        char[] chars = scanner.nextLine().toCharArray();
        int[] array = new int[6];
        int[] record = new int[6];
        for (int i = 0; i < chars.length; i++) {
            array[i] = chars[i] - '0';
            record[i] = 9 - array[i];
        }
        int res = 0;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < 3; i++) {
            sum1 += array[i];
        }
        for (int i = 3; i < 6; i++) {
            sum2 += array[i];
        }
        if (sum1 == sum2) {
            System.out.println(0);
            return;
        } else if (sum1 < sum2) {
            int remain = sum2 - sum1;
            for (int i = 0; i < 3; i++) {
                if (record[i] >= remain) {
                    System.out.println(1);
                    return;
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = i; j < 3; j++) {
                    if (record[i] + record[j] >= remain) {
                        System.out.println(2);
                        return;
                    }
                }
            }
            System.out.println(3);
            return;
        } else {
            int remain = sum1 - sum2;
            for (int i = 3; i < 6; i++) {
                if (record[i] >= remain) {
                    System.out.println(1);
                    return;
                }
            }
            for (int i = 3; i < 6; i++) {
                for (int j = i; j < 6; j++) {
                    if (record[i] + record[j] >= remain) {
                        System.out.println(2);
                        return;
                    }
                }
            }
            System.out.println(3);
            return;
        }
    }
}
```




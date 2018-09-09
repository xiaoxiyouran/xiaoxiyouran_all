# 016 判断是否是完全多部图 

## 链接和考点

| 栏目         | 详细       |
| ------------ | ---------- |
| 京东编程测试 | 2018.09.08 |
| 考点         | vector2D   |
| 难度         | Easy       |

<br>

## 题意

![image-20180909212044536](image-20180909212044536.png)

![image-20180909212051695](image-20180909212051695.png)

![image-20180909212100351](image-20180909212100351.png)

<br>

## 分析 

1-  暴力破解就可以了， O(n^2)

<br>

## 测试

A了100%

<br>

## 参考答案

java 代码如下： 

```java
Scanner scanner=new Scanner(System.in);
        while (scanner.hasNext()){
            int n=scanner.nextInt();
            int[][] fi=new int[n][3];
            int[] fir=new int[n];
            int count=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<3;j++) {
                    fi[i][j]=scanner.nextInt();
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){

                    if(fi[i][0]<fi[j][0]){
                        if(fi[i][1]<fi[j][1]){
                            if(fi[i][2]<fi[j][2]){
                                count++;
                                break;
                            }
                        }
                    }
                }
            }
            System.out.println(count);

        }
}
}
```




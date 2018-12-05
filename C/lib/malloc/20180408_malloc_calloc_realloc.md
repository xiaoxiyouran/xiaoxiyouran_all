# 20180408_malloc_calloc_realloc

原文链接：http://www.jb51.net/article/70969.htm

------

这些函数只能用于内置类型的内存分配。所以也不能用template。

malloc分配的内存空间在逻辑上连续的，而在物理上可以连续也可以不连续。

## 1- malloc

函数原型

```cpp
extern void *malloc(unsigned int num_bytes);
```

头文件：#include <malloc.h> 或 #include <alloc.h> (注意：alloc.h 与 malloc.h 的内容是完全一致的。)

功能：分配长度为num_bytes字节的内存块

说明：如果分配成功则返回指向被分配内存的指针，否则返回空指针NULL。

当内存不再使用时，应使用free()函数将内存块释放。



返回类型是 void* 类型。void* 表示未确定类型的指针。C,C++规定，void* 类型可以强制转换为任何其它类型的指针。这个在MSDN上可以找到相关的解释，具体内容如下：   

malloc returns a void pointer to the allocated space, or NULL if there is insufficient memory available. To return a pointer to a type other than void, use a type cast on the return value. The storage space pointed to by the return value is guaranteed to be suitably aligned for storage of any type of object. If size is 0, malloc allocates a zero-length item in the heap and returns a valid pointer to that item. Always check the return from malloc, even if the amount of memory requested is small.

简单举例：

```cpp
#include<stdio.h>
#include<malloc.h>
int main()
{
  char *p;
  
  p=(char *)malloc(100);
  if(p)
    printf("Memory Allocated at: %x/n",p);
  else
    printf("Not Enough Memory!/n");
  free(p);
  return 0;
}
```



## 2- malloc 和new的比较

1- new 可以自动计算所需要的大小

```cpp
int *p; 
p = new int; //返回类型为int* 类型(整数型指针)，分配大小为 sizeof(int);

// or
int* parr; 
parr = new int [100]; //返回类型为 int* 类型(整数型指针)，分配大小为 sizeof(int) * 100;
```

而 malloc 则必须由我们计算要字节数，并且在返回后强行转换为实际类型的指针。

`````````````````````cpp
int* p; 
p = (int *) malloc (sizeof(int)); 	/// 必须用(int *) 强转，否则有编译错误
`````````````````````



2- malloc 的实参是sizeof(int), 表明一个整型数据需要的大小，如果是：

```cpp
int* p = (int *) malloc (1);
```

代码也能通过编译，但事实上只分配了1个字节大小的内存空间，当你往里头存入一个整数，就会有3个字节无家可归，而直接“住进邻居家”！造成的结果是后面的内存中原有数据内容全部被清空。

malloc 也可以达到 new [] 的效果，申请出一段连续的内存,比如想分配100个int类型的空间：

```cpp
int* p = (int *) malloc ( sizeof(int) * 100 ); //分配可以放得下100个整数的内存空间。
```

malloc 只管分配内存，并不能对所得的内存进行初始化，所以得到的一片新内存中，其值将是随机的。

通过malloc或new得到指针，在其它操作上保持一致。



##3- 动态申请一维数组 

一维数组的数组名可以看成数组起始元素的首地址，因此我定义一个int *arr的指针，分配n个大小的int型空间，写法如下：

```cpp
#include <stdio.h> 
#include <stdlib.h> 
    
int main(void){ 
    int n, *arr; 
    
    while (scanf("%d", &n) != EOF) { 
      arr = (int *)malloc(sizeof(int) * n); 
    } 
    
    return 0; 
} 
```



## 4- 动态申请二维数组

二维数组的数组名是其所有一维数组的首地址，因为二维数组的数组名是指针的指针，因为我定义一个row行column列的二维数组，写法如下：

```cpp
#include <stdio.h> 
#include <stdlib.h> 
  
int main(void) 
{ 
  int i, row, column, **arr; 
  
  while (scanf("%d %d", &row, &column) != EOF) { 
    arr = (int **)malloc(sizeof(int *) * row); // 分配所有行的首地址 
    for (i = 0; i < row; i ++) { // 按行分配每一列 
      arr[i] = (int *)malloc(sizeof(int) * column);   
    } 
  
    free(arr); 
  } 
  
  return 0; 
} 
```

这里提供一些公共函数，注意的是，不能用于自建类型的创建，比如struct等类型。所以不能写成模板函数。

```cpp
#include <stdio.h>
#include <stdlib.h>


void initArray2(int **arr, int row, int column){
    for(int i=0; i< row; i++) {
        for (int j = 0; j < column; j++) {
            arr[i][j] = 0;
        }
    }
}

int** createArray2(int row, int column){
    int ** arr;
    arr = (int **)malloc(sizeof(int *) * row); // 分配所有行的首地址
    for (int i = 0; i < row; i ++) { // 按行分配每一列
        arr[i] = (int *)malloc(sizeof(int) * column);
    }
    initArray2(arr,row,column);
    return arr;
}

void printArray2(int **arr, int row, int column){
    for(int i=0; i< row; i++){
        for(int j=0; j< column; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}
int main(void)
{
    int i, row = 2,column =3 , **arr;

    arr = createArray2(row,column);
    printArray2(arr,row,column);


    free(arr);
    return 0;
}
```

测试结果如下：

```cpp
0       0       0
0       0       0
```

------



## 5- calloc

申请内存有类型信息，并都初始化为0，其它两个都是随机值。 



## 6- realloc

代替malloc。(第一个参数为0)

```cpp
#include <malloc.h>

int main()
{
    int* p = (int*)realloc(0 ,5 * sizeof(int));

    if (NULL != p){
        //do something
    }

    free(p);
    p = NULL;

    return 0;
}
```

用法2.重新申请内存大小

```cpp
int* pI = (int*)malloc(5 * sizeof(int));    
pI = (int*)realloc(pI, 10);  
```

## 7- memset 和strncpy

```cpp


/**
 *   data: 20150108
 * author: kangear
 *   func: malloc in sub function
 *    说明: malloc函数在子函数中的使用
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MALLOC(type, n)  (type*)malloc(n*sizeof(type))
void func(void** buf) {
    *buf = MALLOC(unsigned char, 5);
    memset(*buf, 0, 5);
    strncpy((char *)*buf, "1", 1);  /// 必须用强制类型转换，否则会报错。 *buf 是char* 类型
}
int main() {
    unsigned char *p;
    func((void **)&p);              /// 必须用显示转换，(char * p), &p 就是 void** 类型
    printf("%s\n", p);
}
```

输出结果为：

```cpp
1
```




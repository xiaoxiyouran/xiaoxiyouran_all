# 复杂类型 struct slice 和map

## 指针

Go 具有指针。 指针保存了变量的内存地址。

类型 `*T` 是指向类型 `T` 的值的指针。其==零值是 `nil`。==

```go
var p *int	
```

`&` 符号会生成一个指向其作用对象的指针。

```go
i := 42
p = &i
```

`*` 符号表示指针指向的底层的值。

```go
fmt.Println(*p) // 通过指针 p 读取 i
*p = 21         // 通过指针 p 设置 i
```

这也就是通常所说的==“间接引用”或“非直接引用”==。

与 C 不同，==Go 没有指针运算。==

```go
package main

import "fmt"

func main() {
	i, j := 42, 2701

	p := &i         // point to i
	fmt.Println(*p) // read i through the pointer
	*p = 21         // set i through the pointer
	fmt.Println(i)  // see the new value of i

	p = &j         // point to j
	*p = *p / 37   // divide j through the pointer
	fmt.Println(j) // see the new value of j
}

//42
//21
//73
```

<br>

## 结构体

一个结构体（`struct`）就是一个字段的集合。

（而 `type` 的含义跟其字面意思相符。）

```go
package main

import "fmt"

type Vertex struct {		// 需要要加 type 关键字
	X int
	Y int
}

func main() {
	fmt.Println(Vertex{1, 2})
}

//{1 2}
```

<br>

### 结构体字段

结构体字段使用点号来访问。

```go
package main

import "fmt"

type Vertex struct {
X int
Y int
}

func main() {
v := Vertex{1, 2}	 // 没有构造函数，按照结构体中声明的顺序初始化
v.X = 4					 // 修改结构体 成员的值
fmt.Println(v.X)
}
//4
```

<br>

### 结构体指针

结构体字段可以通过结构体指针来访问。

通过指针间接的访问是透明的。

```go
package main

import "fmt"

type Vertex struct {
	X int
	Y int
}

func main() {
	v := Vertex{1, 2}
	p := &v					// 获得结构体对象指针		
	p.X = 1e9				// 还是可以用  . 直接访问
	fmt.Println(v)
}
//{1000000000 2}
```

<br>

### 结构体文法

结构体文法表示通过结构体==字段的值作为列表来新分配一个结构体==。

使用 `Name:` 语法可以==仅列出部分字段==。（字段名的顺序无关。）

特殊的前缀 `&` 返回一个==指向结构体的指针。== 

```go
package main

import "fmt"

type Vertex struct {
	X, Y int
}

var (
	v1 = Vertex{1, 2}  // 类型为 Vertex
	v2 = Vertex{X: 1}  // Y:0 被省略
	v3 = Vertex{}      // X:0 和 Y:0
	p  = &Vertex{1, 2} // 类型为 *Vertex
)

func main() {
	fmt.Println("%T", p)
	fmt.Println(v1, p, v2, v3)
}

//%T &{1 2}
//{1 2} &{1 2} {1 0} {0 0}

```

<br>

## 数组

类型 `[n]T` 是一个有 `n` 个类型为 `T` 的值的数组。

表达式

```go
var a [10]int
```

定义变量 `a` 是一个有十个整数的数组。

数组的长度是其类型的一部分，因此==数组不能改变大小==。 这看起来是一个制约，但是请不要担心； Go 提供了更加便利的方式来使用数组。

```go
package main

import "fmt"

func main() {
	var a [2]string
	a[0] = "Hello"
	a[1] = "World"
	fmt.Println(a[0], a[1])
	fmt.Println(a)
}

//Hello World
//[Hello World]
```

<br>

## slice

一个 slice 会==指向一个序列的值，并且包含了长度信息==。

`[]T` 是一个元素类型为 `T` 的 slice。

```go
package main

import "fmt"

func main() {
    p := []int{2, 3, 5, 7, 11, 13}	//[]int{} 指的是创建一个数组
	fmt.Println("p ==", p)

	for i := 0; i < len(p); i++ {
		fmt.Printf("p[%d] == %d\n", i, p[i])
	}
}

//p == [2 3 5 7 11 13]
//p[0] == 2
//p[1] == 3
//p[2] == 5
//p[3] == 7
//p[4] == 11
//p[5] == 13
```

<br>

### 对slice切片

slice 可以重新切片，创建一个新的 slice 值指向相同的数组。

表达式

```go
s[lo:hi]
```

表示从 `lo` 到 `hi-1` 的 slice 元素，含两端。因此

```go
s[lo:lo]
```

是空的，而

```go
s[lo:lo+1]
```

有一个元素。

```go
package main

import "fmt"

func main() {
	p := []int{2, 3, 5, 7, 11, 13}
	fmt.Println("p ==", p)
	fmt.Println("p[1:4] ==", p[1:4])

	// 省略下标代表从 0 开始
	fmt.Println("p[:3] ==", p[:3])

	// 省略上标代表到 len(s) 结束
	fmt.Println("p[4:] ==", p[4:])
}

//p == [2 3 5 7 11 13]
//p[1:4] == [3 5 7]
//p[:3] == [2 3 5]
//p[4:] == [11 13]
```

<br>

### 构造 slice

slice 由==函数 `make` 创建。==这会分配一个==零长度的数组并==且返回一个 slice 指向这个数组：

```
a := make([]int, 5)  // len(a)=5
```

为了指定容量，可传递第三个参数 `capability`到 `make`： 

```go
b := make([]int, 0, 5) // len(b)=0, cap(b)=5

b = b[:cap(b)] // len(b)=5, cap(b)=5
b = b[1:]      // len(b)=4, cap(b)=4, 长度和容量一起变小
```

示例如下：

```go
package main

import "fmt"

func main() {
	a := make([]int, 5)
	printSlice("a", a)
	b := make([]int, 0, 5)
	printSlice("b", b)
	c := b[:2]
	printSlice("c", c)
	d := c[2:5]
	printSlice("d", d)
}

func printSlice(s string, x []int) {
	fmt.Printf("%s len=%d cap=%d %v\n",
		s, len(x), cap(x), x)
}

//a len=5 cap=5 [0 0 0 0 0]
//b len=0 cap=5 []
//c len=2 cap=5 [0 0]
//d len=3 cap=3 [0 0 0]
```

<br>

### nil slice

slice 的==零值是 `nil`。==

一个 nil 的 slice 的==长度和容量是 0。==

```go
package main

import "fmt"

func main() {
	var z []int
	fmt.Println(z, len(z), cap(z))
	if z == nil {
		fmt.Println("nil!")
	}
}

//[] 0 0
//nil!
```

<br>

### 向slice添加元素

向 slice 添加元素是一种常见的操作，因此 Go 提供了一个内建函数 `append`。 内建函数的[文档](http://golang.org/pkg/builtin/#append)对 `append` 有详细介绍。

```go
func append(s []T, vs ...T) []T
```

`append` 的==第一个参数 `s` 是一个类型为 `T` 的数组==，其余类型为 `T` 的值将会添加到 slice。

`append` 的结果是一个包含==原 slice 所有元素加上新添加的元素==的 slice。

如果 `s` 的==底层数组太小，而不能容纳所有值时，会分配一个更大的数组==。 返回的 slice 会==指向这个新分配的数组==。

（了解更多关于 slice 的内容，参阅文章[slice：使用和内幕](http://golang.org/doc/articles/slices_usage_and_internals.html)。）

```go
package main

import "fmt"

func main() {
	var a []int
	printSlice("a", a)

	// append works on nil slices.
	a = append(a, 0)
	printSlice("a", a)

	// the slice grows as needed.
	a = append(a, 1)
	printSlice("a", a)

	// we can add more than one element at a time.
	a = append(a, 2, 3, 4)		// 一次添加多个元素
	printSlice("a", a)
}

func printSlice(s string, x []int) {
	fmt.Printf("%s len=%d cap=%d %v\n",
		s, len(x), cap(x), x)
}

//a len=0 cap=0 []
//a len=1 cap=1 [0]
//a len=2 cap=2 [0 1]
//a len=5 cap=6 [0 1 2 3 4]
```

<br>

## range

`for` 循环的 `range` 格式可以==对 slice 或者 map 进行迭代循环==。

```go
package main

import "fmt"

var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

func main() {
	for i, v := range pow {			// 第一个参数是 index， 第二个是value
		fmt.Printf("2**%d = %d\n", i, v)
	}
}

//2**0 = 1
//2**1 = 2
//2**2 = 4
//2**3 = 8
//2**4 = 16
//2**5 = 32
//2**6 = 64
//2**7 = 128
```

可以通过赋值==给 `_` 来忽略序号和值==。

如果只需要索引值，去掉“, value”的部分即可。

```go
package main

import "fmt"

func main() {
	pow := make([]int, 10)			// 长度为 10
	for i := range pow {			// value 直接省略即可
		pow[i] = 1 << uint(i)
	}
	for _, value := range pow {		// 如果省略index， 需要用 _ 代替
		fmt.Printf("%d\n", value)
	}
}

//1
//2
//4
//8
//16
//32
//64
//128
//256
//512
```

<br>

## map

map 映射键到值。

map 在==使用之前必须用 `make`== 而不是 `new` 来创建；==值为 `nil` 的 map 是空的，并且不能赋值==。

```go
package main

import "fmt"

type Vertex struct {
	Lat, Long float64
}

var m map[string]Vertex

func main() {
	m = make(map[string]Vertex)
	m["Bell Labs"] = Vertex{
		40.68433, -74.39967,
	}
	fmt.Println(m["Bell Labs"])
}

//{40.68433 -74.39967}
```

<br>

### map 的文法

map 的文法跟结构体文法相似，不过必须有键名。

```go
package main

import "fmt"

type Vertex struct {
	Lat, Long float64
}

var m = map[string]Vertex{		// 使用键值对， 声明定义时初始化
	"Bell Labs": Vertex{
		40.68433, -74.39967,
	},
	"Google": Vertex{
		37.42202, -122.08408,
	},
}

func main() {
	fmt.Println(m)
}

//map[Bell Labs:{40.68433 -74.39967} Google:{37.42202 -122.08408}]

```

如果顶级的类型**只有类型名的话**，可以**在文法的元素中省略键名。**

```go
package main

import "fmt"

type Vertex struct {
	Lat, Long float64
}

var m = map[string]Vertex{
	"Bell Labs": {40.68433, -74.39967},		//  这里省略了 Vertex 键名
	"Google":    {37.42202, -122.08408},
}

func main() {
	fmt.Println(m)
}

//map[Bell Labs:{40.68433 -74.39967} Google:{37.42202 -122.08408}]
```

<br>

### 修改map

在 map `m` 中**插入或修改一个元素**：

```go
m[key] = elem
```

获得元素：

```go
elem = m[key]
```

==删除元素==：

```go
delete(m, key)
```

通过==双赋值检测某个键存在==：

```go
elem, ok = m[key]
```

如果 `key` 在 `m` 中，`ok` 为 `true` 。否则， `ok` 为 `false`，并且 ==`elem` 是 map 的元素类型的零值==。

同样的，当从 map 中:

- ==读取某个不存在的键时，结果是 map 的元素类型的零值。==
- 如果存在， 返回的就是该键对应的值；

```go
package main

import "fmt"

func main() {
	m := make(map[string]int)

	m["Answer"] = 42
	fmt.Println("The value:", m["Answer"])

	m["Answer"] = 48
	fmt.Println("The value:", m["Answer"])

	delete(m, "Answer")
	fmt.Println("The value:", m["Answer"])		// 删除键后， 值就是0

	v, ok := m["Answer"]
	fmt.Println("The value:", v, "Present?", ok)


	fmt.Println("-------------------------------")
	m["good"] = 1
	v2, ok2 := m["good"]
	fmt.Println("The value:", v2, "Present?", ok2)		// 能取到， element 就是该键对应的值
}


//The value: 42
//The value: 48
//The value: 0
//The value: 0 Present? false
//-------------------------------
//The value: 1 Present? true
```

<br>

## 练习：map

实现 `WordCount`。它应当返回一个含有 `s` 中每个 “词” 个数的 map。函数 `wc.Test` 针对这个函数执行一个测试用例，并输出成功还是失败。

你会发现 [strings.Fields](http://golang.org/pkg/strings/#Fields) 很有帮助。

### 方法一

1- `strings.Fields(s)` 将 字符串s 进行分词， 然后将频率计数即可；

`m[v]` 它的初始值 是 0

```go
package main

import (
	"fmt"
	"strings"
)

func WordCount(s string) map[string]int {
	m := make(map[string]int)// map对象
	c := strings.Fields(s)// []string
	for _, v := range c {
		m[v] += 1 // 如果v没有在map中，m[v]的值为初始值 0
	}
	return m
}
func main() {
	s := "I love China"
	fmt.Println(WordCount(s))
}

//map[I:1 love:1 China:1]
```

<br>

### 方法二

这个 就是将初始值考虑进去了：

```go
func WordCount(s string) map[string]int {
	s_arr := strings.Fields(s)//分割字符串为字符数组
	s_map := make(map[string]int)//建立map
	//对s_arr中的每个字符进行循环
	for i:= 0; i<len(s_arr); i++ {
		if s_map[s_arr[i]] == 0 { //当还没有统计过该字符时，赋值为1
			s_map[s_arr[i]] = 1
		} else {                  //当统计过该字符时，更新计数值+1
			s_map[s_arr[i]] = s_map[s_arr[i]] + 1
		}
	}
	return s_map
}
```

<br>

## 函数值

==函数也是值==。

```go
package main

import (
	"fmt"
	"math"
)

func main() {
	hypot := func(x, y float64) float64 {		// 和 python 一样，可以将函数名赋给一个变量
		return math.Sqrt(x*x + y*y)
	}

	fmt.Println(hypot(3, 4))
}
//5
```

<br>

### 函数的闭包

Go 函数可以是闭包的。闭包是一个函数值，它来自函数体的外部的变量引用。 函数可以对这个引用值进行访问和赋值；换句话说这个函数被“绑定”在这个变量上。

例如，函数 `adder` 返回一个闭包。每个闭包都被绑定到其各自的 `sum` 变量上。

```go
package main

import "fmt"

func adder() func(int) int {		// 返回值是一个函数对象
	sum := 0
	return func(x int) int {		// 真正的函数实现
		sum += x
		return sum
	}
}

func main() {
	pos, neg := adder(), adder()
	for i := 0; i < 10; i++ {
		fmt.Println(
			pos(i),
			neg(-2*i),
		)
	}
}

//0 0
//1 -2
//3 -6
//6 -12
//10 -20
//15 -30
//21 -42
//28 -56
//36 -72
//45 -90
```

<br>

## 练习：斐波纳契闭包

现在来通过函数做些有趣的事情。

实现一个 `fibonacci` 函数，返回一个函数（一个闭包）可以返回连续的斐波纳契数。

```go
package main

import "fmt"

// fibonacci 函数会返回一个返回 int 的函数。
func fibonacci() func() int {
	a := 1; b := 0				// 在闭包内， 这些变量的值是外部的
	return func() int{
		tmp := b
		b = a + b
		a = tmp
		return b
	}
}

func main() {
	f := fibonacci()
	for i := 0; i < 10; i++ {
		fmt.Println(f())
	}
}

//1
//1
//2
//3
//5
//8
//13
//21
//34
//55
```

<br>












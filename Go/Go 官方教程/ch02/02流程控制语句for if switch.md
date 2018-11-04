# 流程控制语句for if switch

## for

Go 只有一种循环结构——`for` 循环。

==基本的 `for` 循环除了没有了 `( )` 之外==（甚至强制不能使用它们），看起来跟 C 或者 Java 中做的一样，而 `{ }` 是必须的。

```go
package main

import "fmt"

func main() {
	sum := 0
	for i := 0; i < 10; i++ {
		sum += i
	}
	fmt.Println(sum)
}
//45
```

跟 C 或者 Java 中一样，可以让前置、后置语句为空。

```go
package main

import "fmt"

func main() {
	sum := 1
	for ; sum < 1000; {
		sum += sum		// 每次2倍
	}
	fmt.Println(sum)
}
//1024
```

<br>

### for 是go 的while

基于此可以省略分号：C 的 `while` 在 Go 中叫做 `for`。

```go
package main

import "fmt"

func main() {
	sum := 1
	for sum < 1000 {
		sum += sum
	}
	fmt.Println(sum)
}

```

<br>

### 死循环

如果省略了循环条件，循环就不会结束，因此可以用更简洁地形式表达死循环。

```go
package main

func main() {
	for {
	}
}
```

<br>

## if

`if` 语句==除了没有了 `( )` 之外==（甚至强制不能使用它们），看起来跟 C 或者 Java 中的一样，而 `{ }` 是必须的。

（耳熟吗？）

```go
package main

import (
	"fmt"
	"math"
)

func sqrt(x float64) string {
	if x < 0 {
		return sqrt(-x) + "i"
	}
	return fmt.Sprint(math.Sqrt(x))
}

func main() {
	fmt.Println(sqrt(2), sqrt(-4))
}

//1.4142135623730951 2i
```

<br>

### if 的便携语句

跟 `for` 一样，`if` 语句可以在条件之前执行一个简单的语句。

由这个语句定义的变量的作用域仅在 `if` 范围之内。

（在最后的 `return` 语句处使用 `v` 看看。）

```go
package main

import (
	"fmt"
	"math"
)

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {	// 运行一条语句，变量作用域仅在if内
		return v
	}
	return lim
}

func main() {
	fmt.Println(
		pow(3, 2, 10),
		pow(3, 3, 20),
	)
}
//9 20
```

<br>

### if 和else

在 `if` 的便捷语句定义的变量同样可以在任何对应的 `else` 块中使用。

```go
package main

import (
	"fmt"
	"math"
)

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	} else {					// else
		fmt.Printf("%g >= %g\n", v, lim)
	}
	// 这里开始就不能使用 v 了
	return lim
}

func main() {
	fmt.Println(
		pow(3, 2, 10),
		pow(3, 3, 20),
	)
}

//27 >= 20
//9 20
```

<br>

## 练习： 循环和函数

作为练习函数和循环的简单途径，用**牛顿法实现开方函数**。

在这个例子中，牛顿法是通过选择一个初始点 *z* 然后重复这一过程求 `Sqrt(x)` 的近似值：

$z = z - \frac{z^2 - x}{2z}$ 

为了做到这个，只需要重复计算 10 次，并且观察不同的值（1，2，3，……）是如何逐步逼近结果的。 然后，修改循环条件，使得当值停止改变（或改变非常小）的时候退出循环。观察迭代次数是否变化。结果与 http://golang.org/pkg/math/#Sqrt 接近吗？

提示：定义并初始化一个浮点值，向其==提供一个浮点语法或使用转换==：

```
z := float64(1)
z := 1.0
```

程序如下：

```go
package main

import (
	"fmt"
)

func Sqrt(x float64) float64 {
	z := 1.0
	for i:=0; i<10; i++{
		z = z - (z*z - x)/(2*z)
	}

	return z
}

func main() {
	fmt.Println(Sqrt(2))
}
//1.414213562373095
```

<br>

## switch

一个结构体（`struct`）就是一个字段的集合。

除非以 `fallthrough` 语句结束，否则分支会自动终止。

```go
package main

import (
	"fmt"
	"runtime"
)

func main() {
	fmt.Print("Go runs on ")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X.")
	case "linux":
		fmt.Println("Linux.")
	default:
		// freebsd, openbsd,
		// plan9, windows...
		fmt.Printf("%s.", os)
	}
}
//Go runs on OS X.
```

<br>

### switch 的执行顺序

switch 的条件从上到下的执行，当匹配成功的时候停止。

（例如，

```
switch i {
case 0:
case f():
}
```

当 `i==0` 时不会调用 `f`。）

注意：Go playground 中的时间**总是从 2009-11-10 23:00:00 UTC 开始**， 如何校验这个值作为一个练习留给读者完成。

```go
package main

import (
	"fmt"
	"time"
)

func main() {
	fmt.Println("When's Saturday?")
	today := time.Now().Weekday()
	switch time.Saturday {
	case today + 0:
		fmt.Println("Today.")
	case today + 1:
		fmt.Println("Tomorrow.")
	case today + 2:
		fmt.Println("In two days.")
	default:
		fmt.Println("Too far away.")
	}
}
//When's Saturday?
//Today.
```

<br>

### 没有条件的switch

没有条件的 switch 同 `switch true` 一样。

这一构造使得可以用==更清晰的形式来编写长的 if-then-else 链==。

```go
package main

import (
	"fmt"
	"time"
)

func main() {
	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 17:
		fmt.Println("Good afternoon.")
	default:
		fmt.Println("Good evening.")
	}
}
//Good morning!
```

<br>

## defer

defer 语句会延迟函数的执行直到上层函数返回。

延迟调用的参数会立刻生成，但是在上层函数返回前函数都不会被调用。

```go
package main

import "fmt"

func main() {
	defer fmt.Println("world")

	fmt.Println("hello")
}

//hello
//world
```

### defer 栈

延迟的函数调用被压入一个栈中。当函数返回时， 会按照==后进先出的顺序==调用被延迟的函数调用。

阅读[博文](http://blog.golang.org/defer-panic-and-recover)了解更多关于 defer 语句的信息。

```go
package main

import "fmt"

func main() {
	fmt.Println("counting")

	for i := 0; i < 10; i++ {
		defer fmt.Println(i)
	}

	fmt.Println("done")
}

//counting
//done
//9
//8
//7
//6
//5
//4
//3
//2
//1
//0
```




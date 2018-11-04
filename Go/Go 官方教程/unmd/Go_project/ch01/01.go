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
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
	wc.Test(WordCount)
}

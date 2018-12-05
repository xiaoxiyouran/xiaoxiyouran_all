# c++ const提高函数健壮性

```cpp
1- const提高函数的健壮性
	在函数传入引用时，防止对外进行更改。如果是值传递，则无所谓
	
2- 返回值赋给const 同类型的指针或者变量

3- 如果函数返回值采用“值传递”方式，由于函数会把返回值赋值到外部临时的存储单元中，加上const也没啥意义。所以不要把 int GetInt();改为const int GetInt();

4- 函数返回值是引用传递的场合不多，一半用在类内赋值函数中，目的是为了实现链式表达。

5- const 成员函数
	只能放在函数最后了,不会修改类的数据成员要声明为const类型。const成员函数不能更改数据成员，也不能调用其他非const成员函数。
	
6- const 对象，只能访问 const 成员函数
```



### const提高函数的健壮性

#### 参数

const只能修饰输入参数。因为输出参数的话是需要修改的，如果const修饰过后就白扯了。 const作函数的输入参数是，可以采用指针或者引用传递，用const修饰，这样就可以防止意外修改了，但是如果是值传递，即没有指针或者引用时就不需要了，因为参数复制，即使函数改了也是白改，不会影响实参。注意对于费内部数据类型的输入参数，应该将值传递改为const引用传递即void Func(A a);改为void Func(const A &a)；对于内部数据类型就没有必要改了，直接用void Func(int a);就好了，没必要加const引用了就。

#### 返回值

- const char *GetString();类似的，返回值指针所指向的内容是不能更改的 **返回值只能赋值给加了const的同类型指针** const char *str = GetString()；

- 如果函数返回值采用“值传递”方式，由于函数会把返回值赋值到外部临时的存储单元中，加上const也没啥意义。所以不要把 int GetInt();改为const int GetInt();

- 函数返回值是引用传递的场合不多，一半用在类内赋值函数中，目的是为了实现链式表达。例如：

  ```
  class A{
    A& operate= （const A &other）；//赋值函数
  }；
  ```

- A a,b,c;

- a = b = c;//可以

- **const 成员函数** 记住哦 const放在尾部，大概是其他地方都给占上了,**只能放在函数最后了,不会修改类的数据成员要声明为const类型。const成员函数不能更改数据成员，也不能调用其他非const成员函数。**形如:

```
class Stack{
    public：
    void Push(int elem);
    int Pop();
    int GetCount() const;//const成员函数private：
    int m_num;
    int m_data[100];
}；

int Stack::GetCount() const
{
    ++m_num;//error 修改了数据成员
    Pop();//error 调用了非const成员函数
}
```
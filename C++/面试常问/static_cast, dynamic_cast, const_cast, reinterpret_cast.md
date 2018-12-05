# static_cast, dynamic_cast, const_cast, reinterpret_cast

```cpp
1- 强制转换类型主要有4种，分别是 static_cast, dynamic_cast, const_cast, reinterpret_cast
    
2- const_cast:
	const_cast主要是用来修改的const和volatile属性的。
	
3- reinterpret_cast：
	把指针转成任意整数 [不安全的]
   · reinterpret_cast用在任意指针（或引用）类型之间的转换
   · 指针与足够大的整数类型之间的转换；从整数类型（包括枚举类型）到指针类型，无视大小。虽然看起来很强大，可以把任何一种类型的指针转换成另一种，但是转换完的通常是不能用的，只有通过转换回原类型的指针才能用的
    
4- static_cast：
   - 非多态类型之间的转换，不提供运行时的检查来确保安全的检查
   - 有继承的：向上安全，向下安全由程序员保证
   - 基本数据类型之间的转换，如把int转换成char，把int转换成enum等等，这种转换的安全性需要程序员来保证；
   - 把void指针转换成目标类型的指针，是及其不安全的； 
   
   注：static_cast不能转换掉expression的const、volatile和__unaligned属性。
   
5- dynamic_cast
   - 常常与type_id一起使用，来确定运行时类别，主要用于类层次之间的上行和下行转换，当然也可以用于类之间的交叉转换。
   - dynamic_cast只能转换指针类型和引用类型，不能转换其他类型。 
   - dynamic_cast用于上行转换的时候，即把子类指针（引用）转换为父类指针（引用）时跟static_cast是一样的，都是安全的。然而在进行下行转换时，* dynamic_cast具有类型检查的功能，比static_cast更加安全。在多态类型之间的转换主要使用dynamic_cast,应为类型提供运行时信息。
   - 如果一条dynamic_cast语句的转换目标是指针类型失败了，则结果为0。如果引用类型失败了，则抛出一个bad_cast的异常。 
   
   - 将基类cast到派生类时候，基类必须要有虚函数，没有虚函数不可以的。`
   
   
```



C++中的强制转换类型主要有4种，分别是static_cast, dynamic_cast, const_cast, reinterpret_cast。 我们首先来说一下比较简单的两种吧。

### const_cast

const_cast主要是用来修改的const和volatile属性的。

```
const char *pc;
char *p = const_cast<char*>(pc);//正确，但是通过p写值是未定义的行为

const_cast只能修改常量属性，不能修改其他属性。比如
const char *cp;
char *q = static_cast(char*) cp;//错误 static_cast 不能修改常量属性
static_cast<string(cp);//正确：字符串字面值转换成string类型了。
const_cast<string>(cp);//错误：const_cast只改变常量属性。
```

- 注意，指针也可以改成引用的。
- 举个例子：

```
class B
{
public:
    B() { }
public:
    int m_iNum;
};
void foo()
{
    const B b1;
    //b1.m_iNum = 100; //compile error
    // 可以做如下转换，体现出转换为指针类型
    B *b2 = const_cast<B*>(&b1);
    
    // 或者左侧也可以用引用类型，如果对b2或b3的数据成员做改变，就是对b1的值在做改变
    B &b3 = const_cast<B&>(b1);
    b2->m_iNum = 200;    //fine
    b3.m_iNum = 300;     //fine
}
int main( int argc, char * argv[] )
{
    foo();
    return 0;
}
```

使用const_cast可以返回一个指向非常量的指针（或引用）指向b1，就可以通过该指针（或引用）对它的数据成员任意改变。 注：你不能直接对非指针和非引用的变量使用const_cast操作符去直接移除它的const、volatile和__unaligned属性。

### reinterpert_cast

- 它可以把一个指针转换成一个整数，也可以把一个整数转换成一个指针。操作符修改了操作数类型，单仅仅是重新解释了给出对象的比特模型而没有进行二进制转换。
- 总结来说**reinterpret_cast用在任意指针（或引用）类型之间的转换**；以及**指针与足够大的整数类型之间的转换；从整数类型（包括枚举类型）到指针类型，无视大小。虽然看起来很强大，可以把任何一种类型的指针转换成另一种，但是转换完的通常是不能用的，只有通过转换回原类型的指针才能用的。**
- 比如:

```
int value = 10;
int *p = &value;
double *d = reinterpret_cast<double*>(p);
```

- 虽然编译不会有错误，但是你所得到的double是不可用的，它只有再转回int才可以，也就是再加上，int *q = reinterpret_cast(d); 这样就可以了。
- 最后还有一点，reinterpret_cast不能去除const和volatile属性。

### static_cast

static_cast应用非常广泛，它可以向我们之前C语言中的强制转换类型那么用，还可以继承类中用于指针的转换。static_cast主要用于**非多态类型之间的转换**，不提供运行时的检查来确保安全的检查。

##### 主要在以下几种场合中使用：

- 1.用于类层次结构中，基类和子类之间指针和引用的转换； 当进行上行转换，也就是把子类的指针或引用转换成父类表示，这种转换是安全的；当进行下行转换，也就是把父类的指针或引用转换成子类表示，这种转换是不安全的，也需要程序员来保证；
- 2.用于基本数据类型之间的转换，如把int转换成char，把int转换成enum等等，这种转换的安全性需要程序员来保证；
- 3.把void指针转换成目标类型的指针，是及其不安全的； 注：static_cast不能转换掉expression的const、volatile和__unaligned属性。

### dynamic_cast

- dynamic_cast是属于RTTI中的一部分，**常常与type_id一起使用，来确定运行时类别，主要用于类层次之间的上行和下行转换，当然也可以用于类之间的交叉转换。**
- 注意一点是，**dynamic_cast只能转换指针类型和引用类型，不能转换其他类型。 dynamic_cast用于上行转换的时候，即把子类指针（引用）转换为父类指针（引用）时跟static_cast是一样的，都是安全的。然而在进行下行转换时，**
- *** dynamic_cast具有类型检查的功能，比static_cast更加安全。在多态类型之间的转换主要使用dynamic_cast,应为类型提供运行时信息。**
- 如果一条dynamic_cast语句的转换目标是指针类型失败了，则结果为0。如果引用类型失败了，则抛出一个bad_cast的异常。 
- 最后注意将基类cast到派生类时候，基类必须要有虚函数，没有虚函数不可以的。
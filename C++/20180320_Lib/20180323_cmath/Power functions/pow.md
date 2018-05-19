# pow

C++ 11 函数原型

```cpp
double pow (double base     , double exponent);
float pow (float base      , float exponent);
long double pow (long double base, long double exponent);
double pow (Type1 base      , Type2 exponent);        	// additional overloads
```

返回的就是：`base^exponent`

要注意：

base： 有限负数。 base =0, 会产生一个错误。

exponent: 有限数，但不是整数，会产生误差。

- 如果base = 0. exponent 是个负数，会产生domain error. 或者 pole error(极差) (or none, depending on the library implementation).
- 结果太多或者太小，都会导致范围错误。



```cpp
/* pow example */
#include <stdio.h>      /* printf */
#include <math.h>       /* pow */

int main ()
{
    printf ("7 ^ 3 = %f\n", pow (7.0, 3.0) );               // 7 ^ 3 = 343.000000
    printf ("4.73 ^ 12 = %f\n", pow (4.73, 12.0) );         // 4.73 ^ 12 = 125410439.217423
    printf ("32.01 ^ 1.54 = %f\n", pow (32.01, 1.54) );     // 32.01 ^ 1.54 = 208.036691
    
    /// special test.
    printf("0^0 = %f\n", pow(0,0));                         // 0^0 = 1.000000
    printf("0^-1 = %f\n", pow(0,-1));                       // 0^-1 = 1.#INF00
    

    return 0;
}
```


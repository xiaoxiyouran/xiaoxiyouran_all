# log

这是自然对数

C++ 11 函数原型如下：

```cpp
     double log (double x);
      float log (float x);
long double log (long double x);
     double log (T x);           // additional overloads for integral types
```

Returns the *natural logarithm* of x.

The natural logarithm is the base-e logarithm: the inverse of the natural exponential function ([exp](http://www.cplusplus.com/exp)). For common (base-10) logarithms, see [log10](http://www.cplusplus.com/log10).



测试

```cpp
/* log example */
#include <stdio.h>      /* printf */
#include <math.h>       /* log,M_E,M_PI */

int main ()
{
    double param, result;
    param = 5.5;
    result = log (param);
    printf ("log(%f) = %f\n", param, result );      // log(5.500000) = 1.704748
    printf ("log(%f) = %f\n", 10.0, log( 10 ) );    // log(10.000000) = 2.302585

    printf ("log(%c) = %f\n", 'e', log(M_E) );      // log(e) = 1.000000

    return 0;
}
```


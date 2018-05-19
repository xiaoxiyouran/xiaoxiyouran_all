# sqrt

C++11 中的函数原型如下：

```cpp
     double sqrt (double x);
      float sqrt (float x);
long double sqrt (long double x);
     double sqrt (T x);           // additional overloads for integral types
```

会先将T类型转成 double 类型？

*Additional overloads* are provided in this header (`<cmath>`) for the [integral types](http://www.cplusplus.com/is_integral): These overloads effectively cast `x` to a `double` before calculations (defined for T being any *integral type*).

This function is also overloaded in `<complex>` and `<valarray>` (see [complex sqrt](http://www.cplusplus.com/complex:sqrt) and [valarray sqrt](http://www.cplusplus.com/valarray:sqrt)).



测试

```cpp
/* sqrt example */
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */

int main ()
{
  double param, result;
  param = 1024.0;
  result = sqrt (param);
  printf ("sqrt(%f) = %f\n", param, result );	// sqrt(1024.000000) = 32.000000
  return 0;
}
```




# log10

在C++ 11 中的函数原型：

```cpp
      double log10 (double x);
      float log10 (float x);
long double log10 (long double x);
     double log10 (T x);           // additional overloads for integral types
```

*Additional overloads* are provided in this header (`<cmath>`) for the [integral types](http://www.cplusplus.com/is_integral): These overloads effectively cast `x` to a `double` before calculations.【自动将类型转为double类型】

This function is also overloaded in `<complex>` and `<valarray>` (see [complex log10](http://www.cplusplus.com/complex:log10) and [valarray log10](http://www.cplusplus.com/valarray:log10)).

测试

```cpp
/* log10 example */
#include <stdio.h>      /* printf */
#include <math.h>       /* log10 */

int main ()
{
  double param, result;
  param = 1000.0;
  result = log10 (param);
  printf ("log10(%f) = %f\n", param, result );		// log10(1000.000000) = 3.000000
  return 0;
}
```


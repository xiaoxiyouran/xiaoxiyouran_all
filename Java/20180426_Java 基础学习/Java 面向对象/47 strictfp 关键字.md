# 47 strictfp 关键字



Java `strictfp`关键字确保您将在每个平台上获得相同的结果，如果**在浮点变量中执行操作。 不同平台的精度可能不同**，这就是为什么java编程语言提供了`strictfp`关键字，它用于在每个平台上获得相同的结果。 所以，现在我们就可以更好的控制浮点数据类型运算了。

**strictfp关键字的全法代码**

`strictfp`关键字**可以应用于方法，类和接口**。

```  Java
strictfp class A{}		//strictfp applied on class  

strictfp interface M{}	//strictfp applied on interface  

class B{  
    strictfp void m(){}	//strictfp applied on method  
}
```

**strictfp关键字的非法代码**

`strictfp`关键字**不能应用于抽象方法，变量或构造函数**。

```java
class B{  
    strictfp abstract void m();//Illegal combination of modifiers  
}  

class B1{  
    strictfp int data=10;//modifier strictfp not allowed here  
}  

class B2{  
    strictfp B(){}//modifier strictfp not allowed here  
}
```
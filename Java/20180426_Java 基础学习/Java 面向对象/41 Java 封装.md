# 41 Java 封装

java中的封装是将代码和数据一起封装到单个单元中的过程，例如胶囊，即几种药物的混合。

我们可以通过将类的所有数据成员设为`private`，以在java中创建一个完全封装的类。现在我们可以使用`setter`和`getter`方法来设置和获取其中的数据。

Java Bean类是完全封装类的示例。

## 在java中封装的优势

通过仅提供`setter`或`getter`方法，可以使类为只读或只写。
它为您提供对数据的控制。 假设要设置`id`的值，即：要求大于`100`，您可以在`setter`方法内写入逻辑。

**在java中封装的简单示例**

让我们来看看一个简单的封装示例，它只有一个字段及其`setter`和`getter`方法。

```  Java
//save as Student.java  
package com.yiibai;

public class Student {
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
```

`Test.java` 的代码如下 -

```  Java
//save as Test.java  
package com.yiibai;

class Test {
    public static void main(String[] args) {
        Student s = new Student();
        s.setName("vijay");
        System.out.println(s.getName());
    }
}
```

**编译:** `javac -d . Test.java`
**运行:** `java com.yiibai.Test`

上面代码输出结果如下 -

```  Java
vijay
```
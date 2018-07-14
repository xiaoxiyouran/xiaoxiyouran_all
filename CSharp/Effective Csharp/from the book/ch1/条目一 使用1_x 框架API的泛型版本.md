# 条目一 使用1_x 框架API的泛型版本

1- .NET 平台的头两个版本并不支持泛型，因此只能基于 System.Object 来编码， 并通过必要的 ==运行时检查保证程序的正确性==。

传统的弱类型系统两大缺点：

- 1.1 版本的任何类/接口 都需要在进行 ==值类型 和 System.Object 转换的过程中执行 装箱/拆箱操作==。
- 使用 System.Object 需要很多检查类型的代码保证参数和返回值类型的正确

而在类型转换失败时的开销会更大： 包括 ==栈审核（stack walk） 和转换异常时的 栈解退（stack unwinding）==、运行时定位 catch 语句等。

<br>

2- `System.Collections` 命名空间中的类在 .NET Framework 2.0 中都提供了新的版本；

如 `System.Collections.Generic` 和 `System.Collections.ObjectModel`;

下表列出一些替代品：

| .NET 1.x  | .NET 2.x          |
| --------- | ----------------- |
| ArrayList | `List<T>`         |
| Stack     | `Stack<T>`        |
| Hashtable | `Dictionary<K,V>` |
| Queue     | `Queue<T>`        |








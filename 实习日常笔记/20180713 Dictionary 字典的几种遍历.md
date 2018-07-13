# 20180713 Dictionary 字典的几种遍历



```csharp
  Dictionary<string, int> list = new Dictionary<string, int>();
  list.Add("d", 1); 

  //3.0以上版本
  foreach (var item in list)
  {
      Console.WriteLine(item.Key + item.Value);
  }

  //KeyValuePair<T,K>
  foreach (KeyValuePair<string, int> kv in list)
  {
      Console.WriteLine(kv.Key + kv.Value);
  }

  //通过键的集合取
  foreach (string key in list.Keys)
  {
      Console.WriteLine(key + list[key]);
  }

  //直接取值
  foreach (int val in list.Values)
  {
      Console.WriteLine(val);
  } 

  //非要采用for的方法也可

  List<string> test = new List<string>(list.Keys);

  for (int i = 0; i < list.Count; i++)
  {
      Console.WriteLine(test[i] + list[test[i]]);
  }
```


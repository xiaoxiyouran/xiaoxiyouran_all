# 20180723HTTPConnection 



httplib是一个相对底层的http请求模块，其上有专门的包装模块，如urllib内建模块，goto等第三方模块，但是封装的越高就越不灵活，比如urllib模块里请求错误时就不会返回结果页的内容，只有头信息，对于某些需要检测错误请求返回值的场景就不适用，所以就得用这个模块了。

1、class httplib.HTTPConnection

说明： 

该类用于创建一个http类型的请求链接

 原型： 

HTTPConnection(host[, port[, strict[, timeout]]])

- host: 请求的服务器host，不能带http://开头
- port: 服务器web服务端口 
- strict: 是否严格检查请求的状态行，就是http1.0/1.1 协议版本的那一行，即请求的第一行，默认为False，为True时检查错误会抛异常 
- timeout: 单次请求的超时时间，没有时默认使用httplib模块内的全局的超时时间

  

```python
实例：
conn1 = HTTPConnection('www.baidu.com:80')
conn2 = HTTPconnection('www.baidu.com',80)
conn3 = HTTPConnection('www.baidu.com',80,True,10)

错误实例：
conn3 = HTTPConnection('www.baidu.com:80',True,10)
```

   <br>

返回： 

- HTTPConnection类会实例并返回一个HTTPConnection对象

 

2、class httplib.HTTPSConnection 

说明： 

该类用于创建一个https类型的请求链接 

原型：

HTTPSConnection(host[, port[, key_file[, cert_file[, strict[, timeout]]]]])

- key_file:一个包含PEM格式的私钥文件
- cert_file:一个包含PEM格式的认证文件 

- other：其它同http参数

  <br>

实例： 

```python
conn3 = HTTPSConnection('accounts.google.com',443,key_file,cert_file,True,10)
```

 返回： 

同样返回一个HTTPSConnection对象 

 <br>

注意：

要创建https链接，必须要保证底层的socket模块是支持ssl的编译模式，即编译时ssl选项的开关是开着的

 <br> 

3、HTTPConnection对象request方法：

 说明：

 发送一个请求

 原型：

 conn.request(method, url[, body[, headers]])

- method: 请求的方式，如'GET','POST','HEAD','PUT','DELETE'等
- url: 请求的网页路径。如：'/index.html'
- body: 请求是否带数据，该参数是一个字典
- headers: 请求是否带头信息，该参数是一个字典，不过键的名字是指定的http头关键字

 <br>

实例：

```python
conn.request('GET', '/', '', {'user-agent':'test'})
```

<br> 

返回： 

无返回，其实就是相对于向服务其发送数据，但是没有最后回车

 <br>

 

4、HTTPConnection对象getresponse方法

 说明：

 获取一个http响应对象，相当于执行最后的2个回车

 原型/实例：

```python
res = conn.getresponse()
```

 返回：

 HTTPResponse对象

 <br> 

5、HTTPConnection对象close()方法

 说明：

 关闭指定的httpconnect链接

 实例：

```python
conn.close()
```

<br> 

 6、HTTPResponse对象read方法

 说明：

 获得http响应的内容部分，即网页源码

 原型：

 ```python
body = res.read([amt])
 ```

amt: 读取指定长度的字符，默认为空，即读取所有内容

实例：

```python
body = res.read()
pbody = res.read(10)
```

 返回：

 网页内容字符串 

 <br>

7、HTTPResponse对象的其它方法或属性

 方法：

 getheaders()

 获得所有的响应头内容，是一个元组列表[(name,value),(name2,value2)]

 getheader(name[,default])

 获得指定的头内容

 fileno()

 socket的fileno

  <br>

属性：

 msg

 所有的头信息，和getheaders方法一样，只不过这个是原始未处理的字符串

 status

 当次请求的状态

version

当次请求的http协议版本，10是http1.0, 11是http/1.1

reason

当次请求的结果的表述内容，200是ok，404是Not Found

 <br>

总体实例： 

```python
#!/usr/bin/env python  
# -*- coding: utf-8 -*-  
import httplib
import urllib
def sendhttp():
    data = urllib.urlencode({'@number': 12524, '@type': 'issue', '@action': 'show'})   
    headers = {"Content-type": "application/x-www-form-urlencoded",
               "Accept": "text/plain"}
	try:
    conn = httplib.HTTPConnection('bugs.python.org')	# 注意这个是请求的服务器主机地址

    conn.request('POST', '/', data, headers)			# '/' url 是服务器上的地址
    httpres = conn.getresponse()
    
    body = httpres.read()		# 可以获取读取的内容
    
    if httpres.status !=200:	# 通过返回的状态码判断状态
        print "error."
    d = json.load(body)			# 用来解析 body
    if d["status"]!= 1:
        print "http 请求失败"
        exit(1)
    return d					# d["data"] 属性应该是获取 ‘/’ 目录下的所有文件名。
    print httpres.status
    print httpres.reason
    print httpres.read()         
	
    finally:
        if con:
            conn.close();


if __name__ == '__main__': 
	sendhttp() 
```

 


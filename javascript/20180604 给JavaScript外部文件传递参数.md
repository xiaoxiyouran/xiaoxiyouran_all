# 20180604 给JavaScript外部文件传递参数



------

原文：https://blog.csdn.net/risingsun001/article/details/9123453

#### 一、利用全局变量

在页面中引入全局变量

```javascript
<script type="text/javascript">  
var  p = "test";  
</script>  
<script type="text/javascript" src="test.js"></script>  
```

 在外部文件test.js中访问

```javascript
/*显示结果*/  
alert(params); 
```

这个方法算是最简单的了吧。

#### 二、获取并解析script元素的src

和全部变量相比，我们直接能像下面这样传入参数：

```javascript
<script type="text/javascript" src="test.js?a=b&c=d"></script>  
```

利用js的顺序执行机制：js文件的加载可以是同步或异步方式，但执行时，一定是按照在==文档流中的顺序==来执行的。怎么理解呢？

因为JS是==顺序解析==的，当前JS脚本解析时==后面的js都还没有解析到，当然就认为自己就是最后一个script了==，也就是说当某个js文件执行时，一定是“已加载”的js文件中的最后一个。此外，这样获取还有一个好处：我们可以==多次引用同一个文件且传入不同的参数==，这样可以在js文件中根据参数不同做不同处理。

```javascript
var scripts = document.getelementsbytagname('script');  
var currentscript = scripts[scripts.length - 1];  
```

得到这个就好办了，通过curJS.src即可获取到完整的路径内容（包括参数）。
下面的就是解析参数内容了，解析的过程相当简单，相信很多人都容易完成这一步。
但我们要对一个特殊情况进行处理：如果一个参数被传入了多次，则要将该参数值转换为数组存储每一个传入的值。

**完整测试脚本如下（来自互联网）：**

```javascript
 var getArgs=(function(){  
    var sc=document.getElementsByTagName('script');  
    var paramsArr=sc[sc.length-1].src.split('?')[1].split('&');  
    var args={},argsStr=[],param,t,name,value;  
    for(var i=0,len=paramsArr.length;i<len;i++){  
            param=paramsArr[i].split('=');  
            name=param[0],value=param[1];  
            if(typeof args[name]=="undefined"){ //参数尚不存在  
                args[name]=value;  
            }else if(typeof args[name]=="string"){ //参数已经存在则保存为数组  
                args[name]=[args[name]]  
                args[name].push(value);  
            }else{  //已经是数组的  
                args[name].push(value);  
            }  
    }  
    /*在实际应用中下面的showArg和args.toString可以删掉，这里只是为了测试函数getArgs返回的内容*/  
    var showArg=function(x){   //转换不同数据的显示方式  
        if(typeof(x)=="string"&&!//d+/.test(x)) return "'"+x+"'";   //字符串  
        if(x instanceof Array) return "["+x+"]" //数组  
        return x;   //数字  
    }  
    //组装成json格式  
    args.toString=function(){  
        for(var i in args) argsStr.push(i+':'+showArg(args[i]));  
        return '{'+argsStr.join(',')+'}';  
    }  
    return function(){return args;} //以json格式返回获取的所有参数  
})();  
  
alert(getArgs());  
alert("username:"+getArgs()["username"]);  
```



测试html代码：

```javascript
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">  
<html xmlns="http://www.w3.org/1999/xhtml">  
<head>  
  <title> new document </title>  
  <meta name="generator" content="editplus" />  
  <meta name="author" content="" />  
  <meta name="keywords" content="" />  
  <meta name="description" content="" />  
  <script type="text/javascript" src="test.js?id=4&username=yemoo&id=1&uid=110"></script>  
  <script type="text/javascript" src="test.js?id=5&username=ajaxbbs&id=7&uid=253"></script>  
  <script type="text/javascript" src="test.js?id=6&username=jack&id=8&uid=258"></script>  
</head>  
<body>  
</body>  
</html>  
```



#### 三、使用id和自定义属性传参

使用方法：

```
<script id="testscript" type="text/javascript" src="test.js" data="a=b&c=d"></script>
```

test.js获取参数方法一：

```javascript
var getscript = document.getelementbyid('testscript')  
```

得到 getscript 的DOM对象，我们就可以利用上面的方法来得到值了。

test.js获取参数方法二：

```javascript
var scriptargs = document.getElementbyid('testscript').getAttribute('data'); 
```

通过这个方法我们可以得到 data的字符串，然后使用“&”分割，得到值。

当然，最简单方法是我们可以有多个自定义属性，然后通过getAttribute 得到每个自定义属性的值，这样就很方便了。

 
# 02 Vector Space Model_Improved Instantiation

![image-20181017155714849](/Users/cookie/Library/Application Support/typora-user-images/image-20181017155714849.png)



![image-20181017161046255](image-20181017161046255.png)





![image-20181017161059550](image-20181017161059550.png)

![image-20181017161259928](image-20181017161259928.png)



![image-20181017161632671](image-20181017161632671.png)



![image-20181017161710438](image-20181017161710438.png)



![image-20181017162044642](image-20181017162044642.png)

![image-20181017162609926](image-20181017162609926.png)

![image-20181017163036640](image-20181017163036640.png)



![image-20181017163112051](image-20181017163112051.png)

<br>

## TF transformation

太多的重复单词会造成误搜索

![image-20181017164530638](image-20181017164530638.png)



![image-20181017164944456](image-20181017164944456.png)



最好的函数是下面这个

![image-20181017185456549](image-20181017185456549.png)

![image-20181017185700864](image-20181017185700864.png)

![image-20181017185752539](image-20181017185752539.png)

<br>

## Doc Length Normalization

![image-20181017190005939](image-20181017190005939.png)

旋转长度归一化：

![image-20181017190320160](image-20181017190320160.png)

调整b的值

![image-20181017190737740](image-20181017190737740.png)

![image-20181017191028875](image-20181017191028875.png)



![image-20181017191417690](image-20181017191417690.png)



![image-20181017191526521](image-20181017191526521.png)



![image-20181017191803438](image-20181017191803438.png)

![image-20181017191939695](image-20181017191939695.png)

<br>

##  Implementation of TR Systems

![image-20181017192156891](image-20181017192156891.png)



![image-20181017192408152](image-20181017192408152.png)





![image-20181017192517256](image-20181017192517256.png)

![image-20181017192750795](image-20181017192750795.png)

![image-20181017193446304](image-20181017193446304.png)



![image-20181017193710009](image-20181017193710009.png)

![image-20181017193755951](image-20181017193755951.png)



![image-20181017194009364](image-20181017194009364.png)

![image-20181017194359615](image-20181017194359615.png)

<br>

## System Implementation - Inverted Index Construction

![image-20181018131914673](image-20181018131914673.png)

困难是如何建立倒排索引：

![image-20181018131951113](image-20181018131951113.png)

![image-20181018133305731](image-20181018133305731.png)

用可边长编码进行压缩：

![image-20181018133714027](image-20181018133714027.png)

![image-20181018150239631](image-20181018150239631.png)

![image-20181018151024988](image-20181018151024988.png)

<br>

## System Implementation - Fast Search

未完： https://www.coursera.org/learn/text-retrieval





<br>

## 参考

0- [利用悟空搜索引擎- 原理及使用](http://blog.jobbole.com/110293/) 

1- https://blog.csdn.net/shijing_0214/article/details/50909082

2- [搜索引擎倒排索引表压缩：gamma编码](https://blog.csdn.net/u014495327/article/details/44139155) 

3- [Lucene 和 solr 全文检索 51cto 视频](http://edu.51cto.com/topic/842.html?source=so)

4- [Github - simple-search](https://github.com/rahulmutt/simple-search) 

5- [gigablast - **Github- giopen-source-search-engine**](https://github.com/gigablast/open-source-search-engine)  这个强大倒是蛮强大的，但是没有跑起来啊， 可以试一下在linux下的运行；

6- [用Python实现一个大数据搜索引擎](https://my.oschina.net/taogang/blog/1579204) 

7- [做一个简单的搜索引擎，需要哪些知识和技术](https://www.zhihu.com/question/29271575) 

在这里提到了， 自定义搜索引擎，可以用[whoosh](https://whoosh.readthedocs.io/en/latest/quickstart.html) 

8- [怎样实现一个搜索引擎](https://my.oschina.net/felingdev/blog/393170) 







​	
























































































































































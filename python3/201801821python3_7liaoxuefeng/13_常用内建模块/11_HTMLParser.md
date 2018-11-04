# HTMLParser

如果我们要编写一个搜索引擎，第一步是用爬虫把目标网站的页面抓下来，第二步就是==解析该HTML页面==，看看里面的内容到底是新闻、图片还是视频。

假设第一步已经完成了，第二步应该如何解析HTML呢？

HTML本质上是XML的子集，但是==HTML的语法没有XML那么严格==，所以不能用标准的DOM或SAX来解析HTML。

好在Python提供了HTMLParser来非常方便地==解析HTML==，只需简单几行代码：

```python
from html.parser import HTMLParser
from html.entities import name2codepoint

class MyHTMLParser(HTMLParser):

    def handle_starttag(self, tag, attrs):
        print('<%s>' % tag)

    def handle_endtag(self, tag):
        print('</%s>' % tag)

    def handle_startendtag(self, tag, attrs):
        print('<%s/>' % tag)

    def handle_data(self, data):
        print(data)

    def handle_comment(self, data):
        print('<!--', data, '-->')

    def handle_entityref(self, name):
        print('&%s;' % name)

    def handle_charref(self, name):
        print('&#%s;' % name)

parser = MyHTMLParser()
parser.feed('''<html>
<head></head>
<body>
<!-- test html parser -->
    <p>Some <a href=\"#\">html</a> HTML&nbsp;tutorial...<br>END</p>
</body></html>''')
```

`feed()`方法可以多次调用，也就是==不一定一次把整个HTML字符串都塞进去，可以一部分一部分塞进去==。

特殊字符有两种，一种是==英文表示的`&nbsp;`，一种是数字表示的`&#1234;`，这两种字符都可以通过Parser解析==出来。

<br>

## 小结

利用HTMLParser，可以把网页中的文本、图像等解析出来。

<br>

## 练习

 找一个网页，例如<https://www.python.org/events/python-events/>，用浏览器查看源码并复制，然后尝试解析一下HTML，输出Python官网发布的会议时间、名称和地点。

方法1：

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/13.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'


from html.parser import HTMLParser
from urllib import request
import re

class MyHTMLParser(HTMLParser):
    def __init__(self):
        super(MyHTMLParser,self).__init__()
        self.j_time = False #这些布尔值是为了在handle_data里作处理data的判断条件。
        self.j_title = False
        self.j_location = False
        self.j_year = False
        self.all_info=[]

    def handle_starttag(self, tag, attrs):
        if tag == 'span' and ('class','say-no-more') in attrs:
            self.j_year=True
        elif tag == 'span' and ('class','event-location') in attrs:
            self.j_location=True
        elif tag == 'h3' and ('class','event-title') in attrs:
            self.j_title=True
        elif tag == 'time':
            self.j_time=True

    def handle_data(self,data):
        if self.j_year is True:   #经大佬提醒这里很关键，要给个正则约束年份只读数字进去。[0-9]就是只读数字。否则会读出两个莫名其妙的字符。
            if re.match(r'[0-9]',data.strip()):
                self.all_info.append(dict(年份=data))
        elif self.j_time is True:
            self.all_info.append(dict(时间=data))
        elif self.j_location is True:
            self.all_info.append(dict(地点=data))
        elif self.j_title is True:
            self.all_info.append(dict(会议主题=data))

    #这里还是不太理解，不过不这样的话，读出来都是乱了的，有始有终？?
    def handle_endtag(self,tag):
        if tag == 'time':
            self.j_time=False
        elif tag=='span':
            self.j_year=False
            self.j_location=False
        elif tag== 'h3':
            self.j_title=False

    def handle_startendtag(self, tag, attrs):
        '''
        处理 <br /> 这种标签的
        :param tag: 
        :param attrs: 
        :return: 
        '''
        pass

def deal(content):
    cope=MyHTMLParser()
    cope.feed(content)
    count=0       #这里可以用大佬的enumerate（枚举）
    for i in cope.all_info:
        count += 1
        print(i) # 每次打印一个字典
        if count % 4 == 0:
            print('-------------------------------------------------')

with request.urlopen('https://www.python.org/events/python-events/') as f:
    Data = f.read()

print(deal(Data.decode('utf-8')))
```

<br>

方法2：

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'''
filename: ch13/12.py
message: notes for liaoxuefeng in learning pyhon 3.7
'''

__author__ = 'xi'

import requests
from lxml import html
def fetchWebData(url):
    page = requests.get(url)
    tree = html.fromstring(page.text)
    print(tree)
    titles=tree.xpath('//h3[@class="event-title"]/a/text()')
    times=tree.xpath('//h3/../p/time/@datetime')
    locations=tree.xpath('//span[@class="event-location"]/text()')
    processdata=map(lambda x,y,z:{'event-title':x,'event-time':y,'event-location':z} ,titles,times,locations)
    for n in processdata:
        print (n)

fetchWebData('https://www.python.org/events/python-events/')
```


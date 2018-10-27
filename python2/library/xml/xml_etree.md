# Xml.etree

为了举一个例子， 修改了一个xml 文件`outttt.xml`， 如下所示：

```xml
<?xml version='1.0' encoding='UTF-8'?>
<root>
  <item>
    <重要性>普通</重要性>
    <标题>QQ授权登录</标题>
    <用户名>QQ授权登陆追信 QQ授权登陆Lofter博客</用户名>
    <帐号 />
    <密码 />
    <相关网址 />
    <备注 />
  </item>
  <item>
    <重要性>普通</重要性>
    <标题>枫林樵夫……秋木</标题>
    <用户名 />
    <帐号>2864542775</帐号>
    <密码>xs451911224</密码>
    <相关网址 />
    <备注 />
  </item>
</root>

```

那么读xml 文件和写xml 文件的一个实例如下：

加密和解密的东西可以先不看， 如果想看，可以参照`Library/Crypto` 或者码云上的password 项目:

```python
#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
filename: xml_etree.py
message: parse xml with ElementTree(元素树)
'''

__author__ = 'xi'

# from xml.etree import ElementTree as ET
# xml = """<books>
# <book id='37476'>aaaa</book>
# <book id='83727'>bbbb</book>
# </books>"""
#
# root = ET.fromstring(xml)
# print root.tag              # books
# child = root.getchildren()
# print child                 # [<Element 'book' at 0x103511710>, <Element 'book' at 0x103511750>]
# print child[0].tag          # book
# print child[0].attrib       # {'id': '37476'}
# print child[0].text         # aaaa


from xml.etree import ElementTree as ET
from xml.etree.ElementTree import Element,ElementTree
import collections


class Etree:
    def __init__(self, read_xml_file_name = '', write_xml_file_name = ''):
        self._read_xml_file_name = read_xml_file_name
        self._write_xml_file_name = write_xml_file_name
        self._tree=[]
        self._root_name = ""
        self._second_name = ""

    def getTree(self):
        return self._tree

    def read_xml(self, filename=''):
        l_filename = filename
        if not l_filename:
            l_filename = self._read_xml_file_name
        tree = ET.parse(l_filename)
        root = tree.getroot()
        # root = ET.fromstring(country_data_as_string) #通过字符串导入,直接获取根
        self._root_name = root.tag # root 标签

        childs = root.getchildren()


        for child0 in childs:
            second = collections.OrderedDict()    # 有序字典， 保持标签的顺序
            self._second_name = child0.tag
            for child00 in child0.getchildren():
                # print child00.tag #标签名，即name、date、price、description
                # print child00.text
                second[self.unicode2str(child00.tag)] = self.unicode2str(child00.text)
            self._tree.append(second)


    def write_xml(self, tree = [], filename = '', rootname = '', secondname = ''):
        l_filename = filename
        if not l_filename:
            l_filename = self._write_xml_file_name

        l_rootname = rootname
        if not l_rootname:
            l_rootname = self._root_name

        l_secondname = secondname
        if not l_secondname:
            l_secondname = self._second_name

        l_tree = tree
        if not l_tree:
            l_tree = self._tree

        def indent(elem, level=0):
            """美化写入文件的内容"""
            i = "\n" + level * "  "
            if len(elem):
                if not elem.text or not elem.text.strip():
                    elem.text = i + "  "
                if not elem.tail or not elem.tail.strip():
                    elem.tail = i
                for elem in elem:
                    indent(elem, level + 1)
                if not elem.tail or not elem.tail.strip():
                    elem.tail = i
            else:
                if level and (not elem.tail or not elem.tail.strip()):
                    elem.tail = i

        root = Element(l_rootname)
        tree = ElementTree(root)

        for second in l_tree:   # 遍历list
            child0 = Element(l_secondname)
            root.append(child0)

            for k, v in second.items(): # 遍历内部字典
                child00 = Element(self.str2unicode(k)) if k else k 
                child00.text = self.str2unicode(v) if v else v
                child0.append(child00)

        indent(root, 0)
        tree.write(l_filename, 'UTF-8')


    def str2unicode(self, val):
        return val.decode('utf-8')

    def unicode2str(self, val):
        if isinstance(val, unicode):
            return val.encode('utf-8')
        else:
            return val

    def code_transfer(self, val):
        if isinstance(val, unicode):
            return self.unicode2str(val)
        else:
            return val

    def encrpy_xml(self, prpcrypt):
        '''
        将 prpcrypt 对象传递进来， 对每个键和值进行加密
        :param prpcrypt: 加密的对象
        :return:
        '''
        encrpy_list = []
        for second in self._tree:  # 遍历list
            second_content = collections.OrderedDict()
            for k, v in second.items():  # 遍历内部字典
                k_new = self.code_transfer(k)       #prpcrypt.encrypt(self.code_transfer(k))
                v_new = prpcrypt.encrypt(self.code_transfer(v))
                second_content[k_new] = v_new
            encrpy_list.append(second_content)

        self._tree = encrpy_list

    def decrpy_xml(self, prpcrypt):
        '''
        解密文档
        :param prpcrypt: 含秘钥的  prpcrypt 对象
        :return:
        '''
        encrpy_list = []
        for second in self._tree:  # 遍历list
            second_content = collections.OrderedDict()
            for k, v in second.items():  # 遍历内部字典
                k_new = self.code_transfer(k)
                v_new = prpcrypt.decrypt(v)
                second_content[k_new] = v_new
            encrpy_list.append(second_content)

        self._tree = encrpy_list


if (__name__ == "__main__"):
    boj = Etree("outttt.xml", "write.xml")
    boj.read_xml()
    boj.write_xml()

############################################################
# 写xml文件
# from xml.etree.ElementTree import Element,ElementTree
#
# books = [
#     {
#         'name': u'Python黑帽子',
#         'date': '2015',
#         'price': u'37￥',
#         'description': u'用python写一些程序'
#     },
#     {
#         'name': u'Web安全深度剖析',
#         'date': '2014',
#         'price': u'39￥',
#         'description': u'讲述web渗透的基础知识'
#     },
#     {
#         'name': u'白帽子讲web安全',
#         'date': '2013',
#         'price': u'44￥',
#         'description': u'道哥力作'
#     }
# ]
```



<br>

## 参考

1-   [Python SAX 处理XML文件](https://blog.csdn.net/whiterbear/article/details/27567627)

2- [ PYTHON解析XML大文件[SAX]](http://www.wklken.me/posts/2012/04/07/python-xml-sax.html)

3- [Python：使用基于事件驱动的SAX解析XML](https://www.cnblogs.com/hongfei/p/python-xml-sax.html) 

4- [使用Python读写xml文件](https://www.jianshu.com/p/b916052bec4e) 

5- [Python 读写XML文件](https://blog.csdn.net/qq_878799579/article/details/74294503) 

6- [Python解析XML](https://www.jianshu.com/p/3cd13dacb9a1) 

7- [用 ElementTree 在 Python 中解析 XML](https://pycoders-weekly-chinese.readthedocs.io/en/latest/issue6/processing-xml-in-python-with-element-tree.html) 

8- [Python XML解析](http://www.runoob.com/python/python-xml.html) 












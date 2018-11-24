# VMware 通过主机shadowsocks代理上网

## 环境

- 宿主：windows 7
- VM: kali linux(基本上linux系统都可以)

## 步骤

1. 在宿主机windows上运行shadowsocks.exe并勾选“允许局域网连接”
2. 使用桥接方式运行虚拟机（这时虚拟机与宿主处于同一个局域网）
3. 进入linux系统，System Settings – Network – Network proxy勾选Manual（手动）,地址全部填宿主机IP（局域网网段）【填Windows的ip地址即可】，设置好代理端口（可在windows下的shadowsocks查看，一般为默认1080）
4. linux用浏览器访问www.google.com，成功

就这个简单的操作折腾了好久，又是配置NAT，又是用fiddle的，试了很多种方法都不行，最后居然

<br>

## 参考

https://blog.csdn.net/u010726042/article/details/53187937


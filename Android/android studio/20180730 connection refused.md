# 20180730 connection refused

打开项目时，发现这个错误，在项目顶层的 gradle.properties 文件中发现如下代理，取消即可：

```shell
#systemProp.https.proxyHost=127.0.0.1
#systemProp.https.proxyPort=2020
#systemProp.http.proxyHost=127.0.0.1
#systemProp.http.proxyPort=2020
#systemProp.http.proxyUser=20speed222870
#systemProp.http.proxyPassword=byebye1
#systemProp.https.proxyUser=20speed222870
#systemProp.https.proxyPassword=byebye1
```


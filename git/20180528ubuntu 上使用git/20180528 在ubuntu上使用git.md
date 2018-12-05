# 20180528 在ubuntu上使用git



安装git的过程就省略了。

<br>

## 添加公钥

如果不添加公钥，会在clone的时候发生如下错误：

```shell
xi@xi-ubuntu16:~$ git clone https://gitee.com/xiaoxiyouran/Power-Model.git
正克隆到 'Power-Model'...
Username for 'https://gitee.com': xiaoxiyouran
Password for 'https://xiaoxiyouran@gitee.com': 
fatal: Authentication failed for 'https://gitee.com/xiaoxiyouran/Power-Model.git/'

```

查询本地公钥并添加：

```shell
xi@xi-ubuntu16:~$ cd ~/.ssh/
xi@xi-ubuntu16:~/.ssh$ ls
id_rsa  id_rsa.pub  known_hosts

xi@xi-ubuntu16:~/.ssh$ cat id_rsa.pub 
ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQC8BHZMBOXkEQAHbNDl5Cfld2xxQmHviZv9k7UsRzYMIpB5YF3EmficMxsd+4D/7SV/59of4cCnZKMSUZnX681ejE+PYO1+Pg0add6C3+ElPzxDfN31k9udcVQK7uXTvIWp1ymWaweNXg81iSf7ZNu3fjrB1homwphryOlAorsznLdJdB8HrcwIeUIns2ZoRQedjsaPF6Zipyt0aI012rJ4QZ+0IB15GH20Ju/tl7uJ0BWL4NisAk6pwb8sqn033KcIoFY24/rbGG6RxmeD1N8fueG+4snxxv/Pusvjz0VqlauLSOxzxrfusZI1T1K8ouQyrFEQtNG8SMhoeCn85d2H 247700529@qq.com

```



## 参考

[如何在ubuntu下使用Github？](https://blog.csdn.net/tina_ttl/article/details/51326684)

[git和github在ubuntu上的使用](https://blog.csdn.net/u012526120/article/details/49401871)


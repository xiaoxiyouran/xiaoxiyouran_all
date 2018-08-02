# 20180802 win Permission denied publickey

## 问题出现的原因

今天在Windows上， git clone 时出现如下错误：

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
$ git remote -v
origin  git@gitee.com:xiaoxiyouran/Learning-Notes-For-Xi_1.git (fetch)
origin  git@gitee.com:xiaoxiyouran/Learning-Notes-For-Xi_1.git (push)

xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
$ git pull origin master
Permission denied (publickey).
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.

xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)

```

## 调试过程

调试的过程参考了： https://www.cnblogs.com/myworld2018/p/9178922.html

 ### 测试ssh连接是否成功



```shell
$ ssh -v git@gitee.com
OpenSSH_7.3p1, OpenSSL 1.0.2h  3 May 2016
debug1: Reading configuration data /etc/ssh/ssh_config
debug1: Connecting to gitee.com [120.55.226.24] port 22.
debug1: Connection established.
debug1: identity file /c/Users/xiaoxi/.ssh/id_rsa type 1
debug1: key_load_public: No such file or directory
debug1: identity file /c/Users/xiaoxi/.ssh/id_rsa-cert type -1
debug1: key_load_public: No such file or directory
debug1: identity file /c/Users/xiaoxi/.ssh/id_dsa type -1
debug1: key_load_public: No such file or directory
debug1: identity file /c/Users/xiaoxi/.ssh/id_dsa-cert type -1
debug1: key_load_public: No such file or directory
debug1: identity file /c/Users/xiaoxi/.ssh/id_ecdsa type -1
debug1: key_load_public: No such file or directory
debug1: identity file /c/Users/xiaoxi/.ssh/id_ecdsa-cert type -1
debug1: key_load_public: No such file or directory
debug1: identity file /c/Users/xiaoxi/.ssh/id_ed25519 type -1
debug1: key_load_public: No such file or directory
debug1: identity file /c/Users/xiaoxi/.ssh/id_ed25519-cert type -1
debug1: Enabling compatibility mode for protocol 2.0
debug1: Local version string SSH-2.0-OpenSSH_7.3
debug1: Remote protocol version 2.0, remote software version Gitee.com
debug1: no match: Gitee.com
debug1: Authenticating to gitee.com:22 as 'git'
debug1: SSH2_MSG_KEXINIT sent
debug1: SSH2_MSG_KEXINIT received
debug1: kex: algorithm: curve25519-sha256@libssh.org
debug1: kex: host key algorithm: ecdsa-sha2-nistp256
debug1: kex: server->client cipher: aes128-ctr MAC: hmac-sha2-256 compression: none
debug1: kex: client->server cipher: aes128-ctr MAC: hmac-sha2-256 compression: none
debug1: expecting SSH2_MSG_KEX_ECDH_REPLY
debug1: Server host key: ecdsa-sha2-nistp256 SHA256:FQGC9Kn/eye1W8icdBgrQp+KkGYoFgbVr17bmjey0Wc
debug1: Host 'gitee.com' is known and matches the ECDSA host key.
debug1: Found key in /c/Users/xiaoxi/.ssh/known_hosts:1
debug1: rekey after 4294967296 blocks
debug1: SSH2_MSG_NEWKEYS sent
debug1: expecting SSH2_MSG_NEWKEYS
debug1: rekey after 4294967296 blocks
debug1: SSH2_MSG_NEWKEYS received
debug1: SSH2_MSG_SERVICE_ACCEPT received
debug1: Authentications that can continue: publickey
debug1: Next authentication method: publickey
debug1: Offering RSA public key: /c/Users/xiaoxi/.ssh/id_rsa
debug1: Server accepts key: pkalg ssh-rsa blen 279
debug1: Authentications that can continue: publickey
debug1: Trying private key: /c/Users/xiaoxi/.ssh/id_dsa
debug1: Trying private key: /c/Users/xiaoxi/.ssh/id_ecdsa
debug1: Trying private key: /c/Users/xiaoxi/.ssh/id_ed25519
debug1: No more authentication methods to try.
Permission denied (publickey).
```

<br>

### 查看ssh-agent代理

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
$ ssh-agent -s
SSH_AUTH_SOCK=/tmp/ssh-H55yB8lUFkbA/agent.88584; export SSH_AUTH_SOCK;
SSH_AGENT_PID=88636; export SSH_AGENT_PID;
echo Agent pid 88636;
```

<br>

### ssh-add 添加本地密钥

1- 这一步出错了：

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
$ ssh-add ~/.ssh/id_rsa
Could not open a connection to your authentication agent.

xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
```

2- eval 后再次执行

```shell
$ eval `ssh-agent -s`
Agent pid 89040

xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
$ ssh-add ~/.ssh/id_rsa
Identity added: /c/Users/xiaoxi/.ssh/id_rsa (/c/Users/xiaoxi/.ssh/id_rsa)
```

<br>

### ssh -T 测试

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
$ ssh -T git@gitee.com
Permission denied (publickey).
```

将本地密钥拷贝添加到服务器

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
$  clip < ~/.ssh/id_rsa.pub # 复制到黏贴版
```

再次测试，成功

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop/Learning-Notes-For-Xi_1 (master)
$ ssh -T git@gitee.com
Hi xiaoxiyouran! You've successfully authenticated, but Gitee.com does not provide shell access.
```




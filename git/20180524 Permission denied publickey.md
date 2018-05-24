# 20180524 Permission denied publickey

在Windows上的git 客户端克隆时发现了以下问题，

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop
$ git clone git@gitee.com:xiaoxiyouran/java_programming_thought_4th.git
Cloning into 'java_programming_thought_4th'...
Permission denied (publickey).
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.


```

然后用如下命令测试：

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop
$ ssh -v git@github.com
OpenSSH_7.3p1, OpenSSL 1.0.2h  3 May 2016
debug1: Reading configuration data /etc/ssh/ssh_config
debug1: Connecting to github.com [52.74.223.119] port 22.
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
debug1: Remote protocol version 2.0, remote software version libssh_0.7.0
debug1: no match: libssh_0.7.0
debug1: Authenticating to github.com:22 as 'git'
debug1: SSH2_MSG_KEXINIT sent
debug1: SSH2_MSG_KEXINIT received
debug1: kex: algorithm: curve25519-sha256@libssh.org
debug1: kex: host key algorithm: ssh-rsa
debug1: kex: server->client cipher: chacha20-poly1305@openssh.com MAC: <implicit> compression: none
debug1: kex: client->server cipher: chacha20-poly1305@openssh.com MAC: <implicit> compression: none
debug1: expecting SSH2_MSG_KEX_ECDH_REPLY
debug1: Server host key: ssh-rsa SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8
The authenticity of host 'github.com (52.74.223.119)' can't be established.
RSA key fingerprint is SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8.
Are you sure you want to continue connecting (yes/no)?

```

再测试，发现

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop
$ ssh -T git@github.com
The authenticity of host 'github.com (13.229.188.59)' can't be established.
RSA key fingerprint is SHA256:nThbg6kXUpJWGl7E1IGOCspRomTxdCARLviKw6E5SY8.
Are you sure you want to continue connecting (yes/no)?
Host key verification failed.

```

上面的？ 后面应该回复yes的，针对 “Host key verification failed” 问题，[参考](https://blog.csdn.net/maotongbin/article/details/53079840)

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop
$ rm -rf ~/.ssh/known_hosts
```

最后只能删除公钥，重新配置一下

```shell\
rm -rf ~/.ssh

ssh-keygen -C "xiaoxiyouran@163.com" -t rsa

# 然后又重新添加公约
vim ~/.ssh/id_rsa.pub
```

再克隆，发现应该回复yes，要不然默认又会报错。

```shell
xiaoxi@xiaoxi-PC MINGW64 ~/Desktop
$ git clone git@gitee.com:xiaoxiyouran/java_programming_thought_4th.git
Cloning into 'java_programming_thought_4th'...
The authenticity of host 'gitee.com (120.55.226.24)' can't be established.
ECDSA key fingerprint is SHA256:FQGC9Kn/eye1W8icdBgrQp+KkGYoFgbVr17bmjey0Wc.
Are you sure you want to continue connecting (yes/no)? yes

```


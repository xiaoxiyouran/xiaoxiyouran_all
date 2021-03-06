# 20180413 DES AES 和 RSA 等常用加密算法介绍

```java
1- 加密算法的三大类
   对称加密（加密与解密的密钥相同）：DES，3DES,AES
   非对称加密（加密与解密密钥不同）：RSA、DSA
   散列算法：SHA-1、MD5
   
   序列算法（序列密码）：次只对明文中的单个位（有时对字节）运算
   分组算法（分组密码）：对明文的一组位进行运算（即运算之前将明文分为若干组，然后分别对每一组进行运算，这些位组称为分组）
   
2- DES加密： 分组密码，以64位为分组对数据加密，它的密钥长度是56位   
   3DES（Triple DES）：对一块数据用三个不同的密钥进行三次加密，强度更高
   
   AES： 对称分组密码体制，密钥长度的最少支持为128、192、256，分组长度128位。美联邦的区块加密标准
   
   RSA： 最有影响力的公钥加密算法， 第一个同时用于 加密+ 数字签名。 基于一个简单的数论知识：将两个大素数相乘十分容易，但想要对其乘积进行因式分解却极其困难，因此可以将乘积公开作为加密密钥
   
   DSA: 基于整数有限域离散对数难题的, 对两个素数公开。即使不知道私钥，你也能确认它们是否是随机产生的，还是作了手脚。 只用于签名。
   
   BASE64： 传输8bit字节代码的编码方式之一，Base64编码可用于在HTTP环境下传递较长的标识信息。

   MD5加密算法：散列函数，提供消息的完整性保护。对一段Message产生fingerprin指纹，以防止被“篡改”。防止文件作者的“抵赖”
   
   SHA1加密算法：SHA1是和MD5一样流行的消息摘要算法。用于数字签名，两个不同的消息不会产生同样的消息摘要 保证数据完整性。
   
   凡是采取“消息摘要”方式的数字验证算法都是有“碰撞”的——也就是两个不同的东西算出的消息摘要相同，互通作弊图就是如此。

   
```





-----------------------------------------------

原文链接： https://blog.csdn.net/w4hechuan2009/article/details/76601895

  文本先简单介绍常用的加密算法，后面将逐步推送每个加密算法的加密原理与应用及java实现方式。

​       加密算法分对称加密和非对称算法，其中**对称加密算法的加密与解密密钥相同，非对称加密算法的加密密钥与解密密钥不同**，此外，还有一类**不需要密钥的散列算法**。

​       常见的**对称加密算法主要有DES、3DES、AES**等，常见的**非对称算法主要有RSA、DSA**等，**散列算法主要有SHA-1、MD5**等。

​       对称算法又可分为两类。一次只对明文中的单个位（有时对字节）运算的算法称为**序列算法或序列密码**。另一类算法是对明文的一组位进行运算（即运算之前将明文分为若干组，然后分别对每一组进行运算，这些位组称为分组），相应的算法称为**分组算法或分组密码**。

## **DES加密算法**

​       DES加密算法是一种**分组密码，以64位为分组对数据加密**，它的**密钥长度是56位**，加密解密用同一算法。DES加密算法是对密钥进行保密，而公开算法，包括加密和解密算法。这样，只有掌**握了和发送方相同密钥的人**才能解读由DES加密算法加密的密文数据。因此，破译DES加密算法实际上就是搜索密钥的编码。对于56位长度的密钥来说，如果用穷举法来进行搜索的话，其**运算次数为2的56次方。**

**3DES（Triple DES）**

​       是基于DES的对称算法，对一块数据**用三个不同的密钥进行三次加密**，强度更高；

##**AES加密算法**

​       AES加密算法是密码学中的高级加密标准，该加密算法采用**对称分组密码体制**，**密钥长度的最少支持为128、192、256，分组长度128位**，算法应易于各种硬件和软件实现。这种加密算法是美国联邦政府采用的区块加密标准，AES标准用来替代原先的DES，已经被多方分析且广为全世界所使用。

##**RSA加密算法**

​       RSA加密算法是目前最有影响力的**公钥加密算法，并且被普遍认为是目前最优秀的公钥方案之一。RSA是第一个能同时用于加密和数宇签名的算法**，它能够抵抗到目前为止已知的所有密码攻击，已被ISO推荐为公钥数据加密标准。RSA加密算法基于一个十分简单的数论事实：**将两个大素数相乘十分容易，但想要对其乘积进行因式分解却极其困难，因此可以将乘积公开作为加密密钥。**

##**DSA加密算法**

​       DSA是**基于整数有限域离散对数**难题的，DSA的一个重要特点**是两个素数公开**，这样，当使用别人的p和q时，即使不知道私钥，你也能确认它们是否是随机产生的，还是作了手脚。这一点，RSA算法做不到。

​       相比于RSA，DSA 只用于签名，而 RSA 可用于签名和加密。

##**Base64加密算法**

​       Base64加密算法是网络上最常见的用于**传输8bit字节代码的编码方式之一，Base64编码可用于在HTTP环境下传递较长的标识信息。**

##**MD5加密算法**

​       MD5为计算机安全领域广泛使用的一种**散列函数**，用以提供消息的完整性保护。

​       MD5被广泛用于各种软件的密码认证和钥匙识别上。MD5用的是哈希函数，它的典型应用是对一段信息产生信息摘要，以防止被篡改。MD5的典型应用是**对一段Message产生fingerprin指纹，以防止被“篡改”。**如果再有—个第三方的认证机构，用MD5还可以**防止文件作者的“抵赖”**，这就是所谓的数字签名应用。MD5还广泛用于操作系统的登陆认证上，如UNIX、各类BSD系统登录密码、数字签名等诸多方。

##**SHA1加密算法**

​       **SHA1是和MD5一样流行的消息摘要算法**。SHA加密算法模仿MD4加密算法。

​       SHA1主要适用于数字签名标准里面定义的**数字签名算法**。对于长度小于2“64位的消息，SHA1会产生一个160位的消息摘要。当接收到消息的时候，这个消息摘要可以用来验证数据的完整性。在传输的过程中，数据很可能会发生变化，那么这时候就会产生不同的消息摘要。SHA1不可以从消息摘要中复原信息，而且两**个不同的消息不会产生同样的消息摘要**。这样，SHA1就可以验证数据的完整性，所以说**SHA1是为了保证文件完整性**的技术。

​       SHA1是一种比MD5的安全性强的算法，理论上，凡是采取“消息摘要”方式的数字验证算法都是**有“碰撞”的——也就是两个不同的东西算出的消息摘要相同，互通作弊图就是如此**。但是安全性高的算法要找到指定数据的“碰撞”很困难，而利用公式来计算“碰撞”就更困难一目前为止通用安全算法中**仅有MD5被破解**。

各种加密算法比较如下：

对称加密算法(加解密密钥相同)

| 名称      | 密钥长度             | 运算速度  | 安全性   | 资源消耗  |
| ------- | ---------------- | ----- | ----- | ----- |
| DES     | 56位              | 较快    | 低     | 中     |
| 3DES    | 112位或168位        | 慢     | 中     | 高     |
| **AES** | **128、192、256位** | **快** | **高** | **低** |

 非对称算法(加密密钥和解密密钥不同)

| 名称   | 成熟度  | 安全性(取决于密钥长度) | 运算速度 | 资源消耗     |
| ---- | ---- | ------------ | ---- | -------- |
| RSA  | 高    | 高            | 慢    | 高        |
| DSA  | 高    | 高            | 快    | 只能用于数字签名 |

 散列算法比较

| 名称    | 安全性  | 速度   |
| ----- | ---- | ---- |
| SHA-1 | 高    | 慢    |
| MD5   | 中    | 快    |

对称与非对称算法比较

| 名称    | 密钥管理                | 安全性  | 速度                                       |
| ----- | ------------------- | ---- | ---------------------------------------- |
| 对称算法  | 比较难,不适合互联网,一般用于内部系统 | 中    | 快好几个数量级(软件加解密速度至少快100倍,每秒可以加解密数M比特数据),适合**大数据量的加解密处理** |
| 非对称算法 | 密钥容易管理              | 高    | **慢,适合小数据量加解密或数据签名**                     |

 以上给出了DES，3DES，AES，RSA等常见加密算法的介绍，后面将陆续推送每一种加密算法的详细实现流程以及相关的JAVA实现代码。 
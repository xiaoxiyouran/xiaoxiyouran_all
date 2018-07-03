# 20180615 xcode 看不到输出文件



/// Xcode解决不能输出文件的问题
// 添加绝对路径 ，感觉mac的绝对路径和windows的不太一样，你可以检查一下
// 更改一下设置，Product > Scheme > Edit Scheme > Run> Options Use custom working directory打勾，然后设置你放文件的位置，这样就不需要添加绝对路径了，而且你还可以通过这个看你文件的绝对路径
// 不知道你的问题是不是这个，我今天也是成功返回但是txt没结果。上面的方法解决了
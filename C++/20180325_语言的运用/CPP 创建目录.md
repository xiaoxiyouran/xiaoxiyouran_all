# CPP 创建目录

如果目录没有就创建：

```cpp
#ifdef WIN32
    #include <io.h>
    #include <direct.h>
#else
    #include <unistd.h>
    #include <sys/stat.h>
#endif

#include <stdint.h>
#include <string>
#define MAX_PATH_LEN 256

#ifdef WIN32
#define ACCESS(fileName,accessMode) _access(fileName,accessMode)
    #define MKDIR(path) _mkdir(path)
#else
#define ACCESS(fileName,accessMode) access(fileName,accessMode)
#define MKDIR(path) mkdir(path,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH)
#endif

// 从左到右依次判断文件夹是否存在,不存在就创建
// example: /Users/cookie/Downloads/mkdir/1/2/3/4/
// 注意:最后一个如果是文件夹的话,需要加上 '\' 或者 '/'
int32_t createDirectory(const std::string &directoryPath)
{
    uint32_t dirPathLen = directoryPath.length();
    if (dirPathLen > MAX_PATH_LEN)
    {
        return -1;
    }
    char tmpDirPath[MAX_PATH_LEN] = { 0 };
    for (uint32_t i = 0; i < dirPathLen; ++i)
    {
        tmpDirPath[i] = directoryPath[i];
        if (tmpDirPath[i] == '\\' || tmpDirPath[i] == '/')
        {
            if (ACCESS(tmpDirPath, 0) != 0)
            {
                int32_t ret = MKDIR(tmpDirPath);
                if (ret != 0)
                {
                    return ret;
                }
            }
        }
    }
    return 0;
}

//int32_t main(int32_t argc, char *argv[])
//{
//    if (argc == 2)
//    {
//        return createDirectory(argv[1]);
//    }
//    return 0;
//}
```

<br>

## 参考

1- https://www.cnblogs.com/tangxin-blog/p/6086425.html

2- https://blog.csdn.net/u010555688/article/details/51219700


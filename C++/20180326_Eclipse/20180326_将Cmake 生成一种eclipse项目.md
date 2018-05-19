# 20180326_将Cmake 生成一种eclipse项目

假设你的代码目录为Demo，其中有一个主CMakeLists.txt

新建一个与Demo同级的目录DemoProj，

```cmake
cd DemoProj

cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../Demo
```

会在DemoProj目录下生成eclipse工程

Eclipse导入【File / import】生成的工程



------

另一种参考

```cmake
cd YOUR_PROJECT_DIR
mkdir eclipse
cd eclipse
cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ..
cd ..
ls -a
You will see .cproject and .project for eclipse
Open eclipse and import your project to eclipse workspace
```


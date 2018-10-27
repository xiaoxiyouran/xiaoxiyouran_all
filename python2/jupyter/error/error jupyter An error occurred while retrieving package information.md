# error jupyter An error occurred while retrieving package information

在安装conda 环境包时，出现如下错误：

```
jupyter An error occurred while retrieving package information.
```

安装命令：

```shell
conda install nb_conda
```

需要在默认环境工作目录下安装， 如果不是， 会读不到环境。



## 解决

先卸载

```
conda remove nb_conda
```

然后, 将工作目录，重新设置成默认， 然后重新安装，

```sh
vim ~/.jupyter/jupyter_notebook_config.py
查找关键词“c.NotebookApp.notebook_dir”
## The directory to use for notebooks and kernels.
# c.NotebookApp.notebook_dir = u'/Users/cookie/Desktop/python_machine_learning'	

conda install nb_conda
```




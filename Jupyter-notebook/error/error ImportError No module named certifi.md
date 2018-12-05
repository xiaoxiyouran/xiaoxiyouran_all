# error ImportError No module named certifi

运行 `jupyter notebook` 时出现错误：

```sh
[17:23@cookie ~ #2]$ jupyter notebook
Vendor:  continuum
Product: anaconda
Message: trial mode expires in 27 days
Vendor:  continuum
Product: anaconda
Message: trial mode expires in 27 days
Traceback (most recent call last):
  File "/Users/cookie/anaconda2/bin/jupyter-notebook", line 4, in <module>
    import notebook.notebookapp
  File "/Users/cookie/anaconda2/lib/python2.7/site-packages/notebook/notebookapp.py", line 48, in <module>
    from tornado import httpserver
  File "/Users/cookie/anaconda2/lib/python2.7/site-packages/tornado/httpserver.py", line 34, in <module>
    from tornado.http1connection import HTTP1ServerConnection, HTTP1ConnectionParameters
  File "/Users/cookie/anaconda2/lib/python2.7/site-packages/tornado/http1connection.py", line 30, in <module>
    from tornado import iostream
  File "/Users/cookie/anaconda2/lib/python2.7/site-packages/tornado/iostream.py", line 40, in <module>
    from tornado.netutil import ssl_wrap_socket, ssl_match_hostname, SSLCertificateError, _client_ssl_defaults, _server_ssl_defaults
  File "/Users/cookie/anaconda2/lib/python2.7/site-packages/tornado/netutil.py", line 39, in <module>
    import certifi
ImportError: No module named certifi
```

solve:

```shell
pip install certifi
```

<br>

## 参考

1- https://github.com/elastic/curator/issues/821
# log

## 20260629

其实这个工程的整体比较好想\
先说一下软件的整体流程

```txt
网页获取 ---拉取本地---> 本地形成一个模板工程 ---> 编码 ---> 本地测试 ---> 上传
```

不同网页的布局是不同的，我需要针对不同的网站分别写几个`getter`\
`getter`获取到之后调用本地的`init`生成一个标准的模板工程\
模板工程大致包含一下内容

- 题目
- 用例
- 编码文档

因为算法题在编写时直写具体的算法，并不是完整的可运行的工程，所以需要对其进行补全\
本地编码完成后，可在本地进行运行，与用例进行对比并返回结果\
最后是上传部分，最简单的方法是让用户手动复制，但不够优雅

## 20260701

整个软件可以分为两个部分

- local：负责本地处理
- remote：负责远端通信

`local`需要实现以下功能

- 接受`remote`传来的内容并将其标准化为本地模板
- 处理本地编译，运行和测试

`remote`需要实现以下功能

- 获取网页内容
- 提交本地内容到网页上

## 20260703

v0.1.x版本要求具有以下功能

- init
- fetch
- pull
- run
- log
- push
- 参数分析器
- 代码模板和隐藏补全文件

## 20260705

项目的核心是参数解释器\
整个项目的架构围绕着参数解释器展开\
参数解释器分析命令和参数，把它们发送给对应的模块，然后各个模块执行动作\
这样设计的好处是以后不管想增加多少新功能，核心的`main`函数不用大改，只需要在解释器里加一条路由规则就行了\
像`git`, `docker`, `cargo`这些工具的底层都是这个架构：命令分发/路由模式(Command Router Pattern)\
我决定把这个参数解释器独立出去成为可复用组件<https://ljf12825.github.io/lab/gg-cli-router/>

TAB补全

## 20260707

Mock测试\
通过git submodule引入ggclirouter.h
使用CMake

## 20260708

LeetCode无公开API，且反爬虫，且网页动态渲染；解决方案：

- GraphQL
- alfa-leetcode-api

Codeforces有官方API\
AtCoder有官方API
洛谷有非官方API\
USACO题目直接是文件，直接爬就行

## 20260709

先从最简单的Codeforces开始

<https://codeforces.com/apiHelp>

Codeforces API是RESTful风格的，所有请求都通过HTTP GET发送到

```txt
https://codeforces.com/api/{methodName}
```

用python处理网络和数据


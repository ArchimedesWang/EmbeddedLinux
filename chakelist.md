# 🧭 使用说明（先看）

* 📘 主线：**《Linux 系统编程》**
* 📕 APUE：**只在“解释不通”时查**
* ⏱️ 每天 2h（±10min 都没问题）
* 🎯 每天**只有 1 个明确目标**
* ✅ 每天必须有“产出”（代码 / 理解）

---

# 🟥 第 1 周：文件 I/O & 文件系统语义

## Day 1｜文件 I/O 基础（校准语义）

### 学习

* ⬜ open / close 的返回值和错误处理
* ⬜ read / write 的返回语义（返回值≠请求字节数）

### 重难点

* ⬜ short read / short write 是**正常行为**

### 项目

* ⬜ 写一个最小文件拷贝程序（不追求性能）

### 验收

* ⬜ 能回答：为什么 write 可能写不完？

---

## Day 2｜文件偏移量与原子性

### 学习

* ⬜ lseek 的三种 whence
* ⬜ O_APPEND / O_TRUNC 的语义

### 重难点

* ⬜ 偏移量属于 **file 表项，不属于 fd**

### 项目

* ⬜ 写一个“追加写日志”程序
* ⬜ 尝试多个 fd 写同一文件

### 验收

* ⬜ 能解释：open 两次 vs dup 一次的区别

---

## Day 3｜文件属性与 inode 语义

### 学习

* ⬜ stat / lstat / fstat
* ⬜ st_mode / st_size / st_mtime

### 重难点

* ⬜ inode 描述的是“文件本体”，不是名字

### 项目

* ⬜ 写一个程序打印文件类型 + 大小

### 验收

* ⬜ 能解释：为什么 rename 不影响 inode？

---

## Day 4｜目录操作

### 学习

* ⬜ opendir / readdir / closedir
* ⬜ struct dirent 的作用

### 重难点

* ⬜ 目录是“文件名的集合”，不是文件内容

### 项目

* ⬜ 写一个 myls（只列文件名）

### 验收

* ⬜ 能解释：目录文件里到底存的是什么？

---

## Day 5｜符号链接

### 学习

* ⬜ 符号链接 vs 普通文件
* ⬜ stat vs lstat 的区别

### 重难点

* ⬜ 符号链接有自己的 inode

### 项目

* ⬜ myls 支持区分符号链接

### 验收

* ⬜ 能解释：符号链接断了会发生什么？

---

## Day 6｜mmap（语义层）

### 学习

* ⬜ mmap 的基本用法
* ⬜ MAP_SHARED / MAP_PRIVATE

### 重难点

* ⬜ mmap 是“内存视角的文件访问”

### 项目

* ⬜ mmap 读取文件内容（不写）

### 验收

* ⬜ 能说清：mmap 相比 read 的优势

---

## Day 7｜复盘（非常重要）

### 只做一件事

* ⬜ 画出 **fd → file → inode** 三层关系图

### 验收

* ⬜ 能用这张图解释第 1 周所有行为

---

# 🟧 第 2 周：进程模型 & 信号

## Day 8｜fork 基础

* ⬜ fork 的返回值语义
* ⬜ 父子进程的区别

✅ 验收：fork 后哪些东西被复制？

---

## Day 9｜exec 语义

* ⬜ exec 是“替换进程映像”
* ⬜ exec 前后的 fd 行为

✅ 验收：为什么 exec 后 fd 还能用？

---

## Day 10｜wait / 僵尸进程

* ⬜ wait / waitpid
* ⬜ 僵尸进程的本质

✅ 验收：僵尸进程为什么一定要回收？

---

## Day 11｜signal 基础

* ⬜ signal vs sigaction
* ⬜ 常见信号

✅ 验收：信号不是函数调用，为什么？

---

## Day 12｜信号 + 系统调用

* ⬜ EINTR 出现的原因
* ⬜ 被信号打断的系统调用

✅ 验收：为什么 read 会返回 -1 且 errno=EINTR？

---

## Day 13｜daemon 框架

* ⬜ setsid
* ⬜ 后台运行

### 项目

* ⬜ 写一个最小 daemon

---

## Day 14｜复盘

* ⬜ 解释：为什么系统服务必须处理 SIGTERM？

---

# 🟨 第 3 周：并发 & I/O 多路复用

## Day 15｜阻塞 / 非阻塞 I/O

* ⬜ fcntl 设置 O_NONBLOCK

✅ 验收：非阻塞 I/O 解决的是什么问题？

---

## Day 16｜select / poll

* ⬜ 多路复用思想

---

## Day 17｜epoll 模型

* ⬜ epoll_create / epoll_ctl / epoll_wait

### 项目

* ⬜ 写一个 epoll 主循环

---

## Day 18｜文件共享与竞态

* ⬜ 文件锁
* ⬜ 原子操作

✅ 验收：竞态来自哪一层？

---

## Day 19｜线程基础（轻量）

* ⬜ pthread_create
* ⬜ 线程共享 fd 的含义

---

## Day 20｜多线程写文件实验

* ⬜ 对比：加锁 vs O_APPEND

---

## Day 21｜复盘

* ⬜ 解释：多线程写日志的正确姿势

---

# 🟩 第 4 周：socket & 系统整合

## Day 22｜socket 基础

* ⬜ socket / bind / listen / accept

---

## Day 23｜socket I/O

* ⬜ send / recv
* ⬜ 半关闭

---

## Day 24｜socket + epoll

* ⬜ socket 纳入 epoll

---

## Day 25｜控制接口

* ⬜ daemon 支持 socket 命令

---

## Day 26｜模块整理

* ⬜ 拆分模块
* ⬜ 接口 / 实现分离

---

## Day 27｜系统复盘

* ⬜ 回看所有 fd 类型：文件 / socket / timer

---

## Day 28｜总结与展望

* ⬜ 总结 Linux 系统编程解决了什么问题
* ⬜ 列出下一阶段：V4L2 / SQLite / 网络

---

# 🧠 最后一条（非常重要）

> **如果你每天都能打勾，
> 4 周后你已经不是“会用 API”，
> 而是“理解系统行为”的工程师。**

如果你愿意，下一步我可以帮你把这份 checklist：

* 🔹 导出成 **Markdown / 表格版**
* 🔹 或直接 **嵌进你现在的项目 README**
* 🔹 或扩展成 **8 周（加 V4L2 / SQLite）版本**

你想下一步怎么继续？

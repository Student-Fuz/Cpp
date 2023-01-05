## C++ 多线程

多线程是多任务处理的一种特殊形式，多任务处理允许让电脑同时运行两个或两个以上的程序。一般情况下，两种类型的多任务处理：基于进程和基于线程。

 - 基于进程的多任务处理是程序的并发执行.
 - 基于线程的多任务处理是同一程序的片段的并发执行。

多线程程序包含可以同时运行的两个或多个部分。这样的程序中的每个部分称为一个线程，每个线程定义了一个单独的执行路径。

### pthread

在linux系统中，常使用POSIX Threads/pthread提供的API编写多线程C++程序。

pthread线程创建方法：
```cpp
#include <pthread.h>
pthread_create (thread, attr, start_routine, arg)
```

线程终止
```cpp
pthread_exit (status)
```
**注意**：如果 main() 是在它所创建的线程之前结束，并通过 pthread_exit() 退出，那么其他线程将继续执行。否则，它们将在 main() 结束时自动被终止
线程创建[例程](/Threads/pthread.cpp)

使用 -lpthread 库编译程序
    $ g++ test.cpp -lpthread -o test.o

#### 连接和分离线程
分离属性是属于线程的属性

分离属性    -->  不需要被的线程去调用pthread_join()来回收资源。
非分离属性  -->  需要被别的线程去调用pthread_join来回收资源。

可以使用以下两个函数来连接或分离线程：
```cpp
pthread_join (threadid, status) 
pthread_detach (threadid)
```

### std::thread
C++ 11 之后添加了新的标准线程库 std::thread，std::thread 在 <thread> 头文件中声明，因此使用 std::thread 时需要包含 在 <thread> 头文件

编译方式：

$ g++ -std=c++11 test.cpp 

std::thread 默认构造函数，创建一个空的 std::thread 执行对象

```cpp
#include<thread>
std::thread thread_object(callable)
```

一个可调用对象可以是以下三个中的任何一个：
- 函数指针
- 函数对象
- lambda 表达式

### 线程/进程同步



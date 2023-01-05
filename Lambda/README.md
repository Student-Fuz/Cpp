## Lambda

lambda表达式是C++11新特性之一，也称lambda函数。

### 用处
通常，lambda用于封装传递给算法或异步方法的几行代码。

对于代码量较小的函数，可以采用lambda表达式书写，以增强代码可读性。

### 格式

```cpp
[ capture ] ( params ) opt -> ret { body; };
```
其中carpture是捕获列表，params是参数，opt是选项，ret则是返回值的类型，body则是函数的具体实现


|    部分    |                           说明                           |
|:--------:|:------------------------------------------------------:|
| carpture |     无则可简写为[ ],捕获上下文变量；上文中的任意变量；所有变量使用=按值捕获，使用&引用捕获     |
|  params  |                      无参数则可省略，输入参数                      |
|   opt    | 可省略，可选mutable，默认情况下Lambda函数总是一个const函数，mutable可以取消其常量性 |
|   ret    |                  return语句仅有一句则可省略，返回值                  |
|   body   |                       lambda函数实现                       |


[例程](lambda.cpp)

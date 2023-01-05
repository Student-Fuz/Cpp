## stringstream类

在C++有两种字符串流，一种在sstream中定义， 另一种在strstream中定义。
它们实现的东西基本一样。
作用类似于C语言中的sprintf()/scanf()

**strstream库**
```cpp
#include <strstream>
```
strstream里包含
class strstreambuf;
class istrstream;
class ostrstream;
class strstream;
它们是基于C类型字符串char*编写的

**sstream库**
```cpp
#include <sstream>
```
sstream中包含
class istringstream;
class ostringstream;
class stringbuf;
class stringstream;
class …….
它们是基于std::string编写的

因此ostrstream::str()返回的是char*类型的字符串
而ostringstream::str()返回的是std::string类型的字符串

在使用的时候要注意到二者的区别，一般情况下推荐使用std::string类型的字符串
当然如果为了保持和C的兼容，使用strstream也是不错的选择。






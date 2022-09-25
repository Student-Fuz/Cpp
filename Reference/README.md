## 引用（reference）

**引用是变量的别名**

引用的注意事项：
- 不能返回局部变量的引用
- 函数返回的引用可以作为函数的左值

注：引用是C++推荐技术，因为语法方便，引用的本质是指针常量，但是所有的指针操作编译器都帮我们做了

**常量引用：引用最常见的使用**


```cpp
        int (const int & a){
        cout << a << endl;
        }
```

示例[程序](Reference\reference\reference.cpp)

### 引用的本质

本质：引用的本质在C++内部实现是一个常量指针

讲解示例：
```cpp
//编译器发现是引用，转换为int* const ref = &a;
void func(int & ref){
    ref = 100; //ref是引用，转换为*ref = 100;
}
int main(){
    int a = 10;
    
    //自动转换为 int* const ref = &a;指针常量是指针指向不可更改，这也是为什么引用不能更改引用对象
    int & ref = a;
    ref = 20; //内部发现ref是应用，自动帮我们转换为： *ref = 20;
    
    cout << "a :" << a << endl;
    cout << "ref: " << ref << endl;
    
    func(a);
    
    return 0;
}
```
## 泛型编程

### 模板

- C++的另一编程思想成为泛型编程，主要利用的技术就是模板
- C++提供两种模板机制：函数模板和类模板

#### 1 函数模板

##### 1.1 函数模板简介

函数模板的作用：
建立一个通用函数，其函数返回类型和形参类型可以不具体制定，用一个虚拟的类型来代表

语法：

 ```cpp
    template<typename T>
    函数声明或定义
 ```
##### 1.2 函数模板注意事项

函数模板的注意事项：
- 自动类型推导，必须推导出一致的数据类型T才可以使用
- 模板必须要确定T的数据类型，才可以使用

```cpp
    //函数模板
    //两值交换
    template <typename T>
    void swapValue(T &a, T &b){
        T temp = a;
        a = b;
        b = temp;
    }
    //注意事项
    //1、自动类型推导，必须推导出一致的数据类型才可以使用
    void test01(){
        int a;
        float b;

        //非法
        //推导出的数据类型必须保持一致
        //swapValue(a,b);
    }   

    //2、模板必须要确定T的数据类型，才可以使用
    template <typename T>
    void func(){
        cout << "func调用" << endl;
    }

    void test02(){
        //非法
        //编译器无法推导出T的数据类型
        //func();

        //合法
        //向编译器指定T的数据类型
        func<int>();
    }
```

##### 1.3 常见算法函数模板


##### 1.4 普通函数与函数模板的区别

普通函数与函数模板的区别：
- 普通函数调用时可以发生自动类型转换（隐式类型转换）
- 函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
- 如果利用显式指定类型的方式，可以发生隐式类型转换

##### 1.5 普通函数与函数模板的区别

##### 1.6 模板的局限性

模板不是万能的

例如：
```cpp
    template<class T>
    void f(T &a, T &b){
        a = b;
    }
```
对于自定义类型的数据类型，刻导致无法处理
解决方法：
- 运算符号重载
- 面对特殊类型单独具体处理

具体处理：
 ```cpp
    template<> bool equal_judge(const Person &a, const Person &b){
        //实现
    }
 ```


#### 2 类模板

##### 2.1 类模板语法

语法如下：

 ```cpp
    template<class NameType, class AgeType>
    class Person{
    public:
        Person(NameType name, AgeType age){
            m_Name = name;
            m_Age = age;
        }
        NameType m_Name;
        AgeType m_Age;
    };

    int main(){

        Person<string,int> p1("孙悟空",999);

        return 0;
    }

 ```

##### 2.2 类模板与函数模板区别

类模板与函数模板的区别主要又两点：
1. 类模板没有自动类型推导的使用方式
2. 类模板在模板参数列表中可以有默认参数

类模板设置格式如下：

```cpp
    template<class NameType, class AgeType = int>
    //类的实现
```

##### 2.3 类模板中成员函数的创建时机

类模板中的成员函数和普通类中的成员函数创建时机是有区别的；

- 普通类中的成员函数一开始就可以创建
- 类模板中的成员函数在调用的时候才被创建


##### 2.4 类模板对象做函数参数

例：
```cpp
    //1、指定传入类型
    void printPerson1(Person<string, int> &p){
        p.showPerson();
    }
    //2、参数模板化
    template<class T1, class T2>
    void printPerson2(Person<T1, T2> &p){
        p.showPerson();
        //查看模板的参数的类型
        cout << "T1的类型为: " << typeid(T1).name() << endl;
        cout << "T2的类型为: " << typeid(T2).name() << endl;
    }
```


##### 2.5 类模板与继承

当类模板碰到继承时，需要注意一下几点：
- 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中的类型
- 如果不指定，编译器无法给子类分配内存
- 如果向灵活指出父类中T的类型，子类也需变成为类模板

示例[程序](Generic_Program\template\class_template\template_inherit.cpp)

##### 2.6 类模板成员函数的类外实现

例:
```cpp
//构造函数类外实现
template<class T1, class T2>
Person<T1,T2>::Person(T1 name, T2 age){
    this->m_Name = name;
    this->m_Age = age;
}

//成员函数类外实现
template<class T1, class T2>
void Person<T1,T2>::showPerson(T1 name, T2 age){
    this->m_Name = name;
    cout << "m_Name: "<< this->m_Name << "m_Age: "<< this->m_Age << endl;
}
 ```

- 总结：类模板中成员函数在类外实现时，需要加上模板参数列表

##### 2.7 类模板分文件编写

学习目标：
- 掌握类模板成员函数分文件编写产生的问题以及解决方式

问题：
- 类模板中的成员函数创建时机实在调用阶段，导致分文件编写时链接不到

解决：
- 解决方式1：直接包含.cpp源文件

例：
```cpp
    #include "Person.cpp"
```
- 解决方式2：将类模板声明和实现写到同一个文件中，并更改后缀名为.hpp,hpp时约定的名称，并不是强制
# C++

### 内存分区模型


C++程序在执行时，将内存大方向划分为**4个区域**

 - 代码区： 存放函数体的二进制代码，由操作系统进行管理
 - 全局区： 存放全局变量和静态变量以及常量
 - 栈区：   由编译器自动分配释放，存放函数的参数值，局部变量等
 - 堆区：   由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收

内存四分区的意义：

不同区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程

示例[程序](.\Object_Oriented_Programming_Practice\Memory\memory.cpp)

#### 1.1 程序运行前

在程序编译后，生成了exe可执行程序，未执行该程序前分为两个区域

**代码区：**
   存放CPU执行的机器指令
   - 代码区是共享的，共享的目的是对于频繁执行的程序，只需要在内存中由一份代码即可
   - 代码区是只读的，使其只读的原因是防止程序意外地修改了它的指令

**全局区：**

 - 全局变量和静态变量存放在此
 - 全局区还包含了常量区，字符串常量和其它常量(全局)也存放在此
    *该区域的数据在程序结束后由操作系统释放*

#### 1.2 程序运行后

**栈区：**
    存放局部变量
    注意：不能返回局部变量的地址

**堆区：**
    由程序员分配释放，若程序员不释放，程序结束时由操作系统回收
 - 在C++中主要利用new在堆区开辟内存
 - 在C++中主要利用delete在堆区释放内存
    示例代码：

    ```cpp
   int* p = new int(10);    //在堆区开辟一个值为10的int类型数据
   delete p;                //释放堆区该int数据
   ```

    ```cpp
   int* arr = new int[];    //在堆区开辟一个值为10的int类型数据
   delete[] arr;            //释放堆区该int数组数据
    ```

### 引用（reference）

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

示例[程序](.\Object_Oriented_Programming_Practice\reference\reference.cpp)


### 函数高级

#### 默认参数

 - 如果某个位置有默认值，那么这个位置往后，从左到右，必须都要有默认值
 - 函数的声明和实现只能有其一有默认值

#### 函数重载

 - 引用作为重载的条件： 区分常量引用和普通引用的应用
 - 函数重载碰到默认参数：需要注意避免语义二义性

示例[程序](.\Object_Oriented_Programming_Practice\overload\overload.cpp)

## 面对对象编程

### 面对对象基础

语法：基本实现[例程](.\Object_Oriented_Programming_Practice\main.cpp)

### 访问权限

三种访问权限
 - public        类内可访问 类外可访问
 - protected     类内可访问 类外不可访问 儿子可访问
 - private       类内可访问 类外不可访问 儿子不可访问

访问权限[例程](.\Object_Oriented_Programming_Practice\access_authority\Person.cpp)

### this的应用

 this是当前对象的指针

 - 解决名称冲突

    ```cpp
        class Person{
        public:
            //形参的名称与类的属性相同时，使用this解决名称冲突
            Person(int age){
                this->age = age;
            }
            int age;
        };


    ```

 - 返回对象本身用*this

    ```cpp
        class Person{
        public:
            Person(int money){
                //this指针指向 被调用的成员函数 所属的对象
                this->age = money;
            }
            Person& PersonAddMoney(Person &p){
                this->money += p.money;
                return *this;
            }
            int money;
        };
    
        Person p1(2000);
        Person p2(2000);
        p2.PersonAddMoney(p1).PersonAddMoney(p1).PersonAddMoney(p1);//链式编程思想
    ```

### 空指针访问成员函数

 例：
 ```cpp
    class Person{
    public:
        void showPersonAge(){
            if(p == NULL){
                return;
            }//此操作避免访问空指针 this
            cout << "age = " << m_Age << endl;
        }
        int m_Age;
    };
    Person * p = NULL;
    p->showPersonAge();
 ```

 ### const修饰成员函数

 常函数：
  - 成员函数加const后我们称这个函数为常函数
  - 常函数内不可以修改成员属性
  - 成员属性声明时加关键字mutable后，在常函数中依然可以修改

 常对象：
  - 声明对象前加const称该对象为常对象
  - 常对象值只调用常函数

### 友元

友元的三种实现

 - 全局函数做友元
 - 类做友元
 - 成员函数做友元

#### 友元函数

友元函数可以访问类的私有权限属性

友元函数的声明示例如下：
```cpp
    class Building{
        friend void goodGuy(Building *building);
    public:
        ...
    private:
        ...
    };
```

### 构造函数与析构函数

1. 构造函数在对象简历时被调用，可重载

    例：
    ```cpp
        Person(参数){
            初始化；
        }
    ```


2. 析构函数在对象被销毁时被调用，用于释放对象所占的内存空间

    例：
    ```cpp
        ~Person(){
            //析构代码，程序员需要手动将堆区开辟的数据释放掉
            //标准写法如下：
            if(m_Height != NULL){
                delete m_Height;
                m_Height = NULL;
            }   
        }
    ```

### 拷贝构造函数

拷贝构造函数的三种调用时机：

 1. 使用一个已经创建完毕的对象来初始化对象
    例：
    ```cpp
        Person p1(20);
        Person p2(p1);
    ```

 2. 值传递的方式给函数参数传值

    例：
    ```cpp
        void test02(Person p){
        }
    ```
   
 3. 值方式返回局部对象(有的编译器会调用拷贝函数、有的不调用而直接返回)

    例：
    ```cpp
    Person doWork(){
        Person p;
        return p;
    }
    Person p = doWork();
    ```

### 深拷贝与浅拷贝

深浅拷贝是面试的经典问题，也是常见的一个坑

 - 浅拷贝：简单的赋值拷贝操作

 - 深拷贝：在堆区重新申请空间，进行拷贝操作

 - 小结： 如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题

### 运算符重载

 运算符重载概念： 对已有的运算符重新进行定义，以适应不同的数据类型

 - 运算符+重载
 例：
```cpp
        class Person{
        public:


            //1、成员函数重载+号

        //    Person operator+(Person &p1){
        //
        //        Person temp;
        //        temp.m_A = this->m_A + p1.m_A;
        //        temp.m_B = this->m_B + p1.m_B;
        //
        //        return temp;
        //    }

            int m_A;
            int m_B;
        };


        //全局函数重载+号

        Person operator+(Person &p1,Person &p2){
            Person temp;
            temp.m_A = p1.m_A + p2.m_A;
            temp.m_B = p1.m_B + p2.m_B;
            return temp;
        }

        //运算符重载也可以发生函数重载
        Person operator+(Person &p1,int num){
            Person temp;
            temp.m_A = p1.m_A + num;
            temp.m_B = p1.m_B + num;
            return temp;
        }

        //成员函数重载本质调用
        //Person p3 = p1.operator+(p2);

        //全局函数重载本质调用
        //Person p3 = operator+(p1,p2);

        Person p3 = p1 + p2;

        Person p4 = p1 + 100;

```

 - 运算符++重载

示例[程序](.\Object_Oriented_Programming_Practice\overload\Operator_plusplus_overload.cpp)

 **注意：C++只能前置链式调用；不能后置链式调用**

### 继承

 子类继承父类代码，减少重复代码

 基本语法：示例[程序](.\Object_Oriented_Programming_Practice\inherit\inherit.cpp)

#### 继承方式

继承的语法： class 子类 : 继承方式 父类

继承方式一共有三种

 - 公共继承
 - 保护继承
 - 私有继承

 不同继承方式，子类属性如下：

![](2022-08-28-23-13-24.png)

 示例[程序]()
### struct和class区别

在C++中struct和class唯一的区别在于默认的访问权限不同

区别：
 - struct默认权限为公共
 - **class默认权限为私有**

## new/delete与malloc/free的区别

1. new/delete是C++操作符，malloc/free是库函数
2. new分配内存按照数据类型进行分配，malloc分配内存按照大小分配
3. new在动态分配内存的时候可以初始化对象，调用其构造函数，delete在释放内存时 调用对象的析构函数。
而malloc只分配一段给定大小的内存，并返回该内存首地址指针，如果失败，返回NULL。
4. new/delete可以重载，而malloc不行
5. new返回的是指定对象的指针，而malloc返回的是void*，因此malloc的返回值一般都需要进行类型转化
6. 对于数据C++定义new[]专门进行动态数组分配，用delete[]进行销毁。new[]会一次分配内存，然后多次调用构造函数；delete[]会先多次调用析构函数，然后一次性释放
new如果分配失败了会抛出bad_malloc的异常，而malloc失败了会返回NULL。因此对于new，正确的姿势是采用try…catch语法，而malloc则应该判断指针的返回值。为了兼容很多c程序员的习惯，C++也可以采用new nothrow的方法禁止抛出异常而返回NULL；
malloc能够直观地重新分配内存使用realloc函数进行内存重新分配实现内存的扩充
new没有这样直观的配套设施来扩充内存。

## 内存泄露



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

 示例[程序](.\Object_Oriented_Programming_Practice\template\class_template\template_inherit.cpp)

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


## STL初识

 - 长久以来，软件界一直希望建立一种可以重复利用的东西
 - C++的面对对象编程和泛型编程思想，目的就是复用性的提升
 - 大多情况下，数据结构和算法都未有一套标准，导致被迫从事大量重复工作
 - 为了简历数据结构和算法的一套标准，诞生了STL

### 2.1 STL基本概念

 - STL(Standard Template Library,标准模板库)
 - STL从广义上分为：容器(container)、算法(algorithm)、迭代器(iterator)
 - 容器和算法之间通过迭代器进行无缝链接
 - STL几乎所有的代码都采用了模板或者模板函数
 - 
| 种类  | 功能   |
|-------------- | -------------- |
| Item1    | Item1     | 


### 2.2 vector

#### 2.2.1 初识vector容器

基本语法如下
例：
```cpp
    //创建一个vector容器
    vector<int> v;

    //创建一个vector容器存放自定义数据类型Person
    //vector<Person> v_p;

    //向容器中插入数据1
    v.push_back(1);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个元素
```

注意：v.end()所指向的时***最后一个元素的下一个元素 ***

遍历方式

 - 三种遍历方式：
 - while
 - for
 - for_each

```cpp 
    //第一种遍历方式
   while(itBegin != itEnd){
       cout << *itBegin << endl;
       itBegin++;
   }

    //第二种遍历方式
   for(vector<int>::iterator it = v.begin(); it != v.end(); it++){

   }

    //第三种遍历方式
    for_each(v.begin(), v.end(),myPrint);
```
 注意：vector<type>::iterator it中的it是vector容器的***指针***指向容器中的数据

#### 2.2.2 vector容器嵌套容器

```cpp
    //构造
    vector<vector<type>> v_nest;
```

### 2.2 string 

本质：
 - string是C++风格的字符串，而string本质上是一个类
***string和char*区别：
 - char*是一个指针
 - string是一个类，类内部封装了char*,管理这个字符串，是一个char*型的容器
  
特点：
string类内封装了很多成员方法
例如：查找find，拷贝copy，删除delete，替换replace，插入insert
string管理char*所分配的内存，不用担心赋值越界和取值越界，由类内部进行负责

#### 3.2.1 string构造函数

构造函数原型：
    - `string()`                     //创建一个空的字符串 例如：string str;
    - `string(const char* s)`        //使用字符串初始化
    - `string(const string& str)`   //使用一个string对象初始化一个string对象
    - `string(int n, char c)`       //使用n个字符c初始化




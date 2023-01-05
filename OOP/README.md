## 面对对象编程

### 面对对象基础

语法：基本实现[例程](main.cpp)

### 访问权限

三种访问权限
- public        类内可访问 类外可访问
- protected     类内可访问 类外不可访问 儿子可访问
- private       类内可访问 类外不可访问 儿子不可访问

访问权限[例程](access_authority\Person.cpp)

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
            初始化;
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

### 函数高级

#### 默认参数

- 如果某个位置有默认值，那么这个位置往后，从左到右，必须都要有默认值
- 函数的声明和实现只能有其一有默认值

#### 函数重载

- 引用作为重载的条件： 区分常量引用和普通引用的应用
- 函数重载碰到默认参数：需要注意避免语义二义性

示例[程序](overload\overload.cpp)

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

示例[程序](overload\Operator_plusplus_overload.cpp)

**注意：C++只能前置链式调用；不能后置链式调用**

### 继承

子类继承父类代码，减少重复代码

基本语法：示例[程序](inherit\inherit.cpp)

#### 继承方式

继承的语法： class 子类 : 继承方式 父类

继承方式一共有三种

- 公共继承
- 保护继承
- 私有继承

不同继承方式，子类属性如下：

![](2022-08-28-23-13-24.png)

示例[程序]()

#### 继承的构造原则

1. 如果子类没有定义构造方法，则调用父类的无参数的构造方法。
2. 如果子类定义了构造方法，不论是无参数还是带参数，在创建子类的对象的时候,首先执行父类无参数的构造方法，然后执行自己的构造方法。 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数，则会调用父类的默认无参构造函数。
3. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类自己提供了无参构造函数，则会调用父类自己的无参构造函数。
4. 在创建子类对象时候，如果子类的构造函数没有显示调用父类的构造函数且父类只定义了自己的有参构造函数，则会出错（如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法）。
5. 如果子类调用父类带参数的构造方法，需要用初始化父类成员对象的方式


### 多态

#### 多态的基本概念

**多态是C++面对对象的三大特性之一**

多态分为两类
- 静态多态：函数重载和运算符重载属于静态多态，复用函数名
- 动态多态：派生类和虚函数实现运行时多态

静态多态和动态多态的区别：
- 静态多态的函数地址早绑定 -编译阶段确定函数地址
- 动态多态的函数地址完绑定 -运行阶段确定函数地址

下面通过案例进行讲解多态：

```cpp
class Animal{
public:
    //speak函数就是虚函数
    //虚函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了
    virtual void speak(){
        cout << "动物在说话" << endl;
    }
};

class Cat : public Animal{
public:
    void speak(){
        cout << "小猫在说话：" << endl;
    }
};

class Dog : public Animal{
public:
    void speak(){
        cout << "小狗在说话" << endl;
    }
};

void DoSpeak(Animal & animal){
    animal.speak();
}

//多态满足条件
//1、有继承关系
//2、子类重写父类中的虚函数
//多态使用条件
//父类指针或引用 指向子类对象

void test01(){
    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
}

int main(){
    test01();

    system("pause");

    return 0 ;
}
```
总结：

多态满足条件
- 有继承关系
- 子类重写父类中的虚函数

多态使用条件
- 父类指针或引用 指向子类对象
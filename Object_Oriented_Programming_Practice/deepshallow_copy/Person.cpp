//
// Created by Fu_zh on 2022/8/22.
//

#include <iostream>
using namespace std;

class Person
{
public:
    Person(){
        cout << "Person默认函数调用" << endl;
    }

    Person(int age){
        m_Age = age;
        cout << "Person有参函数调用" << endl;
    }

    Person(const Person & p){
        m_Age = p.m_Age;
        cout << "Person拷贝函数调用" << endl;
    }

    ~Person(){
        cout << "Person析构函数调用" << endl;
    }

    int m_Age;
};
//拷贝函数的调用时机

//1、使用一个已经创建完毕的对象来初始化对象

void test01(){
    Person p1(20);
    Person p2(p1);
}

//2、值传递的方式给函数参数传值

void test02(Person p){

}

//3、值方式返回局部对象(有的编译器会调用拷贝函数、有的不调用而直接返回)

Person doWork(){
    Person p;
    cout << &p << endl;
    return p;
}

void test03(){
    Person p = doWork();
    cout << &p << endl;
}

int main(){

    //test01();
    //输出：
    //Person有参函数调用
    //Person拷贝函数调用
    //Person析构函数调用
    //Person析构函数调用


    //Person p2;
    //test02(p2);
    //输出：
    //Person默认函数调用
    //Person拷贝函数调用
    //Person析构函数调用
    //Person析构函数调用

    test03();
    //输出：
    //



    return 0;
}

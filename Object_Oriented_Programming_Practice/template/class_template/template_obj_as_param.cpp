//
// Created by Fu_zh on 2022/9/4.
//
#include<iostream>
#include<string>

using namespace std;

template<class NameType, class AgeType = int>
class Person{
public:
    Person(NameType name, AgeType age){
        m_Name = name;
        m_Age = age;
    }

    void showPerson(){
        cout << "name: " << this->m_Name << endl;
        cout << "age: " << this->m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;
};

//非法
// void printPerson1(Person &p){
//    p.showPerson();
//}

//1、指定传入类型
void printPerson1(Person<string, int> &p){
    p.showPerson();
}

void test01(){
    //printPerson1();
    //函数仅接收Person<string, int>所定义的Person对象作为参数
    Person<string,int> p1("孙悟空",999);
    //合法
    printPerson1(p1);

    Person<int,int> p2(1,999);
    //非法
    //printPerson1(p2);
}

//2、参数模板化
template<class T1, class T2>
void printPerson2(Person<T1, T2> &p){
    p.showPerson();
    //查看模板的参数的类型
    cout << "T1的类型为: " << typeid(T1).name() << endl;
    cout << "T2的类型为: " << typeid(T2).name() << endl;
}

void test02(){
    //printPerson2();
    //函数仅接收任意合法的Person对象作为参数
    Person<string,int> p1("孙悟空",999);
    //合法
    printPerson2(p1);

    Person<int,int> p2(1,999);
    //合法
    printPerson2(p2);
}

int main(){
    test01();

    test02();

    return 0;
}

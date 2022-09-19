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
    NameType m_Name;
    AgeType m_Age;
};

int main(){

    Person<string,int> p1("孙悟空",999);
    Person<string,int> p2("孙悟空",1000);
    return 0;
}

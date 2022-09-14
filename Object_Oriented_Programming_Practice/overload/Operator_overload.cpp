//
// Created by Fu_zh on 2022/8/26.
//

#include<iostream>

using namespace std;

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


//利用全局函数重载左移运算符
//本质 operator << (cout,p); 简化 : cout << p;
ostream & operator<<(ostream &out, Person &p){
    out << "m_A = " << p.m_A << "," << "m_B = " << p.m_B << endl;
    return cout;
}

int main(){
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;

    //成员函数重载本质调用
    //Person p3 = p1.operator+(p2);

    //全局函数重载本质调用
    //Person p3 = operator+(p1,p2);

    Person p3 = p1 + p2;

    Person p4 = p1 + 100;

    cout << "p3.m_A : " << p3.m_A << endl;
    cout << "p3.m_B : " << p3.m_B << endl;

    cout << "p4.m_A : " << p4.m_A << endl;
    cout << "p4.m_B : " << p4.m_B << endl;

    cout << p4;

    return 0;
}

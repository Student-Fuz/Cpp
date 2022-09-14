//
// Created by Fu_zh on 2022/8/28.
//

#include <iostream>

using namespace std;

class MyInteger{

    friend ostream & operator<<(ostream &out, MyInteger &myint);

public:
    MyInteger(){
        m_Num = 0;
    }
    //前置++
    //若需要程序连续调用，注意需要返回引用值
    MyInteger& operator++(){
        //先++
        m_Num++;
        //再返回
        return *this;
    }
    //后置++
    //int 代表占位参数，可以用于区分前置和后置的递增
    MyInteger  operator++(int){
        //先 记录当时结果
        MyInteger temp = *this;
        //后递增
        m_Num++;
        //再返回
        return temp;
    }
private:
    int m_Num;
};

//利用全局函数重载左移运算符
//本质 operator << (cout,p); 简化 : cout << p;
ostream & operator<<(ostream &out, MyInteger &myint){
    out  << myint.m_Num << endl;
    return cout;
}

void test01(){
    MyInteger myint;

    myint++;

    cout << myint << endl;
}

int main(){
    MyInteger myint;

    cout << ++myint << endl;
    //输出 1

//    //合法
//    cout << ++(myint++) << endl;

//    //非法
//    cout << myint++ << endl;

    test01();
    //输出 1

    int a;

    //注意：C++不允许前置链式
    cout << ++(++a) << endl;

    //注意：C++不允许后置链式
    //cout << (a++)++ << endl;
    //报错

    return 0;
}
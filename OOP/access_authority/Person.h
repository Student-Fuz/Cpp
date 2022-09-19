//
// Created by Fu_zh on 2022/8/19.
//

#ifndef OBJECT_ORIENTED_PROGRAMMING_PRACTICE_PERSON_H
#define OBJECT_ORIENTED_PROGRAMMING_PRACTICE_PERSON_H

#include <iostream>
using namespace std;

//三种访问权限
//public        类内可访问 类外可访问
//protected     类内可访问 类外不可访问 儿子可访问
//private       类内可访问 类外不可访问 儿子不可访问

class Person {
public:
    string m_Name;
protected:
    string m_Car;
private:
    int m_Password;
public:
    void func(){
        m_Name = "李四";
        m_Car = "拖拉机";
        m_Password = 123456;
    }
};


#endif //OBJECT_ORIENTED_PROGRAMMING_PRACTICE_PERSON_H

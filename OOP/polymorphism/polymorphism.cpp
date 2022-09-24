//
// Created by Fu_zh on 2022/9/24.
//

#include <iostream>

using namespace std;

class Animal{
public:
    //speak函数就是虚函数
    //虚函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了
//    virtual void speak(){
//        cout << "动物在说话" << endl;
//    }

    void speak(){
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

void test02(){
    cout << "sizeof Animal = " << sizeof(Animal) << endl;
}
int main(){
    test01();


    //Animal中仅含虚函数
    //virtual void speak(){}时
    //Animal类的大小是8
    //*********************************************
    //Animal中仅含函数时
    //void speak(){}时
    //Animal类的大小是1
    test02();


    test02();

    return 0 ;
}
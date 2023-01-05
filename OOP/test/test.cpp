#include<iostream>
using namespace std;

class A{
public:
    A(){ cout << "调用A的默认构造函数" << endl; }
    ~A(){ cout << "调用A的析构函数" << endl; }
    void show(){
        cout << "A 的show函数" << endl;
    }
};

class B:public A{
public:
    B(){ cout << "调用B的默认构造函数" << endl; }
    ~B(){ cout << "调用B的析构函数" << endl; }
    void show(){
        cout << "B 的show函数" << endl;
    }
    int value = 1;
};

int main()
{


	//实验一
//	cout << "A对象a::" << endl;
//	A *a = new A();
//	delete a;
//	cout << endl << endl;
//	cout << "B对象b::" << endl;
//	B *b = new B();
//	delete b;

    //实验二
    A *a1 = new B();
    a1->show();
    delete a1;


    return 0;
}
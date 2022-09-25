#include<iostream>
using namespace std;

class A{
public:
    A(){ cout << "调用A的默认构造函数" << endl; }
    virtual ~A(){ cout << "调用A的析构函数" << endl; }
};

class B:public A{
public:
    B(){ cout << "调用B的默认构造函数" << endl; }
    ~B(){ cout << "调用B的析构函数" << endl; }
};

int main()
{

//	//实验一
//	cout << "A对象a::" << endl;
//	A *a = new A();
//	delete a;
//	cout << endl << endl;
//	cout << "B对象b::" << endl;
//	B *b = new B();
//	delete b;


    //实验二
    A *a1 = new B();
    delete a1;



    return 0;
}

//
// Created by Fu_zh on 2022/8/20.
//
#include<iostream>
using namespace std;

//全局变量
int g_a = 10;
int g_b = 10;

//const修饰的全局变量 全局常量
const int c_g_a = 10;

//形参数据也会放到栈区
int* func(int b){
    b = 100;
    int a = 10;//局部变量 存放在栈区，栈区的数据在函数执行完后自动释放
    return &a;
}

int* func_new(int b){
    b = 100;
    //在堆区开辟数据
    int* p = new int(10);
    return p;
}

int main(){

    //全局区

    //全局变量、静态变量、常量

    //创建普通局部变量
    int a = 10;
    int b = 10;

    cout << "局部变量a的地址为: " << &a << endl;
    cout << "局部变量b的地址为: " << &b << endl;
    cout << "局部变量g_a的地址为: " << &g_a << endl;
    cout << "局部变量g_b的地址为: " << &g_b << endl;

    //创建静态变量
    static int s_a = 10;
    static int s_b = 10;
    cout << "局部变量s_a的地址为: " << &s_a << endl;
    cout << "局部变量s_b的地址为: " << &s_b << endl;

    //常量
    //字符串常量
    cout << "字符串的地址为： " << &("Hello World!") << endl;


    cout << "全局常量c_g_a的地址为: " << &c_g_a << endl;

    //局部常量
    const int c_l_a = 10;


    cout << "局部常量c_l_a的地址为: " << &c_l_a << endl;

    int * pa = func(1);
    //非法操作
    cout << pa << endl;

    pa = func_new(1);
    cout << *pa << endl;

    delete pa;//释放堆区数据

    return 0;
}

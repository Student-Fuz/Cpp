//
// Created by Fu_zh on 2022/9/4.
//

#include<iostream>

using namespace std;

//函数模板
//两值交换
template <typename T>
void swapValue(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T1, typename T2>
void print(const T1 &a, const T2 &b){
    cout << "a:" << a << endl;
    cout << "b:" << b << endl;
}

//注意事项
//1、自动类型推导，必须推导出一致的数据类型才可以使用
void test01(){
    int a;
    float b;

    //非法
    //推导出的数据类型必须保持一致
    //swapValue(a,b);
}


//2、模板必须要确定T的数据类型，才可以使用
template <typename T>
void func(){
    cout << "func调用" << endl;
}

void test02(){
    //非法
    //编译器无法推导出T的数据类型
    //func();

    //合法
    //向编译器指定T的数据类型
    func<int>();
}

int main(){
    int a = 100;
    int b = 1000;

    swapValue(a,b);

    cout << "a:" << a <<endl;
    cout << "b:" << b <<endl;
    //输出：
    //a:1000
    //b:100

    float c = 0.01;
    float d = 0.001;

    swapValue(c,d);

    cout << "c:" << c <<endl;
    cout << "d:" << d <<endl;

    int32_t e = 20;
    double f = 20;
    print(e,f);

    return 0;
}

//
// Created by Fu_zh on 2022/8/21.
//

#include<iostream>
using namespace std;

//引用使用的场景，通常用来修饰形参
void showValue(const int& v){
    //非法操作
    //v = 100;
    cout << v << endl;
}

int main(){

    //常量引用
    //使用场景：用来修饰形参，防止误操作

    int a = 1000;
    showValue(a);

    return 0;
}
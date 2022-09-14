//
// Created by Fu_zh on 2022/8/28.
//

#include <iostream>

using namespace std;

//继承实现页面
//减少重复的代码

//基础页面（父类）
class BasePage{
public:
    void header(){
        cout << "首页、公开课、登录、注册...(公共头部)" << endl;
    }
    void footer(){
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left(){
        cout << "Java、Python、C++、...(公共分类列表)" << endl;
    }
};

//Java页面（子类）
class Java : public BasePage{
public:
    void content(){
        cout << "Java学科视频" << endl;
    }
};

//Cpp页面（子类）
class Cpp : public BasePage{
public:
    void content(){
        cout << "Cpp学科视频" << endl;
    }
};

//Python页面（子类）
class Python : public BasePage{
public:
    void content(){
        cout << "Python学科视频" << endl;
    }
};

void test01(){
    Java java;
    java.content();
    java.footer();
    java.header();
    java.left();

    Cpp cpp;
    cpp.content();
    cpp.footer();
    cpp.header();
    cpp.left();

    Python py;
    py.content();
    py.footer();
    py.header();
    py.left();
};
int main(){
    test01();

    return 0;
}

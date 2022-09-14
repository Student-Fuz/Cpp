//
// Created by Fu_zh on 2022/9/9.
//

#include <iostream>

using namespace std;

template<class T>
class Base{
    T m;
};


//class Son :public Base //错误，必须要知道父类中的T类型，才能继承给子类
class Son1 :public Base<int>
{

};

void test01(){
    Son1 s1;
};

//如果想灵活地指定父类中的T类型，子类也需要变成类模板
template<class T1, class T2>
class Son2 :public Base<T1>
{
    T2 obj;
};

void test02(){
    Son2<int, int> s2;
};
int main(){



    return 0;
}

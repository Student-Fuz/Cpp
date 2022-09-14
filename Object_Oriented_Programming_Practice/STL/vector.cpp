//
// Created by Fu_zh on 2022/9/12.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//vector容器存放内置数据类型
void myPrint(int val);

void test01(){

    //创建一个vector容器
    vector<int> v;

    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itBegin = v.begin();//起始迭代器，指向容器中的第一个元素
    vector<int>::iterator itEnd = v.end();//结束迭代器，指向容器中最后一个元素的下一个元素

    //第一种遍历方式
//    while(itBegin != itEnd){
//        cout << *itBegin << endl;
//        itBegin++;
//    }

    //第二种遍历方式
//    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
//
//    }

    //第三种遍历方式
    for_each(v.begin(), v.end(),myPrint);
}

void myPrint(int val){
    cout << val <<endl;
};
int main(){

    test01();

    return 0;
}
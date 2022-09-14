//
// Created by Fu_zh on 2022/9/5.
//

#include <iostream>

using namespace std;

class Person{
public:
    string name;
    int age;
};

template<typename T>
bool equal_judge(const T &a,const T &b){
    if (a == b){
        cout << "Hey,equal!" << endl;
        return true;
    }
    else{
        cout << "Oh,not equal!" << endl;
        return false;
    }
}

//模板的局限性
//体现在特殊类型数据类型无法适应函数、算法时
//需要单独具体化处理

template<> bool equal_judge(const Person &a, const Person &b){
    if(a.age == b.age){
        cout << "Hey,ages equal!" << endl;
        return true;
    }
    else{
        cout << "Oh,ages not equal!" << endl;
        return false;
    }
}

int main(){
    int int_a = 10;
    int int_b = 10;

    equal_judge(int_a,int_b);

    Person std_1;
    Person std_2;

    std_1.name = "Tom";
    std_1.name = "Tom";
    std_2.age = 10;
    std_2.age = 12;

    equal_judge(std_1,std_2);

    return 0;
}
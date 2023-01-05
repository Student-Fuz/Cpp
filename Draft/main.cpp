//
// Created by Fu_zh on 2023/1/4.
//

#include<iostream>

using namespace std;

typedef struct __STUDENT
{
    int age;
    __STUDENT() : age(18)
    {
        cout << "struct initial" << endl;
    }
}STUDENT;
int main(){

//    STUDENT s;
//
//    cout << "Age of s is " << s.age << endl;

    char *ptr;

    cout << ptr << endl;
    return 0;
}
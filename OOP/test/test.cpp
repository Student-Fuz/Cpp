//
// Created by Fu_zh on 2022/8/28.
//

#include "test.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(){

    int * a;
    a = new int;

    cout << sizeof(*a) << endl;

    int * b;

    b = (int*)malloc(10000);

    cout << sizeof(*b) << endl;


    a = new int[10];

    string s = "ab";
    char str[] = "ab";

    cout << sizeof(s) << endl;
    cout << s.length() << endl;
    cout << strlen(str) << endl;

    return 0;
}

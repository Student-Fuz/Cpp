//
// Created by Fu_zh on 2023/1/1.
//

#include <iostream>
using namespace std;
int main()
{
    int a = 5;
    double b = 1.0;
    auto f = [&]{a++;return (5*a+b);};//°´Öµ²¶»ña
    cout << f() << endl;
    return 0;
}
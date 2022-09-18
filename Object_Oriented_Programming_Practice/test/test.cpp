//
// Created by Fu_zh on 2022/8/28.
//

#include "test.h"
#include <iostream>

using namespace std;

int main(){
//    int num_a = 10;
//    int * a = &num_a;
//    *(a+1) = 20;
//    cout << a << endl;
//    cout << *(a+1) << endl;

    int num_a[2] = {10,10};
    int * a = num_a;
    *(a+1) = 20;
    cout << a << endl;
    cout << *(a+1) << endl;
    return 0;
}

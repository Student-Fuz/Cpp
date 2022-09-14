#include <iostream>
#include "template.h"
//#include <arm_neon.h>

void load(int* ptr, int value){
    *ptr = value;
}

int main() {
//    printf("%d",Number(One));
//    int a = 15 , b = 23;
//    swap<int>(a,b);*/
//    std::cout << "a = " << a << std::endl;
//    std::cout << "b = " << b << std::endl;
//    print(Number::One);
//    int len = 10;
//    len = len & 3;
//    std::cout << len << std::endl;
    int data[10]={0};
    int* ptr = data;
    load(ptr+1,1);
    std::cout << ptr[1] << std::endl;
    return 0;
}

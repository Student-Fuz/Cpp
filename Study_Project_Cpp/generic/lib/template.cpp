//
// Created by Fu_zh on 2022/3/27.
//
#include <iostream>
#include "template.h"

template<typename T>
void swap(T& t1, T& t2)
{
    T temp = t2;
    t2 = t1;
    t1 = temp;
}

template<typename T>
void print(T& t)
{
    printf("%d",t);
}

template void swap<int>(int& a, int& b);
template void print<Number>(Number& a);

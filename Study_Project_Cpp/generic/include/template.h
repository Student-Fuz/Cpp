//
// Created by Fu_zh on 2022/3/27.
//

#ifndef STUDY_PROJECT_CPP_TEMPLATE_H
#define STUDY_PROJECT_CPP_TEMPLATE_H

#endif //STUDY_PROJECT_CPP_TEMPLATE_H

#define Number(item__) Number::item__

template<typename T>
void swap(T& t1, T& t2);

template<typename T>
void print(T& t);

enum class Number : int{
    Zero = 0,
    One = 1
};
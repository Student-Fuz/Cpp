//
// Created by Fu_zh on 2023/1/5.
//

#include <iostream>
#include <strstream>
#include <string>
#include <sstream>

using namespace std;

int main(){

    string str = "I am very happy!";
    string temp;

    // sstream库
    // 通过stringstream 进行单词切分
    stringstream sstr_1;
    sstr_1 << str;
    while (sstr_1 >> temp)
        cout << temp << endl;


    //strstream库
    //通过sstream 进行单词切分
    strstream sstr_2;
    sstr_2 << str;
    while (sstr_2 >> temp)
        cout << temp << endl;
    return 0;
}


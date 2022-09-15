#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main(){

    string str0 = "1";
    string str1 = "12";

    cout << sizeof(str0) << endl;
    cout << sizeof(str1) << endl;
    cout << sizeof(string) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(int8_t) << endl;
    cout << sizeof(int16_t) << endl;
    cout << sizeof(int) << endl;



    return 0;
}
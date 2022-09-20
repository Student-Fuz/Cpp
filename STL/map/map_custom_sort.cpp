//
// Created by Fu_zh on 2022/9/20.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;

//仿函数
class MyCompare{
public:
    bool operator()(int v1, int v2){
        //降序
        return v1 > v2;
    }
};

int main() {
//    map<int, int> m;
//    m.insert(make_pair(1,10));
//    m.insert(make_pair(2,20));
//    m.insert(make_pair(3,30));
//    m.insert(make_pair(4,40));
//    m.insert(make_pair(5,50));
//
//    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
//        cout << "key: " << it->first << "value: " << it->second << endl;
//    }

    map<int, int, MyCompare> m;
    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));
    m.insert(make_pair(5,50));

    for(map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++){
        cout << "key: " << it->first << " value: " << it->second << endl;
    }

    return 0;
}
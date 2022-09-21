//
// Created by Fu_zh on 2022/9/20.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;


int main() {

    unordered_map<int, int> m;
    m.insert(make_pair(5,50));
    m.insert(make_pair(1,10));
    m.insert(make_pair(2,20));
    m.insert(make_pair(3,30));
    m.insert(make_pair(4,40));


    for(unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++){
        cout << "key: " << it->first << " value: " << it->second << endl;
    }

    return 0;
}
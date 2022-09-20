//
// Created by Fu_zh on 2022/9/20.
//


#include <iostream>
#include <map>

using namespace std;

int main(){
//    map<string,string> mp;
//
//
//    mp["b"] = "c";
//    mp["a"] = "b";
//    mp["d"] = "e";
//
//    for(map<string,string>::iterator it = mp.begin(); it != mp.end(); it++){
//        cout << it->second << endl;
//    }

    multimap<string,string> mmp;

    mmp.insert(pair<string,string>("a","b"));
    mmp.insert(pair<string,string>("a","b"));

    for(map<string,string>::iterator it = mmp.begin(); it != mmp.end(); it++){
        cout << it->second << endl;
    }

    map<string,string>::iterator it = mmp.begin();
    cout << mmp.count("a") << endl;

    return 0;
}
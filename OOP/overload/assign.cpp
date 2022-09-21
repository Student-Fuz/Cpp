//
// Created by Fu_zh on 2022/9/21.
//

#include <iostream>

using namespace std;

//class Person{
//public:
//    void print(){
//        cout << "name: " << name << " age: " << age << endl;
//    }
//    string name;
//    int age;
//};
class Person;

class Person{
public:
    Person &operator=(const Person& p){
        age = p.age;
        return *this;
    }
    Person(string m_name,int m_age){
        name = m_name;
        age = m_age;
    }

    void print(){
        cout << "name: " << name << " age: " << age << endl;
    }

private:
    string name;
    int age;
};

int main(){
    Person p1("Jack",11);
    Person p2("Mary",10);

    p2 = p1;

    p1.print();
    p2.print();

    return 0;
}
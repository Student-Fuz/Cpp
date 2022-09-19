//
// Created by Fu_zh on 2022/8/20.
//

#include<iostream>
using namespace std;
class Teacher {
public:
    Teacher(){
        cout << "Teacher的默认构造函数调用" << endl;
    }
    Teacher(int age, int Height){
        m_Age = age;

        //在堆区开辟了内存空间
        //让m_Height指向该区域
        m_Height = new int(Height);
        cout << "Teacher的有参构造函数调用" << endl;
    }

    //自己实现拷贝构造函数，解决浅拷贝带来的问题
    Teacher(const Teacher &t){
        cout << "Teacher 拷贝函数调用" << endl;
        m_Age = t.m_Age;

        //浅拷贝
        //m_Height = t.m_Height; 编译器默认实现的就是这行代码

        //深拷贝操作
        m_Height = new int(*t.m_Height);
    }

    ~Teacher(){
        //析构函数 将堆区开辟数据做释放操作
        if(m_Height != NULL){
            delete m_Height;
            m_Height = NULL;
        }
        cout << "Teacher的析构函数调用" << endl;
    }

    int m_Age; //年龄
    int *m_Height; //身高

};

void test01(){
    Teacher t1(18, 165);
    cout << "t1的年龄为： " << t1.m_Age << " t1的身高为： " << *t1.m_Height << endl;
    Teacher t2(t1);
    cout << "t2的年龄为： " << t2.m_Age << " t2的身高为： " << *t2.m_Height << endl;
}

int main(){
    test01();
    return 0;
}
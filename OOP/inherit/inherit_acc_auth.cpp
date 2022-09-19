//
// Created by Fu_zh on 2022/8/28.
//

#include <iostream>

using namespace std;

class Base{
public:
    //任何继承方式都能访问
    int m_A;
protected:
    //任何继承方式都能访问
    int m_B;
private:
    //任何继承方式都无法访问
    int m_C;
};

//公共继承
//父类属性继承后的权限转换：
//public ==> public
//protected ==> protected
class pub_inherit : public Base{
public:
    void print(){
        //合法
        cout << "m_A:" << m_A << endl;
        cout << "m_B:" << m_B << endl;

        //非法
        //cout << "m_C:" << m_C << endl;
    }
};

//保护继承
//父类属性继承后的权限转换：
//public ==> protected
//protected ==> protected
class prtct_inherit : protected Base{
public:
    void print(){
        //合法
        cout << "m_A:" << m_A << endl;
        cout << "m_B:" << m_B << endl;

        //非法
        //cout << "m_C:" << m_C << endl;
    }
};

//私有继承
//父类属性继承后的权限转换：
//public ==> private
//protected ==> private
class prvt_inherit : private Base{
public:
    void print(){
        //合法
        cout << "m_A:" << m_A << endl;
        cout << "m_B:" << m_B << endl;

        //非法
        //cout << "m_C:" << m_C << endl;
    }
};

//二次全公共继承
//公共继承的继承
class pub_inherit_inh : public pub_inherit{
    void print(){
        //合法
        cout << "m_A:" << m_A << endl;
        cout << "m_B:" << m_B << endl;

        //非法
        //cout << "m_C:" << m_C << endl;
    }
};

//保护继承的继承
class prtct_inherit_inh : public prtct_inherit{
    void print(){
        //合法
        cout << "m_A:" << m_A << endl;
        cout << "m_B:" << m_B << endl;

        //非法
        //cout << "m_C:" << m_C << endl;

    }
};

//私有继承的继承
class prvt_inherit_inh : public prvt_inherit{
    void print(){

        //非法
        //cout << "m_A:" << m_A << endl;
        //cout << "m_B:" << m_B << endl;

        //非法
        //cout << "m_C:" << m_C << endl;
    }
};

int main(){

    pub_inherit pub_inh;
    cout << "pub_inh.m_A" << pub_inh.m_A << endl;

    //非法
    //cout << "pub_inh.m_B" << pub_inh.m_B << endl;


    prtct_inherit prtct_inh;

    //非法
    //cout << "prtct_inherit.m_A" << prtct_inh.m_A << endl;
    //非法
    //cout << "prtct_inherit.m_A" << prtct_inh.m_A << endl;

    prvt_inherit prvt_inh;

    //非法
    //cout << "prvt_inherit.m_A" << prvt_inh.m_A << endl;
    //非法
    //cout << "prvt_inherit.m_A" << prvt_inh.m_A << endl;



    return 0;
}

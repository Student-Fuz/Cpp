//
// Created by Fu_zh on 2022/8/23.
//

#include <iostream>
#include <string>
using namespace std;


/*****************************************************
声明
注意：声明按顺序执行，须保证当前声明所使用的其它声明存在
*****************************************************/

class Building;

void goodGuy(Building *building);

void acquaintance(Building *building);

class Goodguy{
public:

    Goodguy();

    void visit();//参观函数 访问Building中的属性

    Building *building;
};

class Goodgirl{
public:

    Goodgirl();

    void visit();//参观函数 访问Building中的属性

    Building *building;
};

class Building{
    //将全局函数goodGuy设置为Building类的友元
    friend void goodGuy(Building *building);

    //将类Goodguy设置为Building类的友元
    friend class Goodguy;

    //将成员函数设置为Building类的友元
    friend void Goodgirl::visit();

public:
    Building();
    string Setting_room;
private:
    string BedRoom;
};

/*******************************
实现
*******************************/

//class Building{
//
//    //将全局函数goodGuy设置为Building类的友元
//    friend void goodGuy(Building *building);
//
//    //将类Goodguy设置为Building类的友元
//    friend class Goodguy;
//
//    friend void Goodgirl::visit();
//
//
//public:
//    Building(){
//        Setting_room = "客厅";
//        BedRoom = "卧室";
//    }
//    string Setting_room = "客厅";
//private:
//    string BedRoom;
//};

Building::Building(){
    Setting_room = "客厅";
    BedRoom = "卧室";
}


/*******************************
全局函数做友元
*******************************/

void goodGuy(Building *building){
    //公共权限
    cout << "好朋友goodGuy正在访问" << building->Setting_room << endl;
    //私有权限
    cout << "好朋友goodGuy正在访问" << building->BedRoom << endl;
}

void acquaintance(Building *building){
    //公共权限
    cout << "泛泛之交acquaintance正在访问" << building->Setting_room << endl;
    //私有权限 访问私有权限属性报错
    //cout << "泛泛之交acquaintance正在访问" << building->BedRoom << endl;
}

/*******************************
类做友元
*******************************/

//类外实现类的成员函数

Goodguy::Goodguy(){
    building = new Building;
}

void Goodguy::visit() {

    cout << "类Goodguy正在访问" << building->Setting_room << endl;

    cout << "类Goodguy正在访问" << building->BedRoom << endl;
}

/*******************************
成员函数做友元
*******************************/


Goodgirl::Goodgirl(){
    building = new Building;
}

void Goodgirl::visit() {

    cout << "类Goodgirl正在访问" << building->Setting_room << endl;

    cout << "类Goodgirl正在访问" << building->BedRoom << endl;
}

int main(){
//    Building my_house;
//
//    //全局函数做友元
//    goodGuy(&my_house);
//    acquaintance(&my_house);
//
//    //类做友元
//    Goodguy gg;
//    gg.visit();

    //成员函数做友元
    Goodgirl ggl;
    ggl.visit();

    return 0;
}
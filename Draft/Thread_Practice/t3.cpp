#include <iostream>
#include "windows.h"  
using namespace std;
DWORD WINAPI FunProc1(LPVOID lpParameter);
DWORD WINAPI FunProc2(LPVOID lpParameter);
int number = 1;
HANDLE hSemaphore;  //定义信号量句柄

int main()
{
    HANDLE hThread1;
    HANDLE hThread2;
    hSemaphore = CreateSemaphore(
        NULL,//指定安全属性，一般传入NULL
        1,   //指定信号量对象的初始值。该值必须大于等于0
        100, //指出该信号量的最大值，该值必须大于0。
        NULL//给出信号量的名字。
    );      //当前1个资源，最大允许100个同时访问   
    hThread1 = CreateThread(
        NULL, //为NULL则表示返回的句柄不能被子进程继承
        0,   //设置初始栈的大小，以字节为单位，如果为0，那么默认将使用与调用该函数的线程相同的栈空间大小。
        FunProc1, //指向线程函数的指针
        NULL, //向线程函数传递的参数，是一个指向结构的指针，不需传递参数时，为NULL。
        0, //控制线程创建的标志，0：表示创建后立即激活
        NULL //保存新线程的id，是指向线程id的指针，如果为空，线程id不被返回
    ); //函数成功，返回线程句柄，否则返回NULL
    hThread2 = CreateThread(NULL, 0, FunProc2, NULL, 0, NULL);//创建后立即激活
    if (hThread1 != NULL)CloseHandle(hThread1);
    if (hThread2 != NULL)CloseHandle(hThread2);
    Sleep(20000);             // 让主线程睡眠1秒     
    if (hSemaphore != NULL)CloseHandle(hSemaphore);

    return 0;
}
DWORD WINAPI FunProc1(LPVOID lpParameter)
{
    long count;
    while (number<25)
    {
        WaitForSingleObject(hSemaphore, INFINITE);//hSemaphore空闲状态时，申请该信号量    
        Sleep(1);
        cout << "FunProc 1:" << number << "count is " << count << endl;
        ++number;
        ReleaseSemaphore(
            hSemaphore,//信号量句柄
            1,      //当前资源计数上加"1"
            &count //返回当前资源计数的原始值
        );
    }
    return 0;
}
DWORD WINAPI FunProc2(LPVOID lpParameter)
{
    long count;
    while (number < 25)
    {
        WaitForSingleObject(hSemaphore, INFINITE);//hSemaphore空闲状态时，申请该信号量     
        Sleep(1);
        cout << "FunProc 2:" << number << "count is " << count << endl;
        ++number;
        ReleaseSemaphore(
            hSemaphore,//信号量句柄
            1,      //当前资源计数上加"1"
            &count //返回当前资源计数的原始值
        );
    }
    
    return 0;
}

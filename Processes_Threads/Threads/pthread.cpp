//
// Created by Fu_zh on 2022/12/31.
//

#include<pthread.h>
#include<iostream>

using namespace std;

#define NUM_THREADS 5

// 线程的运行函数
void* print_hello(void* threadid)
{
    //对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int*)threadid);
    cout << "Hello Runoob！线程：" << tid << endl;
    return 0;
}

int main()
{
    // 定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];
    int ret;
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        cout << "main() : 创建线程: " << i << endl;
        indexes[i] = i;
        //参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
        //传入参数需要位void*类型
        ret = pthread_create(&tids[i], NULL, print_hello, (void*)&(indexes[i]));
        if (ret != 0)
        {
            cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}

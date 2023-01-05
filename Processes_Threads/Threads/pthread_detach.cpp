//
// Created by Fu_zh on 2023/1/1.
//
#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS     5

void *wait(void *t)
{
    int i;
    long tid;

    tid = *((int*)t);

    sleep(1);
    cout << "Sleeping in thread " << endl;
    cout << "Thread with id : " << tid << "  ...exiting " << endl;
    pthread_exit(NULL);
}

int main ()
{
    int rc;
    int i;
    pthread_t threads[NUM_THREADS];

    pthread_attr_t attr_join;
    pthread_attr_t attr_detach;

    void *status;

    // 初始化并设置线程为可连接的（joinable）
    pthread_attr_init(&attr_join);
    pthread_attr_setdetachstate(&attr_join, PTHREAD_CREATE_JOINABLE);

    pthread_attr_init(&attr_detach);
    pthread_attr_setdetachstate(&attr_detach, PTHREAD_CREATE_DETACHED);

    for( i=0; i < NUM_THREADS; i++ ){
        cout << "main() : creating thread, " << i << endl;
        //创建可连接线程
        //rc = pthread_create(&threads[i], &attr_join, wait, (void *)&i );
        //创建分离
        rc = pthread_create(&threads[i], &attr_detach, wait, (void *)&i );
        if (rc){
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }

    // 删除属性，并等待其他线程
    pthread_attr_destroy(&attr_join);
    pthread_attr_destroy(&attr_detach);
    for( i=0; i < NUM_THREADS; i++ ){
        //挂起等待线程threads[i]结束
        rc = pthread_join(threads[i], &status);
        if (rc){
            cout << "Error:unable to join," << rc << endl;
            exit(-1);
        }
        cout << "Main: completed thread id :" << i ;
        cout << "  exiting with status :" << status << endl;
    }

    cout << "Main: program exiting." << endl;
    pthread_exit(NULL);
}

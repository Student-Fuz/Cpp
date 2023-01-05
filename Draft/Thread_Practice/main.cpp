#include<stdio.h>
#include<iostream>
#include<pthread.h>
#include"custom_timer.h"


using namespace std;

#define TIMES 10000000

struct data{
    int a_array[TIMES];
    int b_array[TIMES];
};
struct data data1;
void* thread1( void *arg )
{
    for(int i = 0; i < TIMES; i++)
    data1.a_array[i] = 1;
    return 0;
}
void* thread2( void *arg )
{
    for(int i = 0; i < TIMES; i++)
        data1.b_array[i] = 1;
    return 0;
}
int main( int argc, char *argv[] )
{
    pthread_t th;
    int ret1,ret2;
    int arg = 10;
    int *thread_ret1 = NULL;
    int *thread_ret2 = NULL;
    stop_watch watch;

    ret1 = pthread_create( &th, NULL, thread1, &arg );
    ret2 = pthread_create( &th, NULL, thread1, &arg );
    if( ret1 != 0 && ret2 != 0 ){
        printf( "Create thread error!\n");
        return -1;
    }
    printf( "This is the main process.\n" );

    watch.start();
    pthread_join( th, (void**)&thread_ret1 );
    pthread_join( th, (void**)&thread_ret2 );

    watch.stop();
    cout << watch.elapsed() << " ns" << endl;
    return 0;
}

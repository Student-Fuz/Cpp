#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int var=1;

void *tfn(void *arg)  //每个子线程进行回收
{
    int i;
    i = (int)arg;

    sleep(i);  //输出有顺序
    if(i == 1){
        var = 3;
        printf("var = %d\n",var);
        return (void *)var;

    }else if(i == 3){

        var = 7;
        printf("I'm %d th 线程,线程ID为 %lu var = %d\n",i+1,pthread_self(),var);
        pthread_exit((void *)var);
    }else {

        printf("I'm %d th 线程，线程ID = %lu\n var = %d\n",i+1,pthread_self(),var);
        pthread_exit((void *)var);
    }

    return NULL;
}

int main(void)
{
    pthread_t tid[5];
    int i,sum=0;
    int *ret[5]; //保存 5个线程的退出值

    for(i = 0;i < 5; i++)//循环创建多个子线程
        pthread_create(&tid[i],NULL,tfn,(void*)i);

    for(i=0;i < 5; i++){ //对多个子线程进行回收
        pthread_join(tid[i],(void **)&ret[i]);
        printf("-----------%d th ret = %d\n",i,(int)ret[i]);
        sum=sum+(int)ret[i];
    }
    printf("sum=%d \n",sum);
    printf("I'm main 线程 tid = %lu\t var = %d\n",pthread_self(),var);
    return 0;
}
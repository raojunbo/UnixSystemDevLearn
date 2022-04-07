//
//  thread_mutex_demo.c
//  pthread
//
//  Created by junbo.rao on 2022/4/7.
//

#include "thread_mutex_demo.h"
#import <pthread.h>
#import <stdio.h>
#import <stdlib.h>
#include <unistd.h>

#define NUM_OF_TASKS 5
int money_of_tom = 100;
int money_of_jerry = 100;
pthread_mutex_t g_money_lock;

// 在多个子线程里进行转账
void *transfer(void *notused) {
    pthread_t tid = pthread_self();
    printf("Thread %u is transfering money!\n",(unsigned int)tid);
    // 在没有枪到锁时，进入休眠。在下次被唤醒，被调度时，继续执行。
    pthread_mutex_lock(&g_money_lock);
    
    sleep(rand()%10);
    money_of_tom += 10;
    sleep(rand()%10);
    money_of_jerry -= 10;
    // 解锁
    pthread_mutex_unlock(&g_money_lock);
    printf("Thread %u finish transfering money!\n",(unsigned int)tid);
    
    pthread_exit((void *)0);
}
void test_thread_mutex(void) {
    pthread_t threads[NUM_OF_TASKS];
    pthread_mutex_init(&g_money_lock, NULL);
    
    pthread_attr_t thread_atr;
    pthread_attr_init(&thread_atr);
    pthread_attr_setdetachstate(&thread_atr, PTHREAD_CREATE_DETACHED);
    
    // 创建NUM_OF_TASKS个线程
    int rc;
    for(int t = 0; t < NUM_OF_TASKS; t++) {
        rc = pthread_create(&threads[t], &thread_atr, transfer, NULL);
        if (rc) {
            printf("ERROR; return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    // 在主线程打印值
    for(int t = 0; t < 100; t++) {
        pthread_mutex_lock(&g_money_lock);
        printf("money_of_tom + money_of_jerry = %d\n", money_of_tom + money_of_jerry);
        pthread_mutex_unlock(&g_money_lock);
    }
    pthread_mutex_destroy(&g_money_lock);
    pthread_exit(NULL);
}

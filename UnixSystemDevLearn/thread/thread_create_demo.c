//
//  thread_create_demo.c
//  pthread
//
//  Created by junbo.rao on 2022/4/7.
//

#include "thread_create_demo.h"
// unistd.h 是 C 和 C++ 程序设计语言中提供对 POSIX 操作系统 API 的访问功能的头文件的名称。该头文件由 POSIX.1 标准（可移植系统接口）提出
// 对于类 Unix 系统，unistd.h 中所定义的接口通常都是大量针对系统调用的封装（英语：wrapper functions），如 fork、pipe 以及各种 I/O 原语（read、write、close 等等）。
#import <unistd.h>

//POSIX线程（英语：POSIX Threads，常被缩写为Pthreads）是POSIX的线程标准，定义了创建和操纵线程的一套API。
//实现POSIX 线程标准的库常被称作Pthreads，一般用于Unix-likePOSIX 系统
#import <pthread.h>

//stdlib 头文件里包含了C、C++语言的最常用的系统函数
//该文件包含了C语言标准库函数的定义
#import <stdlib.h>

//stdio 就是指 “standard input & output"（标准输入输出）
#import <stdio.h>

#define NUM_OF_TASKS 5

void *downloadfile(void *filename) {
    printf("I am downloading the file%s\n",(char *)filename);
    sleep(10);
    long downloadingTime = rand()%100;
    printf("I finish downloading the file within %ld minutes!\n", downloadingTime);
    pthread_exit((void *)downloadingTime);
}
void test_thread_create(void) {
    char files[NUM_OF_TASKS][20] = {"file1.avi","file2.avi","file3.avi","file4.avi","file5.avi"};
    pthread_t threads[NUM_OF_TASKS];
    
    
    pthread_attr_t thread_atr;
    // 初始化pthread_attr_t
    pthread_attr_init(&thread_atr);
    // 设置线程detach状态
    // PTHREAD_CREATE_JOINABLE      1 ;// 表示需要主线程需要等待子线程返回
    // PTHREAD_CREATE_DETACHED      2
    pthread_attr_setdetachstate(&thread_atr, PTHREAD_CREATE_JOINABLE);
    
    for (int t = 0; t < NUM_OF_TASKS; t++) {
        // downloadile 为线程要执行的函数
        // files[t] 为线程要执行的函数的参数
        int  rc = pthread_create(&threads[t], &thread_atr, downloadfile, files[t]);
        if (rc) {
            printf("error, return code from pthread_create()");
            exit(-1);
        }
    }
    pthread_attr_destroy(&thread_atr);
    printf("主线程要进入等待\n");
    int downloadtime;
    for (int t = 0; t < NUM_OF_TASKS; t++) {
        // downloadtime为接收线程返回的参数
        pthread_join(threads[t], (void **)&downloadtime);
        printf("Thread %d downloads the file %s in %d minutes.\n",t,files[t],downloadtime);
    }
}

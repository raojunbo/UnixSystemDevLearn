//
//  dlopen.c
//  UnixSystemDevLearn
//
//  Created by junbo.rao on 2022/4/18.
//

#include "dlopenDemo.h"
#import <dlfcn.h>
#import <stdio.h>

int test_dlopen(void) {
    void * handle;
    double (*func)(double);
    char *error;
    // 打开指定的动态库
    handle = dlopen(NULL, RTLD_NOW);
    if (handle == NULL) {
        printf("打开动态库 %s error/n",  dlerror());
        return  -1;
    }
    // 根据打开的句柄，查找符号的地址，是函数，直接调用
    func = dlsym(handle, "sin");
    if ((error = dlerror()) != NULL) {
        printf("符号 sin 没有找到 %s\n",error);
        dlclose(handle);
    }
    printf("符号sin 找到了");
    
    printf("%f\n", func(3.1415926/2));
    dlclose(handle);
    return 0;
}

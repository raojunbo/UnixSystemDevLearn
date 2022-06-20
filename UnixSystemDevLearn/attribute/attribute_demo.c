//
//  attribute_demo.c
//  UnixSystemDevLearn
//
//  Created by junbo.rao on 2022/4/7.
//

#include "attribute_demo.h"

__attribute__((constructor)) static void beforeFunction()
{
    printf("beforeFunction\n");
}

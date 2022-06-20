//
//  main.m
//  UnixSystemDevLearn
//
//  Created by junbo.rao on 2022/4/7.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
@interface Person : NSObject
@property(nonatomic,assign) int age;
@end
@implementation Person
+ (void)load {
    
}
- (void)testObject {
    
}
@end

typedef void (^YZBlock)(void);

int main(int argc, char * argv[]) {
    __weak Person *person = [[Person alloc]init];
    [person testObject];
    return 0;
}

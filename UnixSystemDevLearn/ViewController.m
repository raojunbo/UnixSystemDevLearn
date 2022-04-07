//
//  ViewController.m
//  UnixSystemDevLearn
//
//  Created by junbo.rao on 2022/4/7.
//

#import "ViewController.h"
#import "thread_create_demo.h"
#import "thread_mutex_demo.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    test_thread_create();
}


@end

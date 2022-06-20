//
//  ViewController.m
//  UnixSystemDevLearn
//
//  Created by junbo.rao on 2022/4/7.
//

#import "ViewController.h"
#import "thread_create_demo.h"
#import "thread_mutex_demo.h"
#import "dlopenDemo.h"
#import "RuntimViewController.h"
@interface ViewController ()
@property(nonatomic, strong) UIButton *runtimeBtn;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(0, 100, 100, 50);
    [btn setTitle:@"进入runtime" forState:UIControlStateNormal];
    btn.backgroundColor = [UIColor redColor];
    [btn addTarget:self action:@selector(buttonClick) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn];
}
- (void)buttonClick {
    RuntimViewController *runtime = [[RuntimViewController alloc]init];
    [self presentViewController:runtime animated:YES completion:nil];
}
@end

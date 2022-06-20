//
//  RuntimViewController.m
//  UnixSystemDevLearn
//
//  Created by junbo.rao on 2022/5/2.
//

#import "RuntimViewController.h"

@interface RuntimeDemoObject : NSObject

@end

@implementation RuntimeDemoObject

@end


@interface RuntimViewController ()

@end

@implementation RuntimViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];

    [RuntimeDemoObject performSelector:@selector(testObject)];
    
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end

//
//  ViewController.m
//  Demo
//
//  Created by xxx on 16/8/10.
//  Copyright © 2016年 appadhoc. All rights reserved.
//

#import "ViewController.h"
@import AdhocSDK;

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (IBAction)btnClick:(UIButton *)btn {
    if (btn.tag == 1) {
        BOOL f1 = [[AdhocSDK getFlag:@"f1" default:@NO] boolValue];
        if (f1 == YES) {
            NSLog(@"BOOL flag 'f1' = YES");
        } else {
            NSLog(@"BOOL flag 'f1' = NO");
        }
    } else if (btn.tag == 2) {
        NSString *f2 = [AdhocSDK getFlag:@"f2" default:@"str1"];
        if ([f2 isEqualToString:@"str1"]) {
            NSLog(@"NSString flag 'f2' = str1");
        } else if ([f2 isEqualToString:@"str2"]) {
            NSLog(@"NSString flag 'f2' = str2");
        }
    } else if (btn.tag == 3) {
        NSNumber *f3 = [AdhocSDK getFlag:@"f3" default:@0];
        if ([f3 isEqualToNumber:@0]) {
            NSLog(@"NSNumber flag 'f3' = 0");
        } else if ([f3 isEqualToNumber:@1]) {
            NSLog(@"NSNumber flag 'f3' = 1");
        }
    } else if (btn.tag == 4) {
        [AdhocSDK track:@"t1" value:@1];
    } else if (btn.tag == 5) {
        [AdhocSDK track:@"t1" value:@1 attribute:@{@"name": @"aa"}];
    } else if (btn.tag == 6) {
        [AdhocSDK asynchronousGetFlag:@"f1"
                         defaultValue:@NO
                      timeoutInterval:3
                    completionHandler:^(id flag_value, NSError *error) {
                        if (!error) {
                            __unused BOOL f1 = [flag_value boolValue];
                        }
                    }];
    }
}

@end

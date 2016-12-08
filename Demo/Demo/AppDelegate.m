//
//  AppDelegate.m
//  Demo
//
//  Created by xxx on 16/8/10.
//  Copyright © 2016年 appadhoc. All rights reserved.
//

#import "AppDelegate.h"
@import AdhocSDK;

@interface AppDelegate ()

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    //创建用于SDK启动的配置实例
    AdhocSDKConfig *config = [AdhocSDKConfig defaultConfig];
    
    //设置appKey
    config.appKey = @"ADHOC_c6655b28-12b9-49c7-8987-af337eff73f4";
    
    //是否显示调试按钮
#ifdef DEBUG
    config.debugAssistiveShow = YES;
#else
    config.debugAssistiveShow = NO;
#endif
    
    //设置用户标签
    config.customProperty = @{@"gender": @"boy"};
    
    //启动SDK
    [AdhocSDK startWithConfigure:config options:launchOptions];
    
    
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

@end

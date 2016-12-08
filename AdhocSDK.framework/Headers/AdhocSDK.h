//
//  AdhocSDK.h
//  AdhocSDK
//
//  Created by Adhoc on 15/4/21.
//  Copyright (c) 2015年 Adhoc. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  用于SDK启动
 */
@interface AdhocSDKConfig : NSObject
@property (nonatomic, copy) NSString *appKey;  //官网申请的key，必填项
@property (nonatomic) BOOL debugAssistiveShow; //是否显示调试按钮，默认为NO，不显示（若显示，getflag与track接口访问实时处理，设置的时间间隔无效）
@property (nonatomic) BOOL crashTrackEnabled;  //是否统计crash数据，默认为NO，不进行统计
@property (nonatomic, strong) NSDictionary *customProperty; //设置标签
+ (id)defaultConfig;
@end

/**
 *  用于获取实验变量以及进行优化指标统计
 */
NS_CLASS_AVAILABLE_IOS(7_0) @interface AdhocSDK : NSObject

/// SDK启动入口，需在@selector(application:didFinishLaunchingWithOptions:)里启动
+ (void)startWithConfigure:(AdhocSDKConfig *)config options:(NSDictionary *)options;

/**
 *  获取后台设置的指定的实验变量的值，实验变量的名字注意与后台保持一致
 *  该方法从SDK缓存中直接读取，如需同步获取flag值，请使用下面的接口
 *
 *  @param flag_name     adhoc后台设置的实验变量名字
 *  @param default_value 指定实验变量的默认值
 *
 *  @return 根据后台设置的模块的类型，返回的Obj-C中对应的类型可能为(NSNumber, NSString)
 */
+ (id)getFlag:(NSString *)flag_name default:(id)default_value;

/**
 *  异步方式从服务器直接获取实验变量的值
 *
 *  @param flag_name     adhoc后台设置的实验变量名字
 *  @param default_value 指定实验变量的默认值
 *  @param timeout       设置此次网络请求的超时时间，单位为秒(s)，默认1
 *  @param handler       网络执行结束后的相关操作
 */
+ (void)asynchronousGetFlag:(NSString *)flag_name
               defaultValue:(id)default_value
            timeoutInterval:(NSTimeInterval)timeout
          completionHandler:(void (^)(id flag_value, NSError *error))handler;

/**
 *  统计需要的优化指标，用以实现科学有效的测试
 *
 *  @param stat_name  后台设置的优化指标，名字须保持一致
 *  @param stat_value 当前优化指标单次统计的权重
 *  @param stat_attribute 当前数据的事件标签
 */
+ (void)track:(NSString *)stat_name value:(NSNumber *)stat_value;
+ (void)track:(NSString *)stat_name value:(NSNumber *)stat_value attribute:(NSDictionary *)stat_attribute;

/**
 *  获取当前设备所在实验的实验名列表
 *
 *  @return 实验名数组
 */
+ (NSArray *)getCurrentExperiments;

@end

//
//  AdhocSDK.h
//  AdhocSDK
//
//  Created by Adhoc on 15/4/21.
//  Copyright (c) 2015年 Adhoc. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  用于获取实验变量以及进行优化指标统计
 */
NS_CLASS_AVAILABLE_IOS(7_0) @interface AdhocSDK : NSObject

/**
 *  控制SDK调试按钮显隐
 *
 *  @param show 如果设置为YES，显示调试按钮，否则隐藏
 */
+ (void)showDebugAssistive:(BOOL)show;

/**
 *  设置用户实验变量
 */
+ (void)setTrackProperty:(NSDictionary *)property;

/**
 *  SDK内部在APP每次切到前台时更新本地flags缓存，设置该时间间隔避免用户在较短时间内频繁切换造
 ＊ 成不必要的损失
 *
 *  @param second 时间间隔，单位秒(s)
 */
+ (void)setGapTimeGetFlag:(NSTimeInterval)second;

/**
 *  获取当前设备所在实验的实验名列表
 *
 *  @return 实验名数组
 */
+ (NSArray *)getCurrentExperiments;

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
 *  同步方式从服务器直接获取实验变量的值
 *
 *  @param flag_name     adhoc后台设置的实验变量名字
 *  @param default_value 指定实验变量的默认值
 *  @param timeout       设置此次网络请求的超时时间，单位为秒(s)，默认1
 *  @param error         错误信息
 *
 *  @return 实验变量对应的值，id类型
 */
+ (id)synchronousGetFlag:(NSString *)flag_name
            defaultValue:(id)default_value
         timeoutInterval:(NSTimeInterval)timeout
                   error:(NSError **)error;

/**
 *  统计需要的优化指标，用以实现科学有效的测试
 *
 *  @param stat_name  后台设置的优化指标，名字须保持一致
 *  @param stat_value 当前优化指标单次统计的权重
 */
+ (void)track:(NSString *)stat_name value:(NSNumber*)stat_value;

/**
 *  强制当前设备进入实验，用于开发测试，查看效果
 *
 *  @param qrCode 指定实验的二维码，可以通过官方的扫码工具扫描实验二维码进入实验
 *  @param block  该接口执行后的回调，succ返回YES，当前设备进入试验成功
 */
+ (void)forceToEnterExperiment:(NSString *)qrCode finished:(void(^)(BOOL succ))block;

/**
 *  退出强制加入的试验
 *
 *  @param block  该接口执行后的回调
 */
+ (void)forceToQuitExperimentsFinished:(void (^)(BOOL result, NSError *error))block;

@end

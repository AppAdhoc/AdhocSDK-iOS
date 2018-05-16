# AdhocSDK-iOS
SDK repo for the [**AppAdhoc**](https://www.appadhoc.com) iOS SDK binary and Cocoapods install. 

We support all build targets for iOS 8.0 and above. Enable Bitcode, and support ARC.


# 安装
### CocoaPods
1. 在 Podfile 中添加 `pod 'AdhocSDK'`.
2. 执行 `pod install`.

### 手动安装
1. 官方下载[最新版SDK](http://doc.appadhoc.com/sdk/iosSDK.html).
2. 将下载得到的`AdhocSDK.framework`文件添加到指定的工程.
3. 添加编译参数 `-ObjC`.
4. 必要链接库:
   - libsqlite3.tbd
   - libicucore.tbd (若SDK支持可视化须链接)


# 权限设置
1. SDK调试页面有扫码功能，须授权相机访问:
> `<key>NSCameraUsageDescription</key>`
> `<string>App需要您的同意,才能访问相机</string>`

2. SDK将设备ID存储在本地Keychain中，为保证数据准确，须启用:
> `Target -> Capabilities -> Keychain Sharing -> ON`


# 使用说明
1. SDK的初始化操作须在 `@selector(application:didFinishLaunchingWithOptions:)`中执行：
>
```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    AdhocSDKConfig *config = [AdhocSDKConfig defaultConfig];
    config.appKey = @"ADHOC_xxx"; //必填项，通过官网申请得到
    config.enableDebugAssist = YES; //显示调试按钮，用于开发调试
    config.crashTrackEnabled = YES; //统计崩溃次数
    config.sessionTrackEnabled = YES; //统计APP访问次数
    config.durationTrackEnabled = YES; //统计访问时长
    [AdhocSDK startWithConfigure:config options:launchOptions];
    //sth.
    return YES;
}
```

2. 在实验页面，获取后台设置的试验变量，根据取值的不同，进行不同到实验操作：
>
```
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    //获取Boolean类型的试验变量isNewHomePage的值
    BOOL isNewHomePage = [[AdhocSDK getFlag:@"isNewHomePage" default:@(NO)] boolValue];
    if (isNewHomePage) {
        //跳转至新首页
    } else {
        //跳转至新旧首页
    }
}
```

3. 用户需要在相关的页面事件里上传指定的实验指标，用以判断实验的好坏：
>
```
- (IBAction)btnClicked:(id)sender {
    [AdhocSDK track:@"clickTimes" value:@(1)];
}
```

##### 如有任何问题，详见[官方文档](http://doc.appadhoc.com/sdk/iosSDK.html).



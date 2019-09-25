//
//  FlutterPluginAdhubRewardPlugin.m
//  Pods
//
//  Created by LJM on 2019/9/19.
//

#import "FlutterPluginAdhubRewardPlugin.h"

@class FlutterPluginAdhubRewardPluginDelegate;
@interface FlutterPluginAdhubRewardPlugin ()

/** 视频广告属性 **/
@property (nonatomic, strong) AdHubRewardedVideo *rewardedVideo;
/** registrar **/
@property (nonatomic, strong) NSObject<FlutterPluginRegistrar> *registrar;
/** channel **/
@property (nonatomic, strong) FlutterMethodChannel *channel;
/** 代理 **/
@property (nonatomic, strong) FlutterPluginAdhubRewardPluginDelegate *pluginDelegate;

@end

static FlutterPluginAdhubRewardPlugin *instance = nil;
@implementation FlutterPluginAdhubRewardPlugin


+ (instancetype)allocWithZone:(struct _NSZone *)zone {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [super allocWithZone:zone];
    });
    return instance;
}

+ (instancetype)sharedInstance {
    if (instance == nil) {
        instance = [[super alloc] init];
    }
    return instance;
}

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    
    [FlutterPluginAdhubRewardPlugin sharedInstance].registrar = registrar;
    
    
    [FlutterPluginAdhubRewardPlugin sharedInstance].channel = [FlutterMethodChannel
                                     methodChannelWithName:@"adhub_flutter/reward"
                                     binaryMessenger:[registrar messenger]];
    [registrar addMethodCallDelegate:[FlutterPluginAdhubRewardPlugin sharedInstance] channel:[FlutterPluginAdhubRewardPlugin sharedInstance].channel];
    
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    
    if ([@"loadRewardedVideoAd" isEqualToString:call.method]) {
        NSString *adId = [NSString stringWithFormat:@"%@",call.arguments];
        self.rewardedVideo = [[AdHubRewardedVideo alloc] initWithSpaceID:adId spaceParam:@""];
        self.pluginDelegate = [[FlutterPluginAdhubRewardPluginDelegate alloc] initWithPluginDelegateWithChannel:[FlutterMethodChannel methodChannelWithName:@"adhub_flutter/reward_jm" binaryMessenger:[[FlutterPluginAdhubRewardPlugin sharedInstance].registrar messenger]]];
        self.rewardedVideo.delegate = self.pluginDelegate;
        self.rewardedVideo.adHubRewardedVideoViewController = [UIApplication sharedApplication].keyWindow.rootViewController;
        [self.rewardedVideo ADH_loadRewardedVideoAd];
    } else if ([@"showRewardedVideoAd" isEqualToString:call.method]) {
        [self.rewardedVideo ADH_showRewardedVideoAd];
    }
}


@end




@implementation FlutterPluginAdhubRewardPluginDelegate

- (instancetype)initWithPluginDelegateWithChannel:(FlutterMethodChannel *)channel {
    if (self = [super init]) {
        self.channel = channel;
    }
    return self;
}

/**
 激励视频物料请求成功
 */
- (void)ADH_rewardedVideoDidReceiveAd:(AdHubRewardedVideo *)adHubRewardedVideo {
    [self.channel invokeMethod:@"didReceiveAd" arguments:nil];
}

/**
 激励展现并开始播放视频
 */
- (void)ADH_rewardedVideoDidStartPlay:(AdHubRewardedVideo *)adHubRewardedVideo {
    [self.channel invokeMethod:@"didStartPlay" arguments:nil];
}

/**
 激励视频点击
 */
- (void)ADH_rewardedVideoDidClick:(AdHubRewardedVideo *)adHubRewardedVideo {
    [self.channel invokeMethod:@"didClick" arguments:nil];
}

/**
 激励视频消失
 */
- (void)ADH_rewardedVideoDidDismissScreen:(AdHubRewardedVideo *)adHubRewardedVideo {
    [self.channel invokeMethod:@"didDismissScreen" arguments:nil];
}

/**
 激励视频请求失败
 */
- (void)ADH_rewardedVideo:(AdHubRewardedVideo *)adHubRewardedVideo didFailToLoadAdWithError:(AdHubRequestError *)error {
    [self.channel invokeMethod:@"didError" arguments:nil];
}

/**
 激励视频奖励
 如果有渠道时，此方法仅限用于给用户发放奖励回调，奖励内容不可用。
 @param reward 奖励内容 JSON字符串，自行解析
 */
- (void)ADH_rewardedVideo:(AdHubRewardedVideo *)adHubRewardedVideo didRewardUserWithReward:(NSObject *)reward {
    [self.channel invokeMethod:@"didRewardUserWithReward" arguments:nil];
}

@end

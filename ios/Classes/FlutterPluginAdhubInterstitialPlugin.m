//
//  FlutterPluginAdhubInterstitialPlugin.m
//  Pods
//
//  Created by LJM on 2019/9/25.
//

#import "FlutterPluginAdhubInterstitialPlugin.h"

@class FlutterPluginAdhubInterstitialPluginDelegate;
@interface FlutterPluginAdhubInterstitialPlugin()

/** registrar **/
@property (nonatomic, strong) NSObject<FlutterPluginRegistrar> *registrar;

/** interstitial **/
@property (nonatomic, strong) AdHubInterstitial *interstitial;
/** 代理 **/
@property (nonatomic, strong) FlutterPluginAdhubInterstitialPluginDelegate *pluginDelegate;

@end

static FlutterPluginAdhubInterstitialPlugin *instance = nil;
@implementation FlutterPluginAdhubInterstitialPlugin

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
    [FlutterPluginAdhubInterstitialPlugin sharedInstance].registrar = registrar;
    FlutterMethodChannel* channel = [FlutterMethodChannel
                                                               methodChannelWithName:@"adhub_flutter/interstitial"
                                                               binaryMessenger:[registrar messenger]];
    [registrar addMethodCallDelegate:[FlutterPluginAdhubInterstitialPlugin sharedInstance] channel:channel];
    
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    if ([@"loadInterstitialAd" isEqualToString:call.method]) {
        NSString *adId = [NSString stringWithFormat:@"%@",call.arguments];
        self.interstitial = [[AdHubInterstitial alloc] initWithSpaceID:adId spaceParam:@""];
        self.interstitial.adhubInterstitialController = [UIApplication sharedApplication].delegate.window.rootViewController;
        self.pluginDelegate = [[FlutterPluginAdhubInterstitialPluginDelegate alloc] initWithPluginDelegateWithChannel:[FlutterMethodChannel methodChannelWithName:@"adhub_flutter/interstitial_jm" binaryMessenger:[[FlutterPluginAdhubInterstitialPlugin sharedInstance].registrar messenger]]];
        self.interstitial.delegate = self.pluginDelegate;
        [self.interstitial ADH_loadInterstitialAd];
    } else if ([@"showInterstitialAd" isEqualToString:call.method]) {
        [self.interstitial ADH_showInterstitialAd];
    }
}

@end



@implementation FlutterPluginAdhubInterstitialPluginDelegate

- (instancetype)initWithPluginDelegateWithChannel:(FlutterMethodChannel *)channel {
    if (self = [super init]) {
        self.channel = channel;
    }
    return self;
}

/**
 插屏加载成功
 */
- (void)ADH_interstitialDidReceiveAd:(AdHubInterstitial *)adHubInterstitial {
    NSLog(@"插屏加载成功");
    [self.channel invokeMethod:@"didReceiveAd" arguments:nil];
}

/**
 插屏展现
 */
- (void)ADH_interstitialDidPresentScreen:(AdHubInterstitial *)adHubInterstitial {
    NSLog(@"插屏展现");
    [self.channel invokeMethod:@"didStartPlay" arguments:nil];
}

/**
 插屏点击
 */
- (void)ADH_interstitialDidClick:(AdHubInterstitial *)adHubInterstitial {
    NSLog(@"插屏点击");
    [self.channel invokeMethod:@"didClick" arguments:nil];
}

/**
 插屏消失&&关闭
 */
- (void)ADH_interstitialDidDismissScreen:(AdHubInterstitial *)adHubInterstitial {
    NSLog(@"插屏消失&&关闭");
    [self.channel invokeMethod:@"didDismissScreen" arguments:nil];
}

/**
 插屏请求失败
 */
- (void)ADH_interstitial:(AdHubInterstitial *)adHubInterstitial didFailToLoadAdWithError:(AdHubRequestError *)error {
    NSLog(@"插屏请求失败");
    [self.channel invokeMethod:@"didError" arguments:nil];
}

@end

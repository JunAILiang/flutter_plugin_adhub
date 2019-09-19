//
//  FlutterPluginAdhubPluginInitialize.m
//  Pods
//
//  Created by LJM on 2019/9/19.
//

#import "FlutterPluginAdhubPluginInitialize.h"
#import <AdHubSDK/AdHubSDK.h>

@implementation FlutterPluginAdhubPluginInitialize

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    FlutterMethodChannel* channel = [FlutterMethodChannel
                                     methodChannelWithName:@"adhub_flutter"
                                     binaryMessenger:[registrar messenger]];
    FlutterPluginAdhubPluginInitialize* instance = [[FlutterPluginAdhubPluginInitialize alloc] init];
    [registrar addMethodCallDelegate:instance channel:channel];
}

- (void)handleMethodCall:(FlutterMethodCall*)call result:(FlutterResult)result {
    
    if ([@"initialize" isEqualToString:call.method]) {
        NSString *appId = [NSString stringWithFormat:@"%@",call.arguments];
        [AdHubSDKManager configureWithApplicationID:appId];
    } else if ([@"openTheAdHubLog" isEqualToString:call.method]) {
      [AdHubSDKManager openTheAdHubLog];
   }
}

@end

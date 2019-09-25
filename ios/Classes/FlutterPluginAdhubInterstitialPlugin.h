//
//  FlutterPluginAdhubInterstitialPlugin.h
//  Pods
//
//  Created by LJM on 2019/9/25.
//

#import <Foundation/Foundation.h>
#import <Flutter/Flutter.h>
#import <AdHubSDK/AdHubSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface FlutterPluginAdhubInterstitialPlugin : NSObject<FlutterPlugin>

@end


@interface FlutterPluginAdhubInterstitialPluginDelegate : NSObject<AdHubInterstitialDelegate>

- (instancetype)initWithPluginDelegateWithChannel:(FlutterMethodChannel *)channel;

@property (nonatomic, strong) FlutterMethodChannel *channel;

@end

NS_ASSUME_NONNULL_END

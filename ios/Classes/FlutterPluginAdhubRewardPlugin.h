//
//  FlutterPluginAdhubRewardPlugin.h
//  Pods
//
//  Created by LJM on 2019/9/19.
//

#import <Foundation/Foundation.h>
#import <Flutter/Flutter.h>
#import <AdHubSDK/AdHubSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface FlutterPluginAdhubRewardPlugin : NSObject<FlutterPlugin>

@end

@interface FlutterPluginAdhubRewardPluginDelegate : NSObject<AdHubRewardedVideoDelegate>

- (instancetype)initWithPluginDelegateWithChannel:(FlutterMethodChannel *)channel;

/** delegate **/
@property (nonatomic, strong) id<AdHubRewardedVideoDelegate> delegate;
/** channel **/
@property (nonatomic, strong) FlutterMethodChannel *channel;

@end

NS_ASSUME_NONNULL_END

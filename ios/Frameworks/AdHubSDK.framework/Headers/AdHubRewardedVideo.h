//
//  AdHubRewardedVideo.h
//  AdHubSDK
//
//  Created by 北京市吕俊学 on 2019/3/1.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdHubRewardedVideoDelegate;
@class AdHubRequestError;

@interface AdHubRewardedVideo : NSObject

@property (nonatomic, copy, readonly) NSString *spaceID;
@property (nonatomic, copy, readonly) NSString *spaceParam;

/**
 用来接收激励视频广告读取和展示状态变化通知的 delegate
 */
@property (nonatomic, weak) id<AdHubRewardedVideoDelegate> delegate;

/**
 adHubRewardedVideoViewController 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
 */
@property (nonatomic, weak) UIViewController *adHubRewardedVideoViewController;

/**
 初始化方法
 @param spaceID 广告位 ID
 @param spaceParam 广告位参数 可填写任意字符串
 @return 激励视频广告对象
 */
- (instancetype)initWithSpaceID:(NSString *)spaceID
                     spaceParam:(NSString *)spaceParam NS_DESIGNATED_INITIALIZER;

/**
 请求加载激励视频广告
 */
- (void)ADH_loadRewardedVideoAd;

/**
 激励视频展示，确保广告加载成功后调用
 */
- (void)ADH_showRewardedVideoAd;

@end

/**
 代理方法
 */
@protocol AdHubRewardedVideoDelegate <NSObject>

@optional

/**
 激励视频物料请求成功
 */
- (void)ADH_rewardedVideoDidReceiveAd:(AdHubRewardedVideo *)adHubRewardedVideo;

/**
 激励展现并开始播放视频
 */
- (void)ADH_rewardedVideoDidStartPlay:(AdHubRewardedVideo *)adHubRewardedVideo;

/**
 激励视频点击
 */
- (void)ADH_rewardedVideoDidClick:(AdHubRewardedVideo *)adHubRewardedVideo;

/**
 激励视频消失
 */
- (void)ADH_rewardedVideoDidDismissScreen:(AdHubRewardedVideo *)adHubRewardedVideo;

/**
 激励视频请求失败
 */
- (void)ADH_rewardedVideo:(AdHubRewardedVideo *)adHubRewardedVideo didFailToLoadAdWithError:(AdHubRequestError *)error;

/**
 激励视频奖励
 如果有渠道时，此方法仅限用于给用户发放奖励回调，奖励内容不可用。
 @param reward 奖励内容 JSON字符串，自行解析
 */
- (void)ADH_rewardedVideo:(AdHubRewardedVideo *)adHubRewardedVideo didRewardUserWithReward:(NSObject *)reward;

@end

NS_ASSUME_NONNULL_END

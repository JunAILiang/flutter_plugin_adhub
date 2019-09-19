//
//  AdHubInterstitial.h
//  AdHubSDK
//
//  Created by 北京市吕俊学 on 2019/1/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdHubInterstitialDelegate;
@class AdHubRequestError;

@interface AdHubInterstitial : NSObject

@property (nonatomic, copy, readonly) NSString *spaceID;
@property (nonatomic, copy, readonly) NSString *spaceParam;

/**
 用来接收 Interstitial 广告读取和展示状态变化通知的 delegate
 */
@property (nonatomic, weak) id<AdHubInterstitialDelegate> delegate;

/**
 adhubInterstitialController 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
 详解：[必选]开发者需传入用来弹出目标页的ViewController，一般为当前ViewController
 当需要在Tabbar页面弹出时，根视图须设置为Tabbar，否则会影响广告后续点击
 */
@property (nonatomic, weak) UIViewController *adhubInterstitialController;

/**
 初始化方法
 @param spaceID 广告位 ID
 @param spaceParam 广告位参数 可填写任意字符串
 @return Interstitial 广告对象
 */
- (instancetype)initWithSpaceID:(NSString *)spaceID spaceParam:(NSString *)spaceParam;

/**
 Interstitial 加载
 */
- (void)ADH_loadInterstitialAd;

/**
 Interstitial 展示，确保广告加载成功后调用
 */
- (void)ADH_showInterstitialAd;

@end

/**
 代理方法
 */
@protocol AdHubInterstitialDelegate <NSObject>

@optional

/**
 插屏加载成功
 */
- (void)ADH_interstitialDidReceiveAd:(AdHubInterstitial *)adHubInterstitial;

/**
 插屏展现
 */
- (void)ADH_interstitialDidPresentScreen:(AdHubInterstitial *)adHubInterstitial;

/**
 插屏点击
 */
- (void)ADH_interstitialDidClick:(AdHubInterstitial *)adHubInterstitial;

/**
 插屏消失&&关闭
 */
- (void)ADH_interstitialDidDismissScreen:(AdHubInterstitial *)adHubInterstitial;

/**
 插屏请求失败
 */
- (void)ADH_interstitial:(AdHubInterstitial *)adHubInterstitial didFailToLoadAdWithError:(AdHubRequestError *)error;

@end

NS_ASSUME_NONNULL_END

//
//  AdHubBannerView.h
//  AdHubSDK
//
//  Created by 北京市吕俊学 on 2019/1/2.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdHubSDKDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AdHubBannerViewDelegate;
@class AdHubRequestError;

@interface AdHubBannerView : UIView

@property (nonatomic, copy, readonly) NSString *spaceID;
@property (nonatomic, copy, readonly) NSString *spaceParam;

/**
 用来接收 Banner 广告读取和展示状态变化通知的 delegate
 */
@property (nonatomic, weak) id<AdHubBannerViewDelegate> delegate;

/**
 adhubBannerViewController 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
 */
@property (nonatomic, weak) UIViewController *adhubBannerViewController;

/**
 初始化方法
 @param frame 广告展示的位置和大小，banner默认比例6.4:1；只需要设置宽度，高度自适应，默认宽度屏幕宽度
 @param spaceID 广告位 ID
 @param spaceParam 广告位参数 可填写任意字符串
 @return Banner 广告对象
 */
- (instancetype)initWithFrame:(CGRect)frame spaceID:(NSString *)spaceID spaceParam:(NSString *)spaceParam;

/**
 Banner 加载
 */
- (void)ADH_loadBannerAd;

/**
 Banner 广告移除 开发者自行调用
 */
- (void)ADH_bannerCloseAd;

#pragma mark - DEPRECATED

- (void)ADH_setVertexPoint:(CGPoint)point ADHUB_DEPRECATED_MSG_ATTRIBUTE("use initWithFrame:spaceID:spaceParam: instead.");
- (instancetype)initWithSpaceID:(NSString *)spaceID spaceParam:(NSString *)spaceParam ADHUB_DEPRECATED_MSG_ATTRIBUTE("use initWithFrame:spaceID:spaceParam: instead.");


@end

/**
 代理方法
 */
@protocol AdHubBannerViewDelegate <NSObject>

@optional

/**
 Banner加载成功
 */
- (void)ADH_bannerDidReceiveAd:(AdHubBannerView *)adHubBanner;

/**
 Banner点击
 */
- (void)ADH_bannerDidClick:(AdHubBannerView *)adHubBanner;

/**
 Banner消失
 */
- (void)ADH_bannerDidDismissScreen:(AdHubBannerView *)adHubBanner;

/**
 Banner请求失败
 */
- (void)ADH_banner:(AdHubBannerView *)adHubBanner didFailToLoadAdWithError:(AdHubRequestError *)error;

@end

NS_ASSUME_NONNULL_END

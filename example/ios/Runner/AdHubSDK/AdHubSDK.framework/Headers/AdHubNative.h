//
//  AdHubNative.h
//  AdHubSDK
//
//  Created by 北京市吕俊学 on 2019/1/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdHubNativeDelegate;
@class AdHubNativeAdDataModel;
@class AdHubRequestError;

@interface AdHubNative : NSObject

@property (nonatomic, copy, readonly) NSString *spaceID;
@property (nonatomic, copy, readonly) NSString *spaceParam;

/**
 用来接收原生广告获取状态变化通知的 delegate
 */
@property (nonatomic, weak) id<AdHubNativeDelegate> delegate;

/**
 显示adhub广告的View，此参数不能为空
 */
@property (nonatomic, weak) UIView *adhubNativeView;
/**
 显示渠道广告时，想要返回的view尺寸，需要load前设置。设置与adhubNativeView相同尺寸。
 */
@property (nonatomic, assign) CGSize channelAdSize;

/**
 adhubNativeViewController 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
 */
@property (nonatomic, weak) UIViewController *adhubNativeViewController;

/**
 是否由SDK生成Logo，默认Yes。
 */
@property (nonatomic, assign) BOOL iSAdLogoView;

/**
 初始化方法
 @param spaceID 广告位 ID
 @param spaceParam 广告位参数 可填写任意字符串
 @return 原生广告对象
 */
- (instancetype)initWithSpaceID:(NSString *)spaceID
                     spaceParam:(NSString *)spaceParam NS_DESIGNATED_INITIALIZER;

/**
 是否为渠道广告，当iSChannelAd为NO时，使用adDataModels自定义广告。当iSChannelAd为YES时，使用channeNativeAdView将View直接添加到页面。
 */
@property (nonatomic, assign, readonly) BOOL iSChannelAd;

/**
 广告加载成功后获得的 原生广告数据模型（使用model数据，自定义View样式）
 */
@property (nonatomic, strong, readonly) NSArray<AdHubNativeAdDataModel *> *adDataModels;

/**
 广告加载成功后获得的 View广告（数组内部为加载完成的View形式广告，直接add到目标View）
 */
@property (nonatomic, strong, readonly) NSArray *channeNativeAdView;

/**
 Native 获取
 @param count 广告条数（渠道广告时候生效，adhub广告只能拉取1条广告）
 */
- (void)ADH_loadNativeAd:(int)count;

@end

/**
 代理方法
 */
@protocol AdHubNativeDelegate <NSObject>

@optional

/**
 原生广告请求成功
 */
- (void)ADH_nativeDidLoad:(AdHubNative *)adHubNative;

/**
 原生广告点击
 */
- (void)ADH_nativeDidClick:(AdHubNative *)adHubNative;

/**
 原生广告请求失败
 */
- (void)ADH_native:(AdHubNative *)adHubNative didFailToLoadAdWithError:(AdHubRequestError *)error;

@end

NS_ASSUME_NONNULL_END

//
//  AdHubCustomView.h
//  AdHubSDK
//
//  Created by 北京市吕俊学 on 2019/1/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AdHubCustomViewDelegate;
@class AdHubRequestError;

@interface AdHubCustomView : UIView

@property (nonatomic, copy, readonly) NSString *spaceID;
@property (nonatomic, copy, readonly) NSString *spaceParam;

/**
 用来接收 Custom 广告读取和展示状态变化通知的 delegate
 */
@property (nonatomic, weak) id<AdHubCustomViewDelegate> delegate;

/**
 adhubCustomViewController 展示view的控制器或者弹出落地页的需要的控制器，此参数不能为空
 */
@property (nonatomic, weak) UIViewController *adhubCustomViewController;

/**
 初始化方法
 @param spaceID 广告位 ID
 @param spaceParam 广告位参数 可填写任意字符串
 @return Custom 广告对象
 */
- (instancetype)initWithSpaceID:(NSString *)spaceID spaceParam:(NSString *)spaceParam;

/**
 Custom 加载
 */
- (void)ADH_loadCustomAd;

/**
 设置广告顶点坐标
 如果未设置新坐标，取后台创建广告默认坐标，如果设置新坐标，后台创建广告设置的坐标失效。
 @param point 坐标
 */
- (void)ADH_setVertexPoint:(CGPoint)point;

/**
 Custom 广告移除 开发者自行调用
 */
- (void)ADH_customCloseAd;

@end

/**
 代理方法
 */
@protocol AdHubCustomViewDelegate <NSObject>

@optional

/**
 Custom加载成功
 */
- (void)ADH_customDidReceiveAd:(AdHubCustomView *)adHubCustom;

/**
 Custom点击
 */
- (void)ADH_customDidClick:(AdHubCustomView *)adHubCustom;

/**
 Custom消失
 */
- (void)ADH_customDidDismissScreen:(AdHubCustomView *)adHubCustom;

/**
 Custom请求失败
 */
- (void)ADH_custom:(AdHubCustomView *)adHubCustom didFailToLoadAdWithError:(AdHubRequestError *)error;

@end

NS_ASSUME_NONNULL_END

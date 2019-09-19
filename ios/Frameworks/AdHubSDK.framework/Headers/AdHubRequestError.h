//
//  AdHubRequestError.h
//  AdHubSDK
//
//  Created by 北京市吕俊学 on 2018/12/5.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// AdHubSDK Ads error domain.
extern NSString *const kAdHubErrorDomain;

// NSError codes for AdHub error domain.
typedef NS_ENUM(NSInteger, AdHubErrorCode) {
    kAdHubErrorUnknown                              = -10000,
    
    // SpaceID不能为空
    kAdHubErrorSpaceIDNULL                          = -10001,
    
    // 无效的URL，不能为空
    kAdHubErrorURLNULL                              = -10002,
    
    // 在请求广告数据过程中请求超时
    kAdHubErrorTimeout                              = -10003,
    
    // 在请求广告数据过程中出现了网络错误
    kAdHubErrorNetworkError                         = -10004,
    
    // 广告ID出现错误
    kAdHubErrorIDNotFound                           = -10005,
    
    // 广告ID使用错误，类型不匹配
    kAdHubErrorIDUseError                           = -10006,
    
    // 广告请求成功，但没有返回广告内容
    kAdHubErrorNoFill                               = -10007,
    
    // 广告请求成功，加载素材失败
    kAdHubErrorLoadAdError                          = -10008,
    
    // 广告请求成功，获取到不支持的广告类型
    kAdHubErrorDoesNotSupport                       = -10009,
    
    // 广告请求成功，激励视频存在错误
    kAdHubErrorRewardedIsHotVideo                   = -10010,
    
    // 广告View未添加到页面
    kAdHubErrorAdNotAddView                         = -11001,
    
    // 未发现上层控制器
    kAdHubErrorDoesNotCurrentViewController         = -11002,
    
    // 未发现布局广告View
    kAdHubErrorDoesNotCurrentView                   = -11003,
    
    // 原生广告上报时，页面没有添加到视图上
    kAdHubErrorDoesNotDisplayedInScreen             = -11004,
    
    // 第三方渠道错误
    kThirdPartyChannelError                         = -12001,
    
    // 第三方渠道为空
    kAdHubErrorChannelParameterNULL                 = -12002,
    
};

@interface AdHubRequestError : NSError

+ (AdHubRequestError *)errorWithCode:(AdHubErrorCode)code;

@end

NS_ASSUME_NONNULL_END

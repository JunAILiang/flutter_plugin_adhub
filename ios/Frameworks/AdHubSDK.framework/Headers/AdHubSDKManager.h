//
//  AdHubSDKManager.h
//  AdHubSDK
//
//  Created by 北京市吕俊学 on 2018/12/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdHubSDKManager : NSObject

/**
 配置 AppID
 @param applicationID 商户分配到的唯一appID
 */
+ (void)configureWithApplicationID:(NSString *)applicationID;

/**
 配置 AppID
 官户使用此方法初始化
 @param applicationID 商户分配到的唯一appID
 @param domainURL 指定域名，需以http或https开头
 */
+ (void)configureWithApplicationID:(NSString *)applicationID DomainURL:(NSString *)domainURL;

/**
 开启错误日志
 */
+ (void)openTheAdHubLog;

/**
 SDK版本号
 @return SDK版本号
 */
+ (NSString *)sdkVersion;

@end

NS_ASSUME_NONNULL_END

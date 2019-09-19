//
//  AdHubNativeAdDataModel.h
//  AdHubSDK
//
//  Created by 北京市吕俊学 on 2019/2/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class AdHubAdResponse;

@interface AdHubNativeAdDataModel : NSObject

//  按钮文字
@property (nonatomic, strong, readonly) NSString *adhubAction;
//  广告标题
@property (nonatomic, strong, readonly) NSString *adhubHeadline;
//  广告图片素材
@property (nonatomic, strong, readonly) NSArray *adhubImages;
//  广告文字素材
@property (nonatomic, strong, readonly) NSArray *adhubTexts;
//  广告视频素材
@property (nonatomic, strong, readonly) NSArray *adhubVideos;


// 由于广告法规定，必须添加logo，（建议：广告图片放置在广告的左下角，logo放置在广告的右下角）
//  广告图片，当此字符串不为空时，加载adLabelURL的图片。
@property (nonatomic, strong, readonly) NSString *adhubLabelURL;
//  广告文字，当adLabelURL为空时，使用adLabel的文字
@property (nonatomic, strong, readonly) NSString *adhubLabel;
//  logo图片，当此字符串不为空时，加载logoURL的图片。
@property (nonatomic, strong, readonly) NSString *adhubLogoURL;
//  logo文字，当logoURL为空时，使用logoLabel的文字
@property (nonatomic, strong, readonly) NSString *adhubLogoLabel;


/**
 SDK内部方法，无需调用与使用
 */
- (instancetype)initWithData:(AdHubAdResponse *)adHubAdResponse;

@end

NS_ASSUME_NONNULL_END

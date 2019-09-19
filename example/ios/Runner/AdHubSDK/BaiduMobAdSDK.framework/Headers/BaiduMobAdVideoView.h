//
//  BaiduMobAdCustomVideoView.h
//  BaiduMobAdSDK
//
//  Created by Yang,Dingjia on 2018/11/13.
//  Copyright © 2018 Baidu Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

@class BaiduMobAdVideoView;
@protocol BaiduMobAdVideoViewDelegate <NSObject>
@optional

/**
 视频播放完成

 @param videoView self
 */
- (void)baiduMobMediaPlayerDidEnd:(BaiduMobAdVideoView *)videoView;

/**
 视频播放失败

 @param videoView self
 */
- (void)baiduMobMediaPlayerDidFailed:(BaiduMobAdVideoView *)videoView;

@end

@interface BaiduMobAdVideoView : UIView

@property (nonatomic, weak) id <BaiduMobAdVideoViewDelegate> delegate;

/**
 初始化方法

 @param frame frame
 @param object BaiduMobAdNativeAdObject
 @return BaiduMobAdVideoView
 */
- (instancetype)initWithFrame:(CGRect)frame andObject:(id)object;

- (void)play;   //开始播放
- (void)replay; //重新播放
- (void)pause;  //暂停播放
- (void)stop;   //销毁播放器
- (void)setVideoMute:(BOOL)mute;//设置静音  YES静音   NO非静音
- (BOOL)isPlaying;  //是否正在播放

- (NSTimeInterval)currentTime;  //当前播放时间
- (NSTimeInterval)duration;     //视频时长

#pragma mark - 计费相关视频事件 重要！

/**
 视频曝光事件 确定视图显示在window上之后再调用trackImpression，不要太早调用
 */
- (void)trackImpression;

/**
 视频点击事件 点击计费接口
 */
- (void)handleClick;

@end

//
//  RTCEngineChannel.h
//  RTCEngineKit
//
//  Created by SailorGa on 2026/8/11.
//  Copyright © 2026 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<RTCEngineKit/RTCEngineObjects.h>)
#import <RTCEngineKit/RTCEngineObjects.h>
#import <RTCEngineKit/RTCEngineChannelDelegate.h>
#else
#import "RTCEngineObjects.h"
#import "RTCEngineChannelDelegate.h"
#endif

NS_ASSUME_NONNULL_BEGIN

/// 完成回调
typedef void (^RTCEngineKitFinishBlock)(void);

@protocol RTCEngineChannelDelegate;

#pragma mark - RTCEngineChannel
/// RTC 单频道实例
/// 由 -[RTCEngineKit createChannelWithDelegate:] 创建，每个实例独立持有信令频道、媒体连接、成员缓存与远端渲染状态
/// 同一进程可同时存在多个频道实例，实例之间的成员数据、码流统计与渲染互不干扰
/// 摄像头、音频路由、ReplayKit 采集、美颜渲染等进程级共享能力由 RTCEngineKit 单例统一提供，频道实例不重复暴露
/// 使用完毕后必须调用 destroy 归还实例，否则引擎会一直持有该频道
@interface RTCEngineChannel : NSObject

+ (instancetype)new __attribute__((unavailable("Use -[RTCEngineKit createChannelWithDelegate:] instead")));
- (instancetype)init __attribute__((unavailable("Use -[RTCEngineKit createChannelWithDelegate:] instead")));

/// 频道事件代理
@property (nonatomic, weak, nullable) id<RTCEngineChannelDelegate> delegate;
/// 已加入的频道名称，未加入时为空
@property (nonatomic, copy, readonly, nullable) NSString *channel;
/// 语音转写状态
@property (nonatomic, assign, readonly) BOOL enabledTrans;


#pragma mark - ------------ 频道相关接口函数 ------------

#pragma mark 加入频道
/// 加入频道
/// @param token 鉴权令牌
- (RTCEngineError)joinChannelWithToken:(NSString *)token;

#pragma mark 离开频道
/// 离开频道
/// @param finishBlock 完成回调
- (void)leaveChannel:(nullable RTCEngineKitFinishBlock)finishBlock;

#pragma mark 销毁频道实例
/// 销毁频道实例
/// 内部先执行离开频道，完成后从引擎的频道列表中摘除并断开代理，调用后不可再使用该实例
- (void)destroy;


#pragma mark - ------------ 数据管理相关接口 ------------

#pragma mark 获取当前账户数据
/// 获取当前账户数据
- (nullable RTCEngineUserModel *)getMySelf;

#pragma mark 获取当前频道数据
/// 获取当前频道数据
- (nullable RTCEngineChannelModel *)getChannelDetails;

#pragma mark 获取成员数据
/// 获取成员数据
/// @param userId 用户标识
- (nullable RTCEngineUserModel *)findMemberWithUserId:(NSString *)userId;

#pragma mark 获取成员列表
/// 获取成员列表
- (NSArray<RTCEngineUserModel *> *)getRemoteUsers;

#pragma mark 获取画板地址
/// 获取画板地址
- (nullable NSString *)getDrawingHost;


#pragma mark - ------------ 视频相关接口函数 ------------

#pragma mark 恢复/暂停推流
/// 恢复/暂停推流
/// 推送的画面来源为进程级共享摄像头，是否推送由当前频道实例独立控制
/// @param publish YES-恢复 NO-暂停
- (RTCEngineError)publishLocalVideo:(BOOL)publish;

#pragma mark 订阅远端用户的视频流
/// 订阅远端用户的视频流
/// @param userId 指定远端用户标识
/// @param trackId 指定要观看的轨道号
/// @param view 承载视频画面的控件
- (RTCEngineError)startRemoteView:(NSString *)userId trackId:(RTCTrackIdentifierFlags)trackId view:(VIEW_CLASS *)view;

#pragma mark 更新远端用户的视频流
/// 更新远端用户的视频流
/// @param userId 指定远端用户标识
/// @param trackId 指定要观看的轨道号
/// @param view 承载视频画面的控件
- (RTCEngineError)updateRemoteView:(NSString *)userId trackId:(RTCTrackIdentifierFlags)trackId view:(VIEW_CLASS *)view;

#pragma mark 停止订阅远端用户的视频流
/// 停止订阅远端用户的视频流
/// @param userId 指定远端用户标识
/// @param trackId 指定要观看的轨道号
- (RTCEngineError)stopRemoteView:(NSString *)userId trackId:(RTCTrackIdentifierFlags)trackId;

#pragma mark 停止订阅指定远端用户的所有视频流
/// 停止订阅指定远端用户的所有视频流
/// @param userId 指定远端用户标识
- (RTCEngineError)stopAllRemoteViewWithUserId:(NSString *)userId;

#pragma mark 停止订阅所有远端用户的视频流
/// 停止订阅所有远端用户的视频流
- (RTCEngineError)stopAllRemoteView;

#pragma mark 订阅远端合成画面视频流，并绑定视频渲染控件
/// 订阅远端合成画面视频流，并绑定视频渲染控件
/// @param view 承载视频画面的渲染控件
- (RTCEngineError)startRemoteMixture:(VIEW_CLASS *)view;

#pragma mark 停止订阅远端合成画面视频流，并释放渲染控件
/// 停止订阅远端合成画面视频流，并释放渲染控件
- (RTCEngineError)stopRemoteMixture;

#pragma mark 订阅远端转推音视频流，并绑定视频渲染控件
/// 订阅远端转推音视频流，并绑定视频渲染控件
/// @param streamName 需要订阅的远端流名(由外部传入)
/// @param view 承载视频画面的渲染控件
- (RTCEngineError)startRemoteRetweet:(NSString *)streamName view:(VIEW_CLASS *)view;

#pragma mark 停止订阅远端转推音视频流，并释放渲染控件
/// 停止订阅远端转推音视频流，并释放渲染控件
/// @param streamName 需要停止订阅的远端流名(由外部传入)
- (RTCEngineError)stopRemoteRetweet:(NSString *)streamName;


#pragma mark - ------------ 流媒体相关接口函数 ------------

#pragma mark 设置流媒体配置参数
/// 设置流媒体配置参数
/// @param config 流媒体配置参数
- (void)setStreamMediaConfig:(RTCEngineMediaConfig *)config;

#pragma mark 设置网络质量控制参数
/// 设置网络质量控制参数
/// @param param 质量控制参数
- (void)setNetworkQosParam:(RTCEngineNetworkQosParam *)param;

#pragma mark 设置远程调试参数
/// 设置远程调试参数
/// @param param 调试参数
- (void)setRemoteDebugParam:(RTCEngineDebugParam *)param;


#pragma mark - ------------ 音频相关接口函数 ------------

#pragma mark 音频发送状态
/// 音频发送状态
/// @param enabled YES-开启 NO-关闭
- (RTCEngineError)enabledSendAudio:(BOOL)enabled;

#pragma mark 设置音频优先策略
/// 设置音频优先策略
/// @param userId 指定远端用户标识
/// @param enabled  YES-开启 NO-关闭
- (RTCEngineError)setAudioPriorityWithUserId:(NSString *)userId enabled:(BOOL)enabled;

#pragma mark 设置声音播放状态
/// 设置声音播放状态
/// @param enabled 是否开启远端音频播放(YES-开启 NO-关闭)
- (RTCEngineError)enabledAudioSpeaker:(BOOL)enabled;

#pragma mark 设置本端音频单元启停
/// 设置本端音频单元启停
/// @discussion 录像直播等本端不采集、不接收 RTC 音频的纯本地播放场景，关闭音频单元可释放流媒体语音处理单元(VPIO)，避免本地 AVPlayer 播放音量被压低；返回该场景后需恢复
/// @param enabled 是否启用本端音频单元(YES-由流媒体自动管理 NO-停止)
- (RTCEngineError)enabledAudioModule:(BOOL)enabled;

#pragma mark 设置语音转写状态
/// 设置语音转写状态
/// @param enabled 是否开启语音转写(YES-开启 NO-关闭)
- (RTCEngineError)enabledSpeechTrans:(BOOL)enabled;

#pragma mark 重启音频会话
/// 重启音频会话
- (void)resetAudioSession;


#pragma mark - ------------ 屏幕共享相关接口函数 ------------

#pragma mark 发布/停止屏幕共享流
/// 发布/停止屏幕共享流
/// ReplayKit 采集为进程级共享能力，本接口只控制当前频道实例是否订阅并推送采集数据
/// 首个频道发布时启动采集，最后一个频道停止发布时才真正结束采集
/// @param publish YES-发布 NO-停止
- (RTCEngineError)publishScreenRecord:(BOOL)publish;

#pragma mark 发布视图录制的屏幕共享流
/// 发布视图录制的屏幕共享流
/// 共用共享发布连接(publishScreenPeerConnection)，数据来源一般为UIView内容采集
/// 与 publishScreenEncoderWithStreamData 互斥使用，由外部业务决定采用哪种方式送流
/// - Parameters:
///   - pixelBuffer: UIView采集的像素数据(CVPixelBufferRef)
///   - displayAngle: 显示角度(0/90/180/270)
- (void)publishScreenViewCaptureWithPixelBuffer:(CVPixelBufferRef)pixelBuffer displayAngle:(int)displayAngle;

#pragma mark 设置视图采集共享
/// 设置视图采集共享
/// 视图采集为云录制的“保底画面源”，屏幕共享为“高优先级画面源”
/// 两者共用屏幕共享通道，按优先级自动切换：
/// - 开启时：若屏幕录制未进行，建立共享通道；若屏幕录制已在进行，通道已存在无需重复建立
/// - 屏幕录制停止时：若视图采集已开启，通道不关闭，自动恢复推送视图采集数据
/// - 关闭时：若屏幕录制未进行，拆除共享通道；若屏幕录制已在进行，通道保留给屏幕录制
/// - Parameter enabled: 启用状态 YES-开启 NO-关闭
- (RTCEngineError)enabledViewCaptureShare:(BOOL)enabled;


#pragma mark - ------------ 发布自定义流相关接口函数 ------------

#pragma mark 启动自定义流
/// 启动自定义流
/// @param streamTrackModel 自定义码流轨道信息
- (RTCEngineError)startCustomStreamWithStreamTrackModel:(RTCEngineStreamTrackModel *)streamTrackModel;

#pragma mark 关闭自定义流
/// 关闭自定义流
/// @param trackId 轨道号码
- (RTCEngineError)stopCustomStreamWithTrackId:(RTCTrackIdentifierFlags)trackId;

#pragma mark 发布自定义码流
/// 发布自定义码流
/// @param streamData 码流数据
/// @param bitslen 数据长度
/// @param pts 显示时间戳
/// @param dts 解码时间戳
/// @param trackId 轨道号码
/// @param streamType 媒体流类型
- (RTCEngineError)publishCustomStreamWithStreamData:(const unsigned char *)streamData bitslen:(int)bitslen pts:(uint32_t)pts dts:(uint32_t)dts trackId:(RTCTrackIdentifierFlags)trackId streamType:(RTCStreamType)streamType;

@end

NS_ASSUME_NONNULL_END

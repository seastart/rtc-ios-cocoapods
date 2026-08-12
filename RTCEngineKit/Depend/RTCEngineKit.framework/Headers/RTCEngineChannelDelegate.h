//
//  RTCEngineChannelDelegate.h
//  RTCEngineKit
//
//  Created by SailorGa on 2026/8/11.
//  Copyright © 2026 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<RTCEngineKit/RTCEngineKit.h>)
#import <RTCEngineKit/RTCEngineObjects.h>
#else
#import "RTCEngineObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineChannel;

#pragma mark - 频道级会话事件回调
/// 频道级会话事件回调
/// 本协议只承载频道内的连接、成员、消息、码流、音频与屏幕共享事件，全部回调首参携带事件来源频道实例
/// 多频道场景下通过首参区分事件归属，频道名称可从 channel.channel 读取
/// 进程级共享能力事件（音频路由、网络测速、应用性能）请实现 RTCEngineDelegate
@protocol RTCEngineChannelDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----

#pragma mark - ------------ 连接相关回调 ------------
#pragma mark 重连成功回调
/// 重连成功回调
/// @param channel 事件来源频道实例
- (void)engineChannelOnReconnected:(RTCEngineChannel *)channel;

#pragma mark 连接断开回调
/// 连接断开回调
/// 发生不可恢复的错误或者被动离开频道，这个事件触发需要重新获取令牌
/// @param channel 事件来源频道实例
/// @param reason 离开原因
/// @param errCode 错误码
/// @param errMsg 错误信息
- (void)engineChannel:(RTCEngineChannel *)channel onDisconnected:(RTCLeaveReason)reason errCode:(RTCEngineError)errCode errMsg:(nullable NSString *)errMsg;

#pragma mark 开始重连回调
/// 开始重连回调
/// @param channel 事件来源频道实例
- (void)engineChannelOnReconnecting:(RTCEngineChannel *)channel;


#pragma mark - ------------ 我的相关回调 ------------
#pragma mark 加入频道成功回调
/// 加入频道成功回调
/// @param channel 事件来源频道实例
/// @param userId 用户标识
- (void)engineChannel:(RTCEngineChannel *)channel onJoinSucceed:(NSString *)userId;

#pragma mark 自己数据更新回调
/// 自己数据更新回调
/// @param channel 事件来源频道实例
/// @param userId 用户标识
- (void)engineChannel:(RTCEngineChannel *)channel onUserUpdate:(NSString *)userId;


#pragma mark - ------------ 频道相关回调 ------------
#pragma mark 频道更新回调
/// 频道更新回调
/// @param channel 事件来源频道实例
/// @param props 自定义数据
- (void)engineChannel:(RTCEngineChannel *)channel onChannelUpdate:(NSString *)props;


#pragma mark - ------------ 用户相关回调 ------------
#pragma mark 用户加入频道回调
/// 用户加入频道回调
/// @param channel 事件来源频道实例
/// @param userId 用户标识
- (void)engineChannel:(RTCEngineChannel *)channel onRemoteUserJoinChannel:(NSString *)userId;

#pragma mark 用户数据更新回调
/// 用户数据更新回调
/// @param channel 事件来源频道实例
/// @param userId 用户标识
- (void)engineChannel:(RTCEngineChannel *)channel onRemoteUserUpdate:(NSString *)userId;

#pragma mark 用户离开频道回调
/// 用户离开频道回调
/// @param channel 事件来源频道实例
/// @param userId 用户标识
/// @param reason 离开原因
- (void)engineChannel:(RTCEngineChannel *)channel onRemoteUserLeaveChannel:(NSString *)userId reason:(RTCLeaveReason)reason;

#pragma mark 用户码流数据变更回调
/// 用户码流数据变更回调
/// @param channel 事件来源频道实例
/// @param userId 用户标识
/// @param streamTrackModel 码流轨道数据
/// @param changeType 操作类型
- (void)engineChannel:(RTCEngineChannel *)channel onRemoteStreamTrackChange:(NSString *)userId streamTrackModel:(RTCEngineStreamTrackModel *)streamTrackModel changeType:(RTCChangeType)changeType;


#pragma mark - ------------ 消息相关回调 ------------
#pragma mark 自定义消息回调
/// 自定义消息回调
/// @param channel 事件来源频道实例
/// @param content 消息内容
/// @param action 消息标识
/// @param userId 用户标识
/// @param sessionId 会话标识
/// @param nickname 用户昵称
- (void)engineChannel:(RTCEngineChannel *)channel onCustomMessage:(NSString *)content action:(NSString *)action userId:(nullable NSString *)userId sessionId:(nullable NSString *)sessionId nickname:(nullable NSString *)nickname;


#pragma mark - ------------ 音频相关回调 ------------
#pragma mark 音频采集数据回调
/// 音频采集数据回调
/// @param channel 事件来源频道实例
/// @param samplerate 采样率
/// @param channels 声道数
/// @param stamp 时间戳
/// @param dataSize 数据大小
/// @param pcmData 音频元数据
- (void)engineChannel:(RTCEngineChannel *)channel onAudioCapture:(int)samplerate channels:(int)channels stamp:(unsigned int)stamp dataSize:(int)dataSize pcmData:(void *)pcmData;

#pragma mark 音频采集重采样数据回调
/// 音频采集重采样数据回调
/// @param channel 事件来源频道实例
/// @param samplerate 采样率
/// @param channels 声道数
/// @param stamp 时间戳
/// @param resampledData 音频重采样数据
- (void)engineChannel:(RTCEngineChannel *)channel onAudioCaptureResampled:(int)samplerate channels:(int)channels stamp:(unsigned int)stamp resampledData:(NSData *)resampledData;

#pragma mark 远程成员音频状态回调
/// 远程成员音频状态回调
/// @param channel 事件来源频道实例
/// @param audioArray 成员音频列表
- (void)engineChannel:(RTCEngineChannel *)channel onRemoteMemberAudioStatus:(NSArray<RTCStreamAudioModel *> *)audioArray;

#pragma mark 服务是否允许发言回调
/// 服务是否允许发言回调
/// @param channel 事件来源频道实例
/// @param enabled 是否允许发言，YES-允许发言 NO-不允许发言
- (void)engineChannel:(RTCEngineChannel *)channel onServiceEnabledSpeak:(BOOL)enabled;


#pragma mark - ------------ 流媒体相关回调 ------------
#pragma mark 流媒体连接成功回调
/// 流媒体连接成功回调
/// @param channel 事件来源频道实例
- (void)engineChannelOnStreamMediaDidConnectSucceed:(RTCEngineChannel *)channel;

#pragma mark 流媒体平台变化回调
/// 流媒体平台变化回调
/// @param channel 事件来源频道实例
/// @param vendorName 平台名称
- (void)engineChannel:(RTCEngineChannel *)channel onStreamChangedVendorName:(NSString *)vendorName;

#pragma mark 下行码率自适应状态回调
/// 下行码率自适应状态回调
/// @param channel 事件来源频道实例
/// @param userId 用户标识
/// @param state 下行码率自适应状态
- (void)engineChannel:(RTCEngineChannel *)channel onDownBitrateAdaptiveUserId:(NSString *)userId state:(RTCDownBitrateAdaptiveState)state;

#pragma mark 上行码率自适应状态回调
/// 上行码率自适应状态回调
/// @param channel 事件来源频道实例
/// @param state 上行码率自适应状态
- (void)engineChannel:(RTCEngineChannel *)channel onUploadBitrateAdaptiveState:(RTCUploadBitrateAdaptiveState)state;

#pragma mark 下行平均丢包档位变化回调
/// 下行平均丢包档位变化回调
/// @param channel 事件来源频道实例
/// @param state 下行平均丢包档位
- (void)engineChannel:(RTCEngineChannel *)channel onDownLossLevelChangeState:(RTCDownLossLevelState)state;

#pragma mark 下行平均丢包率回调
/// 下行平均丢包率回调
/// @param channel 事件来源频道实例
/// @param average 下行平均丢包率
- (void)engineChannel:(RTCEngineChannel *)channel onDownLossRateAverage:(CGFloat)average;

#pragma mark 流媒体发送状态数据回调
/// 流媒体发送状态数据回调
/// @param channel 事件来源频道实例
/// @param sendModel 流媒体发送状态数据
- (void)engineChannel:(RTCEngineChannel *)channel onSendStreamModel:(RTCStreamSendModel *)sendModel;

#pragma mark 流媒体接收状态数据回调
/// 流媒体接收状态数据回调
/// @param channel 事件来源频道实例
/// @param receiveArray 流媒体接收状态数据
- (void)engineChannel:(RTCEngineChannel *)channel onReceiveStreamModel:(NSArray <RTCStreamReceiveModel *> *)receiveArray;

#pragma mark 服务端上行质量检测回调
/// 服务端上行质量检测回调（Seastart SFU 26.4 起，由服务端通过 Signal DataChannel 下发，含 score/level/mos 等服务端独有指标，作为本地 engineChannel:onSendStreamModel: 的补充）
/// @param channel 事件来源频道实例
/// @param sample 上行质量样本
- (void)engineChannel:(RTCEngineChannel *)channel onSendQualitySample:(RTCStreamQualitySampleModel *)sample;

#pragma mark 服务端下行质量检测回调
/// 服务端下行质量检测回调（Seastart SFU 26.4 起，由服务端通过 Signal DataChannel 下发，为整体下行的聚合样本，与 engineChannel:onReceiveStreamModel: 的 per-stream 维度互补）
/// @param channel 事件来源频道实例
/// @param sample 下行质量样本
- (void)engineChannel:(RTCEngineChannel *)channel onReceiveQualitySample:(RTCStreamQualitySampleModel *)sample;

#pragma mark 流媒体接收远端流状态变更回调
/// 流媒体接收远端流状态变更回调
/// @param channel 事件来源频道实例
/// @param userId 用户标识
/// @param trackId 轨道标识
/// @param status 接收状态，YES-超时 NO-恢复
- (void)engineChannel:(RTCEngineChannel *)channel onReceiveStreamStatusChange:(NSString *)userId trackId:(RTCTrackIdentifierFlags)trackId status:(BOOL)status;

#pragma mark 流媒体接收转推流状态变更回调
/// 流媒体接收转推流状态变更回调
/// 转推流不作为远端用户视频数据上报，单独通过本回调通知接收状态。
/// @param channel 事件来源频道实例
/// @param streamName 转推流名
/// @param status 接收状态，YES-超时 NO-恢复
- (void)engineChannel:(RTCEngineChannel *)channel onReceiveRetweetStreamStatusChange:(NSString *)streamName status:(BOOL)status;


#pragma mark - ------------ 屏幕共享相关回调 ------------
#pragma mark 屏幕共享状态回调
/// 屏幕共享状态回调
/// @param channel 事件来源频道实例
/// @param status 状态码
- (void)engineChannel:(RTCEngineChannel *)channel onScreenRecordStatus:(RTCScreenRecordStatus)status;

@end

NS_ASSUME_NONNULL_END

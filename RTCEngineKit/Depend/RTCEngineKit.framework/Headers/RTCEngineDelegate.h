//
//  RTCEngineDelegate.h
//  RTCEngineKit
//
//  Created by SailorGa on 2022/7/9.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineKit;

#pragma mark - 会话事件回调
@protocol RTCEngineDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----

#pragma mark - ------------ 连接相关回调 ------------
#pragma mark 连接成功回调
/// 连接成功回调
/// 首次连接或者断线重连成功后触发
- (void)onConnected;

#pragma mark 连接断开回调
/// 连接断开回调
/// 发生不可恢复的错误，这个事件触发需要重新登录
/// @param errCode 错误码
/// @param errMsg 错误信息
- (void)onDisconnected:(RTCEngineError)errCode errMsg:(nullable NSString *)errMsg;

#pragma mark 开始重连回调
/// 开始重连回调
/// 连接断开并开始重连时触发
- (void)onReconnecting;

#pragma mark - ------------ 通讯相关回调 ------------
#pragma mark 自定义消息回调
/// 自定义消息回调
/// @param content 消息内容
/// @param action 消息标识
/// @param userId 用户标识
- (void)onCustomMessage:(NSString *)content action:(NSString *)action userId:(nullable NSString *)userId;


#pragma mark - ------------ 频道相关回调 ------------
#pragma mark 加入频道成功回调
/// 加入频道成功回调
/// @param channel 频道标识
/// @param userId 用户标识
- (void)onJoinSucceed:(NSString *)channel userId:(NSString *)userId;

#pragma mark 频道更新回调
/// 频道更新回调
/// @param channel 频道标识
/// @param props 自定义数据
- (void)onChannelUpdate:(NSString *)channel props:(NSString *)props;

#pragma mark 频道销毁回调
/// 频道销毁回调
/// @param channel 频道标识
- (void)onChannelDestroy:(NSString *)channel;


#pragma mark - ------------ 用户相关回调 ------------
#pragma mark 用户加入频道回调
/// 用户加入频道回调
/// @param channel 频道标识
/// @param userId 用户标识
- (void)onRemoteUserJoinChannel:(NSString *)channel userId:(NSString *)userId;

#pragma mark 成员数据更新回调
/// 成员数据更新回调
/// @param channel 频道标识
/// @param userId 用户标识
- (void)onRemoteUserUpdate:(NSString *)channel userId:(NSString *)userId;

#pragma mark 用户离开频道回调
/// 用户离开频道回调
/// @param channel 频道标识
/// @param userId 用户标识
/// @param reason 离开原因
- (void)onRemoteUserLeaveChannel:(NSString *)channel userId:(NSString *)userId reason:(RTCLeaveChannelReason)reason;

#pragma mark 用户码流数据变更回调
/// 用户码流数据变更回调
/// @param channel 频道标识
/// @param userId 用户标识
/// @param streamTrackModel 码流轨道数据
/// @param changeType 操作类型
- (void)onRemoteStreamTrackChange:(NSString *)channel userId:(NSString *)userId streamTrackModel:(RTCEngineStreamTrackModel *)streamTrackModel changeType:(RTCChangeType)changeType;


#pragma mark - ------------ 音频相关回调 ------------
#pragma mark 音频路由变更回调
/// 音频路由变更回调
/// @param route 音频路由
/// @param previousRoute 变更前的音频路由
- (void)onAudioRouteChange:(RTCAudioRoute)route previousRoute:(RTCAudioRoute)previousRoute;

#pragma mark 远程成员音频状态回调
/// 远程成员音频状态回调
/// @param audioArray 成员音频列表
- (void)onRemoteMemberAudioStatus:(NSArray<RTCStreamAudioModel *> *)audioArray;

#pragma mark 服务是否允许发言回调
/// 服务是否允许发言回调
/// @param enabled 是否允许发言，YES-允许发言 NO-不允许发言
- (void)onServiceEnabledSpeak:(BOOL)enabled;


#pragma mark - ------------ 流媒体相关回调 ------------
#pragma mark 流媒体连接成功回调
/// 流媒体连接成功回调
- (void)onStreamMediaDidConnectSucceed;

#pragma mark 下行码率自适应状态回调
/// 下行码率自适应状态回调
/// @param userId 用户标识
/// @param state 下行码率自适应状态
- (void)onDownBitrateAdaptiveUserId:(NSString *)userId state:(RTCDownBitrateAdaptiveState)state;

#pragma mark 上行码率自适应状态回调
/// 上行码率自适应状态回调
/// @param state 上行码率自适应状态
- (void)onUploadBitrateAdaptiveState:(RTCUploadBitrateAdaptiveState)state;

#pragma mark 下行平均丢包档位变化回调
/// 下行平均丢包档位变化回调
/// @param state 下行平均丢包档位
- (void)onDownLossLevelChangeState:(RTCDownLossLevelState)state;

#pragma mark 下行平均丢包率回调
/// 下行平均丢包率回调
/// @param average 下行平均丢包率
- (void)onDownLossRateAverage:(CGFloat)average;

#pragma mark 流媒体发送状态数据回调
/// 流媒体发送状态数据回调
/// @param sendModel 流媒体发送状态数据
- (void)onSendStreamModel:(RTCStreamSendModel *)sendModel;

#pragma mark 流媒体接收状态数据回调
/// 流媒体接收状态数据回调
/// @param receiveModel 流媒体接收状态数据
- (void)onReceiveStreamModel:(RTCStreamReceiveModel *)receiveModel;


#pragma mark - ------------ 屏幕共享相关回调 ------------
#pragma mark 屏幕共享状态回调
/// 屏幕共享状态回调
/// @param status 状态码
- (void)onScreenRecordStatus:(RTCScreenRecordStatus)status;


#pragma mark - ------------ 网络测速相关回调 ------------
#pragma mark 网络测速开始回调
/// 网络测速开始回调
- (void)onSpeedTestBegined;

#pragma mark 网络测速的结果回调
/// 网络测速的结果回调
/// @param uploadResult 上行网速测试数据
/// @param downResult 下行网速测试数据
/// @param connectResult 连接情况
- (void)onSpeedTestUploadResult:(nullable RTCSpeedTestResult *)uploadResult downResult:(nullable RTCSpeedTestResult *)downResult connectResult:(nullable RTCSpeedTestConnectResult *)connectResult;


#pragma mark - ------------ 其它相关回调 ------------
#pragma mark 应用性能使用情况回调
/// 应用性能使用情况回调
/// @param memory 内存占用
/// @param cpuUsage CUP使用率
- (void)onApplicationPerformance:(CGFloat)memory cpuUsage:(CGFloat)cpuUsage;

@end

NS_ASSUME_NONNULL_END



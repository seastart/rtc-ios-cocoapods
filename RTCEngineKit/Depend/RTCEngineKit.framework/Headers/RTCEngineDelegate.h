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

#pragma mark - ------------ 错误事件回调 ------------
#pragma mark 错误事件回调
/// 错误事件回调
/// @param errCode 错误码
/// @param errMsg 错误信息
- (void)onError:(RTCEngineError)errCode errMsg:(nullable NSString *)errMsg;


#pragma mark - ------------ 通讯相关回调 ------------
#pragma mark 连接事件回调
/// 连接事件回调
- (void)onConnected;

#pragma mark 断开事件回调
/// 断开事件回调
- (void)onDisconnected;

#pragma mark 登录事件回调
/// 登录事件回调
/// @param userId 当前用户ID
- (void)onLogin:(NSString *)userId;

#pragma mark 互动消息事件回调
/// 互动消息事件回调
/// @param content 消息内容
/// @param action 消息标识
/// @param userId 发送成员ID
- (void)onRemoteMessage:(NSString *)content action:(NSString *)action userId:(NSString *)userId;


#pragma mark - ------------ 房间相关回调 ------------
#pragma mark 进入房间事件回调
/// 进入房间事件回调
/// @param roomId 房间ID
/// @param userId 用户ID
- (void)onEnterRoom:(NSString *)roomId userId:(NSString *)userId;

#pragma mark 房间更新事件回调
/// 房间更新事件回调
/// @param roomId 房间ID
- (void)onRoomUpdate:(NSString *)roomId;


#pragma mark - ------------ 用户相关回调 ------------
#pragma mark 用户加入当前房间回调
/// 用户加入当前房间回调
/// @param roomId 房间ID
/// @param userId 用户ID
- (void)onRemoteUserEnterRoom:(NSString *)roomId userId:(NSString *)userId;

#pragma mark 成员信息更新事件回调
/// 成员信息更新事件回调
/// @param roomId 房间ID
/// @param userId 用户ID
- (void)onRemoteUserUpdate:(NSString *)roomId userId:(NSString *)userId;

#pragma mark 用户离开当前房间回调
/// 用户离开当前房间回调
/// @param roomId 房间ID
/// @param userId 用户ID
- (void)onRemoteUserLeaveRoom:(NSString *)roomId userId:(NSString *)userId;


#pragma mark - ------------ 音频相关回调 ------------
#pragma mark 音频播放路由变化回调
/// 音频播放路由变化回调
/// @param state 路由类型
/// @param deviceName 路由信息
- (void)onAudioRouteChange:(RTCAudioRoute)state deviceName:(NSString *)deviceName;

#pragma mark 远程成员音频状态回调
/// 远程成员音频状态回调
/// @param audioArray 成员音频列表
- (void)onRemoteMemberAudioStatus:(NSArray<RTCStreamAudioModel *> *)audioArray;

#pragma mark 服务是否允许发言回调
/// 服务是否允许发言回调
/// @param enabled 是否允许发言，YES-允许发言 NO-不允许发言
- (void)onServiceEnabledSpeak:(BOOL)enabled;


#pragma mark - ------------ 流媒体相关回调 ------------
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



//
//  RTCEngineKit.h
//  RTCEngineKit
//
//  Created by SailorGa on 2021/10/26.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CoreMedia.h>
#import <ReplayKit/ReplayKit.h>

#if __has_include(<RTCEngineKit/RTCEngineKit.h>)
#import <RTCEngineKit/RTCEngineObjects.h>
#import <RTCEngineKit/RTCEngineDelegate.h>
#import <RTCEngineKit/RTCScreenDelegate.h>
#else
#import "RTCEngineObjects.h"
#import "RTCEngineDelegate.h"
#import "RTCScreenDelegate.h"
#endif

NS_ASSUME_NONNULL_BEGIN

/// 完成回调
typedef void (^RTCEngineKitFinishBlock)(void);

#pragma mark - RTCEngineKit
@interface RTCEngineKit : NSObject

+ (instancetype)new __attribute__((unavailable("Use +sharedEngine instead or +sharedEngineWithConfig")));
- (instancetype)init __attribute__((unavailable("Use +sharedEngine instead or +sharedEngineWithConfig")));

#pragma mark - ------------ Core Service ------------

/// RTC事件代理
@property (nonatomic, weak) id<RTCEngineDelegate> delegate;

#pragma mark 获取RTC引擎实例
/// 获取RTC引擎实例
+ (RTCEngineKit *)sharedEngine;

#pragma mark 初始化RTC引擎
/// 初始化RTC引擎
/// @param engineConfig 配置参数
/// @param userModel 用户信息
/// @param delegate 代理回调
+ (instancetype)sharedEngineWithConfig:(RTCEngineConfig *)engineConfig userModel:(RTCEngineUserModel *)userModel delegate:(nullable id <RTCEngineDelegate>)delegate;

#pragma mark 初始化RTC引擎
/// 初始化RTC引擎
/// @param engineConfig 配置参数
/// @param userModel 用户信息
/// @param delegate 代理回调
- (BOOL)initializeWithConfig:(RTCEngineConfig *)engineConfig userModel:(RTCEngineUserModel *)userModel delegate:(nullable id <RTCEngineDelegate>)delegate;

#pragma mark 资源销毁
/// 资源销毁
- (void)destroy;

#pragma mark RTC引擎版本
///  RTC引擎版本
- (NSString *)version;


#pragma mark - ------------ 房间相关接口函数 ------------

#pragma mark 加入房间
/// 加入房间
/// @param roomId 房间ID
/// @param userRole 成员角色
- (BOOL)joinRoomWithRoomId:(NSString *)roomId userRole:(RTCUserRoleType)userRole;

#pragma mark 退出房间
/// 退出房间
/// @param finishBlock 完成回调
- (void)leaveRoom:(nullable RTCEngineKitFinishBlock)finishBlock;

#pragma mark 变更账户信息
/// 变更账户信息
/// @param userModel 账户信息
- (BOOL)changeWithUserModel:(RTCEngineUserModel *)userModel;

#pragma mark 变更房间信息
/// 变更房间信息
/// @param roomModel 房间信息
- (BOOL)changeWithRoomModel:(RTCEngineRoomModel *)roomModel;

#pragma mark 发送房间外消息
/// 发送房间外消息
/// @param userIds 用户ID列表
/// @param content 消息内容
/// @param action 消息类型
- (BOOL)sendMessageWithUserIds:(NSArray <NSString *> *)userIds content:(NSString *)content action:(NSString *)action;

#pragma mark 发送房间内消息
/// 发送房间内消息
/// @param content 消息内容
/// @param action 消息类型
- (BOOL)sendRoomMessageWithContent:(NSString *)content action:(NSString *)action;


#pragma mark - ------------ 数据管理相关接口 ------------

#pragma mark 获取当前账户信息
/// 获取当前账户信息
- (RTCEngineUserModel *)getMySelf;

#pragma mark 获取当前房间信息
/// 获取当前房间信息
- (RTCEngineRoomModel *)getRoomObject;

#pragma mark 获取成员信息
/// 获取成员信息
/// @param userId  用户ID
- (RTCEngineUserModel *)findMemberWithUserId:(NSString *)userId;

#pragma mark 获取成员列表
/// 获取成员列表
- (NSArray<RTCEngineUserModel *> *)getRemoteUsers;


#pragma mark - ------------ 视频相关接口函数 ------------

#pragma mark 开启本地摄像头的预览画面
/// 开启本地摄像头的预览画面
/// @param frontCamera YES-前置摄像头 NO-后置摄像头
/// @param view 承载视频画面的控件
- (void)startLocalPreview:(BOOL)frontCamera view:(VIEW_CLASS *)view;

#pragma mark 更新本地摄像头的预览画面
/// 更新本地摄像头的预览画面
/// @param view 承载视频画面的控件
- (void)updateLocalView:(VIEW_CLASS *)view;

#pragma mark 停止摄像头预览
/// 停止摄像头预览
- (void)stopLocalPreview;

#pragma mark 恢复/暂停推流
/// 恢复/暂停推流
/// @param publish YES-恢复 NO-暂停
- (void)publishLocalVideo:(BOOL)publish;

#pragma mark 切换摄像头
/// 切换摄像头
- (void)switchCamera;

#pragma mark 设置摄像头的缩放倍数
/// 设置摄像头的缩放倍数
/// @param zoomRatio 缩放系数(1.0~5.0)
- (void)setCameraZoomRatio:(CGFloat)zoomRatio;

#pragma mark 设置摄像头的对焦位置
/// 设置摄像头的对焦位置
/// @param position 对焦位置
- (void)setCameraFocusPosition:(CGPoint)position;

#pragma mark 设置摄像头的曝光系数
/// 设设置摄像头的曝光系数
/// @param exposureRatio 曝光系数(-8.0~8.0)
- (void)setCameraExposureRatio:(CGFloat)exposureRatio;

#pragma mark 设置闪光灯状态
/// 设置闪光灯状态
/// @param enabled 是否开启闪光灯(YES-开启 NO-关闭)
- (void)enableCameraTorch:(BOOL)enabled;

#pragma mark 订阅远端用户的视频流
/// 订阅远端用户的视频流
/// @param userId 指定远端用户的ID
/// @param trackId 指定要观看的轨道ID
/// @param view 承载视频画面的控件
- (void)startRemoteView:(NSString *)userId trackId:(RTCTrackIdentifierFlags)trackId view:(VIEW_CLASS *)view;

#pragma mark 更新远端用户的视频流
/// 更新远端用户的视频流
/// @param userId 指定远端用户的ID
/// @param trackId 指定要观看的轨道ID
/// @param view 承载视频画面的控件
- (void)updateRemoteView:(NSString *)userId trackId:(RTCTrackIdentifierFlags)trackId view:(VIEW_CLASS *)view;

#pragma mark 停止订阅远端用户的视频流
/// 停止订阅远端用户的视频流
/// @param userId 指定远端用户的ID
/// @param trackId 指定要观看的轨道ID
- (void)stopRemoteView:(NSString *)userId trackId:(RTCTrackIdentifierFlags)trackId;

#pragma mark 停止订阅所有远端用户的视频流
/// 停止订阅所有远端用户的视频流
- (void)stopAllRemoteView;


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
- (void)enabledSendAudio:(BOOL)enabled;

#pragma mark 设置音频优先策略
/// 设置音频优先策略
/// @param userId 指定远端用户的ID
/// @param enabled  YES-开启 NO-关闭
- (void)setAudioPriorityWithUserId:(NSString *)userId enabled:(BOOL)enabled;

#pragma mark 设置扬声器状态
/// 设置扬声器状态
/// @param enabled 是否开启扬声器(YES-开启 NO-关闭)
- (void)enabledAudioSpeaker:(BOOL)enabled;

#pragma mark 切换音频路由
/// 切换音频路由
/// @param audioRoute 音频路由
- (void)switchAudioRoute:(RTCAudioRoute)audioRoute;


#pragma mark - ------------ 屏幕共享相关接口函数 ------------
#pragma mark 关闭屏幕共享
/// 关闭屏幕共享
- (void)closeScreenServer;

#pragma mark 开启屏幕共享客户端
/// 开启屏幕共享客户端
/// @param delegate 代理回调
- (void)startScreenRecordingClient:(nullable id <RTCScreenDelegate>)delegate;

#pragma mark 发送共享屏幕帧数据
/// 发送共享屏幕帧数据
/// @param sampleBuffer 帧数据
/// @param sampleBufferType 帧数据类型
- (void)sendSampleBufferServer:(CMSampleBufferRef)sampleBuffer withType:(RPSampleBufferType)sampleBufferType;


#pragma mark - ------------ 网络测速相关接口函数 ------------
#pragma mark 开始网络测速
/// 开始网络测速
/// @param params 测速参数
/// 1、请在进入房间前进行网速测试，在房间中网速测试会影响正常的音视频传输效果，而且由于干扰过多，网速测试结果也不准确。
/// 2、同一时间只允许一项网速测试任务运行。
- (BOOL)startSpeedTest:(RTCSpeedTestParams *)params;

#pragma mark 停止网络测速
/// 停止网络测速
- (void)stopSpeedTest;

@end

NS_ASSUME_NONNULL_END

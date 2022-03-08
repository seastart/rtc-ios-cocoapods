//
//  RTCEngineKit.h
//  RTCEngineKit
//
//  Created by SailorGa on 2021/10/26.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<RTCEngineKit/RTCEngineKit.h>)
#import <RTCEngineKit/RTCEngineObjects.h>
#else
#import "RTCEngineObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineKit;

#pragma mark - RTC连接事件回调
@protocol RTCEngineDelegate <NSObject>

#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark RTC事件回调
/// RTC事件回调
/// @param engine RTCEngineKit实例
/// @param event 事件名称
/// @param result 事件参数
- (void)rtcEngine:(RTCEngineKit *)engine didReceiveEngineEvent:(RTCEngineKitEventName)event result:(NSString *)result;

#pragma mark RTC帧数据回调
/// RTC帧数据回调
/// @param engine RTCEngineKit实例
/// @param userId 用户ID
/// @param frame 数据帧对象
- (void)rtcEngine:(RTCEngineKit *)engine didRemoteMediaStreamUser:(NSString *)userId frame:(RTCEngineFrame)frame;

@end

#pragma mark - RTCEngineKit
@interface RTCEngineKit : NSObject

#pragma mark - ------------ Core Service ------------

#pragma mark RTC服务代理
/// RTC服务代理
@property (nonatomic, weak) id <RTCEngineDelegate> delegate;

#pragma mark 获取RTC实例
/// 获取RTC实例
+ (RTCEngineKit *)sharedEngine;

#pragma mark RTC服务版本
///  RTC服务版本
- (NSString *)version;

#pragma mark RTC服务版本信息
/// RTC服务版本信息
- (NSString *)versionInfo;

#pragma mark 初始化RTC服务
/// 初始化RTC服务
/// @param engineConfig 配置参数
- (BOOL)initializeWithConfig:(RTCEngineConfig *)engineConfig;

#pragma mark 加入房间
/// 加入房间
/// @param roomNo 房间号码
- (BOOL)joinRoomWithRoomNo:(NSString *)roomNo;

#pragma mark 退出房间
/// 退出房间
- (void)leaveRoom;

#pragma mark 加入电子画板
/// 加入电子画板
/// @param drawingConfig 画板配置
- (BOOL)joinDrawingWithConfig:(RTCDrawingConfig *)drawingConfig;

#pragma mark 退出电子画板
/// 退出电子画板
- (void)leaveDrawing;

#pragma mark 发送房间外消息
/// 发送房间外消息
/// @param userList 用户ID列表
/// @param message 消息详情
- (BOOL)sendMessageWithUserList:(NSArray *)userList message:(NSString *)message;

#pragma mark 发送房间内消息
/// 发送房间内消息
/// @param message 消息详情
- (BOOL)sendRoomMessageWithMessage:(NSString *)message;

#pragma mark 变更用户信息
/// 变更用户信息
/// @param userModel 用户信息
/// @param changeType 变更操作类型
- (nullable RTCEngineUserModel *)changeWithUserModel:(RTCEngineUserModel *)userModel changeType:(RTCChangeType)changeType;

#pragma mark 变更房间信息
/// 变更房间信息
/// @param roomModel 房间信息
- (nullable RTCEngineRoomModel *)changeWithRoomModel:(RTCEngineRoomModel *)roomModel;

#pragma mark 订阅用户远程流
/// 订阅用户远程流
/// @param userId 用户ID
/// @param trackId 轨道ID
- (BOOL)subscribeRemoteStreamWithUserId:(NSString *)userId trackId:(int)trackId;

#pragma mark 取消订阅用户远程流
/// 取消订阅用户远程流
/// @param userId 用户ID
/// @param trackId 轨道ID
- (BOOL)unSubscribeRemoteStreamWithUserId:(NSString *)userId trackId:(int)trackId;

#pragma mark 发送原始数据的帧缓冲区
/// 发送原始数据的帧缓冲区
/// @param frameBuffer 数据帧缓冲区
- (BOOL)sendMediaFrame:(RTCEngineFrame)frameBuffer;

#pragma mark 资源销毁
/// 资源销毁
- (void)destroy;

@end

NS_ASSUME_NONNULL_END

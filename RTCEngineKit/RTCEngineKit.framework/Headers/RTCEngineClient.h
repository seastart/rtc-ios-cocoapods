//
//  RTCEngineClient.h
//  RTCEngineKit
//
//  Created by SailorGa on 2021/10/25.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCEnum.h"

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineRoomClient;
@class RTCEngineClient;
@class RTCEngineConfig;
@class RTCAccount;

#pragma mark - RTCEngineClient回调
@protocol RTCEngineClientDelegate <NSObject>

#pragma mark 可选实现代理方法
@optional

#pragma mark Delegate Methods

#pragma mark Core Delegate Methods

@end

@interface RTCEngineClient : NSObject

#pragma mark 对象方法初始化
/// 对象方法初始化
/// @param config 配置
/// @param delegate 代理回调
- (instancetype _Nonnull)initWithConfig:(RTCEngineConfig *_Nonnull)config delegate:(id<RTCEngineClientDelegate> _Nullable)delegate;

#pragma mark 类方法初始化
/// 类方法初始化
/// @param config 配置
/// @param delegate 代理回调
+ (instancetype _Nonnull)sharedEngineClientWithConfig:(RTCEngineConfig *_Nonnull)config delegate:(id<RTCEngineClientDelegate> _Nullable)delegate;

#pragma mark - 构建RTC服务连接
/// 构建RTC服务连接
/// @param account 账户信息
/// 返回值：YES-成功，NO-失败
- (RTCConnectResult)buildConnectWithAccount:(RTCAccount *_Nonnull)account;

#pragma mark - 加入房间
/// 加入房间
/// @param roomNo 房间号码
/// 注意：连接事件成功之后调取
- (RTCEngineRoomClient *_Nonnull)joinRoomWithRoomNo:(NSString *_Nonnull)roomNo;

#pragma mark - 释放资源
/// 释放资源
- (void)destroy;

@end

NS_ASSUME_NONNULL_END

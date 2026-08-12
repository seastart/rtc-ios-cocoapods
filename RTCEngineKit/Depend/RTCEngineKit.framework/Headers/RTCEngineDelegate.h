//
//  RTCEngineDelegate.h
//  RTCEngineKit
//
//  Created by SailorGa on 2022/7/9.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<RTCEngineKit/RTCEngineKit.h>)
#import <RTCEngineKit/RTCEngineObjects.h>
#else
#import "RTCEngineObjects.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineKit;

#pragma mark - 进程级引擎事件回调
/// 进程级引擎事件回调
/// 本协议只承载 RTCEngineKit 单例范围内的共享能力事件，与具体频道无关
/// 频道内的连接、成员、码流、音频、屏幕共享等事件请实现 RTCEngineChannelDelegate
@protocol RTCEngineDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----

#pragma mark - ------------ 音频相关回调 ------------
#pragma mark 音频路由变更回调
/// 音频路由变更回调
/// 音频路由为进程级共享设备状态，变更对全部频道同时生效
/// @param route 音频路由
/// @param previousRoute 变更前的音频路由
- (void)onAudioRouteChange:(RTCAudioRoute)route previousRoute:(RTCAudioRoute)previousRoute;


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
/// 统计维度为当前应用进程，不区分频道
/// @param memory 内存占用
/// @param cpuUsage CUP使用率
- (void)onApplicationPerformance:(CGFloat)memory cpuUsage:(CGFloat)cpuUsage;

@end

NS_ASSUME_NONNULL_END

//
//  RTCEngineManager.h
//  RTCEngineKit
//
//  Created by SailorGa on 2021/10/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - RTCEngineManager

@interface RTCEngineManager : NSObject

#pragma mark - ------------ Core Service ------------
#pragma mark 获取单例RTC对象
/// 获取单例RTC对象
+ (RTCEngineManager *)sharedManager;

#pragma mark RTC基础服务版本
///  RTC基础服务版本
- (NSString *)version;

#pragma mark RTC基础服务版本信息
/// RTC基础服务版本信息
- (NSString *)versionInfo;

#pragma mark 初始化RTC服务
/// 初始化RTC服务
/// @param filePath 日志文件存储路径
/// 返回值：YES-成功，NO-失败
- (BOOL)initializeGlobalWithFilePath:(nullable NSString *)filePath;

#pragma mark - 释放资源
/// 释放资源
- (void)destroy;

@end

NS_ASSUME_NONNULL_END

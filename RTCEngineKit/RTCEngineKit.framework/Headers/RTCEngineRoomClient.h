//
//  RTCEngineRoomClient.h
//  RTCEngineKit
//
//  Created by SailorGa on 2021/10/25.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineRoomClient;

#pragma mark - RTCEngineRoomClient回调
@protocol RTCEngineRoomClientDelegate <NSObject>

#pragma mark 可选实现代理方法
@optional

#pragma mark Delegate Methods

#pragma mark Core Delegate Methods

@end

@interface RTCEngineRoomClient : NSObject

#pragma mark 房间连接回调
/// 房间连接回调
@property (nonatomic, weak) id <RTCEngineRoomClientDelegate> delegate;

#pragma mark 对象方法初始化
/// 对象方法初始化
/// @param reciver 对象实例
- (instancetype _Nonnull)initWithReciver:(void *_Nonnull)reciver;

#pragma mark 类方法初始化
/// 类方法初始化
/// @param reciver 对象实例
+ (instancetype _Nonnull)sharedEngineRoomClientWithReciver:(void *_Nonnull)reciver;

#pragma mark - 加入房间
/// 加入房间
/// @param roomNo 房间号码
- (BOOL)joinRoomWithRoomNo:(NSString *_Nonnull)roomNo;

#pragma mark - 释放资源
/// 释放资源
- (void)destroy;

@end

NS_ASSUME_NONNULL_END

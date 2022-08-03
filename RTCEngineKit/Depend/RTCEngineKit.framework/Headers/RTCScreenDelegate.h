//
//  RTCScreenDelegate.h
//  RTCEngineKit
//
//  Created by SailorGa on 2022/7/23.
//  Copyright © 2022 SailorGa. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineKit;

#pragma mark - 屏幕共享回调
@protocol RTCScreenDelegate <NSObject>
#pragma mark 可选实现代理方法
@optional

#pragma mark - ----- Core Delegate Methods -----
#pragma mark 录屏完成回调
/// 录屏完成回调
/// @param engine 回调实例
/// @param reason 结束原因
- (void)broadcastFinished:(RTCEngineKit *)engine reason:(NSString *)reason;

@end

NS_ASSUME_NONNULL_END

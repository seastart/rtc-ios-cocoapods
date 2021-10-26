//
//  RTCEngineConfig.h
//  RTCEngineKit
//
//  Created by SailorGa on 2021/10/25.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RTCEngineConfig : NSObject

/// 应用ID
@property (nonatomic, copy) NSString *appId;
/// 服务地址
@property (nonatomic, copy) NSString *uri;
/// 服务线路ID
@property (nonatomic, copy, nullable) NSString *lineId;
/// 服务分组ID
@property (nonatomic, copy, nullable) NSString *groupId;

@end

NS_ASSUME_NONNULL_END

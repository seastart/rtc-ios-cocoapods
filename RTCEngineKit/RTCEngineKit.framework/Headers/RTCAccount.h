//
//  RTCAccount.h
//  RTCEngineKit
//
//  Created by SailorGa on 2021/10/25.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RTCEnum.h"

NS_ASSUME_NONNULL_BEGIN

@interface RTCAccount : NSObject

/// 用户ID
@property (nonatomic, copy) NSString *user_id;
/// 用户名称
@property (nonatomic, copy) NSString *name;
/// 终端类型，默认 RTCTerminalIOS
@property (nonatomic, assign) RTCTerminal type;
/// 成员角色，默认 RTCRoleTypeDefault
@property (nonatomic, assign) RTCRoleType role;

@end

NS_ASSUME_NONNULL_END

//
//  RTCEngineEnum.h
//  RTCEngineKit
//
//  Created by SailorGa on 2022/3/4.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - ------- RTC服务事件名称枚举类型 -------
typedef NSString *RTCEngineKitEventName NS_STRING_ENUM;

#pragma mark RTC服务事件
/// 错误事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameError;
/// 登录事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameLogin;
/// 加入事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameJoin;
/// 房间事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameRoomEvent;
/// 成员事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameUserEvent;
/// 码流事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameStreamsEvent;
/// 退出事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameUserLeave;
/// 消息事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameMessage;

#pragma mark 电子画板事件
/// 电子画板加入事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameDrawingJoin;
/// 电子画板绘制事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameDrawingDraw;
/// 电子画板撤销事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameDrawingBack;
/// 电子画板清空事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameDrawingClean;
/// 电子画板重置事件
FOUNDATION_EXPORT RTCEngineKitEventName const RTCEngineKitEventNameDrawingReset;


#pragma mark - RTC错误码
/**
 RTC错误码
 
 - RTCEngineResultOK: 无错误
 - RTCEngineResultInternalError: 服务器内部错误
 - RTCEngineResultInvalidParams: 参数错误
 - RTCEngineResultInvalidSession: Session无效
 - RTCEngineResultNotFound: 查找资源不存在
 - RTCEngineResultConcLimit: 并发授权不足
 - RTCEngineResultServerLess: 没有服务器
 - RTCEngineResultServerLineLess: 没有服务器线路
 - RTCEngineResultInvalidAppId: 无效的AppID
 - RTCEngineResultTimeout: 超时
 - RTCEngineResultNetError: 网络错误
 - RTCEngineResultThirdPartyRefused: 第三方授权限制
 - RTCEngineResultTPNetError: 流媒体节点网络错误
 */
typedef enum : NSInteger {
    
    RTCEngineResultOK = 0,
    RTCEngineResultInternalError = 1,
    RTCEngineResultInvalidParams = 2,
    RTCEngineResultInvalidSession = 3,
    RTCEngineResultNotFound = 4,
    RTCEngineResultConcLimit = 5,
    RTCEngineResultServerLess = 7,
    RTCEngineResultServerLineLess = 8,
    RTCEngineResultInvalidAppId = 9,
    RTCEngineResultTimeout = 10,
    RTCEngineResultNetError = 11,
    RTCEngineResultThirdPartyRefused = 12,
    RTCEngineResultTPNetError = 13
} RTCEngineResult;


#pragma mark - 终端类型
/**
 终端类型
 
 - RTCTerminalTypeUnknown: 未知终端
 - RTCTerminalTypeWindows: Windows端
 - RTCTerminalTypeMacOS: Mac端
 - RTCTerminalTypeAndroid: 安卓端
 - RTCTerminalTypeAndroidTV: 安卓TV端
 - RTCTerminalTypeIOS: iOS端
 - RTCTerminalTypeEmbeddedDev: 嵌入式终端
 */
typedef enum : NSUInteger {
    
    RTCTerminalTypeUnknown = 0,
    RTCTerminalTypeWindows = 1000,
    RTCTerminalTypeMacOS = 1001,
    RTCTerminalTypeAndroid = 2000,
    RTCTerminalTypeAndroidTV = 2001,
    RTCTerminalTypeIOS = 2002,
    RTCTerminalTypeEmbeddedDev = 3000
} RTCTerminalType;


#pragma mark - 成员角色类型
/**
 成员角色类型
 
 - RTCUserRoleTypeDefault: 普通成员
 - RTCUserRoleTypeAudience: 听众, 听众的信息不会公布给房间内的其他成员
 */
typedef enum : NSInteger {
    
    RTCUserRoleTypeDefault = 0,
    RTCUserRoleTypeAudience = 1
} RTCUserRoleType;


#pragma mark - 编码类型
/**
 编码类型
 
 - RTCCodecTypeH264: H264
 - RTCCodecTypeH265: H265
 - RTCCodecTypeAAC: AAC
 - RTCCodecTypeOPUS: OPUS
 */
typedef enum : NSUInteger {
    
    RTCCodecTypeH264 = 0x1b,
    RTCCodecTypeH265 = 0x24,
    RTCCodecTypeAAC = 0x0f,
    RTCCodecTypeOPUS = 0x5355504f
} RTCCodecType;


#pragma mark - 变更操作类型
/**
 变更操作类型
 
 - RTCChangeTypeNone: 无操作
 - RTCChangeTypeSet: 替换
 - RTCChangeTypeAppend: 新增
 - RTCChangeTypeRemove: 移除
 - RTCChangeTypeClear: 清空
 */
typedef enum : NSUInteger {
    
    RTCChangeTypeNone = 0,
    RTCChangeTypeSet = 1,
    RTCChangeTypeAppend = 2,
    RTCChangeTypeRemove = 3,
    RTCChangeTypeClear = 4
} RTCChangeType;


#pragma mark - 媒体类型
/**
 媒体类型
 
 - RTCMediaTypeData: 数据类型
 - RTCMediaTypeVideo: 视频类型
 - RTCMediaTypeAudio: 音频类型
 */
typedef enum : NSInteger {
    
    RTCMediaTypeData = 0,
    RTCMediaTypeVideo = 1,
    RTCMediaTypeAudio = 2
} RTCMediaType;


#pragma mark - 数据帧类型
/**
 数据帧类型
 
 - RTCFrameTypeUnknown: 未知类型
 - RTCFrameTypeIDR: IDR帧
 - RTCFrameTypeIFrame: I帧
 - RTCFrameTypePFrame: P帧
 */
typedef enum : NSInteger {
    
    RTCFrameTypeUnknown = -1,
    RTCFrameTypeIDR = 0,
    RTCFrameTypeIFrame = 1,
    RTCFrameTypePFrame = 2,
} RTCFrameType;


#pragma mark - 像素格式类型
/**
 像素格式类型
 
 - RTCColorFormatUnknown: 未知类型
 - RTCColorFormatRGB: RGB
 - RTCColorFormatRGBA: RGBA
 - RTCColorFormatYUV444p: YUV444p
 - RTCColorFormatYUV422p: YUV422p
 - RTCColorFormatYUV420p: YUV420p
 - RTCColorFormatMJPEG: MJPEG
 */
typedef enum : NSInteger {
    
    RTCColorFormatUnknown = 0,
    RTCColorFormatRGB = 1,
    RTCColorFormatRGBA = 2,
    RTCColorFormatYUV444p = 3,
    RTCColorFormatYUV422p = 4,
    RTCColorFormatYUV420p = 5,
    RTCColorFormatMJPEG = 100
} RTCColorFormat;


#pragma mark - 电子画板权限
/**
 电子画板权限
 
 - RTCDrawingPrivilegesDefault: 默认，只读权限
 - RTCDrawingPrivilegesWrite: 可写权限
 - RTCDrawingPrivilegesAdmin: 管理权限
 */
typedef enum : NSInteger {
    
    RTCDrawingPrivilegesDefault = 0,
    RTCDrawingPrivilegesWrite = 1,
    RTCDrawingPrivilegesAdmin = 3
} RTCDrawingPrivileges;


#pragma mark - 电子画板绘制状态
/**
 电子画板绘制状态
 
 - RTCDrawingTypeBegin: 开始绘制
 - RTCDrawingTypeDrawing: 绘制中
 - RTCDrawingTypeEnd: 结束绘制
 */
typedef enum : NSInteger {
    
    RTCDrawingTypeBegin = 0,
    RTCDrawingTypeDrawing = 1,
    RTCDrawingTypeEnd = 2
} RTCDrawingType;


#pragma mark - 电子画板图形类型
/**
 电子画板图形类型
 
 - RTCDrawingTypeRubber: 橡皮擦
 - RTCDrawingTypePen: 画笔
 - RTCDrawingTypeLine: 线条
 - RTCDrawingTypeRect: 矩形
 - RTCDrawingTypeEllipse: 椭圆
 - RTCDrawingTypeArrow: 箭头
 - RTCDrawingTypeText: 文本
 */
typedef enum : NSInteger {
    
    RTCDrawingTypeRubber = 0,
    RTCDrawingTypePen = 1,
    RTCDrawingTypeLine = 2,
    RTCDrawingTypeRect = 3,
    RTCDrawingTypeEllipse = 4,
    RTCDrawingTypeArrow = 5,
    RTCDrawingTypeText = 6
} RTCDrawingShapeType;


#pragma mark - 电子画板指令
/**
 电子画板指令
 
 - RTCDrawingCommandEnterRequest: 进入请求
 - RTCDrawingCommandEnterResponse: 进入响应
 - RTCDrawingCommandHeartbeatRequest: 心跳请求
 - RTCDrawingCommandHeartbeatResponse: 心跳响应
 - RTCDrawingCommandExitRequest: 退出请求
 - RTCDrawingCommandExitResponse: 退出响应
 - RTCDrawingCommandDraw: 绘制请求
 - RTCDrawingCommandDrawEvent: 绘制响应
 - RTCDrawingCommandBack: 撤销请求
 - RTCDrawingCommandBackEvent: 撤销响应
 - RTCDrawingCommandClean: 清除请求
 - RTCDrawingCommandCleanEvent: 清除响应
 - RTCDrawingCommandReset: 重置画布请求
 - RTCDrawingCommandResetEvent: 重置画布响应
 */
typedef enum : NSInteger {
    
    RTCDrawingCommandEnterRequest = 1,
    RTCDrawingCommandEnterResponse = 2,
    
    RTCDrawingCommandHeartbeatRequest = 3,
    RTCDrawingCommandHeartbeatResponse = 4,
    
    RTCDrawingCommandExitRequest = 5,
    RTCDrawingCommandExitResponse = 6,
    
    RTCDrawingCommandDraw = 7,
    RTCDrawingCommandDrawEvent = 8,
    
    RTCDrawingCommandBack = 9,
    RTCDrawingCommandBackEvent = 10,
    
    RTCDrawingCommandClean = 11,
    RTCDrawingCommandCleanEvent = 12,
    
    RTCDrawingCommandReset = 13,
    RTCDrawingCommandResetEvent = 14,
    
} RTCDrawingCommand;

NS_ASSUME_NONNULL_END

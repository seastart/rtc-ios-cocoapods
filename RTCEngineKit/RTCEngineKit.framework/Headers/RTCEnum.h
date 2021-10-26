//
//  RTCEnum.h
//  RTCEngineKit
//
//  Created by SailorGa on 2021/10/25.
//  Copyright © 2021 SailorGa. All rights reserved.
//

#ifndef RTCEnum_h
#define RTCEnum_h

#pragma mark - RTC指令
/**
 RTC指令
 
 - RTCCommandUnknown: 未知指令
 - RTCCommandRoomEnterRequest: 进入房间请求
 - RTCCommandRoomEnterRsponse: 进入房间响应
 - RTCCommandRoomEnterReady: 准备就绪请求
 - RTCCommandRoomHeartbeatRequest: 心跳请求
 - RTCCommandRoomHeartbeatResponse: 心跳响应
 - RTCCommandRoomUserEvent: 成员进入事件或者成员信息变更事件
 - RTCCommandRoomExitRequest: 退出房间请求
 - RTCCommandRoomExitResponse: 退出房间响应
 - RTCCommandRoomUserExitEvent: 成员退出事件
 - RTCCommandRoomSetRoomRequest: 设置房间状态请求
 - RTCCommandRoomSetRoomResponse: 设置房间状态响应
 - RTCCommandRoomRoomEvent: 房间信息变更事件
 - RTCCommandRoomSendMessageRequest: 发送消息请求
 - RTCCommandRoomSendMessageResponse: 发送消息响应
 - RTCCommandRoomMessageEvent: 消息事件
 - RTCCommandRoomKickoutRequest: 踢人请求
 - RTCCommandRoomKickoutResponse: 踢人响应
 - RTCCommandRoomKickoutEvent: 踢人事件
 - RTCCommandIMEnterRequest: 进入请求
 - RTCCommandIMEnterResponse: 进入响应
 - RTCCommandIMExitRequest: 退出请求
 - RTCCommandIMExitResponse: 退出响应
 - RTCCommandIMHeartbeatRequest: 心跳请求
 - RTCCommandIMHeartbeatResponse: 心跳响应
 - RTCCommandIMKickoutRequest: 踢人请求
 - RTCCommandIMKickoutResponse: 踢人响应
 - RTCCommandIMKickoutEvent: 心跳事件
 - RTCCommandIMSendMessageRequest: 发送消息请求
 - RTCCommandIMSendMessageResponse: 发送消息响应
 - RTCCommandIMMessageEvent: 发送消息事件
 */
typedef enum : NSInteger {
    
    /// //////////////////////////////////////////////////////////////////////////////
    ///       基础指令
    /// //////////////////////////////////////////////////////////////////////////////
    RTCCommandUnknown = 0,
    
    
    /// //////////////////////////////////////////////////////////////////////////////
    ///       房间内指令
    /// //////////////////////////////////////////////////////////////////////////////
    RTCCommandRoomEnterRequest = 1000,
    RTCCommandRoomEnterRsponse = 1001,
    RTCCommandRoomEnterReady = 1002,
    
    RTCCommandRoomHeartbeatRequest = 1010,
    RTCCommandRoomHeartbeatResponse = 1011,
    RTCCommandRoomUserEvent = 1012,
    
    RTCCommandRoomExitRequest = 1020,
    RTCCommandRoomExitResponse = 1021,
    RTCCommandRoomUserExitEvent = 1022,
    
    RTCCommandRoomSetRoomRequest = 1030,
    RTCCommandRoomSetRoomResponse = 1031,
    RTCCommandRoomRoomEvent = 1032,
    
    RTCCommandRoomSendMessageRequest = 1040,
    RTCCommandRoomSendMessageResponse = 1041,
    RTCCommandRoomMessageEvent = 1042,
    
    RTCCommandRoomKickoutRequest = 1050,
    RTCCommandRoomKickoutResponse = 1051,
    RTCCommandRoomKickoutEvent = 1052,
    
    
    /// //////////////////////////////////////////////////////////////////////////////
    ///       房间外指令
    /// //////////////////////////////////////////////////////////////////////////////
    RTCCommandIMEnterRequest = 2000,
    RTCCommandIMEnterResponse = 2001,
    
    RTCCommandIMExitRequest = 2010,
    RTCCommandIMExitResponse = 2011,
    
    RTCCommandIMHeartbeatRequest = 2020,
    RTCCommandIMHeartbeatResponse = 2021,
    
    RTCCommandIMKickoutRequest = 2030,
    RTCCommandIMKickoutResponse = 2031,
    RTCCommandIMKickoutEvent = 2032,
    
    RTCCommandIMSendMessageRequest = 2040,
    RTCCommandIMSendMessageResponse = 2041,
    RTCCommandIMMessageEvent = 2042
} RTCCommand;


#pragma mark - RTC错误码
/**
 RTC错误码
 
 - RTCResultOK: 无错误
 - RTCResultUnknownError: 未知错误
 - RTCResultInvalidParams: 无效的参数
 - RTCResultInvalidSession: 无效的Session
 - RTCResultRoomNotFound: 房间不存在
 - RTCResultUserNotFound: 用户不存在
 - RTCResultConcLimit: 并发不足
 - RTCResultUploadNotFound: 流媒体不存在
 - RTCResultNetError: 网络错误
 */
typedef enum : NSInteger {
    
    RTCResultOK = 0,
    RTCResultUnknownError = 1,
    RTCResultInvalidParams = 2,
    RTCResultInvalidSession = 3,
    RTCResultRoomNotFound = 4,
    RTCResultUserNotFound = 5,
    RTCResultConcLimit = 6,
    RTCResultUploadNotFound = 7,
    RTCResultNetError = -2
} RTCResult;


#pragma mark - RTC连接错误码
/**
 RTC连接错误码
 
 - RTCConnectResultOK: 无错误
 - RTCConnectResultCreateError: 创建RTCClient对象失败
 - RTCConnectResultAccountError: 设置账号信息失败
 - RTCConnectResultConnectError: RTC服务器连接失败
 */
typedef enum : NSInteger {
    
    RTCConnectResultOK = 0,
    RTCConnectResultCreateError = 1,
    RTCConnectResultAccountError = 2,
    RTCConnectResultConnectError = 3
} RTCConnectResult;


#pragma mark - RTC终端类型
/**
 RTC终端类型
 
 - RTCTerminalUnknown: 未知终端
 - RTCTerminalPC: PC端
 - RTCTerminalMac: Mac端
 - RTCTerminalAndroid: 安卓端
 - RTCTerminalIOS: iOS端
 - RTCTerminalEmbedded: 嵌入式终端
 */
typedef enum : NSUInteger {
    
    RTCTerminalUnknown = 0,
    RTCTerminalPC = 0x0101,
    RTCTerminalMac = 0x0102,
    RTCTerminalAndroid = 0x0201,
    RTCTerminalIOS = 0x0202,
    RTCTerminalEmbedded = 0x0300
} RTCTerminal;


#pragma mark - RTC成员角色
/**
 RTC成员角色
 
 - RTCRoleTypeDefault: 默认角色
 - RTCRoleTypeAudience: 观众
 */
typedef enum : NSInteger {
    
    RTCRoleTypeDefault = 0,
    RTCRoleTypeAudience = 1
} RTCRoleType;


#pragma mark - RTC取流类型
/**
 RTC取流类型
 
 - RTCPickerTypeClose: 未取流
 - RTCPickerTypeAudio: 音频流
 - RTCPickerTypeVideo: 视频流
 - RTCPickerTypeAll: 音视频流
 */
typedef enum : NSInteger {
    
    RTCPickerTypeClose = 0,
    RTCPickerTypeAudio = 1,
    RTCPickerTypeVideo = 2,
    RTCPickerTypeAll = RTCPickerTypeAudio | RTCPickerTypeVideo
} RTCPickerType;


#pragma mark - RTC媒体类型
/**
 RTC媒体类型
 
 - RTCMediaTypeData: 数据类型
 - RTCMediaTypeVideo: 视频类型
 - RTCMediaTypeAudio: 音频类型
 */
typedef enum : NSInteger {
    
    RTCMediaTypeData = 0,
    RTCMediaTypeVideo = 1,
    RTCMediaTypeAudio = 2
} RTCMediaType;


#pragma mark - RTC码流类型
/**
 RTC码流类型
 
 - RTCStreamTypeMain: 主码流
 - RTCStreamTypeSub: 子码流
 */
typedef enum : NSInteger {
    
    RTCStreamTypeMain = 0,
    RTCStreamTypeSub = 1
} RTCStreamType;


#pragma mark - RTC编码类型
/**
 RTC编码类型
 
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


#pragma mark - RTC帧类型
/**
 RTC帧类型
 
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


#pragma mark - RTC色彩格式类型
/**
 RTC色彩格式类型
 
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

#endif /* RTCEnum_h */

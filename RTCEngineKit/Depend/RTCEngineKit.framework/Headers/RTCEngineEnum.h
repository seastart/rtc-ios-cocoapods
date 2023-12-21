//
//  RTCEngineEnum.h
//  RTCEngineKit
//
//  Created by SailorGa on 2022/3/4.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - RTC错误码
typedef enum : NSInteger {
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       基础错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 无错误
    RTCEngineErrorOK = 0,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       系统级错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 系统内部错误
    RTCEngineErrorSystemFail = 1,
    /// 未初始化
    RTCEngineErrorNotInitialized = 2,
    /// 媒体模块尚未初始化
    RTCEngineErrorMediaNotInitialized = 3,
    /// 外部视频设备错误
    RTCEngineErrorVideoCapturerFail = 100,
    /// 外部音频设备错误
    RTCEngineErrorAudioCapturerFail = 101,
    /// 外部扬声器错误
    RTCEngineErrorAudioPlayerFail = 102,
    /// 设备访问无权限
    RTCEngineErrorDeviceNoRights = 103,
    /// 设备不存在
    RTCEngineErrorDeviceNotfound = 104,
    /// 协议解析错误
    RTCEngineErrorProtocolParsingFail = 200,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       通用错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 超时
    RTCEngineErrorTimeout = 1000,
    /// 参数错误
    RTCEngineErrorInvalidArgs = 1001,
    /// 重复操作冲突
    RTCEngineErrorConflict = 1002,
    /// 尚未加入房间
    RTCEngineErrorNotYetInRoom = 1003,
    /// 网络测试时拒绝操作
    RTCEngineErrorForbiddenInNetTesting = 1004,
    /// 查找的资源不存在
    RTCEngineErrorNotFound = 1100,
    /// 用户不存在
    RTCEngineErrorUserNotFound = 1101,
    /// 房间不存在
    RTCEngineErrorRoomNotFound = 1102,
    /// 码流不存在
    RTCEngineErrorStreamNotFound = 1103,
    /// 会话不存在
    RTCEngineErrorSessionNotFound = 1104,
    /// 被踢出
    RTCEngineErrorSessionKickout = 1105,
    /// 用户签名失效
    RTCEngineErrorUserSigInvalid = 1106,
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       网络类错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 网络错误
    RTCEngineErrorNetFail = 2000,
    /// 媒体网络错误
    RTCEngineErrorMediaNetFail = 2001,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       应用相关错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 无效的AppID
    RTCEngineErrorInvalidAppId = 3001,
    /// 签名错误
    RTCEngineErrorApiSignatureFail = 3002,
    /// Api请求时间戳错误
    RTCEngineErrorApiTimestampeFail = 3003,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       权限类错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 操作未授权
    RTCEngineErrorUnauthorized = 4000,
    /// 操作不允许
    RTCEngineErrorForbidden = 4001,
    /// 并发不足
    RTCEngineErrorConcLimit = 4002,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       服务端错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 服务器内部错误
    RTCEngineErrorServerFail = 5000,
    /// MQTT服务器资源不足
    RTCEngineErrorMQTTServerLess = 5010,
    /// MQTT没有服务器线路
    RTCEngineErrorMQTTServerLineLess = 5011,
    /// 流媒体服务器资源不足
    RTCEngineErrorUploadServerLess = 5020,
    /// 流媒体没有服务器线路
    RTCEngineErrorUploadServerLineLess = 5021,
    /// 流媒体服务器绑定的WebRTC网关不足
    RTCEngineErrorUploadWebRtcLess = 5022,
    /// 流媒体服务器绑定的RTMP网关不足
    RTCEngineErrorUploadRtmpLess = 5023,
    /// WebRTC服务器资源不足
    RTCEngineErrorWebRtcServerLess = 5030,
    /// WebRTC没有服务器线路
    RTCEngineErrorWebRtcServerLineLess = 5031,
    /// RTMP服务器资源不足
    RTCEngineErrorRTMPServerLess = 5040,
    /// RTMP没有服务器线路
    RTCEngineErrorRTMPServerLineLess = 5041,
    
    
    /////////////////////////////////////////////////////////////////////////////////
    ///
    ///       第三方自定义错误码
    ///
    /////////////////////////////////////////////////////////////////////////////////
    /// 第三方平台鉴权错误
    RTCEngineErrorThirdPartyRefused = 100000,
} RTCEngineError;


#pragma mark - 日志等级
/**
 日志等级

 - RTCEngineLogLevelTrace: TRACE
 - RTCEngineLogLevelDebug: DEBUG
 - RTCEngineLogLevelInfo: INFO
 - RTCEngineLogLevelWarn: WARN
 - RTCEngineLogLevelError: ERROR
 - RTCEngineLogLevelCritical: CRITICAL
 - RTCEngineLogLevelOff: OFF
*/
typedef enum : NSUInteger {
    
    RTCEngineLogLevelTrace = 0,
    RTCEngineLogLevelDebug = 1,
    RTCEngineLogLevelInfo = 2,
    RTCEngineLogLevelWarn = 3,
    RTCEngineLogLevelError = 4,
    RTCEngineLogLevelCritical = 5,
    RTCEngineLogLevelOff = 6,
} RTCEngineLogLevel;


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


#pragma mark - 媒体流类型
/**
 媒体流类型
 
 - RTCStreamTypeAudio: 音频流类型
 - RTCStreamTypeVideo: 视频流类型
 */
typedef enum : NSInteger {
    
    RTCStreamTypeAudio = 0,
    RTCStreamTypeVideo = 1
} RTCStreamType;


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


#pragma mark - 码流轨道掩码
/**
 码流轨道掩码
 
 - RTCTrackMaskFlags0: 轨道0掩码
 - RTCTrackMaskFlags1: 轨道1掩码
 - RTCTrackMaskFlags2: 轨道2掩码
 - RTCTrackMaskFlags3: 轨道3掩码
 - RTCTrackMaskFlags4: 轨道4掩码
 - RTCTrackMaskFlags5: 轨道5掩码
 - RTCTrackMaskFlags6: 轨道6掩码
 */
typedef enum : NSUInteger {
    
    RTCTrackMaskFlags0 = 1 << 0,
    RTCTrackMaskFlags1 = 1 << 1,
    RTCTrackMaskFlags2 = 1 << 2,
    RTCTrackMaskFlags3 = 1 << 3,
    RTCTrackMaskFlags4 = 1 << 4,
    RTCTrackMaskFlags5 = 1 << 5,
    RTCTrackMaskFlags6 = 1 << 6,
} RTCTrackMaskFlags;


#pragma mark - 码流轨道标识
/**
 码流轨道标识
 
 - RTCTrackIdentifierFlags0: 轨道0标识(子码流)
 - RTCTrackIdentifierFlags1: 轨道1标识(主码流)
 - RTCTrackIdentifierFlags2: 轨道2标识(共享码流)
 - RTCTrackIdentifierFlags3: 轨道3标识(可自定义码流)
 - RTCTrackIdentifierFlags4: 轨道4标识(可自定义码流)
 - RTCTrackIdentifierFlags5: 轨道5标识(可自定义码流)
 - RTCTrackIdentifierFlags6: 轨道6标识(可自定义码流)
 - RTCTrackIdentifierFlagsAudio: 音频轨道标识
 */
typedef enum : NSInteger {
    
    RTCTrackIdentifierFlags0 = 0,
    RTCTrackIdentifierFlags1 = 1,
    RTCTrackIdentifierFlags2 = 2,
    RTCTrackIdentifierFlags3 = 3,
    RTCTrackIdentifierFlags4 = 4,
    RTCTrackIdentifierFlags5 = 5,
    RTCTrackIdentifierFlags6 = 6,
    RTCTrackIdentifierFlagsAudio = -1
} RTCTrackIdentifierFlags;


#pragma mark - 屏幕共享状态
/**
 屏幕共享状态
 
 - RTCScreenRecordStatusNormal: 屏幕共享常规状态
 - RTCScreenRecordStatusError: 屏幕共享连接错误
 - RTCScreenRecordStatusStop: 屏幕共享已经停止
 - RTCScreenRecordStatusStart: 屏幕共享已经开始
 */
typedef enum : NSInteger {
    
    RTCScreenRecordStatusNormal = 1000,
    RTCScreenRecordStatusError = -1,
    RTCScreenRecordStatusStop = 0,
    RTCScreenRecordStatusStart = 1
} RTCScreenRecordStatus;


#pragma mark - 网络延时抗抖动等级
/**
 网络延时抗抖动等级
 
 - RTCNetworkQosShakeLevelUltraShort: 超短(0) 单向延迟120ms左右 这种模式下没有丢包补偿机制 并且编码关闭了B帧 一般不建议实际使用
 - RTCNetworkQosShakeLevelShort: 短(1) 单向延迟200ms左右 单次丢包补偿 B帧为1 双向对讲环境下可以使用
 - RTCNetworkQosShakeLevelMedium: 中(2) 单向延迟350ms左右 两次丢包补偿 B帧为1 双向对讲环境下推荐使用
 - RTCNetworkQosShakeLevelLong: 长(3) 单向延迟600ms左右 三次丢包补偿 B帧为3 这种模式仅用于单向收看 双向对讲环境下不建议使用 该参数无法动态设置
 */
typedef enum : NSInteger {
    
    RTCNetworkQosShakeLevelUltraShort = 0,
    RTCNetworkQosShakeLevelShort = 1,
    RTCNetworkQosShakeLevelMedium = 2,
    RTCNetworkQosShakeLevelLong = 3
} RTCNetworkQosShakeLevel;


#pragma mark - 音频路由类型
/**
 音频路由类型
 
 - RTCAudioRouteUnknown: 未知
 - RTCAudioRouteSpeaker: 扬声器
 - RTCAudioRouteReceiver: 听筒
 - RTCAudioRouteBluetooth: 蓝牙耳机
 - RTCAudioRouteHeadset: 有线耳机
 */
typedef enum : NSInteger {
    
    RTCAudioRouteUnknown = 0,
    RTCAudioRouteSpeaker = 1,
    RTCAudioRouteReceiver = 2,
    RTCAudioRouteBluetooth = 3,
    RTCAudioRouteHeadset = 4
} RTCAudioRoute;


#pragma mark - 网络状况
/**
 网络状况
 
 - RTCNetworkStateNormal: 良好
 - RTCNetworkStatePoor: 不佳
 - RTCNetworkStateBad:  较差
 - RTCNetworkStateVeryBad: 极差
 */
typedef enum : NSInteger {
    
    RTCNetworkStateNormal = 0,
    RTCNetworkStatePoor = 1,
    RTCNetworkStateBad = 2,
    RTCNetworkStateVeryBad = 3
} RTCNetworkState;


#pragma mark - 订阅远程流类型
/**
 订阅远程流类型
 
 - RTCPickerStateClose: 关闭订阅
 - RTCPickerStateAudio: 订阅音频流
 - RTCPickerStateVideo: 订阅视频流
 - RTCPickerStateAudioAndVideo: 订阅音视频流
 - RTCPickerStateBesides: 订阅除某个人的流
 */
typedef enum : NSInteger {
    
    RTCPickerStateClose = 0,
    RTCPickerStateAudio = 1,
    RTCPickerStateVideo = 2,
    RTCPickerStateAudioAndVideo = 3,
    RTCPickerStateBesides = 0x2000
} RTCPickerState;


#pragma mark - 下行码率自适应状态
/**
 下行码率自适应状态
 
 - RTCDownBitrateAdaptiveStateNormal: 正常
 - RTCDownBitrateAdaptiveStatePoor: 较差
 - RTCDownBitrateAdaptiveStateBad: 很差
 - RTCDownBitrateAdaptiveStateVeryBad: 极差
 - RTCDownBitrateAdaptiveStateLose: 下行链路状态不存在
 */
typedef enum : NSInteger {
    
    RTCDownBitrateAdaptiveStateNormal = 0,
    RTCDownBitrateAdaptiveStatePoor = -1,
    RTCDownBitrateAdaptiveStateBad = -2,
    RTCDownBitrateAdaptiveStateVeryBad = -3,
    RTCDownBitrateAdaptiveStateLose = -4
} RTCDownBitrateAdaptiveState;


#pragma mark - 下行平均丢包档位
/**
 下行平均丢包档位
 
 - RTCDownLossLevelStateInvalid: 无效
 - RTCDownLossLevelStateNormal: 正常
 - RTCDownLossLevelStatePoor: 较差
 - RTCDownLossLevelStateBad:  很差
 - RTCDownLossLevelStateVeryBad: 极差
 */
typedef enum : NSInteger {
    
    RTCDownLossLevelStateInvalid = -1,
    RTCDownLossLevelStateNormal = 0,
    RTCDownLossLevelStatePoor = 1,
    RTCDownLossLevelStateBad = 2,
    RTCDownLossLevelStateVeryBad = 3
} RTCDownLossLevelState;


#pragma mark - 上行码率自适应状态
/**
 上行码率自适应状态
 
 - RTCUploadBitrateAdaptiveStateStart: 码率自适应开始工作
 - RTCUploadBitrateAdaptiveStateNormal: 码率恢复到最初设置
 - RTCUploadBitrateAdaptiveStateHalf:  码率变为原来的一半
 - RTCUploadBitrateAdaptiveStateQuarter: 码率变为原来的四分之一
 - RTCUploadBitrateAdaptiveStateVeryBad: 当前网络环境及其差劲情况
 */
typedef enum : NSInteger {
    
    RTCUploadBitrateAdaptiveStateStart = 1000,
    RTCUploadBitrateAdaptiveStateNormal = 0,
    RTCUploadBitrateAdaptiveStateHalf = -1,
    RTCUploadBitrateAdaptiveStateQuarter = -2,
    RTCUploadBitrateAdaptiveStateVeryBad = -3,
} RTCUploadBitrateAdaptiveState;


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

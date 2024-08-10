//
//  RTCEngineEnum.h
//  RTCEngineKit
//
//  Created by SailorGa on 2022/3/4.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


#pragma mark - 错误码
/// 错误码
typedef enum : NSInteger {
    
    /// 无错误
    RTCEngineErrorOK = 0,
    
    /// 系统内部错误
    RTCEngineErrorSystemError = 100001,
    /// 未初始化
    RTCEngineErrorNotInitialized = 100002,
    /// 媒体模块尚未初始化
    RTCEngineErrorMediaNotInitialized = 100003,
    /// 协议解析错误
    RTCEngineErrorProtocolParsingError = 100004,
    
    /// 超时
    RTCEngineErrorTimeout = 100005,
    /// 参数错误
    RTCEngineErrorInvalidArgs = 100006,
    /// 重复操作冲突
    RTCEngineErrorConflict = 100007,
    /// 令牌失效
    RTCEngineErrorSdkTokenInvalid = 100008,
    
    /// 网络错误
    RTCEngineErrorNetError = 100009,
    /// 媒体网络错误
    RTCEngineErrorMediaNetError = 100010,
    /// 目标不存在
    RTCEngineErrorNotFound = 100011,
    
    /// 设备访问无权限
    RTCEngineErrorDeviceNoAuthorized = 103001,
    /// 未加入频道
    RTCEngineErrorNotJoinedChannel = 103002,
    /// 操作不被允许
    RTCEngineErrorForbidden = 103003,
    /// 码流不存在
    RTCEngineErrorStreamNotFound = 103004
} RTCEngineError;


#pragma mark - 设备类型
/// 设备类型
typedef enum : NSUInteger {
    
    /// 未知设备
    RTCDeviceTypeUnknown = 0,
    
    /// Windows
    RTCDeviceTypeWindows = 1,
    /// Android
    RTCDeviceTypeAndroid = 2,
    /// iOS
    RTCDeviceTypeIOS = 3,
    /// Linux
    RTCDeviceTypeLinux = 4,
    /// MacOS
    RTCDeviceTypeMacOS = 5,
    
    /// WebRTC
    RTCDeviceTypeWebRTC = 6,
    /// RTMP
    RTCDeviceTypeRtmp = 7
} RTCDeviceType;


#pragma mark - 成员角色
/// 成员角色
typedef enum : NSInteger {
    
    /// 普通成员
    RTCUserRoleDefault = 0,
    /// 听众, 听众的信息不会公布给房间内的其他成员
    RTCUserRoleAudience = 1
} RTCUserRole;


#pragma mark - 编码类型
/// 编码类型
typedef enum : NSUInteger {
    
    /// 未知类型
    RTCCodecTypeUnknown = 0,
    /// H264
    RTCCodecTypeH264 = 0x1b,
    /// H265
    RTCCodecTypeH265 = 0x24,
    /// AAC
    RTCCodecTypeAAC = 0x0f,
    /// OPUS
    RTCCodecTypeOPUS = 0x5355504f
} RTCCodecType;


#pragma mark - 线路类型
/// 线路类型
typedef enum : NSInteger {
    
    /// 默认
    RTCLineTypeDefault = 0,
    /// 正常
    RTCLineTypeNormal = 1
} RTCLineType;


#pragma mark - 服务类型
/// 服务类型
typedef enum : NSInteger {
    
    RTCServerTypeMQ = 0,
    RTCServerTypeUpload = 1,
    RTCServerTypeWebRTC = 2,
    RTCServerTypeRTMP = 3,
    RTCServerTypeStorage = 4
} RTCServerType;


#pragma mark - 变更操作类型
/// 变更操作类型
typedef enum : NSUInteger {
    
    /// 无操作
    RTCChangeTypeNone = 0,
    /// 更新
    RTCChangeTypeUpdate = 1,
    /// 新增
    RTCChangeTypeAppend = 2,
    /// 移除
    RTCChangeTypeRemove = 3,
    /// 清空
    RTCChangeTypeClear = 4
} RTCChangeType;


#pragma mark - 媒体类型
/// 媒体类型
typedef enum : NSInteger {
    
    /// 数据类型
    RTCMediaTypeData = 0,
    /// 视频类型
    RTCMediaTypeVideo = 1,
    /// 音频类型
    RTCMediaTypeAudio = 2
} RTCMediaType;


#pragma mark - 媒体流类型
/// 媒体流类型
typedef enum : NSInteger {
    
    /// 音频流类型
    RTCStreamTypeAudio = 0,
    /// 视频流类型
    RTCStreamTypeVideo = 1
} RTCStreamType;


#pragma mark - 数据帧类型
/// 数据帧类型
typedef enum : NSInteger {
    
    /// 未知类型
    RTCFrameTypeUnknown = -1,
    /// IDR帧
    RTCFrameTypeIDR = 0,
    /// I帧
    RTCFrameTypeIFrame = 1,
    /// P帧
    RTCFrameTypePFrame = 2
} RTCFrameType;


#pragma mark - 像素格式类型
/// 像素格式类型
typedef enum : NSInteger {
    
    /// 未知类型
    RTCColorFormatUnknown = 0,
    /// RGB
    RTCColorFormatRGB = 1,
    /// RGBA
    RTCColorFormatRGBA = 2,
    /// YUV444p
    RTCColorFormatYUV444p = 3,
    /// YUV422p
    RTCColorFormatYUV422p = 4,
    /// YUV420p
    RTCColorFormatYUV420p = 5,
    /// MJPEG
    RTCColorFormatMJPEG = 100
} RTCColorFormat;


#pragma mark - 电子画板权限
/// 电子画板权限
typedef enum : NSInteger {
    
    /// 默认，只读权限
    RTCDrawingPrivilegesDefault = 0,
    /// 可写权限
    RTCDrawingPrivilegesWrite = 1,
    /// 管理权限
    RTCDrawingPrivilegesAdmin = 3
} RTCDrawingPrivileges;


#pragma mark - 电子画板图形类型
/// 电子画板图形类型
typedef enum : NSInteger {
    
    /// 橡皮擦
    RTCDrawingTypeRubber = 0,
    /// 画笔
    RTCDrawingTypePen = 1,
    /// 线条
    RTCDrawingTypeLine = 2,
    /// 矩形
    RTCDrawingTypeRect = 3,
    /// 椭圆
    RTCDrawingTypeEllipse = 4,
    /// 箭头
    RTCDrawingTypeArrow = 5,
    /// 文本
    RTCDrawingTypeText = 6
} RTCDrawingShapeType;


#pragma mark - 电子画板绘制状态
/// 电子画板绘制状态
typedef enum : NSInteger {
    
    /// 开始绘制
    RTCDrawingTypeBegin = 0,
    /// 绘制中
    RTCDrawingTypeDrawing = 1,
    /// 结束绘制
    RTCDrawingTypeEnd = 2
} RTCDrawingType;


#pragma mark - 电子画板指令
/// 电子画板指令
typedef enum : NSInteger {
    
    /// 进入请求
    RTCDrawingCommandEnterRequest = 1,
    /// 进入响应
    RTCDrawingCommandEnterResponse = 2,
    
    /// 心跳请求
    RTCDrawingCommandHeartbeatRequest = 3,
    /// 心跳响应
    RTCDrawingCommandHeartbeatResponse = 4,
    
    /// 退出请求
    RTCDrawingCommandExitRequest = 5,
    /// 退出响应
    RTCDrawingCommandExitResponse = 6,
    
    /// 绘制请求
    RTCDrawingCommandDraw = 7,
    /// 绘制响应
    RTCDrawingCommandDrawEvent = 8,
    
    /// 撤销请求
    RTCDrawingCommandBack = 9,
    /// 撤销响应
    RTCDrawingCommandBackEvent = 10,
    
    /// 清除请求
    RTCDrawingCommandClean = 11,
    /// 清除响应
    RTCDrawingCommandCleanEvent = 12,
    
    /// 重置画布请求
    RTCDrawingCommandReset = 13,
    /// 重置画布响应
    RTCDrawingCommandResetEvent = 14
} RTCDrawingCommand;


#pragma mark - 日志等级
/// 日志等级
typedef enum : NSUInteger {
    
    /// TRACE
    RTCEngineLogLevelTrace = 0,
    /// DEBUG
    RTCEngineLogLevelDebug = 1,
    /// INFO
    RTCEngineLogLevelInfo = 2,
    /// WARN
    RTCEngineLogLevelWarn = 3,
    /// ERROR
    RTCEngineLogLevelError = 4,
    /// CRITICAL
    RTCEngineLogLevelCritical = 5,
    /// OFF
    RTCEngineLogLevelOff = 6
} RTCEngineLogLevel;


#pragma mark - 离开频道原因
/// 离开频道原因
typedef enum : NSInteger {
    
    /// 发生错误
    RTCLeaveReasonError = -1,
    /// 主动离开
    RTCLeaveReasonNormal = 1,
    /// 被踢离开
    RTCLeaveReasonKickout = 2,
    /// 被顶号
    RTCLeaveReasonReplaced = 3,
    /// 心跳超时离开
    RTCLeaveReasonTimeout = 4,
    /// 频道销毁离开
    RTCLeaveReasonDestroy = 5
} RTCLeaveReason;


#pragma mark - 码流轨道掩码
/// 码流轨道掩码
typedef enum : NSUInteger {
    
    /// 轨道0掩码
    RTCTrackMaskFlags0 = 1 << 0,
    /// 轨道1掩码
    RTCTrackMaskFlags1 = 1 << 1,
    /// 轨道2掩码
    RTCTrackMaskFlags2 = 1 << 2,
    /// 轨道3掩码
    RTCTrackMaskFlags3 = 1 << 3,
    /// 轨道4掩码
    RTCTrackMaskFlags4 = 1 << 4,
    /// 轨道5掩码
    RTCTrackMaskFlags5 = 1 << 5,
    /// 轨道6掩码
    RTCTrackMaskFlags6 = 1 << 6,
} RTCTrackMaskFlags;


#pragma mark - 码流轨道标识
/// 码流轨道标识
typedef enum : NSInteger {
    
    /// 轨道0标识(子码流)
    RTCTrackIdentifierFlags0 = 0,
    /// 轨道1标识(主码流)
    RTCTrackIdentifierFlags1 = 1,
    /// 轨道2标识(共享码流)
    RTCTrackIdentifierFlags2 = 2,
    /// 轨道3标识(可自定义码流)
    RTCTrackIdentifierFlags3 = 3,
    /// 轨道4标识(可自定义码流)
    RTCTrackIdentifierFlags4 = 4,
    /// 轨道5标识(可自定义码流)
    RTCTrackIdentifierFlags5 = 5,
    /// 轨道6标识(可自定义码流)
    RTCTrackIdentifierFlags6 = 6,
    /// 音频轨道标识
    RTCTrackIdentifierFlagsAudio = 7
} RTCTrackIdentifierFlags;


#pragma mark - 屏幕共享状态
/// 屏幕共享状态
typedef enum : NSInteger {
    
    /// 屏幕共享常规状态
    RTCScreenRecordStatusNormal = 1000,
    /// 屏幕共享连接错误
    RTCScreenRecordStatusError = -1,
    /// 屏幕共享已经停止
    RTCScreenRecordStatusStop = 0,
    /// 屏幕共享已经开始
    RTCScreenRecordStatusStart = 1
} RTCScreenRecordStatus;


#pragma mark - 网络延时抗抖动等级
/// 网络延时抗抖动等级
typedef enum : NSInteger {
    
    /// 超短(0) 单向延迟120ms左右 这种模式下没有丢包补偿机制 并且编码关闭了B帧 一般不建议实际使用
    RTCNetworkQosShakeLevelUltraShort = 0,
    /// 短(1) 单向延迟200ms左右 单次丢包补偿 B帧为1 双向对讲环境下可以使用
    RTCNetworkQosShakeLevelShort = 1,
    /// 中(2) 单向延迟350ms左右 两次丢包补偿 B帧为1 双向对讲环境下推荐使用
    RTCNetworkQosShakeLevelMedium = 2,
    /// 长(3) 单向延迟600ms左右 三次丢包补偿 B帧为3 这种模式仅用于单向收看 双向对讲环境下不建议使用 该参数无法动态设置
    RTCNetworkQosShakeLevelLong = 3
} RTCNetworkQosShakeLevel;


#pragma mark - 音频路由类型
/// 音频路由类型
typedef enum : NSInteger {
    
    /// 未知
    RTCAudioRouteUnknown = 0,
    /// 扬声器
    RTCAudioRouteSpeaker = 1,
    /// 听筒
    RTCAudioRouteReceiver = 2,
    /// 蓝牙耳机
    RTCAudioRouteBluetooth = 3,
    /// 有线耳机
    RTCAudioRouteHeadset = 4
} RTCAudioRoute;


#pragma mark - 网络状况
/// 网络状况
typedef enum : NSInteger {
    
    /// 良好
    RTCNetworkStateNormal = 0,
    /// 不佳
    RTCNetworkStatePoor = 1,
    /// 较差
    RTCNetworkStateBad = 2,
    /// 极差
    RTCNetworkStateVeryBad = 3
} RTCNetworkState;


#pragma mark - 订阅远程流类型
/// 订阅远程流类型
typedef enum : NSInteger {
    
    /// 关闭订阅
    RTCPickerStateClose = 0,
    /// 订阅音频流
    RTCPickerStateAudio = 1,
    /// 订阅视频流
    RTCPickerStateVideo = 2,
    /// 订阅音视频流
    RTCPickerStateAudioAndVideo = 3,
    /// 订阅除某个人的流
    RTCPickerStateBesides = 0x2000
} RTCPickerState;


#pragma mark - 下行码率自适应状态
/// 下行码率自适应状态
typedef enum : NSInteger {
    
    /// 正常
    RTCDownBitrateAdaptiveStateNormal = 0,
    /// 较差
    RTCDownBitrateAdaptiveStatePoor = -1,
    /// 很差
    RTCDownBitrateAdaptiveStateBad = -2,
    /// 极差
    RTCDownBitrateAdaptiveStateVeryBad = -3,
    /// 下行链路状态不存在
    RTCDownBitrateAdaptiveStateLose = -4
} RTCDownBitrateAdaptiveState;


#pragma mark - 下行平均丢包档位
/// 下行平均丢包档位
typedef enum : NSInteger {
    
    /// 无效
    RTCDownLossLevelStateInvalid = -1,
    /// 正常
    RTCDownLossLevelStateNormal = 0,
    /// 较差
    RTCDownLossLevelStatePoor = 1,
    /// 很差
    RTCDownLossLevelStateBad = 2,
    /// 极差
    RTCDownLossLevelStateVeryBad = 3
} RTCDownLossLevelState;


#pragma mark - 上行码率自适应状态
/// 上行码率自适应状态
typedef enum : NSInteger {
    
    /// 码率自适应开始工作
    RTCUploadBitrateAdaptiveStateStart = 1000,
    /// 码率恢复到最初设置
    RTCUploadBitrateAdaptiveStateNormal = 0,
    /// 码率变为原来的一半
    RTCUploadBitrateAdaptiveStateHalf = -1,
    /// 码率变为原来的四分之一
    RTCUploadBitrateAdaptiveStateQuarter = -2,
    /// 当前网络环境及其差劲情况
    RTCUploadBitrateAdaptiveStateVeryBad = -3,
} RTCUploadBitrateAdaptiveState;


#pragma mark - 码流轨道种类
/// 码流轨道种类
typedef NSString *RTCStreamTrackKind NS_STRING_ENUM;
/// 视频类型
FOUNDATION_EXPORT RTCStreamTrackKind const RTCStreamTrackKindVideo;
/// 音频类型
FOUNDATION_EXPORT RTCStreamTrackKind const RTCStreamTrackKindAudio;


#pragma mark - 码流轨道描述
/// 码流轨道描述
typedef NSString *RTCStreamTrackDesc NS_STRING_ENUM;
/// 麦克风流描述
FOUNDATION_EXPORT RTCStreamTrackDesc const RTCStreamTrackDescMic;
/// 摄像头大流描述
FOUNDATION_EXPORT RTCStreamTrackDesc const RTCStreamTrackDescCameraBig;
/// 摄像头小流描述
FOUNDATION_EXPORT RTCStreamTrackDesc const RTCStreamTrackDescCameraSmall;
/// 桌面共享流描述
FOUNDATION_EXPORT RTCStreamTrackDesc const RTCStreamTrackDescScreen;


#pragma mark - 日志组件中的日志等级
/// 日志组件中的日志等级
typedef enum : NSUInteger {
    
    RTCLoggerLevelUndefined = 0,
    RTCLoggerLevelTrace = 1,
    RTCLoggerLevelDebug = 5,
    RTCLoggerLevelInfo = 9,
    RTCLoggerLevelWarn = 13,
    RTCLoggerLevelError = 17,
    RTCLoggerLevelFatal = 21
} RTCLoggerLevel;


#pragma mark - 日志组件中的日志种类
/// 日志组件中的日志种类
typedef NSString *RTCLoggerKind NS_STRING_ENUM;
/// type=app.start
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindAppStart;
/// type=app.resource
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindAppResource;
/// type=app.network
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindAppNetwork;
/// type=app.log
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindAppLog;
/// type=rtc.event.audioinput
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcEventAudioInput;
/// type=rtc.event.audiooutput
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcEventAudioOutput;
/// type=rtc.event.videoinput
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcEventVideoInput;
/// type=rtc.event.videooutput
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcEventVideoOutput;
/// type=rtc.event.remotestream
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcEventRemoteStream;
/// type=rtc.event.connection
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcEventConnection;
/// type=rtc.config.mcu
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcConfigMcu;
/// type=rtc.ook
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcOok;
/// type=rtc.log
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcLog;
/// type=rtc.marker
FOUNDATION_EXPORT RTCLoggerKind const RTCLoggerKindRtcMarker;


NS_ASSUME_NONNULL_END

//
//  RTCEngineObjects.h
//  RTCEngineKit
//
//  Created by SailorGa on 2022/3/3.
//  Copyright © 2022 SailorGa. All rights reserved.
//

#import <Foundation/Foundation.h>

#if __has_include(<RTCEngineKit/RTCEngineKit.h>)
#import <RTCEngineKit/RTCEngineEnum.h>
#else
#import "RTCEngineEnum.h"
#endif

#import <UIKit/UIKit.h>
typedef UIView VIEW_CLASS;
typedef UIColor COLOR_CLASS;

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineStreamTrackModel;
@class RTCStreamAudioModel;
@class RTCStreamSendModel;
@class RTCStreamReceiveModel;


#pragma mark - 初始化RTC配置参数
/// 初始化RTC配置参数
@interface RTCEngineConfig : NSObject

/// 日志文件路径，默认沙盒 Document 目录
@property (nonatomic, copy) NSString *logPath;
/// 是否启用本地日志，默认 NO
/// 关闭后，必要日志会输出到控制台，建议 Debug 版本关闭
/// 启用后，会保存控制台日志，建议 Release 版本开启
@property (nonatomic, assign) BOOL enableLocalLog;

/// 版本信息，例如：@"smeeting:0.0.1"，注意：如没有特殊业务场景可不传
@property (nonatomic, copy, nullable) NSString *version;

@end


#pragma mark - 用户信息
/// 用户信息
@interface RTCEngineUserModel : NSObject

/// 应用标识
@property (nonatomic, copy) NSString *appId;
/// 用户标识
@property (nonatomic, copy) NSString *userId;
/// 会话标识
@property (nonatomic, copy) NSString *sessionId;
/// 用户名称
@property (nonatomic, copy) NSString *name;
/// 设备类型，默认 SRTCDeviceTypeIOS
@property (nonatomic, assign) SRTCDeviceType deviceType;
/// 设备标识
@property (nonatomic, copy) NSString *deviceId;
/// 组件版本号
@property (nonatomic, copy) NSString *version;
/// 网络标识
@property (nonatomic, copy) NSString *netid;
/// 分组标识
@property (nonatomic, copy) NSString *sgid;
/// 频道名称
@property (nonatomic, copy) NSString *channel;
/// 连接标识(流媒体)
@property (nonatomic, assign) int linkId;
/// 会话令牌(流媒体)
@property (nonatomic, copy) NSString *sessionKey;
/// 流媒体服务标识
@property (nonatomic, copy) NSString *uploadId;
/// 是否为观众
@property (nonatomic, assign) BOOL isAudience;
/// 加入时间
@property (nonatomic, assign) NSInteger joinAt;
/// 更新时间
@property (nonatomic, assign) NSInteger updatedAt;
/// 离开时间
@property (nonatomic, assign) NSInteger leaveAt;
/// 码流轨道列表
@property (nonatomic, strong) NSMutableArray <RTCEngineStreamTrackModel *> *streamTracks;

/// 自定义属性
@property (nonatomic, assign) id props;

@end


#pragma mark - 码流轨道信息
/// 码流轨道信息
@interface RTCEngineStreamTrackModel : NSObject

/// 码流标识
@property (nonatomic, copy) NSString *streamId;
/// 码流描述
@property (nonatomic, copy) NSString *desc;
/// 码流种类
@property (nonatomic, copy) RTCStreamTrackKind kind;
/// 编码类型
@property (nonatomic, assign) RTCCodecType codecType;
/// 画面宽
@property (nonatomic, assign) int width;
/// 画面高
@property (nonatomic, assign) int height;
/// 帧率
@property (nonatomic, assign) int fps;
/// 码率
@property (nonatomic, assign) int bitrate;
/// 画面旋转角度
@property (nonatomic, assign) int angle;
/// 音频采样率
@property (nonatomic, assign) int sampleRate;
/// 轨道号码
@property (nonatomic, assign) RTCTrackIdentifierFlags track;

/// 自定义属性
@property (nonatomic, assign) id props;

@end


#pragma mark - 频道信息
/// 频道信息
@interface RTCEngineChannelModel : NSObject

/// 应用标识
@property (nonatomic, copy) NSString *appId;
/// 频道名称
@property (nonatomic, copy) NSString *channel;
/// 连接标识(流媒体)
@property (nonatomic, assign) int linkId;
/// 频道最大用户数
@property (nonatomic, assign) int maxUser;
/// 频道音频最大转发数
@property (nonatomic, assign) int maxAudio;
/// 频道用户最大可转发数
@property (nonatomic, assign) int maxPeer;
/// 频道用户视频最大可转发数
@property (nonatomic, assign) int maxVideo;
/// 创建时间
@property (nonatomic, assign) NSInteger createdAt;
/// 更新时间
@property (nonatomic, assign) NSInteger updatedAt;

/// 自定义属性
@property (nonatomic, assign) id props;

@end


#pragma mark - 流媒体配置参数
/// 流媒体配置参数
@interface RTCEngineMediaConfig : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 回声消除AEC，默认12
@property (nonatomic, assign) int aec;
/// 自动增益控制AGC，默认16000
@property (nonatomic, assign) int agc;
/// 音频采样率，默认48000
@property (nonatomic, assign) int audioSampe;
/// 音频编码格式，默认OPUS
@property (nonatomic, assign) RTCCodecType audioEncode;
/// 音频路由，默认RTCAudioRouteSpeaker
@property (nonatomic, assign) RTCAudioRoute audioRoute;

/// 视频分辨率宽必须是16的倍数 高必须是2的倍数 否则容易出现绿边等问题(已做了兼容)
/// 1080P---1920x1080
/// 720P---1280x720
/// 480P---640x480
/// 180P---320x180
/// 视频分辨率宽，默认640
@property (nonatomic, assign) int videoWidth;
/// 视频分辨率高，默认480
@property (nonatomic, assign) int videoHeight;
/// 视频镜像，默认YES
@property (nonatomic, assign) BOOL videoMirror;

/// 视频帧率，默认25
@property (nonatomic, assign) int fps;
/// 视频码率，默认0.9*1024，单位kbps
@property (nonatomic, assign) int bitrate;

/// 是否启用媒体流加密 YES开启 NO关闭，默认 NO
@property (nonatomic, assign) BOOL enableEncrypt;
/// 是否强制横屏，默认 NO
@property (nonatomic, assign) BOOL forceLandscape;

@end


#pragma mark - 网络质量控制参数
/// 网络质量控制参数
@interface RTCEngineNetworkQosParam : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 接收自适应延迟二档位，默认 500
@property (nonatomic, assign) int secondGear;
/// 接收自适应延迟三档位，默认 1200
@property (nonatomic, assign) int thirdGear;

/// 获取云端音频数据信息周期，默认为500毫秒
@property (nonatomic, assign) float onAudioCycle;

/// 开启硬件解码 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isHardwarede;
/// 开启网络自适应延迟 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isNetworkAdaptive;
/// 开启码率自适应 YES开启 NO关闭，默认 YES
@property (nonatomic, assign) BOOL isBitrateAdaptive;

/// 网络延时抗抖动等级，默认RTCNetworkQosShakeLevelMedium
@property (nonatomic, assign) RTCNetworkQosShakeLevel shakeLevel;

@end


#pragma mark - 调试模式参数
/// 调试模式参数
@interface RTCEngineDebugParam : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 远程调试地址
@property (nonatomic, copy, nullable) NSString *debugHost;

/// 保存视频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveVideo;
/// 保存采集音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioCapture;
/// 保存远程音频流，默认 NO
@property (nonatomic, assign) BOOL enableSaveAudioReceive;

@end


#pragma mark - 测速参数
/// 测速参数
@interface RTCSpeedTestParams : NSObject

/// 连接标识(流媒体)
@property (nonatomic, assign) int linkId;

/// 流媒体服务地址
@property (nonatomic, copy) NSString *streamHost;
/// 流媒体服务端口
@property (nonatomic, assign) int streamPort;

/// 预期的上行带宽，默认 2000kbps，设置为0时不对上行做检测
@property (nonatomic, assign) int expectedUpBandwidth;
/// 预期的下行带宽，默认 2000kbps，设置为0时不对下行做检测
@property (nonatomic, assign) int expectedDownBandwidth;
/// 测试时长，默认 30s
@property (nonatomic, assign) int duration;

@end


#pragma mark - 测速结果
/// 测速结果
@interface RTCSpeedTestResult : NSObject

/// 接收/发送包数
@property (nonatomic, assign) NSInteger recv;
/// 错序数
@property (nonatomic, assign) NSInteger miss;
/// 丢包数
@property (nonatomic, assign) NSInteger losf;
/// 速率/码率(kbps)
@property (nonatomic, assign) NSInteger speed;
/// 网络延迟
@property (nonatomic, assign) NSInteger delay;

/// 丢包率
@property (nonatomic, assign) float dropRate;
/// 网络状况
@property (nonatomic, assign) RTCNetworkState state;

@end


#pragma mark - 测速连接状态结果
/// 测速连接状态结果
@interface RTCSpeedTestConnectResult : NSObject

/// 网络回环延迟
@property (nonatomic, assign) NSInteger delay;

/// 互联网连接情况，YES-正常 NO-异常
@property (nonatomic, assign) BOOL internetConnect;
/// 流媒体连接情况，YES-正常 NO-异常
@property (nonatomic, assign) BOOL streamConnect;
/// 会控服务连接情况，YES-正常 NO-异常
@property (nonatomic, assign) BOOL signalingConnect;

@end


#pragma mark - 流媒体音频信息列表
/// 流媒体音频信息列表
@interface RTCStreamAudioStatus : NSObject

@property (nonatomic, copy) NSArray <RTCStreamAudioModel *> *audioInfo;

@end


#pragma mark - 流媒体音频信息
/// 流媒体音频信息
@interface RTCStreamAudioModel : NSObject

/// 用户标识
@property (nonatomic, copy, readonly) NSString *userId;

/// 连接标识(流媒体)
@property (nonatomic, assign) int linkId;
/// 功率
@property (nonatomic, assign) NSInteger power;
/// 分贝值
@property (nonatomic, assign) NSInteger db;

@end


#pragma mark - 流媒体发送状态信息列表
/// 流媒体发送状态信息列表
@interface RTCStreamSendStatus : NSObject

@property (nonatomic, copy) NSArray <RTCStreamSendModel *> *uploadinfo;

@end


#pragma mark - 流媒体发送状态信息
/// 流媒体发送状态信息
@interface RTCStreamSendModel : NSObject

/// 上传缓冲包数
@property (nonatomic, assign) int buffer;
/// 上传延迟
@property (nonatomic, assign) int delay;
/// 溢出缓冲包数
@property (nonatomic, assign) int overflow;
/// 视频上传速率(单位kbps)
@property (nonatomic, copy) NSString *speed;
/// 音频上传速率(单位kbps)
@property (nonatomic, copy) NSString *audio_speed;
/// 上传状态
@property (nonatomic, assign) NSInteger status;
/// 补偿前丢包率
@property (nonatomic, assign) float loss_r;
/// 补偿后丢包率
@property (nonatomic, assign) float loss_c;
/// 抖动
@property (nonatomic, assign) double jitter;

@end


#pragma mark - 流媒体接收状态信息列表
/// 流媒体接收状态信息列表
@interface RTCStreamReceiveStatus : NSObject

@property (nonatomic, copy) NSArray <RTCStreamReceiveModel *> *recvinfo;

@end


#pragma mark - 流媒体接收状态信息
/// 流媒体接收状态信息
@interface RTCStreamReceiveModel : NSObject

/// 用户标识
@property (nonatomic, copy, readonly) NSString *userId;

/// 连接标识(流媒体)
@property (nonatomic, assign) int linkId;
/// 接收包数
@property (nonatomic, assign) int recv;
/// 补偿包数
@property (nonatomic, assign) int comp;
/// 总丢包数
@property (nonatomic, assign) int losf;
/// 端到端丢包率
@property (nonatomic, assign) float lrl;
/// 服务器到端丢包率
@property (nonatomic, assign) float lrd;
/// 音频包数
@property (nonatomic, assign) int audio;
/// 视频包数
@property (nonatomic, assign) int video;

/* ------ 传输码率 ------ */
/// 总速率
@property (nonatomic, assign) float total_speed;
/// 音频速率
@property (nonatomic, assign) float audio_speed;
/// 视频速率
@property (nonatomic, assign) float video_speed;

@end


#pragma mark - 电子画板配置参数
/// 电子画板配置参数
@interface RTCDrawingConfig : NSObject

/// 房间标识
@property (nonatomic, copy) NSString *roomId;
/// 图片地址
@property (nonatomic, copy) NSString *picUrl;
/// 用户标识
@property (nonatomic, copy) NSString *userId;

/// 画板权限，默认 RTCDrawingPrivilegesAdmin
@property (nonatomic, assign) RTCDrawingPrivileges privileges;

/// 画板宽
@property (nonatomic, assign) int width;
/// 画板高
@property (nonatomic, assign) int height;

@end


#pragma mark - 音频路由对象
/// 音频路由对象
@interface RTCAudioRouteModel : NSObject

/// 音频路由标识
@property (nonatomic, copy, nullable) NSString *identifier;
/// 音频路由
@property (nonatomic, assign) RTCAudioRoute route;
/// 音频路由名称
@property (nonatomic, copy, nullable) NSString *routeName;

/// 初始化音频路由对象
/// - Parameters:
///   - identifier: 音频路由标识
///   - route: 音频路由类型
///   - routeName: 音频路由名称
- (instancetype)initWithIdentifier:(nullable NSString *)identifier route:(RTCAudioRoute)route routeName:(nullable NSString *)routeName;

@end


NS_ASSUME_NONNULL_END

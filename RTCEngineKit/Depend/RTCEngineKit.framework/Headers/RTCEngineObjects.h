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

@class RTCEngineStreamModel;
@class RTCStreamAudioModel;
@class RTCStreamSendModel;
@class RTCStreamReceiveModel;


#pragma mark - 初始化RTC配置参数
/// 初始化RTC配置参数
@interface RTCEngineConfig : NSObject

/// AppID
@property (nonatomic, copy) NSString *appId;
/// AppKey
@property (nonatomic, copy) NSString *appKey;
/// 服务器地址
@property (nonatomic, copy) NSString *domain;
/// 日志文件路径
@property (nonatomic, copy, nullable) NSString *logPath;
/// 日志等级，默认 RTCEngineLogLevelDebug
@property (nonatomic, assign) RTCEngineLogLevel logLevel;
/// 服务线路标识
@property (nonatomic, copy, nullable) NSString *lineId;
/// 服务分组标识
@property (nonatomic, copy, nullable) NSString *groupId;

/// 平台透传参数
@property (nonatomic, copy, nullable) NSString *args;

@end

#pragma mark - 用户信息
@interface RTCEngineUserModel : NSObject

/// 用户标识
@property (nonatomic, copy) NSString *id;
/// 用户名称
@property (nonatomic, copy) NSString *name;
/// 用户头像
@property (nonatomic, copy, nullable) NSString *avatar;
/// 连接标识
@property (nonatomic, copy) NSString *linkId;
/// 会话令牌
@property (nonatomic, copy) NSString *sessionKey;

/// 成员角色，默认 RTCUserRoleTypeDefault
@property (nonatomic, assign) RTCUserRoleType role;

/// 终端类型，默认 RTCTerminalTypeIOS
@property (nonatomic, assign) RTCTerminalType terminalType;
/// 终端描述
@property (nonatomic, copy, nullable) NSString *terminalDesc;

/// 码流信息
@property (nonatomic, strong) NSMutableArray <RTCEngineStreamModel *> *streams;

/// 扩展字段
@property (nonatomic, assign) id props;

@end


#pragma mark - 码流信息
@interface RTCEngineStreamModel : NSObject

/// 码流标识
@property (nonatomic, assign) RTCTrackIdentifierFlags id;
/// 码流类型
@property (nonatomic, assign) NSInteger type;
/// 编码类型
@property (nonatomic, assign) RTCCodecType codecType;
/// 画面宽
@property (nonatomic, assign) NSInteger width;
/// 画面高
@property (nonatomic, assign) NSInteger height;
/// 帧率
@property (nonatomic, assign) NSInteger fps;
/// 码率
@property (nonatomic, assign) NSInteger bitrate;
/// 画面旋转角度
@property (nonatomic, assign) NSInteger angle;

/// 扩展字段
@property (nonatomic, assign) id props;

@end


#pragma mark - 房间信息
@interface RTCEngineRoomModel : NSObject

/// 房间标识
@property (nonatomic, copy) NSString *id;
/// 连接标识
@property (nonatomic, copy) NSString *linkId;
/// 会话令牌
@property (nonatomic, copy) NSString *sessionKey;

/// 扩展字段
@property (nonatomic, assign) id props;

@end


#pragma mark - 流媒体配置参数
@interface RTCEngineMediaConfig : NSObject

/// 获取默认配置对象
+ (instancetype)defaultConfig;

/// 回声消除AEC，默认12
@property (nonatomic, assign) int aec;
/// 自动增益控制AGC，默认16000
@property (nonatomic, assign) int agc;
/// 音频采样率，默认48000
@property (nonatomic, assign) int audioSampe;
/// 音频编码格式，默认AAC
@property (nonatomic, assign) RTCCodecType audioEncode;

/// 视频帧率，默认25
@property (nonatomic, assign) int fps;
/// 视频码率，默认900*1024
@property (nonatomic, assign) int bitrate;

/// 视频分辨率宽必须是16的倍数 高必须是2的倍数 否则容易出现绿边等问题(已做了兼容)
/// 1080P---1920x1080
/// 720P---1280x720
/// 480P---640x480
/// 180P---320x180

/// 视频分辨率宽，默认480
@property (nonatomic, assign) int videoWidth;
/// 视频分辨率高，默认640
@property (nonatomic, assign) int videoHeight;
/// 视频镜像，默认YES
@property (nonatomic, assign) BOOL videoMirror;

@end


#pragma mark - 网络质量控制参数
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
@interface RTCSpeedTestParams : NSObject

/// 流媒体标识
@property (nonatomic, assign) int linkId;

/// 流媒体服务地址
@property (nonatomic, copy, nonnull) NSString *streamHost;
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
@interface RTCStreamAudioStatus : NSObject

@property (nonatomic, copy) NSArray <RTCStreamAudioModel *> *audioInfo;

@end


#pragma mark - 流媒体音频信息
@interface RTCStreamAudioModel : NSObject

/// 用户标识
@property (nonatomic, copy, readonly) NSString *userId;

/// 流媒体标识
@property (nonatomic, assign) NSInteger linkId;
/// 功率
@property (nonatomic, assign) NSInteger power;
/// 分贝值
@property (nonatomic, assign) NSInteger db;

@end


#pragma mark - 流媒体发送状态信息列表
@interface RTCStreamSendStatus : NSObject

@property (nonatomic, copy) NSArray <RTCStreamSendModel *> *uploadinfo;

@end


#pragma mark - 流媒体发送状态信息
@interface RTCStreamSendModel : NSObject

/// 上传缓冲包数
@property (nonatomic, assign) int buffer;
/// 上传延迟
@property (nonatomic, assign) int delay;
/// 溢出缓冲包数
@property (nonatomic, assign) int overflow;
/// 上传速率(单位kps)
@property (nonatomic, copy) NSString *speed;
/// 上传状态
@property (nonatomic, assign) NSInteger status;
/// 补偿前丢包率
@property (nonatomic, assign) float loss_r;
/// 补偿后丢包率
@property (nonatomic, assign) float loss_c;

@end


#pragma mark - 流媒体接收状态信息列表
@interface RTCStreamReceiveStatus : NSObject

@property (nonatomic, copy) NSArray <RTCStreamReceiveModel *> *recvinfo;

@end


#pragma mark - 流媒体接收状态信息
@interface RTCStreamReceiveModel : NSObject

/// 用户标识
@property (nonatomic, copy, readonly) NSString *userId;

/// 流媒体标识
@property (nonatomic, assign) int linkid;
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


NS_ASSUME_NONNULL_END

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

NS_ASSUME_NONNULL_BEGIN

@class RTCEngineUserModel;
@protocol RTCEngineUserModel
@end

@class RTCEngineRoomModel;
@protocol RTCEngineRoomModel
@end

@class RTCEngineStreamModel;
@protocol RTCEngineStreamModel
@end

#pragma mark - 初始化RTC配置参数
/// 初始化RTC配置参数
@interface RTCEngineConfig : NSObject

/// AppID
@property (nonatomic, copy) NSString *appId;
/// AppKey
@property (nonatomic, copy) NSString *appKey;
/// 服务器地址
@property (nonatomic, copy) NSString *domain;

/// 用户信息
@property (nonatomic, strong) RTCEngineUserModel *userModel;

/// 密钥(如果开启了后台验证，这个参数会在登录/加入房间等时透传给第三方平台)
@property (nonatomic, copy, nullable) NSString *secret;
/// 日志文件路径
@property (nonatomic, copy, nullable) NSString *logFile;
/// 服务线路标识
@property (nonatomic, copy, nullable) NSString *lineId;
/// 服务分组标识
@property (nonatomic, copy, nullable) NSString *groupId;

/// 终端类型，默认 RTCTerminalTypeIOS
@property (nonatomic, assign) RTCTerminalType terminalType;
/// 终端描述
@property (nonatomic, copy, nullable) NSString *terminateDesc;

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
@property (nonatomic, copy) NSString *linkid;
/// 会话令牌
@property (nonatomic, copy) NSString *sessionKey;

/// 成员角色，默认 RTCUserRoleTypeDefault
@property (nonatomic, assign) RTCUserRoleType role;

/// 码流信息
@property (nonatomic, copy) NSArray <RTCEngineStreamModel> *streams;

/// 更新时间
@property (nonatomic, assign) NSInteger updatedAt;
/// 房间号码
@property (nonatomic, copy) NSString *roomId;
/// 流媒体标识
@property (nonatomic, copy) NSString *uploadId;
/// 最大视频路数
@property (nonatomic, assign) NSInteger maxVideos;

/// 扩展字段
@property (nonatomic, assign) id props;

@end


#pragma mark - 码流信息
@interface RTCEngineStreamModel : NSObject

/// 码流标识
@property (nonatomic, assign) NSInteger id;
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
/// 最大音频路数
@property (nonatomic, assign) NSInteger maxAudios;
/// 最大成员路数
@property (nonatomic, assign) NSInteger maxUsers;
/// 连接标识
@property (nonatomic, copy) NSString *linkid;
/// 会话令牌
@property (nonatomic, copy) NSString *sessionKey;
/// 更新时间
@property (nonatomic, assign) NSInteger updatedAt;

/// 扩展字段
@property (nonatomic, assign) id props;

@end


#pragma mark - 登录事件信息
@interface RTCEngineLoginEventModel : NSObject

/// 用户信息
@property (nonatomic, strong) RTCEngineUserModel *user;

@end


#pragma mark - 消息事件信息
@interface RTCEngineMessageEventModel : NSObject

/// 消息内容
@property (nonatomic, copy) NSString *message;
/// 房间标识
@property (nonatomic, copy) NSString *roomId;
/// 用户信息
@property (nonatomic, strong) RTCEngineUserModel *sender;

@end


#pragma mark - 加入房间事件信息
@interface RTCEngineJoinEventModel : NSObject

/// 用户信息
@property (nonatomic, strong) RTCEngineUserModel *user;
/// 房间信息
@property (nonatomic, strong) RTCEngineRoomModel *room;

/// 当前成员列表信息
@property (nonatomic, copy) NSArray <RTCEngineUserModel> *users;

@end


#pragma mark -  成员事件信息
@interface RTCEngineUserEventModel : NSObject

/// 用户信息
@property (nonatomic, strong) RTCEngineUserModel *user;

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


#pragma mark - 音视频帧数据格式
/// 音视频帧数据格式
typedef struct RTCEngineFrame {
    
    unsigned char * data;
    int dataSize;
    long long pts;
    long long dts;
    int trackId;
    RTCMediaType mt;
    RTCCodecType ct;
    RTCFrameType ft;
} RTCEngineFrame;


#pragma mark - 图像数据格式
/// 图像数据格式
typedef struct RTCEnginePicture {
    
    RTCColorFormat fmt;
    int width;
    int height;
    int trackId;
    unsigned char * _Nonnull buffer[4];
    int stride[4];
} RTCEnginePicture;


#pragma mark - 音频PCM数据格式
/// 音频PCM数据格式
typedef struct RTCEngineAudioPcm {
    
    RTCCodecType ct;
    int samples;
    int sampleRate;
    int channel;
    unsigned char * _Nonnull buffer[4];
    int stride[4];
} RTCEngineAudioPcm;

NS_ASSUME_NONNULL_END

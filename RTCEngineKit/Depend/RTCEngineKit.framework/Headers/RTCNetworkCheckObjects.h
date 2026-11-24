//
//  RTCNetworkCheckObjects.h
//  RTCEngineKit
//
//  Created by SailorGa on 2026/11/24.
//  Copyright © 2026 SailorGa. All rights reserved.
//
//  会前网络检测的参数与结果对象
//  检测项、状态取值、原因码与各端 SDK 统一（字符串取值与其它端完全一致，便于 App 与日志跨端对照）
//

#import <Foundation/Foundation.h>

#if __has_include(<RTCEngineKit/RTCEngineKit.h>)
#import <RTCEngineKit/RTCEngineEnum.h>
#else
#import "RTCEngineEnum.h"
#endif

NS_ASSUME_NONNULL_BEGIN

#pragma mark - 检测项标识
/// 检测项标识，固定 5 项，取值与各端一致
typedef NSString *RTCNetworkCheckItemId NS_TYPED_ENUM;
/// 网络权限（iOS：蜂窝数据权限，Wi-Fi 下不影响）
FOUNDATION_EXPORT RTCNetworkCheckItemId const RTCNetworkCheckItemIdPermission;
/// 网络连接情况（系统网络状态）
FOUNDATION_EXPORT RTCNetworkCheckItemId const RTCNetworkCheckItemIdConnectivity;
/// 最大传输单元检测（向媒体服务器发不分片的 UDP 探测包）
FOUNDATION_EXPORT RTCNetworkCheckItemId const RTCNetworkCheckItemIdMtu;
/// 域名解析检测（接口、信令、媒体服务器的域名）
FOUNDATION_EXPORT RTCNetworkCheckItemId const RTCNetworkCheckItemIdDns;
/// 服务器连接情况（接口 api、信令 signal、媒体 media 三个子检查）
FOUNDATION_EXPORT RTCNetworkCheckItemId const RTCNetworkCheckItemIdServer;

#pragma mark - 检测状态
/// 检测状态（单项与汇总共用一套字符串，汇总只会出现 ok / warning / fail）
typedef NSString *RTCNetworkCheckStatus NS_TYPED_ENUM;
/// 汇总：全部正常
FOUNDATION_EXPORT RTCNetworkCheckStatus const RTCNetworkCheckStatusOk;
/// 单项：通过
FOUNDATION_EXPORT RTCNetworkCheckStatus const RTCNetworkCheckStatusPass;
/// 单项 / 汇总：有隐患但可用
FOUNDATION_EXPORT RTCNetworkCheckStatus const RTCNetworkCheckStatusWarning;
/// 单项 / 汇总：异常
FOUNDATION_EXPORT RTCNetworkCheckStatus const RTCNetworkCheckStatusFail;
/// 单项：无需检测（如非 seastart 流媒体不测 MTU、接口不通时依赖服务端信息的项）
FOUNDATION_EXPORT RTCNetworkCheckStatus const RTCNetworkCheckStatusSkipped;
/// 单项：本平台不支持（iOS 五项都支持，保留取值与其它端对齐）
FOUNDATION_EXPORT RTCNetworkCheckStatus const RTCNetworkCheckStatusUnsupported;

#pragma mark - 原因码
/// 机器可读的原因码，通过时为空串
typedef NSString *RTCNetworkCheckReason NS_TYPED_ENUM;
/// 未授予网络权限（iOS 不会出现，保留与其它端对齐）
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonNoPermission;
/// 蜂窝数据被系统设置限制，且当前不在 Wi-Fi / 有线网络下
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonCellularRestricted;
/// 当前没有网络连接
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonOffline;
/// 1200 字节的探测包都回不来，但 STUN 通（网络对大包有限制）
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonMtuTooSmall;
/// UDP 不通（媒体服务器 STUN 无应答 / 探测包全部无回显）
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonUdpBlocked;
/// 有域名解析失败
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonDnsFailed;
/// 检测信息接口 netcheck/info 调用失败（服务器不可达或老服务端没有该接口）
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonApiUnreachable;
/// 信令服务器连不上（TCP/TLS 与 WebSocket 都不通）
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonSignalUnreachable;
/// 流媒体供应商不是 seastart，不做媒体 UDP / MTU 检测（skipped 时使用）
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonVendorNotSupported;
/// seastart 但服务端没有可用的媒体节点（server 记 fail，mtu 记 skipped）
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonMediaUnavailable;
/// 拿不到服务端检测信息，依赖它的 mtu、server.signal、server.media 记 skipped
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonServerInfoUnavailable;
/// 系统设不了不分片（DF），mtu 记 unsupported
FOUNDATION_EXPORT RTCNetworkCheckReason const RTCNetworkCheckReasonDfNotSupported;


#pragma mark - 网络检测参数
/// 网络检测参数
/// OC SDK 初始化时不携带应用标识与服务器地址（二者都在鉴权令牌里），因此与 JS 端一样由调用方补入参：
/// 传 appId + serverUrl，或传 token（任意一个本应用的 RTC 令牌，频道令牌 / 即时通讯令牌均可，不要求未过期），二选一；
/// 两者都传时以 appId + serverUrl 为准
@interface RTCNetworkCheckParams : NSObject

/// 应用标识(app_id)
@property (nonatomic, copy, nullable) NSString *appId;
/// SDK 接口前缀(即令牌中的 client_api，如 @"https://host/sdkapi")；检测信息接口为 {serverUrl}/v1/netcheck/info
@property (nonatomic, copy, nullable) NSString *serverUrl;
/// 加密令牌，appId / serverUrl 未传时从中解出
@property (nonatomic, copy, nullable) NSString *token;
/// 单项超时(毫秒)，默认 3000，小于等于 0 时按默认值
@property (nonatomic, assign) NSInteger timeoutMs;

@end

#pragma mark - 网络检测单项结果
/// 网络检测单项结果
@interface RTCNetworkCheckItem : NSObject

/// 检测项标识
@property (nonatomic, copy) RTCNetworkCheckItemId itemId;
/// 检测状态：pass / warning / fail / skipped / unsupported
@property (nonatomic, copy) RTCNetworkCheckStatus status;
/// 原因码，pass 时为空串
@property (nonatomic, copy) RTCNetworkCheckReason reason;
/// 给人看的中文说明，App 可直接显示
@property (nonatomic, copy) NSString *message;
/// 本项耗时(毫秒)
@property (nonatomic, assign) NSInteger costMs;
/// 本项测量值，键名与各端一致：
/// connectivity：{netType: "wifi"|"cellular"|"ethernet"|"unknown"}
/// mtu：{maxSize: 1472}（全部不通时为 0）
/// dns：{hosts: [{host, ips, costMs}]}
/// server：{api, signal, media}，子检查统一为 {ok, status: "pass"|"fail"|"skipped", reason, rttMs}；
///         signal 另带 via("tcp"|"ws"，不通时为空串)；api 失败时另带 httpStatus（收到 HTTP 响应时）/ code（HTTP 200 但业务码非 0 时）
/// permission：{}
@property (nonatomic, copy) NSDictionary<NSString *, id> *data;

/// 生成单项结果
/// @param itemId 检测项标识
/// @param status 检测状态
/// @param reason 原因码，传 nil 记为空串
/// @param message 说明文案
/// @param data 测量值，传 nil 记为空字典
+ (instancetype)itemWithId:(RTCNetworkCheckItemId)itemId status:(RTCNetworkCheckStatus)status reason:(nullable RTCNetworkCheckReason)reason message:(NSString *)message data:(nullable NSDictionary<NSString *, id> *)data;

/// 转为字典（键名与其它端一致：id / status / reason / message / costMs / data），便于日志与跨端对照
- (NSDictionary<NSString *, id> *)toDictionary;

@end


#pragma mark - 网络检测汇总结果
/// 网络检测汇总结果
@interface RTCNetworkCheckResult : NSObject

/// 汇总状态：有 fail 即 fail；无 fail 但有 warning 即 warning；否则 ok（skipped / unsupported 不影响汇总）
@property (nonatomic, copy) RTCNetworkCheckStatus status;
/// 各项结果，固定 5 项、固定顺序：permission、connectivity、mtu、dns、server
@property (nonatomic, copy) NSArray<RTCNetworkCheckItem *> *items;
/// 总耗时(毫秒)
@property (nonatomic, assign) NSInteger costMs;

/// 按单项结果计算汇总状态
/// @param items 单项结果
+ (RTCNetworkCheckStatus)statusForItems:(NSArray<RTCNetworkCheckItem *> *)items;

/// 固定的检测项顺序
+ (NSArray<RTCNetworkCheckItemId> *)itemOrder;

/// 转为字典（键名与其它端一致：status / items / costMs）
- (NSDictionary<NSString *, id> *)toDictionary;

@end


#pragma mark - 回调定义
/// 单项完成回调（主线程），按固定顺序 permission → connectivity → mtu → dns → server 回调，每项一次
typedef void (^RTCNetworkCheckItemBlock)(RTCNetworkCheckItem *item);
/// 检测完成回调（主线程）
/// 正常结束：result 非空、errorCode 为 RTCEngineErrorOK；被取消：result 为 nil、errorCode 为 RTCEngineErrorUserCancelled(103026)
typedef void (^RTCNetworkCheckCompletionBlock)(RTCNetworkCheckResult * _Nullable result, RTCEngineError errorCode);

NS_ASSUME_NONNULL_END

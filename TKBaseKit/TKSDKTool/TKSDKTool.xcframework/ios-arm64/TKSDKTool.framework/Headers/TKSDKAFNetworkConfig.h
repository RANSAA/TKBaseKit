//
//  TKSDKAFNetworkConfig.h
//  TKSDKTool
//
//  Created by PC on 2021/7/5.
//  Copyright © 2021 PC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface TKSDKAFNetworkConfig : NSObject
/** 是否开启log,  默认：YES */
@property (nonatomic, assign) BOOL isLog;
/** 是否开启URLEncode，  默认：YES */
@property (nonatomic, assign) BOOL isURLEncode;
//  设置文件上传时，文件的MIME类型， 默认：@"*/*"
@property (nonatomic, strong) NSString *updateMIME;
/** 使用cache时，可以用来标记不同用户。 默认：@"TK" */
@property (nonatomic, strong) NSString *cacheUser;
/**
 功能：是否对AFNetworking的failure错误进行解析， 默认：YES
 条件：error.userInfo.data可以转化为json时，才会转换到success状态。
 场景：比如有的服务器返回400时，它是有响应数据的，但是在AF中会走failure，这是不符合实际使用场景的；
 所以这时就需要对这个error进行解析，如果符合条件就需要将failure状态转换到success状态。
 */
@property (nonatomic, assign) BOOL isAnalysError;
/** 获取32位的随机字符串*/
@property (nonatomic, copy, readonly) NSString *random32;


/**单利实例化*/
+ (instancetype)shared;


/** 是否缓存请求数据，default NO; 注意要想缓存请求数据isCashe的值必须为YES*/
@property (nonatomic, assign) BOOL isCache;
/** 是否缓存所有的请求数据，default NO */
@property (nonatomic, assign) BOOL allCache;
/** 添加需要缓存请求的url*/
- (void)addCacheUrl:(NSString *)url;
/** 检查url是否在缓存列表中*/
- (BOOL)containsCacheUrl:(NSString *)url;
/** 获取所有的缓存url*/
- (NSArray *)allCacheUrls;
/** 清除缓存 **/
- (void)clearCache;
/** 获取缓存目录 */
- (NSString *)cachePath;
/** 获取长度为len的字符串，包含数字，大小写字母。*/
- (NSString *)randomWith:(NSUInteger)len;
/** 获取指定路径中的文件大小，单位：bytes*/
- (NSUInteger)fileSizeAtPath:(NSString *)path;

@end

NS_ASSUME_NONNULL_END

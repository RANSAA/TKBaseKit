//
//  Tool.h
//  复习
//
//  Created by PC on 2019/3/20.
//  Copyright © 2019年 PC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TKSDKEncryptTool : NSObject
/** 单例 */
+ (instancetype)shared;
/** 自定义加密密码,不推荐使用 */
- (void)customSecretKey:(NSString *)secretKey;

/** 加密并返回 */
+ (NSString*)TKXOREncodedStr:(NSString *)inputString;
/** 解码并返回 */
+ (NSString*)TKXORDecodeStr:(NSString *)xorString;
@end

NS_ASSUME_NONNULL_END

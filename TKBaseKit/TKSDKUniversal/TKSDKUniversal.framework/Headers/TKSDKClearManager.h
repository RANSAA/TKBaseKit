//
//  TKSDKClearManager.h
//  TKSDKUniversal
//
//  Created by Mac on 2019/3/22.
//  Copyright © 2019年 Mac. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TKSDKClearManager : NSObject
/** 存放将要计算，清理垃圾对应的目录  */
@property(nonatomic, strong) NSArray *clearPathAry;
@property(nonatomic, assign) CGFloat unitSize;//单位换算比例 默认1024.0

/** 如果继承该类，那么shared必须重写，并并设置unitSize的值  */
+ (instancetype)shared;

/**
 设置要清理垃圾的目录数组
 **/
- (void)setClearPathAry:(NSArray *)clearPathAry;
/**
 获取所有指定路径的缓存大小
 success：获取指定目录的缓存大小后回调,单位M
 **/
- (void)getAllCacheSizeSuccess:(void(^)(CGFloat size))success;
/**
 获取所有指定路径中的缓存
 success: 缓存清理完毕回调
 @param success 0.0
 */
- (void)clearAllCacheSuccess:(void(^)(CGFloat size))success;

@end

NS_ASSUME_NONNULL_END

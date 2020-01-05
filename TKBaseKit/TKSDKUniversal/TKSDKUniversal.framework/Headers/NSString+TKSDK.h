//
//  NSString+TKSDK.h
//  TKSDKUniversal
//
//  Created by Mac on 2019/3/22.
//  Copyright © 2019年 Mac. All rights reserved.
//

/**
 NSString的一些常用扩展
 **/
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TKSDK)

/**
 创建目录
 */
+ (void)TKCreateStorageFolder:(NSString *)path;

/**
 获取TK在沙盒中的存储目录
 */
+ (NSString *)TKGetStorageFolder;

/**
 判断path路径是文件，还是目录或者不存在
 return: 0:文件 1：目录 -1：不存在
 */
+ (NSInteger)TKCheckPathTypeWith:(NSString *)path;

/** 获取某个字符或汉字的首字母*/
+ (NSString *)TKFirstCharactorWithString:(NSString *)string;

/** 将字符串数组按默认方式排序，并返回 */
+ (NSArray *)TKDefaultSort:(NSArray<NSString*> *)stringsToSort;

/** 将字符串数组按默认方式排序，汉字优先排序，并返回 */
+ (NSArray *)TKLocalSort:(NSArray<NSString*> *)stringsToSort;

/** URL编码 */
+ (NSString *)TKURLEncodedStringWith:(NSString *)str;

/** URL解码 */
+ (NSString *)TKURLDecodedStringWith:(NSString *)str;

/** base64 编码URLSafe模式*/
+ (NSString *)TKBase64EncodedStringWith:(NSString *)string;

/** base64 解码*/
+ (NSString *)TKBase64DecodedStringWith:(NSString *)base64String;

/**
 直接将float格式化2位小数的字符串，直接截取小数点后两位
 与.2f有点区别（即：最后一位的值不会四舍五入）
 */
+ (NSString *)TKStringTwoWithFloat:(CGFloat)Float;

/** 判断字符串是否是数字  */
+ (BOOL)TKIsNumberWithString:(NSString *)strValue;

/** html字符串装换为富文本字符串 */
+ (NSAttributedString *)TKHtmlWithText:(NSString *)text;

/** 解析html中的图片地址 **/
+ (NSArray *)TKHtmlFilterImagesWithStr:(NSString *)htmlStr;


/**
 计算字符串的高度或者宽度
 @param str 字符串类型为：NSString，NSAttributedString等
 @param fixed 需要固定的的值(计算高度就要固定宽度的值，反之亦然)
 @param type 0:计算字符串的高度 1：计算字符串的宽度
 @param attr str为NSString类型时，字符串的属性，如字体大小，类型等！
 @return 返回字符串的高度或者宽度
 */
+ (CGFloat)TKGetTextHighOrWideString:(id)str fixed:(CGFloat)fixed type:(NSInteger)type attributes:(nullable NSDictionary *)attr;




@end

NS_ASSUME_NONNULL_END

//
//  NSObject+TKSDK.h
//  TKSDKUniversal
//
//  Created by Mac on 2019/3/22.
//  Copyright © 2019年 Mac. All rights reserved.
//
/**
 学习网址：https://www.jianshu.com/p/6c6f3a24b1ef
 **/
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (TKSDK)

#pragma mark Selector
/**
 功能：可以传递多个参数的performSelector方法
 @param selector 调用的方法，注意selector中的基础类型需要包装成类类型
 @param objects 参数数组
 警告: 1.不支持返回类型为struct的方法调用。2.将返回值类型为基础数据类型的值，包装成了NSNumber类型。
 */
- (id)performSelector:(SEL)selector withObjects:(nullable NSArray *)objects;
+ (id)performSelector:(SEL)selector withObjects:(nullable NSArray *)objects;

@end

NS_ASSUME_NONNULL_END

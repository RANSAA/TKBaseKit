//
//  TKSDKLayout.h
//  复习
//
//  Created by PC on 2019/3/19.
//  Copyright © 2019年 PC. All rights reserved.
//

/**
 处理布局相关的工具
 **/
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TKSDKLayout : NSObject

/**
 解决iOS11中uiscrollVIEW顶部自动有空白的问题
 这儿一直不显示留白的区域
 **/
+(void)TKLayoutScrollViewAdjustmentNeverWith:(UIScrollView *)scrollView;

/**
 设置view与toView对应的NSLayoutConstraint(包括，上，下，左，右)
 attribute： 上，下，左，右，宽，高
 并返回对应的NSLayoutConstraint
 **/
+ (NSLayoutConstraint *)TKLayoutEqualConstraintWithView:(UIView *)view toView:(UIView*)toView attribute:(NSLayoutAttribute)attribute constant:(CGFloat)constant;

/**
 设置view与toView的上下左右保持一致
 返回：约束数组layout，依次对应:top,left,bottom,right
 **/
+ (NSArray *)TKLayoutEqualConstraintArrayWithView:(UIView *)view toView:(UIView*)toView;

@end

NS_ASSUME_NONNULL_END

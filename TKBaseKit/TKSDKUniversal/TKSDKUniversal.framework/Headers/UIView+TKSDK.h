//
//  UIView+TKSDK.h
//  TKSDKUniversal
//
//  Created by Mac on 2019/3/22.
//  Copyright © 2019年 Mac. All rights reserved.
//
/**
 UIView扩展的一些常用功能
 **/
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (TKSDK)

/** 取消UIview的userInteractionEnabled，0.3s后恢复 */
- (void)setViewUserInteractionEnabledCancel;

/** 设置view的边框宽度与颜色  */
-(void)setLayerBorderColor:(UIColor *)borderColor borderWidth:(CGFloat)borderWidth;
/** 设置view的弧度 */
-(void)setLayerCornerRadiusWith:(CGFloat)radius;
/** 设置view的弧度-->值为1.0 */
-(void)setLayerCornerRadiusWithOne;
/** 设置view的弧度-->值为2.0 */
-(void)setLayerCornerRadiusWithTwo;
/** 设置view的弧度-->值为4.0 */
-(void)setLayerCornerRadiusWithFour;
/** 设置view的弧度-->值为5.0 */
-(void)setLayerCornerRadiusWithFive;
/** 设置view的弧度-->值为10.0 */
-(void)setLayerCornerRadiusWithTen;


@end

NS_ASSUME_NONNULL_END

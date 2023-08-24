//
//  TKSDKCornerShadowView.h
//  TKBaseKit
//
//  Created by kimi on 2023/8/23.
//  Copyright © 2023 PC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 一个同时支持阴影，边框线，任意角圆角的View。
 
 注意：
 由于路径是采用UIBezierPath bezierPathWithRoundedRect 方法绘制所有有一些系统自带的问题，目前并未解决。
 出现问题:
    1. 同时设置两个相邻的角为圆角，并且cornerRadius的值大于View的最小边乘以0.325时，此时的圆角半径立即为最小边的1/2。
    2. 同时设置两个相邻的角为圆角，并且设置边框线时，如果边框线的宽度大于某一个值时，边框线的某一个连接处会出现空白的缺失部分。
 
 推荐：
    如果是正常设置是个圆角时，推荐之间使用layer的相关方法来同时设置圆角，边框线，阴影。
 */

IB_DESIGNABLE
@interface TKSDKCornerShadowView : UIView
@property(nonatomic, assign) IBInspectable BOOL topLeft;
@property(nonatomic, assign) IBInspectable BOOL topRight;
@property(nonatomic, assign) IBInspectable BOOL bottomLeft;
@property(nonatomic, assign) IBInspectable BOOL bottomRight;

@property(nonatomic, assign) IBInspectable CGFloat cornerRadius;

@property(nonatomic, assign) IBInspectable CGFloat shadowRadius;
@property(nonatomic, assign) IBInspectable CGFloat shadowOpacity;
@property(nonatomic, assign) IBInspectable CGSize  shadowOffset;
@property(nonatomic, strong) IBInspectable UIColor *shadowColor;

@property(nonatomic, assign) IBInspectable CGFloat borderWidth;
@property(nonatomic, strong) IBInspectable UIColor *borderColor;

/** 背景填充颜色，注:不使用backgroundColor而使用该属性设置背景颜色 */
@property(nonatomic, strong) IBInspectable UIColor *fillColor;

@end

NS_ASSUME_NONNULL_END

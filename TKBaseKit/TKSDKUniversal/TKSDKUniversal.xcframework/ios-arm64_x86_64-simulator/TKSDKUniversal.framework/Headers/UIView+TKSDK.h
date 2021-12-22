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

#pragma mark 0.3s防止重复点击
/** 取消UIview的userInteractionEnabled，0.3s后恢复 */
- (void)setViewUserInteractionEnabledCancel;


#pragma mark 常用的layer属性设置
/** 设置view的边框宽度与颜色  */
-(void)setLayerBorderColor:(UIColor *)borderColor borderWidth:(CGFloat)borderWidth;

/**
设置UIView的弧度，子控件超出view区域部分不会被裁剪掉！
PS:一般只用于UIView控件设置弧度，如UIButton等子控件设置弧度无效
*/
-(void)setLayerCornerRadiusViewWith:(CGFloat)radius;
/**
设置UIView的弧度，子控件超出view区域部分也会被裁剪掉！
PS:设置了masksToBounds = YES
*/
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


#pragma mark 获取当前View所在控制器

/**
功能：获取view当前所在的Controller控制器。
如果是childViewController的view，并且将view作为subView添加到ViewControler.view中,那么获取到的控制器依然是"作为主控制器的ViewControler"
PS:注意与controllerFromChildController的区别
 */
- (nullable UIViewController *)controllerFromController;

/**
功能：获取view当前所在的Controller控制器。
如果是childViewController的view，并且将view作为subView添加到ViewControler.view中,那么获取到的控制器将会是"作为子控制器的childViewController"。
PS:注意与controllerFromController的区别
*/
- (nullable UIViewController *)controllerFromChildController;

#pragma mark 约束添加
/**
向view添加相对于toView的四边都对齐的约束，并返回。
return:返回四边的约束NSLayoutConstraint，顺序为top,left,Bottom,right
*/
- (NSArray<NSLayoutConstraint *>*)addEdgeConstraintsToView:(UIView *)toView API_AVAILABLE(ios(9.0));



#pragma mark frame相关设置
@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGPoint origin;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign, readonly) CGPoint centerPoint;    //view的中心点(width,height的1/2处)，不是center

@end

NS_ASSUME_NONNULL_END

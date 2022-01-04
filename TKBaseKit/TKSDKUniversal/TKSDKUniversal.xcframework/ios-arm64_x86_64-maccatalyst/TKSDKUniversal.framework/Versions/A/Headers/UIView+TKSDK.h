//
//  UIView+TKSDK.h
//  TKSDKUniversal
//
//  Created by Mac on 2019/3/22.
//  Copyright © 2019年 Mac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSValue+TKSDK.h"


/**
 注意：
    在这个UIView扩展中的+load方法中默认有一个函数交换的操作，其中交换了layoutSubviews方法;
    用户可以自行是否取消这个函数交换操作，如果取消了函数交换操作，那么该扩展中的某些与frame相关的方法可能不能实时更新。
    取消函数交换操作方法：
                    只需要在info.plist文件中添加一个类型为BOOL的字段，并将只设置为YES，即：
                    TKBaseKitUIViewSwizzleMethodCancel = YES;

 */



NS_ASSUME_NONNULL_BEGIN
@interface UIView (TKSDK)
#pragma mark frame相关设置
@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGPoint origin;
@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign, readonly) CGPoint centerPoint;    // view的中心点(width,height的1/2处)，不是center
@property (nonatomic, assign, readonly) CGRect fixedBounds;     // fixedBounds = (CGRect){CGPointZero,self.frame.size}

#pragma mark 防止重复点击
/** 防止重复点击(userInteractionEnabled=NO)，0.3秒后恢复 */
- (void)setAfterUserInteractionEnabled;


#pragma mark Layer: CAShapeLayer绘制任意圆角
/**
 同时实现：圆角(任意角)+边框线效果的解决方案
        如果是任意半径圆角可以使用setShapeLayerCornerRadiusWith和setShapeLayerBorderColor组合方式；
        标准圆角可以直接使用原生的layer属性设置；

 同时实现：圆角+边框线+阴影效果的解决方案
        1.如果是标准圆角，可以直接使用原生的layer属性设置，注意layer.masksToBounds = NO
        2.如果4个圆角半径各不相等(任意圆角)可以使用原生的layer.shadowXXX设置阴影，加setShapeLayerCornerRadiusWith和setShapeLayerBorderColor组合方式；
        3.也可以直接在draw方法中利用CGContext绘制

 提示：如果想要添加阴影效果，需要为控件设置背景颜色。

 功能扩展：
        可以通"继承"或者"扩展"的方式都可以让某种视图控件支持"任意圆角+边框线+阴影"效果，
        如果不实现并且使用了setShapeLayerCornerRadiusWith:将无法设置阴影效果。

 代码：
 + (Class)layerClass {
     return [CAShapeLayer class];
 }

 - (void)setBackgroundColor:(UIColor *)backgroundColor {
     self.layer.backgroundColor = backgroundColor.CGColor;
     ((CAShapeLayer *)self.layer).fillColor = backgroundColor.CGColor;
 }

 - (UIColor *)backgroundColor
 {
     CGColorRef colorRef = ((CAShapeLayer *)self.layer).fillColor;
     if (colorRef == NULL) {
         colorRef = self.layer.backgroundColor;
     }
     UIColor *bgColor = nil;
     if (colorRef) {
         bgColor = [UIColor colorWithCGColor:colorRef];
     }
     return bgColor;
 }

 */

//使用CAShapeLayer绘制任意圆角(设置layer.mask)，corner表示4个顶点的圆角半径。
- (void)setShapeLayerCornerRadiusWith:(UIEdgeCorners)corner;

//使用CAShapeLayer绘制绘制边框。
-(void)setShapeLayerBorderColor:(UIColor *)borderColor borderWidth:(CGFloat)borderWidth;


#pragma mark Layer: 常用的layer属性设置

/** 设置view的边框宽度与颜色  */
-(void)setLayerBorderColor:(UIColor *)borderColor borderWidth:(CGFloat)borderWidth;

/**
设置UIView的弧度，子控件超出view区域部分也会被裁剪掉！
PS:设置了masksToBounds = YES
*/
-(void)setLayerCornerRadiusWith:(CGFloat)radius;

/**
设置UIView的弧度，子控件超出view区域部分不会被裁剪掉！
PS:一般只用于UIView控件设置弧度，如UIButton等子控件设置弧度无效
*/
-(void)setLayerCornerRadiusFullWith:(CGFloat)radius;


#pragma mark Controller: 获取当前View所在控制器

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

#pragma mark Constraints: 约束添加
/**
向view添加相对于toView的四边都对齐的约束，并返回。
return:返回四边的约束NSLayoutConstraint，顺序为top,left,Bottom,right
*/
- (NSArray<NSLayoutConstraint *>*)addEdgeConstraintsToView:(UIView *)toView API_AVAILABLE(ios(9.0));





@end

NS_ASSUME_NONNULL_END

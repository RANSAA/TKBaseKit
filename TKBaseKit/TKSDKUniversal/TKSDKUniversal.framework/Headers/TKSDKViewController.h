//
//  TKSDKViewController.h
//  AF
//
//  Created by Apple on 2018/3/2.
//  Copyright © 2018年 PC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TKSDKNavigationBar.h"

/**  继承与UIVIewController
 *  使用自定义的导航条--默认是把系统的导航条给隐藏了的
 *  使用自定义的导航调配，新页面显示可以利用PUSH与Model的方式进行
 *  支持侧滑返回(使用系统默认的侧滑返回方式)
 *  默认开启可以同时接受处理多分手势(默认接受多个手势，如果不需要可以在其子类中重写相应的协议方法)
 *  实现了UIGestureRecognizerDelegate代理
 **/

@interface TKSDKViewController : UIViewController <UIGestureRecognizerDelegate>
@property(nonatomic, strong) TKSDKNavigationBar * _Nullable TKNavigationBar;//自定义的导航条
@property(nonatomic, assign) BOOL isEnabledSideslip;//是否开启侧滑返回，默认开启
@property(nonatomic, assign) BOOL isEnabledTKNavigationBar;//是否开启TKNavigationBar的使用，默认开启
/**
 设置是否默认不使用TKSDKNavigationBar， YES:不使用TKSDKNavigationBar
 可用于替换：[self setValue:@(NO) forKey:@"_isEnabledTKNavigationBar"];
 **/
@property(nonatomic, assign) BOOL isDefaultNoUseTKNavBar;


/**  返回函数操作 */
- (void)backAction:(id _Nonnull)sender;
/**
 当页面完全返回上一级页面后会调用该函数
 :- (void)didMoveToParentViewController:(UIViewController *)parent
 **/
- (void)backDidParentControllerAction;

/**  设置状态栏文字是否为白色：YES:白色 NO:黑色 **/
- (void)setStatusBarStyleLightContent:(BOOL)isLightContent;
/**  设置状态栏是否隐藏 */
- (void)setStatusBarIsHidden:(BOOL)isHidden;
/**  设置当前用户界面为横屏时是否显示状态栏，默认不显示(横屏时才有效) */
- (void)setStatusBarLandscapeIsShow:(BOOL)isShow;

/**
 默认配置方法，重写修改配置:
 直接修改
 _isEnabledSideslip
 _isEnabledTKNavigationBar
 PS:重写的时候，先super。再修改,修改时使用kvc的方式修改，如
 **/
- (void)defaultEnabledConfig;

/**
 方法代替UINavigationController中的一些方法
 实质上就是UINavigationController的push方法
 只是为了写代码的时候方便而已
 添加这两个方法就行了
 PS:
 push与pop这两个方法注意，如果存在navigationController，
 直接push和pop，反之直接使用present与dismiss
 **/
- (void)pushViewController:(UIViewController *_Nullable)viewController animated:(BOOL)animated;
- (nullable UIViewController *)popViewControllerAnimated:(BOOL)animated;
- (nullable NSArray<__kindof UIViewController *> *)popToRootViewControllerAnimated:(BOOL)animated;
- (nullable NSArray<__kindof UIViewController *> *)popToViewController:(UIViewController *_Nullable)viewController animated:(BOOL)animated;


/**
 作用：解决侧滑返回时，VC中有scrollView时，不能侧滑返回成功的问题
 scrollView:和屏幕边缘侧滑返回冲突的控件
 **/
- (void)setPanGestureRecognizerWithScrollView:(UIScrollView *_Nullable)scrollView;
/**
 作用：设置指定ScrollView，状态栏，刘海区域的不会自动留空白
 UIScrollViewContentInsetAdjustmentNever
 **/
- (void)setContentInsetWithScrollView:(UIScrollView *_Nullable)scrollView;

@end


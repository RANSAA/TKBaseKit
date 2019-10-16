//
//  TKSDKNavigationBar.h
//  AF
//
//  Created by PC on 2018/3/3.
//  Copyright © 2018年 PC. All rights reserved.
//

#import <UIKit/UIKit.h>
//#import "UIDevice+TKSDK.h"

/** 自定义的导航条
 *  导航条高度： 44+状态栏高度
 *  如果在使用了该导航条的基类中布局时的条件是:
 *  子控件的最顶部的约束应该是44+self.TopGuide
 *
 * PS：如果需要对该导航条添加新的子控件，那么就直接添加就是，不过添加的时候要注意之前已经有了的控件
 * 特别是约束一定不要添加错了，不让可能会出现一些隐藏的bug
 **/


@interface TKSDKNavigationBar : UIView

#pragma mark ----------子视图(都是懒加载)----------
/** 导航条的背景图背景图 */
@property(nonatomic, strong) UIImageView *backgroundImage;
/** navView,导航条的有效显示区域(不包含状态栏所在的区域)，默认44 */
@property(nonatomic, strong) UIView *navView;
/** navView中添加的背景图*/
@property(nonatomic, strong) UIImageView *navBackgroundImage;
/** statusBarView 状态栏所在区域 */
@property(nonatomic, strong) UIImageView *statusBarView;
/** 返回按钮*/
@property(nonatomic, strong) UIButton *btnBack;
/** 右边按钮*/
@property(nonatomic, strong) UIButton *btnRight;
/** 标题*/
@property(nonatomic, strong) UILabel  *labTitle;

#pragma mark ----------配置----------
/** navView竖屏时的高度，默认为44 */
@property(nonatomic, assign) CGFloat navViewPortraitHeight;
/** navView横屏时的高度，默认为44 */
@property(nonatomic, assign) CGFloat navViewLandscapeHeight;

#pragma mark ----------约束----------
//返回按钮的宽度约束
@property(nonatomic, strong)NSLayoutConstraint *layBtnBackWidth;
//返回按钮距离导航条的左边的距离
@property(nonatomic, strong)NSLayoutConstraint *layBtnBackLeftMargin;
//右边按钮的宽度约束
@property(nonatomic, strong)NSLayoutConstraint *layBtnRightWidth;
//右边按钮距离导航条的右边约束
@property(nonatomic, strong)NSLayoutConstraint *layBtnRightRightMargin;
//labTitle相对于contentview进行约束的
@property(nonatomic, strong)NSLayoutConstraint *layLabTitleRightMargin;
@property(nonatomic, strong)NSLayoutConstraint *layLabTitleLeftMargin;


#pragma mark 创建并将导航条添加到controller上
+ (instancetype)creteViewAddController:(UIViewController *)vc;

@end


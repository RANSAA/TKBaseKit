//
//  TKSDKNavigationController.h
//  AF
//
//  Created by Apple on 2018/3/2.
//  Copyright © 2018年 PC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface TKSDKNavigationController : UINavigationController

/**设置状态栏字体颜色 */
- (void)setIsStatusBarStyleLightContent:(NSNumber *)isStatusBarStyleLightContent;
/**设置状态栏隐藏  */
- (void)setIsStatusBarStyleHidden:(NSNumber *)isStatusBarStyleHidden;

@end

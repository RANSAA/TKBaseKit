//
//  TKFPSLabel.h
//  TKSDKUniversal
//
//  Created by PC on 2021/6/4.
//  Copyright © 2021 PC. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TKFPSLabel : UILabel
/**
 直接创建并显示在keyWindow上面。
 PS:也可以通过initWithXX方式创建，并添加到指定View上。
 */
+ (void)show;

/**销毁CADisplayLink， 使用initWithXX创建时需要手动销毁CADisplayLink。 */
- (void)invalidate;

@end

NS_ASSUME_NONNULL_END

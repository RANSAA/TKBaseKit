//
//  UIButton+TKSDK.h
//  testFor
//
//  Created by Mac on 2019/6/15.
//  Copyright © 2019 Mac. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 ⚠️注意：
        在UIButton扩展中添加setTitle:方法设置标题时,在iOS 10.3中可以正常设置，但是在iOS13.0+中无效，所以不要扩展setTitle:方法。

 */



NS_ASSUME_NONNULL_BEGIN

@interface UIButton (TKSDK)

/** 设置标题 */
- (void)setText:(NSString *)title;
/** 设置标题 */
- (void)setTitleText:(NSString *)title;


/** 设置字体颜色 */
- (void)setTitleColor:(UIColor *)color;
/** 设置image  */
- (void)setImage:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END

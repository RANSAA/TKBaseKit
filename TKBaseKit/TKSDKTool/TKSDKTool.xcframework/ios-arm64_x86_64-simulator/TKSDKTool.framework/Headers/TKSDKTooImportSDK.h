//
//  TKSDKTooImportSDK.h
//  TKSDKTool
//
//  Created by PC on 2021/6/15.
//  Copyright © 2021 PC. All rights reserved.
//

/**
 该文件用于管理依赖的三方框架
 */

#ifndef TKSDKTooImportSDK_h
#define TKSDKTooImportSDK_h



#if __has_include(<MBProgressHUD/MBProgressHUD.h>)
#import <MBProgressHUD/MBProgressHUD.h>
#else
#import "MBProgressHUD.h"
#endif

#if __has_include(<YYModel/YYModel.h>)
#import <YYModel/YYModel.h>
#else
#import "YYModel.h"
#endif

#if __has_include(<GTMBase64/GTMBase64.h>)
#import <GTMBase64/GTMBase64.h>
#else
#import "GTMBase64.h"
#endif

#if __has_include(<Masonry/Masonry.h>)
#import <Masonry/Masonry.h>
#else
#import "Masonry.h"
#endif

#if __has_include(<MJRefresh/MJRefresh.h>)
#import <MJRefresh/MJRefresh.h>
#else
#import "MJRefresh.h"
#endif

#if __has_include(<AFNetworking/AFNetworking.h>)
#import <AFNetworking/AFNetworking.h>
#else
#import "AFNetworking.h"
#endif



//#import <AFNetworking/AFNetworking.h>
//AFNetworking, 移出了其中的UIKit模块
//#import <AFURLSessionManager.h>
//#import <AFHTTPSessionManager.h>
//#import <AFURLRequestSerialization.h>
//#import <AFURLResponseSerialization.h>
//#import <AFNetworkReachabilityManager.h>
//#import <AFSecurityPolicy.h>



#endif /* TKSDKTooImportSDK_h */

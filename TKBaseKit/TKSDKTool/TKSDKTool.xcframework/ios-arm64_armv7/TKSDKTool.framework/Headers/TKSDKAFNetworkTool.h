    //
    //  TKSDKAFNetworkTool.h
    //
    //  Created by saya on 2016/10/25.
    //  Copyright (c) 2016年 wxxu. All rights reserved.
    //

/**
 该类是在AFNetworking 3.1.0 的基础上进行的二次封装 --由于ipv6的必须支持问题AF已经弃用NSURLConnection
 改用NSURLSession替代，并且只是用NSURLSession了

 1. AFHTTPSesstionManager *session = [AFHTTPSesstionManager manager];

 所有的网络请求,均有manager发起

 2. 提交请求和响应的数据是都是二进制的二进制的

 3. 请求格式
 AFHTTPRequestSerializer            二进制格式

 4. 返回格式
 AFHTTPResponseSerializer           二进制格式

 5.响应的数据可以根据其类容进行装换，如：
 AFJSONResponseSerializer           JSON
 AFXMLParserResponseSerializer      XML,只能返回XMLParser,还需要自己通过代理方法解析
 AFXMLDocumentResponseSerializer    (Mac OS X)
 AFPropertyListResponseSerializer   PList  (是一种特殊的XML,解析起来相对容易)
 AFImageResponseSerializer          Image
 AFCompoundResponseSerializer       组合

 这7种解析器AFNetworking 已经不再提供了，我们可以利用响应的NSData数据转化成其对应的解析器(三方或者系统自带的)


 // 本类中都是将NSData数据转化成JSON的

 图片上传通用接口
 //接口
 NSString *url = @"http://www.chuantu.biz/upload.php";
 //参数
 NSDictionary *filePar = @{@"nameCmd":@"uploadimg" ,@"fileName":@"11111.jpg"};
 **/

//版本V2.0

#import <Foundation/Foundation.h>
#import "TKSDKTooImportSDK.h"
#import "TKSDKAFNetworkConfig.h"


typedef  NS_ENUM(NSInteger ,TKSDKNetRequestType){
    TKSDKNetRequestTypeGet      = 0,
    TKSDKNetRequestTypePost     = 1,
    TKSDKNetRequestTypePut      = 2,
    TKSDKNetRequestTypeHead     = 3,
    TKSDKNetRequestTypeDelete   = 4,
    TKSDKNetRequestTypePatch    = 5
};

typedef NS_ENUM(NSInteger,TKSDKNetResponseType){
    TKSDKNetResponseTypeData = 0,
    TKSDKNetResponseTypeJson = 1
};


@interface TKSDKAFNetworkTool : NSObject
#pragma mark -------基础设置区域，如：开启缓存，开启log等--------
//⚠️⚠️⚠️：推荐使用TKSDKAFNetworkConfig进行参数配置。

/** 是否开启log */
+ (void)isEndbledLog:(BOOL)isEndbled;
/** 是否开启缓存,默认不开启*/
+ (void)isEndbledCache:(BOOL)isEndbled;
/** 是否开启URLEncode，默认开启 */
+ (void)isEndbledURLEncode:(BOOL)isEndbled;
/** 清除缓存 **/
+ (void)clearCache;
/** 直接根据路径获取文件大小 */
+ (NSUInteger)getFileSizeAtPath:(nullable NSString *)filePath;
/** 使用个字母和数字生成32位的随机字符串随机字符串  */
+ (nonnull NSString *)getRandomStringUseCharacter;



#pragma mark -------------------------网络状态检测-------------------------
/**
 *  检测网路状态
 AFNetworkReachabilityStatusUnknown          = -1,  // 未知
 AFNetworkReachabilityStatusNotReachable     = 0,   // 无连接
 AFNetworkReachabilityStatusReachableViaWWAN = 1,   // 3G 花钱
 AFNetworkReachabilityStatusReachableViaWiFi = 2,   // WiFi
 **/
+ (void)netWorkStatus:(nullable void(^)(AFNetworkReachabilityStatus status))netStatus;

/**
 将字典类型参数转换成字符串参数模式(用于追加到url后边)
 @{@"k1":@"v1", @"k2":@"v2"} 转换后  k1=v1&k2=v2
 */
+ (nonnull NSString *)parameterToString:(nullable NSDictionary *)par;

#pragma mark-------------------------请求部分-------------------------

/**
基础通用的请求方法,支持GET,POST,HEAD,PUT,DELETE,PATCH
 
@param url 请求URL
@param par 请求参数字典
@param filePar 要上传文件时使用，并且同时可以以不同的方式进行上传文件，
目前可同时包括：NSString , NSURL ,NSData 3种f方式进行上传文件
使用方式如：filePar=@{@"参数名1":@"数据类型-NSString",
                    @"参数名2":@"数据类型-NSURL",
                    @"参数名3":@"数据类型-NSData"}
其中文件类型可同时为上面3种

@param requestType 请求方式：post或者get
@param responseType 响应数据类型：data或者json
@param progress 请求进度：上行或者下行
@param success 成功回调
@param fail 失败回调
 
*/
+ (nullable NSURLSessionDataTask *)baseRequestWithUrl:(nullable NSString *)url
                                         par:(nullable id)par
                               uploadFilePar:(nullable NSDictionary *)filePar
                                 requestType:(TKSDKNetRequestType)requestType
                                responseType:(TKSDKNetResponseType)responseType
                                    progress:(nullable void(^)(CGFloat progress))progress
                                     success:(nullable void(^)(id _Nullable responseObject))success
                                        fail:(nullable void(^)(NSError * _Nullable error))fail;


/**
 get方式数据请求，获取数据类型为Json格式
*  url: 请求URL地址
*  par: post请求参数字典
*  success:请求成功回调
*  fail:请求失败回调
    PS:注意参数不是直接追加到url后面的
**/
+ (nullable NSURLSessionDataTask *)JSONGetWithUrl:(nullable NSString *)url par:(nullable id)par success:(nullable void(^)(id _Nullable json))success fail:(nullable void(^)(NSError * _Nullable error))fail;


/** get方式数据请求，取数据类型为Json格式
 *  url:请求URL
 *  success:请求成功回调
 *  fail:请求失败回调
 **/
+ (nullable NSURLSessionDataTask *)JSONGetWithUrl:(nullable NSString *)url success:(nullable void(^)(id _Nullable json))success fail:(nullable void(^)(NSError * _Nullable error))fail;


/** post方式数据请求获，取数据类型为Json格式
 *  url: 请求URL地址
 *  par: post请求参数字典
 *  success:请求成功回调
 *  fail:请求失败回调
 **/
+ (nullable NSURLSessionDataTask *)JSONPostWithUrl:(nullable NSString *)url par:(nullable id)par success:(nullable void(^)(id _Nullable json))success fail:(nullable void(^)(NSError * _Nullable error))fail;
/** get方法直接获取NSData数据
 *  url: 请求URL地址
 *  success: 请求成功回调
 *  fail: 请求失败回调
 **/
+ (nullable NSURLSessionDataTask *)DataGetWithUrl:(nullable NSString *)url success:(nullable void(^)(id _Nullable data))success fail:(nullable void(^)(NSError * _Nullable error))fail;

/** get方法直接获取NSData数据
 *  url: 请求URL地址
 *  success: 请求成功回调
 *  fail: 请求失败回调
 *  PS:注意这儿的参数不是直接追加到url后面的
 **/
+ (nullable NSURLSessionDataTask *)DataGetWithUrl:(nullable NSString *)url par:(nullable id)par success:(nullable void(^)(id _Nullable data))success fail:(nullable void(^)(NSError * _Nullable error))fail;

/** post方法直接获取NSData数据
 *  url: 请求URL地址
 *  par: post请求参数字典
 *  success:请求成功回调
 *  fail:请求失败回调
 **/
+ (nullable NSURLSessionDataTask *)DataPostWithUrl:(nullable NSString *)url par:(nullable id)par success:(nullable void(^)(id _Nullable data))success fail:(nullable void(^)(NSError * _Nullable error))fail;

/**
 简单的上传操作
 返回类型为NSData
 PS:使用了公共的baseRequestWithUrl方法
 */
+(nullable NSURLSessionDataTask *)UploadFileWithUrl:(nullable NSString *)url par:(nullable id)par filePar:(nullable NSDictionary *)filePar progress:(nullable void(^)(CGFloat progress))progress success:(nullable void(^)(id _Nullable data))success fail:(nullable void(^)(NSError * _Nullable error))fail;

/**
 简单下载操作
 返回类型为NSData
 PS:使用了公共的baseRequestWithUrl方法
 */
+ (nullable NSURLSessionDataTask *)DownloadFileWithUrl:(nullable NSString *)url par:(nullable id)par progress:(nullable void(^)(CGFloat progress))progress success:(nullable void(^)(id _Nullable data))success fail:(nullable void(^)(NSError * _Nullable error))fail;




#pragma mark-------------------------定制重写区域-------------------------
/**
 重写：为AFHTTPSessionManager重新定制configuration
 注意：
    返回null，则使用[AFHTTPSessionManager manager]创建对象；
    返回不为null，使用[[AFHTTPSessionManager alloc] initWithSessionConfiguration:configuration]创建对象
 */
+ (nullable NSURLSessionConfiguration *)customConfiguration;

/**
 重写，定制AFHTTPSessionManager，
 一般用于自定义扩展AF，如HTTPS CA证书的自定义等

 sessionManager：    AFHTTPSessionManager单利生成的对象
 重写该方法用于定制扩展AFNetwork的一些三方框架，如OAuth 2 Authentication认证等！

 添加自定义的HTTPS CA证书
 ps：https://www.cnblogs.com/jyking/p/6737295.html
 ps:https://blog.csdn.net/dongruanlong/article/details/72641754
 */
+ (void)customSessionManager:(nonnull AFHTTPSessionManager *)sessionManager;

/**
 重写，可以在requestSerializer中添加通用header参数
 @param requestSerializer 向header中添加一些v标识
 通过AFHTTPRequestSerializer添加header参数
 */
+ (void)customPublicHeaderWith:(nonnull AFHTTPRequestSerializer*)requestSerializer;

/**
 重写，为URL请求添加header请求参数
 PS:优先级高于在customPublicHeaderWith:中为header添加参数。
 */
+ (nullable NSDictionary *)customURLHeaders;

/**
 重写，处理请求URL，比如是否添加公共请求域名，以及一些特殊的请求路劲绑定不同的域名,可对请求url进行拼接
 PS:重写该方法时最好先执行super一下该方法
 @param url 请求传入的URL
 @param requestType 请求方式
 @param responseType 响应方式
 @return 针对URL进行特殊处理，如添加域名，针对特殊URL进行处理
 */
+ (nonnull NSString *)customRequestURL:(nonnull NSString *)url requestType:(TKSDKNetRequestType)requestType responseType:(TKSDKNetResponseType)responseType;

/// 重写，参数二次解析封装处理
/// @param par 请求传入默认参数
/// @param url 请求传入url
/// @return 返回额为处理的参数；如添加一些公共参数
/// PS:重写该方法时，注意par为null的情况
+ (nullable id)customRequestMutablePar:(nullable id)par url:(nonnull NSString *)url;


/// 可以重写该方法对响应Data数据进行处理，然后再将处理后的数据返回，该方法为最优先的数据处理函数。例如通过该方法解密数据后，其它方法的入口数据都是解密后的NSData数据
/// @param responseData 服务器原始的响应NSData数据
/// @param url 对应的url
/// @return 处理后的NSData数据
/// 注意:请求失败时并且成功从缓存中读取到数据时success回调时是不会走该方法的，因为缓存的数据就是该方法处理后返回的NSData
+ (nullable NSData *)customPrepareResponseData:(nullable NSData *)responseData url:(nonnull NSString *)url;

/// 重写该方法，可以先对响应数据二次处理，注意该方法是不会修改响应数据，比如在success回调前可以先筛选某些特定通用数据等。
/// @param responseObject 请求成功时响应的数据(类型：NSData)
/// @param requestType 请求类型
/// @param responseType 响应数据的类型
/// @param url 请求url
+ (void)customResponseDataWithSuccess:(nullable id)responseObject requestType:(TKSDKNetRequestType)requestType responseType:(TKSDKNetResponseType)responseType url:(nonnull NSString *)url;


/// 重写该方法，可以先对请求错误信息Error的二次处理
/// @param error 响应错误信息
/// @param url 请求url
+ (void)customResponseError:(nullable NSError *)error url:(nonnull NSString *)url;



@end


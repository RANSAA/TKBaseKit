## TKBaseKit

<br>


### 更新⚠️⚠️： 
1. v2.2.1版本支持Xcode14, iOS版本支持切换到11.0+
2. 对内置的三方库引用切换到了ctsfok用户的fok版本，而不是用原作者的库，所以引用方式有一点变动，切换的三方库有：
```
Masonry:
主分支：
pod 'Masonry', :git => 'https://github.com/ctsfork/Masonry.git'
指定tag：
pod 'Masonry', :git => 'https://github.com/ctsfork/Masonry.git', :tag => 'v1.1.1'


YYModel:
主分支：
pod 'YYModel', :git => 'https://github.com/ctsfork/YYModel.git'
指定tag：
pod 'YYModel', :git => 'https://github.com/ctsfork/YYModel.git', :tag => '1.0.5'
```

<br>

## 功能说明：
该静态框架主要封装了一些常用的工具，以及一些三方框架的二次封装；其中又分为两个框架分别为：
* TKSDKUniversal：通用基础库Framework封装
* TKSDKTool：对一些三方框架进行了二次封装如：AFNetworking，MJRefresh等，具体请查看TKSDKTooImportSDK.h文件

<br>

## 使用说明

1. CocoaPods方式：
```
//全部引入
pod 'TKBaseKit', '2.2.1'    

使用：直接导入下列头文件即可：
#import <TKBaseKit.h>


//按模块引入
pod 'TKBaseKit/TKSDKUniversal'
pod 'TKBaseKit/TKSDKTool'

使用：导入对应静态库的头文件即可：
#import <TKSDKUniversal/TKSDKUniversal.h>
#import <TKSDKTool/TKSDKTool.h>
```
2. 手动添加
```
//全部引入
将TKBaseKit中的所有文件加入项目中


//按模块引入
TKSDKUniversal.xcframework
TKSDKTool.xcframework
TKSDKTool.bundle

然后按需导入对应静态库的头文件：
#import <TKSDKUniversal/TKSDKUniversal.h>
#import <TKSDKTool/TKSDKTool.h>


然后对项目进行设置：
1.  设置"Other Linker Flags"-->添加: -ObjC 
2.  将Build Settings中的Allow Non-modular Includes In Framework Modules设为YES
3.  将Build Settings中的 "Excluded Architectures" --> "Release" --> 选中 --> "Any iOS Simulator SDK", 为其添加："arm64"。 即排除模拟器arm64架构的生成。
注意：第3项可以根据情况不设置。
```
3. 内置依赖三方库添加，如果不使用TKSDKTool框架可不添加三方依赖，因为只有TKSDKTool内置了的三方依赖库
```
    pod 'MJRefresh',     '~> 3.7'
    pod 'GTMBase64'
    pod 'AFNetworking'
    pod 'MBProgressHUD'
    pod 'Masonry',       :git => 'https://github.com/ctsfork/Masonry.git', :tag => 'v1.1.1'
    pod 'YYModel',       :git => 'https://github.com/ctsfork/YYModel.git', :tag => '1.0.5'
```




<br>

## TKSDKUniversal介绍

* TKSDKUniversalMacro.h：定义了一些常用的宏。
> ***


* View：一些自定义控件
> * **TKSDKNavigationBar**：自定义导航条
>>>  导航条区域主要分为：navView和statusBarView，导航条的整体高度为这两个区域的高度和。\
>>>  navView:有效导航区域区域，默认高度44。\
>>>  statusBarView:状态栏安全区域。 \
>>>  backgroundView:整个导航条最底部的背景图显示区域，和整个导航条的bounds保持一致。\
>>>  navViewBackgroundView：navView中底部的背景图显示区域.\
>>>  注：导航条中的所有子控件(navView除外)都是采用懒加载的方式。\
>>>    \
>>>  PS：instanceWithController:方法构建的导航条都是依赖于controller中的TopLayoutGuide.bottom进行约束的， 约束条件是导航条底部(NavigationBar.bottom)相对于TopLayoutGuide.bottom进行约束的。


> * **TKSDKXibView**：利用xib文件创建View（可以直接使用init方法创建）,并且创建的View也可以作为另一个Xib的子控件。说明：xib文件的名称要有类名保持一致。
>>>  绑定方式：直接绑定到xib文件的Fiel's Owner 的class上面。\
>>>  作为子控件：本方创建的Xib控件可以直接在StoryBorad上面作为子控件使用，使用方式->直接绑定对应view的class即可。\
>>>  注意：本类是直接在控件中添加了一层View并与之绑定，如果要像一般控件那样操作self.view.XXX，请直接操作self.xibChildView.XXX


> * **TKFPSLabel**：一个实时显示FPS的控件。
> ***

* Controller：一些控制器
> * **TKSDKNavigationController**：自定义导航控制器。

> * **TKSDKViewController**：自定义UIViewController视图控制器，支持自定义导航条，以及一些常用操作。

> * **TKSDKTableViewController**：自定义UITableViewController视图控制器，支持自定义导航条，以及一些常用操作。注意：使用新建的"selfView"视图替换原始的self.view，使用时注意self.view与self.tableView的区别。

> * **TKSDKCollectionViewController**：自定义UICollectionViewController视图控制器，支持自定义导航条，以及一些常用操作。注意：使用新建的"selfView"视图替换原始的self.view，使用时注意self.view与self.collectionView的区别。

> * **TKSDKListViewController**：自定义TKSDKViewController + UITableView实现与TKSDKTableViewController类似的功能。

> * **TKSDKGridViewController**：自定义TKSDKViewController + UITCollectionView实现与TKSDKCollectionViewController类似的功能。
>>
>> 注意：如果在使用自定义控制器时出现导航条被遮挡的情况时，请执行[self makeNavigationBarToFront],使TKNavigationBar始终保持在最上层。\
>>      或者直接使用addSubView:方法向self.view上添加新视图，并且总能使TKNavigationBar保持在最上层。


> ***
* Category：一些类别扩展

> * **UIView+TKSDK**：包括但不限于 ==> 可获取当前UIView所在的控制器

> * **UIApplication+TKSDK**：包括但不限于 ==> 可获取当前显示的控制器

> * **NSObject+TKSDK**：

> * **NSString+TKSDK**：

> * **UIButton+TKSDK**：

> * **UIColor+TKSDK**：

> * **UIDevice+TKSDK**：

> * **UIImage+TKSDK**：
> ***


* Utilities：一些工具类

> * **TKSDKClearManager**：缓存清理工具

* **未全部列出，可自行查看框架！**

<br>


## TKSDKTool介绍

* TKSDKAFNetworkTool：AFNetworking二次封装。
* TKSDKRefresh：MJRefresh二次封装
* TKSDKEncryptTool：常用加密解密工具




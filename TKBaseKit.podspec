#
#  Be sure to run `pod spec lint TKBaseKit.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#
#  Be sure to run `pod spec lint name.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

name = "TKBaseKit"

Pod::Spec.new do |spec|

  spec.name         = "#{name}"   #框架名称
  spec.version      = "2.2.4"         #版本
  spec.summary      = "基础通用框架，以及一些工具和一些三方框架的二次封装！"          #简短的描述
  spec.description  = <<-DESC
  TKBaseKit通用基础框架，包含：
  1.TKSDKUniversal  基础框架控制器与一些实用的工具类
  2.TKSDKTool       二次封装三方库的一些工具
                   DESC
  spec.homepage     = "https://github.com/RANSAA/TKBaseKit"   #github项目首页
  spec.license      = "MIT"     #开源协议方式
  spec.author       = { "sayaDev" => "1352892108@qq.com" }    #作者
  spec.source       = { :git => "https://github.com/RANSAA/TKBaseKit.git", :tag => "v#{spec.version}" } #对应github资源与版本
  spec.requires_arc = true    #支持arc
  spec.platform     = :ios, "11.0"         #支持版本
  # spec.ios.deployment_target = '11.0'
  # spec.osx.deployment_target = '10.15'
  
  # spec.static_framework = true  #静态库，如果该pod中依赖了静态库，需要将该属性设置为true




  # 处理Include of non-modular header inside framework module ：处理静态库在工程项目中，找不到三方库的问题
  # 说明：
  # "CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES" => "YES"  ：处理静态库在工程项目中，找不到三方库的问题
  # 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'                 : 排除模拟生成arm64， Xcode12会在模拟器模式下生成arm64架构
  # spec.xcconfig = { "CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES" => "YES", 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  spec.xcconfig = { 
    # "CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES" => "YES",
    'OTHER_LDFLAGS' => '-ObjC -all_load',
    # 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386'
  }




  # spec.frameworks = "Foundation","UIKit"
  spec.source_files         = "#{name}/TKBaseKit.h"
  spec.public_header_files  = "#{name}/TKBaseKit.h"


  # 目前使用了一个公共Privacy模块用于存放PrivacyInfo.xcprivacy隐私清单，然后TKSDKUniversal与TKSDKTool模块同时依赖他。
  # 如果后期开发使用时出现隐私错误，可以为两个模块分别绑定隐私清单，因为该框架是同时集成了两个动态XCFramework静态框架。
  spec.subspec 'Privacy' do |ss|
    ss.resource_bundles = {
      ## 隐私清单 - 注意:建议与资源文件分别存放在不同的bundle中
      'TKBaseKit.Privacy' => [    
          "TKBaseKit/PrivacyInfo.xcprivacy" 
       ],
  }
  end

  spec.subspec 'TKSDKUniversal' do |ss|
    ss.vendored_frameworks  = "#{name}/TKSDKUniversal/TKSDKUniversal.xcframework"
    ## 隐私清单
    ss.dependency "TKBaseKit/Privacy"

    # ## 隐私清单 - 直接添加对应的隐私清单文件
    # ss.resource_bundles = {
    #   'TKBaseKit.TKSDKUniversal.Privacy' => [    
    #       "TKBaseKit/TKSDKUniversal/PrivacyInfo.xcprivacy" 
    #    ],
    # }
  end

  spec.subspec 'TKSDKTool' do |ss|
    ss.resources            = "#{name}/TKSDKTool/*.bundle"
    ss.vendored_frameworks  = "#{name}/TKSDKTool/TKSDKTool.xcframework"
    ss.dependency 'GTMBase64'       
    ss.dependency 'Masonry'                  
    ss.dependency 'YYModel'          
    ss.dependency 'AFNetworking'  
    ss.dependency 'MJRefresh'       #,'~> 3.7.9'
    ss.dependency 'MBProgressHUD'   

    ## 隐私清单
    ss.dependency "TKBaseKit/Privacy"

    # ## 隐私清单 - 直接添加对应的隐私清单文件
    # ss.resource_bundles = {
    #   'TKBaseKit.TKSDKTool.Privacy' => [    
    #       "TKBaseKit/TKSDKTool/PrivacyInfo.xcprivacy" 
    #    ],
    # }
  end

  # ――― Resources ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  A list of resources included with the Pod. These are copied into the
  #  target bundle with a build phase script. Anything else will be cleaned.
  #  You can preserve files from being cleaned, please don't preserve
  #  non-essential files like tests, examples and documentation.
  #

  # spec.resource  = "icon.png"
  # spec.resources = "Resources/*.png"

  # spec.preserve_paths = "FilesToSave", "MoreFilesToSave"


  # ――― Project Linking ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  Link your library with frameworks, or libraries. Libraries do not include
  #  the lib prefix of their name.
  #

  # spec.framework  = "SomeFramework"
  # spec.frameworks = "SomeFramework", "AnotherFramework"

  # spec.library   = "iconv"
  # spec.libraries = "iconv", "xml2"


  # ――― Project Settings ――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  If your library depends on compiler flags you can set them in the xcconfig hash
  #  where they will only apply to your library. If you depend on other Podspecs
  #  you can include multiple dependencies to ensure it works.

  # spec.requires_arc = true

  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # spec.dependency "JSONKit", "~> 1.4"



end

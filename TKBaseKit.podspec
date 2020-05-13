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

# file_source       = "*.{h,m}"
# file_header       = "*.h"
# public_source     = "#{name}/NSObject/NSObject+CrashNilSafe.{h,m}"
# public_header     = "#{name}/NSObject/NSObject+CrashNilSafe.h"
# public_base       = "#{name}/NSObject"

Pod::Spec.new do |spec|

  spec.name         = "#{name}"   #框架名称
  spec.version      = "2.0"         #版本
  spec.summary      = "基础导航，网络框架等！"          #简短的描述
  spec.description  = <<-DESC
  该框架包含两个子框架，它们分别为：
  1.TKSDKUniversal  基础导航与工具类
  2.TKSDKTool       二次封装三方库，AFNetworking, MJRefresh,以及引入了一些其它常用的库
                   DESC
  spec.homepage     = "https://github.com/RANSAA/TKBaseKit"   #github项目首页
  spec.license      = "MIT"     #开源协议方式
  spec.author       = { "sayaDev" => "1352892108@qq.com" }    #作者
  spec.source       = { :git => "https://github.com/RANSAA/TKBaseKit.git", :tag => "v#{spec.version}" } #对应github资源与版本
  spec.requires_arc = true    #支持arc
  spec.platform     = :ios, "8.0"         #支持版本


  spec.source_files         = "#{name}/TKBaseKit.h"
  spec.public_header_files  = "#{name}/TKBaseKit.h"

  # spec.frameworks = "Foundation","UIKit"
  # spec.static_framework = true


  #第一个配置：处理Include of non-modular header inside framework module ：处理静态库在工程项目中，找不到三方库的问题
  spec.xcconfig = { "CLANG_ALLOW_NON_MODULAR_INCLUDES_IN_FRAMEWORK_MODULES" => "YES"}


  spec.subspec 'TKSDKUniversal' do |ss|
    ss.vendored_frameworks  = "#{name}/TKSDKUniversal/TKSDKUniversal.framework"
  end

  spec.subspec 'TKSDKTool' do |ss|
    ss.resources            = "#{name}/TKSDKTool/*.bundle"
    ss.vendored_frameworks  = "#{name}/TKSDKTool/TKSDKTool.framework"
    ss.dependency 'Masonry'
    ss.dependency 'GTMBase64'                       , '~> 1.0.1'
    ss.dependency 'MJRefresh'                       , '~> 3.3.1'
    ss.dependency 'AFNetworking/Serialization'      , '~> 3.2.1'
    ss.dependency 'AFNetworking/Security'           , '~> 3.2.1'
    ss.dependency 'AFNetworking/Reachability'       , '~> 3.2.1'
    ss.dependency 'AFNetworking/NSURLSession'       , '~> 3.2.1'
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

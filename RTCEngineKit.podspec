#
# Be sure to run `pod lib lint RTCEngineKit.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'RTCEngineKit'
  s.version          = '2.2.11'
  s.summary          = 'RTC服务引擎.'
  
# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC
                       
  s.homepage         = 'https://github.com/seastart/rtc-ios-cocoapods'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'SailorGa' => 'ljia789@gmail.com' }
  s.source           = { :git => 'https://github.com/seastart/rtc-ios-cocoapods.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  
  # 指定支持平台
  s.ios.deployment_target = '10.0'
  
  # 依赖系统Frameworks库
  s.ios.frameworks = 'VideoToolbox', 'AudioToolbox', 'AVFoundation', 'CoreFoundation', 'CoreMedia', 'CoreVideo', 'Foundation', 'QuartzCore', 'Metal', 'MetalPerformanceShaders', 'Security', 'OpenGLES', 'Accelerate', 'CoreML', 'CoreGraphics', 'ReplayKit', 'SystemConfiguration', 'CallKit'
  # 依赖系统Librarie库
  s.ios.library = 'c++', 'z', 'iconv'
  
  # 依赖本地库文件
  s.vendored_frameworks = 'RTCEngineKit/Depend/*.framework'
  # 依赖本地资源文件
  s.resource = 'RTCEngineKit/Resources/*.bundle'
  
  # 依赖远程网络组件库
  s.dependency 'AFNetworking', '>= 4.0.0'
  # 依赖远程Socket组件库
  s.dependency 'CocoaAsyncSocket'
end

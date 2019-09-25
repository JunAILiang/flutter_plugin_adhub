#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#
Pod::Spec.new do |s|
  s.name             = 'flutter_plugin_adhub'
  s.version          = '0.0.1'
  s.summary          = 'A new Flutter plugin.'
  s.description      = <<-DESC
A new Flutter plugin.
                       DESC
  s.homepage         = 'http://example.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }
  s.source_files = 'Classes/**/*'
  s.public_header_files = 'Classes/**/*.h'
  s.dependency 'Flutter'

  s.vendored_frameworks = [
  'Frameworks/AdHubSDK.framework',
  'Frameworks/BaiduMobAdSDK.framework'
  ]
  s.vendored_libraries = [
  'Frameworks/libFalconAdSDK.a',
  'Frameworks/libGDTMobSDK.a',
  'Frameworks/libProtobuf.a'
  ]
  s.resource = [
  'Frameworks/baidumobadsdk.bundle',
  'Frameworks/FmobiBundle.bundle'
  ]

  # s.ios.vendored_frameworks = 'Frameworks/AdHubSDK.framework'
  # s.vendored_frameworks = 'AdHubSDK.framework'
  # s.ios.resource = 'Frameworks/baidumobadsdk.bundle'
  # s.resource = 'baidumobadsdk.bundle'
  # s.ios.vendored_frameworks = 'Frameworks/BaiduMobAdSDK.framework'
  # s.vendored_frameworks = 'BaiduMobAdSDK.framework'
  # s.ios.resource = 'Frameworks/FmobiBundle.bundle'
  # s.resource = 'FmobiBundle.bundle'
  # s.ios.vendored_libraries = 'Frameworks/libFalconAdSDK.a'
  # s.vendored_libraries = 'libFalconAdSDK.a'
  # s.ios.vendored_libraries = 'Frameworks/libGDTMobSDK.a'
  # s.vendored_libraries = 'libGDTMobSDK.a'
  # s.ios.vendored_libraries = 'Frameworks/libProtobuf.a'
  # s.vendored_libraries = 'libProtobuf.a'

  s.static_framework = true


  s.ios.deployment_target = '8.0'
end


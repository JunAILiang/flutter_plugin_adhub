import 'package:flutter/services.dart';

class Adhub {

  static const MethodChannel _channel = const MethodChannel('adhub_flutter');

  /// 初始化appId(一般在应用启动时进行设置)
  /// appid必传,否则无法初始化
  static void initialize(String appId) {
    _channel.invokeMethod('initialize', appId);
  }

  /// 是否开启调试日志(默认false)
  static void openTheAdHubLog() {
    _channel.invokeMethod('openTheAdHubLog');
  }
}
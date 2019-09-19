import 'package:flutter/services.dart';
import 'package:flutter_plugin_adhub/src/adhub_event_handler.dart';

class AdhubReward extends AdHubEventHandler {

  /// 如果没这个桥我该何去何从
  static const MethodChannel _channel = const MethodChannel('adhub_flutter/reward');

  MethodChannel _adChannel;
  int id;
  final String videoAdId;
  final void Function(AdHubEvents, Map<String, dynamic>) listener;

  AdhubReward({
    this.videoAdId,
    this.listener,
  }): super(listener) {
     id = hashCode;
     if (listener != null) {
       _adChannel = MethodChannel('adhub_flutter/reward_jm');
       _adChannel.setMethodCallHandler(handleEvent);
     }
  }

  /// 加载激励视频广告(广告ID)
  /// adid必传,否则无法加载广告
  void loadRewardedVideoAd() {
    _channel.invokeMethod('loadRewardedVideoAd', videoAdId);
  }

  /// 展示激励视频广告, 确保广告加载成功后调用
  void showRewardedVideoAd() {
    _channel.invokeMethod('showRewardedVideoAd');
  }


}

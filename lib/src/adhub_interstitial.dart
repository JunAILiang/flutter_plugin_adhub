import 'package:flutter/services.dart';
import 'package:flutter_plugin_adhub/src/adhub_event_handler.dart';

class AdhubInterstitial extends AdHubEventHandler {

  /// 如果没这个桥我该何去何从
  static const MethodChannel _channel = const MethodChannel('adhub_flutter/interstitial');

  MethodChannel _adChannel;
  int id;
  final String interstitialAdId;
  final void Function(AdHubEvents, Map<String, dynamic>) listener;

  AdhubInterstitial({
    this.interstitialAdId,
    this.listener,
  }): super(listener) {
    id = hashCode;
    if (listener != null) {
      _adChannel = MethodChannel('adhub_flutter/interstitial_jm');
      _adChannel.setMethodCallHandler(handleEvent);
    }
  }

  /// 加载插屏广告
  void loadInterstitialAd() {
    _channel.invokeMethod('loadInterstitialAd', interstitialAdId);
  }

  /// 展示插屏广告, 确保广告加载成功后调用
  void showInterstitialAd() {
    _channel.invokeMethod('showInterstitialAd');
  }


}

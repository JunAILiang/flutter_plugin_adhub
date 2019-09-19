import 'package:flutter/services.dart';

abstract class AdHubEventHandler {
  final Function(AdHubEvents, Map<String, dynamic>) _listener;

  AdHubEventHandler(Function(AdHubEvents, Map<String, dynamic>) listener) : _listener = listener;

  Future<dynamic> handleEvent(MethodCall call) async {
    switch (call.method) {
      case 'videoDidReceiveAd':
        _listener(AdHubEvents.videoDidReceiveAd, null);
        break;
      case 'videoDidStartPlay':
        _listener(AdHubEvents.videoDidStartPlay, null);
        break;
      case 'videoDidClick':
        _listener(AdHubEvents.videoDidClick, null);
        break;
      case 'videoDidDismissScreen':
        _listener(AdHubEvents.videoDidDismissScreen, null);
        break;
      case 'videoDidError':
        _listener(AdHubEvents.videoDidError, null);
        break;
      case 'videoDidRewardUserWithReward':
        _listener(AdHubEvents.videoDidRewardUserWithReward, null);
        break;
    }

    return null;
  }

}



enum AdHubEvents {
  videoDidReceiveAd,
  videoDidStartPlay,
  videoDidClick,
  videoDidDismissScreen,
  videoDidError,
  videoDidRewardUserWithReward,
}
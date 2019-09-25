import 'package:flutter/services.dart';

abstract class AdHubEventHandler {
  final Function(AdHubEvents, Map<String, dynamic>) _listener;

  AdHubEventHandler(Function(AdHubEvents, Map<String, dynamic>) listener) : _listener = listener;

  Future<dynamic> handleEvent(MethodCall call) async {
    switch (call.method) {
      case 'didReceiveAd':
        _listener(AdHubEvents.didReceiveAd, null);
        break;
      case 'didStartPlay':
        _listener(AdHubEvents.didStartPlay, null);
        break;
      case 'didClick':
        _listener(AdHubEvents.didClick, null);
        break;
      case 'didDismissScreen':
        _listener(AdHubEvents.didDismissScreen, null);
        break;
      case 'didError':
        _listener(AdHubEvents.didError, null);
        break;
      case 'didRewardUserWithReward':
        _listener(AdHubEvents.didRewardUserWithReward, null);
        break;
    }

    return null;
  }

}



enum AdHubEvents {
  didReceiveAd,
  didStartPlay,
  didClick,
  didDismissScreen,
  didError,
  didRewardUserWithReward,
}
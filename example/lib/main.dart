import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:flutter_plugin_adhub/flutter_plugin_adhub.dart';

void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  String _platformVersion = 'Unknown';

  bool isPlaying = false;

  AdhubReward adhubReward;
  AdhubInterstitial interstitial;

  @override
  void initState() {
    super.initState();
    initPlatformState();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initPlatformState() async {
    Adhub.initialize("3068");
//    Adhub.openTheAdHubLog();

  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        floatingActionButton: FloatingActionButton(
          onPressed: (){
            if (isPlaying) {
//              AdhubReward().showRewardedVideoAd();
//              FlutterPluginAdhub.showRewardedVideoAd();
//              adhubReward.showRewardedVideoAd();
            } else {
              isPlaying = true;

//              adhubReward = AdhubReward(
//                videoAdId: "9070",
//                listener: (AdHubEvents event, Map<String, dynamic> args) {
//                  print("我走到了这个回调");
//                  print(event);
//                  if (event == AdHubEvents.didError) {
//
//                  } else if (event == AdHubEvents.didReceiveAd) {
//                    adhubReward.showRewardedVideoAd();
//                  }
//                }
//              );
//
//              adhubReward.loadRewardedVideoAd();


              interstitial = AdhubInterstitial(
                interstitialAdId: "9072",
                listener: (AdHubEvents event, Map<String, dynamic> args) {
                  print("我走到了这个回调");
                  print(event);
                  if (event == AdHubEvents.didError) {

                  } else if (event == AdHubEvents.didReceiveAd) {
                    interstitial.showInterstitialAd();
                  }
                }
              );

              interstitial.loadInterstitialAd();

            }

            setState(() {
            });
          },
          child: Text(isPlaying?"展示":"加载"),
        ),
        body: Center(
          child: Text('Running on: $_platformVersion\n'),
        ),
      ),
    );
  }
}

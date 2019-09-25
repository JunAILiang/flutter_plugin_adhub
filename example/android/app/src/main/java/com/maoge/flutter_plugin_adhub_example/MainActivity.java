package com.maoge.flutter_plugin_adhub_example;

import android.os.Bundle;

import com.hubcloud.adhubsdk.AdHub;

import io.flutter.app.FlutterActivity;
import io.flutter.plugins.GeneratedPluginRegistrant;
import android.content.Context;

import com.maoge.flutter_plugin_adhub.AdUtil;
import com.maoge.util.AdhubInterstitialUtil;
import com.maoge.util.AdhubVideoUtil;
import com.maoge.util.L;


public class MainActivity extends FlutterActivity {

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    GeneratedPluginRegistrant.registerWith(this);

    AdUtil.setGouzi(new AdUtil.Gouzi() {

      /** 初始化appId **/
      @Override
      public void initialize(String appId) {
        AdHub.init(getContext(), appId);
      }

      @Override
      public void loadRewardedVideoAd(final String adId) {
        AdhubVideoUtil.loadRewardedVideoAd(getContext(), adId);
      }

      @Override
      public void showRewardedVideoAd() {
        AdhubVideoUtil.showRewardedVideoAd();
      }


      @Override
      public void loadInterstitialAd(String adId) {
        AdhubInterstitialUtil.loadInterstitialAd(getContext(), adId);
      }

      @Override
      public void showInterstitialAd() {
        AdhubInterstitialUtil.showInterstitialAd();
      }
    });
  }

  private Context getContext(){
    return this;
  }


}




























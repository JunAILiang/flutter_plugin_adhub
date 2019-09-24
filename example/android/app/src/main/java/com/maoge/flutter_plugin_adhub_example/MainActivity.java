package com.maoge.flutter_plugin_adhub_example;

import android.os.Bundle;

import com.hubcloud.adhubsdk.RewardedVideoAd;

import io.flutter.app.FlutterActivity;
import io.flutter.plugins.GeneratedPluginRegistrant;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;

import com.hubcloud.adhubsdk.AdHub;
import com.hubcloud.adhubsdk.AdRequest;
import com.hubcloud.adhubsdk.RewardItem;
import com.hubcloud.adhubsdk.RewardedVideoAd;
import com.hubcloud.adhubsdk.RewardedVideoAdListener;
import com.maoge.flutter_plugin_adhub.AdUtil;

import io.flutter.app.FlutterActivity;
import io.flutter.plugins.GeneratedPluginRegistrant;


public class MainActivity extends FlutterActivity {

  private static RewardedVideoAd mRewardedVideoAd;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    GeneratedPluginRegistrant.registerWith(this);

    AdUtil.setGouzi(new AdUtil.Gouzi() {
      @Override
      public void initialize(String appId) {
        AdHub.init(getContext(), appId);
      }

      @Override
      public void loadRewardedVideoAd(final String adId) {
        mRewardedVideoAd = AdHub.getRewardedVideoAdInstance(getContext());

        mRewardedVideoAd.setRewardedVideoAdListener(new RewardedVideoAdListener() {
          @Override
          public void onRewarded(RewardItem rewardItem) {
            Log.d("lance", "onRewarded:" + rewardItem.getType() + "==" + rewardItem.getAmount());
          }

          @Override
          public void onRewardedVideoAdClosed() {
            Log.d("lance", "onRewardedVideoAdClosed");
            //TODO 关闭广告后自动加载下一个广告
//            load(adId);
          }

          @Override
          public void onRewardedVideoAdShown() {
            Log.d("lance", "onRewardedVideoAdShown");
          }

          @Override
          public void onRewardedVideoAdFailedToLoad(int i) {
            Log.d("lance", "onRewardedVideoAdFailedToLoad:" + i);
          }

          @Override
          public void onRewardedVideoAdLeftApplication() {
            Log.d("lance", "onRewardedVideoAdLeftApplication");
          }

          @Override
          public void onRewardedVideoAdLoaded() {
            Log.d("lance", "onRewardedVideoAdLoaded");
            if (mRewardedVideoAd.isLoaded()) {
              mRewardedVideoAd.show();
            }
          }

          @Override
          public void onRewardedVideoAdOpened() {
            Log.d("lance", "onRewardedVideoAdOpened");
          }

          @Override
          public void onRewardedVideoStarted() {
            Log.d("lance", "onRewardedVideoStarted");
          }
        });

        if (!mRewardedVideoAd.isLoaded()) {
          mRewardedVideoAd.loadAd(adId, new AdRequest.Builder().build());
        }
      }

      @Override
      public void showRewardedVideoAd() {
        if (mRewardedVideoAd.isLoaded()) {
          mRewardedVideoAd.show();
        }
      }
    });
  }

  private Context getContext(){
    return this;
  }


}




























package com.maoge.util;

import android.content.Context;
import android.util.Log;

import com.hubcloud.adhubsdk.AdHub;
import com.hubcloud.adhubsdk.AdRequest;
import com.hubcloud.adhubsdk.InterstitialAd;
import com.hubcloud.adhubsdk.RewardItem;
import com.hubcloud.adhubsdk.RewardedVideoAd;
import com.hubcloud.adhubsdk.RewardedVideoAdListener;
import com.maoge.flutter_plugin_adhub.FlutterPluginAdhubRewardPlugin;

public class AdhubVideoUtil {

    private static RewardedVideoAd mRewardedVideoAd;

    public static void loadRewardedVideoAd(Context context, final String adId) {
        mRewardedVideoAd = AdHub.getRewardedVideoAdInstance(context);

        mRewardedVideoAd.setRewardedVideoAdListener(new RewardedVideoAdListener() {
            @Override
            public void onRewarded(RewardItem rewardItem) {
            }

            @Override
            public void onRewardedVideoAdClosed() {
                if (FlutterPluginAdhubRewardPlugin.channelV != null) {
                    FlutterPluginAdhubRewardPlugin.channelV.invokeMethod("didDismissScreen", null);
                }
            }

            @Override
            public void onRewardedVideoAdShown() {
            }

            @Override
            public void onRewardedVideoAdFailedToLoad(int i) {
                if (FlutterPluginAdhubRewardPlugin.channelV != null) {
                    FlutterPluginAdhubRewardPlugin.channelV.invokeMethod("didError", null);
                }
            }

            @Override
            public void onRewardedVideoAdLeftApplication() {
            }

            @Override
            public void onRewardedVideoAdLoaded() {
                if (FlutterPluginAdhubRewardPlugin.channelV != null) {
                    FlutterPluginAdhubRewardPlugin.channelV.invokeMethod("didReceiveAd", null);
                }
            }

            @Override
            public void onRewardedVideoAdOpened() {
            }

            @Override
            public void onRewardedVideoStarted() {
            }
        });

        if (!mRewardedVideoAd.isLoaded()) {
            mRewardedVideoAd.loadAd(adId, new AdRequest.Builder().build());
        }
    }


    public static void showRewardedVideoAd() {
        if (mRewardedVideoAd.isLoaded()) {
            mRewardedVideoAd.show();
        }
    }

}

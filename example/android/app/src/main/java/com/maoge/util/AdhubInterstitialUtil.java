package com.maoge.util;

import android.content.Context;
import android.util.Log;

import com.hubcloud.adhubsdk.AdListener;
import com.hubcloud.adhubsdk.AdRequest;
import com.hubcloud.adhubsdk.InterstitialAd;
import com.maoge.flutter_plugin_adhub.FlutterPluginAdhubInterstitialPlugin;

public class AdhubInterstitialUtil {

    private static InterstitialAd mInterstitialAd;

    public static void loadInterstitialAd(Context context, String adId) {
        mInterstitialAd = new InterstitialAd(context, false);
        mInterstitialAd.setAdUnitId(adId);
        mInterstitialAd.setAdListener(new AdListener() {
            @Override
            public void onAdClosed() {
                if (FlutterPluginAdhubInterstitialPlugin.channelInterstitial != null) {
                    FlutterPluginAdhubInterstitialPlugin.channelInterstitial.invokeMethod("didDismissScreen", null);
                }
            }

            @Override
            public void onAdClicked() {
                super.onAdClicked();
            }

            @Override
            public void onAdFailedToLoad(int errorCode) {
                if (FlutterPluginAdhubInterstitialPlugin.channelInterstitial != null) {
                    FlutterPluginAdhubInterstitialPlugin.channelInterstitial.invokeMethod("didError", null);
                }
            }

            @Override
            public void onAdShown() {
                super.onAdShown();
            }

            @Override
            public void onAdLoaded() {
                if (FlutterPluginAdhubInterstitialPlugin.channelInterstitial != null) {
                    FlutterPluginAdhubInterstitialPlugin.channelInterstitial.invokeMethod("didReceiveAd", null);
                }
            }

        });

        if (!mInterstitialAd.isLoading() && !mInterstitialAd.isLoaded()) {
            AdRequest adRequest = new AdRequest.Builder().build();
            mInterstitialAd.loadAd(adRequest);
        }

    }


    public static void showInterstitialAd() {
        if (mInterstitialAd != null && mInterstitialAd.isLoaded()) {
            mInterstitialAd.show();
        }
    }
}

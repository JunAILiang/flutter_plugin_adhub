package com.maoge.flutter_plugin_adhub;

import android.util.Log;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.PluginRegistry;

public class FlutterPluginAdhubInterstitialPlugin extends FlutterPluginAdhubPlugin {

    private static MethodChannel channel;
    public static MethodChannel channelInterstitial;

    /** Plugin registration. */
    public static void registerWith(PluginRegistry.Registrar registrar) {
        channel = new MethodChannel(registrar.messenger(), "adhub_flutter/interstitial");
        channel.setMethodCallHandler(new FlutterPluginAdhubInterstitialPlugin());

        channelInterstitial = new MethodChannel(registrar.messenger(), "adhub_flutter/interstitial_jm");
        channelInterstitial.setMethodCallHandler(new FlutterPluginAdhubInterstitialPlugin());
    }

    @Override
    public void onMethodCall(MethodCall call, MethodChannel.Result result) {
        if (call.method.equals("loadInterstitialAd")) {
            AdUtil.loadInterstitialAd(call.arguments.toString());
        } else if (call.method.equals("showInterstitialAd")) {
            AdUtil.showInterstitialAd();
        }
    }

}

package com.maoge.flutter_plugin_adhub;

import android.util.Log;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.PluginRegistry;

public class FlutterPluginAdhubRewardPlugin extends FlutterPluginAdhubPlugin {

    private static MethodChannel channel;
    public static MethodChannel channelV;

    /** Plugin registration. */
    public static void registerWith(PluginRegistry.Registrar registrar) {
        channel = new MethodChannel(registrar.messenger(), "adhub_flutter/reward");
        channel.setMethodCallHandler(new FlutterPluginAdhubRewardPlugin());

        channelV = new MethodChannel(registrar.messenger(), "adhub_flutter/reward_jm");
        channelV.setMethodCallHandler(new FlutterPluginAdhubRewardPlugin());
    }

    @Override
    public void onMethodCall(MethodCall call, MethodChannel.Result result) {
        if (call.method.equals("loadRewardedVideoAd")) {
            AdUtil.loadRewardedVideoAd(call.arguments.toString());
        } else if (call.method.equals("showRewardedVideoAd")) {
            AdUtil.showRewardedVideoAd();
        }
    }

}

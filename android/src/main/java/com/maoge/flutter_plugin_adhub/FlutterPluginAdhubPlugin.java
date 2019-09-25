package com.maoge.flutter_plugin_adhub;


import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;
import io.flutter.plugin.common.PluginRegistry.Registrar;


public class FlutterPluginAdhubPlugin implements MethodCallHandler {

    /** Plugin registration. */
    public static void registerWith(Registrar registrar) {
        FlutterPluginAdhubPluginInitialize.registerWith(registrar);
        FlutterPluginAdhubRewardPlugin.registerWith(registrar);
        FlutterPluginAdhubInterstitialPlugin.registerWith(registrar);
    }

    @Override
    public void onMethodCall(MethodCall call, Result result) {
    }

}

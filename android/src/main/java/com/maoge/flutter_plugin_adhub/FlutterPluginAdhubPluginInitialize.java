package com.maoge.flutter_plugin_adhub;

import android.util.Log;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.PluginRegistry;

public class FlutterPluginAdhubPluginInitialize extends FlutterPluginAdhubPlugin {

    private static MethodChannel channel;

    /** Plugin registration. */
    public static void registerWith(PluginRegistry.Registrar registrar) {
        channel = new MethodChannel(registrar.messenger(), "adhub_flutter");
        channel.setMethodCallHandler(new FlutterPluginAdhubPluginInitialize());
    }

    @Override
    public void onMethodCall(MethodCall call, MethodChannel.Result result) {
        if (call.method.equals("initialize")) {
            AdUtil.initialize(call.arguments.toString());
        }
    }

}

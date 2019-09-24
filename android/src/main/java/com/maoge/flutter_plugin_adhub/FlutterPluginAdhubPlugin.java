package com.maoge.flutter_plugin_adhub;

import android.util.Log;

import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugin.common.MethodChannel.MethodCallHandler;
import io.flutter.plugin.common.MethodChannel.Result;
import io.flutter.plugin.common.PluginRegistry.Registrar;


public class FlutterPluginAdhubPlugin implements MethodCallHandler {
//    private static MethodChannel channel;

    /** Plugin registration. */
    public static void registerWith(Registrar registrar) {
        FlutterPluginAdhubPluginInitialize.registerWith(registrar);
        FlutterPluginAdhubRewardPlugin.registerWith(registrar);
//        channel = new MethodChannel(registrar.messenger(), "adhub_flutter");
//        channel.setMethodCallHandler(new FlutterPluginAdhubPlugin());
    }

    @Override
    public void onMethodCall(MethodCall call, Result result) {
//
//        Log.e("test", "进来了");
//        if (call.method.equals("getPlatformVersion")) {
//            result.success("Android " + android.os.Build.VERSION.RELEASE);
//        } else if (call.method.equals("initialize")) {
//            System.out.println(call.arguments);
//            AdUtil.init((String) call.arguments);
////            Log.e("test", "init->"+call.argument("appId"));
//        } else if (call.method.equals("load")) {
//            AdUtil.load((String) call.arguments);
//            Log.e("test", "load");
//        } else if (call.method.equals("show")) {
//            AdUtil.show((String) call.arguments);
//            Log.e("test", "show");
//        } else {
//            result.notImplemented();
//            Log.e("test", "11111111111");
//        }
    }

}

package com.maoge.util;

import android.util.Log;

public class L {
    public static boolean isDebug = true;
    public final static String tag = "test";
    public static void e(String str){
        if (isDebug){
            Log.e(tag, str);
        }
    }
}

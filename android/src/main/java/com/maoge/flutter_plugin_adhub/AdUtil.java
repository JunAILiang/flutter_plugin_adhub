package com.maoge.flutter_plugin_adhub;

import android.content.Context;
import android.util.Log;

/*import com.hubcloud.adhubsdk.AdHub;
import com.hubcloud.adhubsdk.AdRequest;
import com.hubcloud.adhubsdk.RewardItem;
import com.hubcloud.adhubsdk.RewardedVideoAd;
import com.hubcloud.adhubsdk.RewardedVideoAdListener;*/

import java.lang.reflect.Method;

/**
 * 广告工具类
 * Created by luweixin on 2019/9/18.
 */

public class AdUtil {

    /** 钩子接口 **/
    public interface Gouzi{
        /** 初始化app **/
        void initialize(String appId);

        /** 加载视频广告 **/
        void loadRewardedVideoAd(String adId);
        /** 显示视频广告 **/
        void showRewardedVideoAd();

        /** 加载插屏广告 **/
        void loadInterstitialAd(String adId);
        /** 显示插屏广告 **/
        void showInterstitialAd();
    }

    /** 钩子初始化 **/
    private static Gouzi gouzi;
    public static void setGouzi(Gouzi gouzi){
        AdUtil.gouzi = gouzi;
    }

    /** 初始化adhub **/
    public static void initialize(String appId){
        if (gouzi!=null){
            gouzi.initialize(appId);
        }
    }


    /** 加载视频广告 **/
    public static void loadRewardedVideoAd(final String adId){
        if (gouzi!=null){
            gouzi.loadRewardedVideoAd(adId);
        }
    }
    /** 展示视频广告 **/
    public static void showRewardedVideoAd(){
        if (gouzi!=null){
            gouzi.showRewardedVideoAd();
        }
    }


    /** 加载插屏广告 **/
    public static void loadInterstitialAd(final String adId) {
        if (gouzi != null) {
            gouzi.loadInterstitialAd(adId);
        }
    }
    /** 展示插屏广告 **/
    public static void showInterstitialAd() {
        if (gouzi != null) {
            gouzi.showInterstitialAd();
        }
    }





    /**
     * Context对象
     */
    private static Context CONTEXT_INSTANCE;

    /**
     * 取得Context对象
     * PS:必须在主线程调用
     * @return Context
     */
    public static Context getContext() {
        if (CONTEXT_INSTANCE == null) {
            synchronized (AdUtil.class) {
                if (CONTEXT_INSTANCE == null) {
                    try {
                        Class<?> ActivityThread = Class.forName("android.app.ActivityThread");

                        Method method = ActivityThread.getMethod("currentActivityThread");
                        Object currentActivityThread = method.invoke(ActivityThread);//获取currentActivityThread 对象

                        Method method2 = currentActivityThread.getClass().getMethod("getApplication");
                        CONTEXT_INSTANCE =(Context)method2.invoke(currentActivityThread);//获取 Context对象

                    } catch (Exception e) {
                        e.printStackTrace();
                    }
                }
            }
        }
        return CONTEXT_INSTANCE;
    }
}

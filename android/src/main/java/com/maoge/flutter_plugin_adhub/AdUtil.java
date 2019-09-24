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

    public interface Gouzi{
        /** 初始化app **/
        void initialize(String appId);

        /** 加载视频广告 **/
        void loadRewardedVideoAd(String adId);
        /** 显示视频广告 **/
        void showRewardedVideoAd();
    }

    private static Gouzi gouzi;
    public static void setGouzi(Gouzi gouzi){
        AdUtil.gouzi = gouzi;
    }

    public static void initialize(String appId){
        if (gouzi!=null){
            gouzi.initialize(appId);
        }
    }

    //private static RewardedVideoAd mRewardedVideoAd;

    public static void loadRewardedVideoAd(final String adId){
        if (gouzi!=null){
            gouzi.loadRewardedVideoAd(adId);
        }

        /*mRewardedVideoAd = AdHub.getRewardedVideoAdInstance(getContext());

        mRewardedVideoAd.setRewardedVideoAdListener(new RewardedVideoAdListener() {
            @Override
            public void onRewarded(RewardItem rewardItem) {
                Log.d("lance", "onRewarded:" + rewardItem.getType() + "==" + rewardItem.getAmount());
            }

            @Override
            public void onRewardedVideoAdClosed() {
                Log.d("lance", "onRewardedVideoAdClosed");
                //TODO 关闭广告后自动加载下一个广告
                load(adId);
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
        }*/
    }
    public static void showRewardedVideoAd(){
        if (gouzi!=null){
            gouzi.showRewardedVideoAd();
        }
        /*if (mRewardedVideoAd.isLoaded()) {
            mRewardedVideoAd.show();
        }*/
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

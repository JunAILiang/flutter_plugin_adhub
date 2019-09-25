#import "FlutterPluginAdhubPlugin.h"
#import <AdHubSDK/AdHubSDK.h>
#import "FlutterPluginAdhubPluginInitialize.h"
#import "FlutterPluginAdhubRewardPlugin.h"
#import "FlutterPluginAdhubInterstitialPlugin.h"

@implementation FlutterPluginAdhubPlugin

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    [FlutterPluginAdhubPluginInitialize registerWithRegistrar:registrar];
    [FlutterPluginAdhubRewardPlugin registerWithRegistrar:registrar];
    [FlutterPluginAdhubInterstitialPlugin registerWithRegistrar:registrar];
}

@end

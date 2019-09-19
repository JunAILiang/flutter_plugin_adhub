#import "FlutterPluginAdhubPlugin.h"
#import <AdHubSDK/AdHubSDK.h>
#import "FlutterPluginAdhubPluginInitialize.h"
#import "FlutterPluginAdhubRewardPlugin.h"

@implementation FlutterPluginAdhubPlugin

+ (void)registerWithRegistrar:(NSObject<FlutterPluginRegistrar>*)registrar {
    [FlutterPluginAdhubPluginInitialize registerWithRegistrar:registrar];
    [FlutterPluginAdhubRewardPlugin registerWithRegistrar:registrar];
}

@end

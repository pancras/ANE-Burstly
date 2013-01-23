//////////////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2012 Freshplanet (http://freshplanet.com | opensource@freshplanet.com)
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//  limitations under the License.
//
//////////////////////////////////////////////////////////////////////////////////////

#import "FlashRuntimeExtensions.h"
#import "BurstlyAdRequest.h"
#import "BurstlyBannerViewDelegate.h"
#import "BurstlyInterstitialDelegate.h"

@interface AirBurstly : NSObject <BurstlyBannerViewDelegate, BurstlyInterstitialDelegate>

+ (AirBurstly *)sharedInstance;

@property (nonatomic, retain) NSString *appId;
@property (nonatomic, retain) NSString *bannerZoneId;
@property (nonatomic, retain) NSString *interstitialZoneId;

@property (nonatomic, getter=isIntegrationMode) BOOL integrationMode;
@property (nonatomic) BurstlyTestAdNetwork testAdNetwork;

+ (void)dispatchEvent:(NSString *)eventName withInfo:(NSString *)info;
+ (void)log:(NSString *)message;

- (void)showBanner;
- (void)hideBanner;
- (BOOL)isInterstitialPreCached;
- (void)showInterstitial;

@end


// C interface
DEFINE_ANE_FUNCTION(AirBurstlySetAppId);
DEFINE_ANE_FUNCTION(AirBurstlySetBannerZoneId);
DEFINE_ANE_FUNCTION(AirBurstlySetInterstitialZoneId);
DEFINE_ANE_FUNCTION(AirBurstlyShowBanner);
DEFINE_ANE_FUNCTION(AirBurstlyHideBanner);
DEFINE_ANE_FUNCTION(AirBurstlyIsInterstitialPreCached);
DEFINE_ANE_FUNCTION(AirBurstlyShowInterstitial);
DEFINE_ANE_FUNCTION(AirBurstlySetIntegrationMode);


// ANE setup
void AirBurstlyContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx, uint32_t* numFunctionsToTest, const FRENamedFunction** functionsToSet);
void AirBurstlyContextFinalizer(FREContext ctx);
void AirBurstlyInitializer(void** extDataToSet, FREContextInitializer* ctxInitializerToSet, FREContextFinalizer* ctxFinalizerToSet);
void AirBurstlyFinalizer(void* extData);
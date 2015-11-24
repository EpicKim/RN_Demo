//
//  AMMacro.h
//  AppMarket
//
//  Created by Mars Ding on 15/7/21.
//  Copyright (c) 2015年 2345 Co., Ltd. All rights reserved.
//

#ifndef AppMarket_AMMacro_h
#define AppMarket_AMMacro_h

#define RUN_ON_MAIN_THREAD(x) dispatch_async(dispatch_get_main_queue(), x);
//--------------------------PRINT LOG--------------------------
#pragma mark - Print Log
/**
 *  Output log when debug state
 */
#ifdef DEBUG
#define DebugLog(format, ...) NSLog((@"%s (%@:Line %d) " format), \
__PRETTY_FUNCTION__, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__,\
## __VA_ARGS__)
#else
#define DebugLog(format, ...)
#endif
//--------------------------PRINT LOG--------------------------

//--------------------------DEVICE INFO--------------------------
#pragma mark - Device Info
/**
 *  System Version Comparison
 */
#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define SCREEN_RETINA                               ([[UIScreen mainScreen] scale] >= 2.0)
#define SCREEN_WIDTH                                ([[UIScreen mainScreen] bounds].size.width)
#define SCREEN_HEIGHT                               ([[UIScreen mainScreen] bounds].size.height)
#define SCREEN_MAX_LENGTH                           (MAX(SCREEN_WIDTH, SCREEN_HEIGHT))
#define SCREEN_MIN_LENGTH                           (MIN(SCREEN_WIDTH, SCREEN_HEIGHT))

#define DEVICE_IPAD                                 (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
#define DEVICE_IPHONE                               (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)

#define DEVICE_IPHONE_4_OR_LESS                     (DEVICE_IPHONE && SCREEN_MAX_LENGTH < 568.0)
#define DEVICE_IPHONE_5                             (DEVICE_IPHONE && SCREEN_MAX_LENGTH == 568.0)
#define DEVICE_IPHONE_6                             (DEVICE_IPHONE && SCREEN_MAX_LENGTH == 667.0)
#define DEVICE_IPHONE_6P                            (DEVICE_IPHONE && SCREEN_MAX_LENGTH == 736.0)

#if TARGET_OS_IPHONE
//iPhone Device
#elif TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif
//--------------------------DEVICE INFO--------------------------

//--------------------------LOAD IMAGE--------------------------
#pragma mark - Load Image

#define LOADIMAGE_NAMED(name) [UIImage imageNamed:name]

#define LOADIMAGE_FILE(path, type) [UIImage imageWithContentsOfFile: \
[[NSBundle mainBundle] pathForResource:path ofType:type]]
//--------------------------LOAD IMAGE--------------------------

//--------------------------COLOR--------------------------
#pragma mark - Color

#define UIColorFromRGB(rgbValue) \
[UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0x0000FF))/255.0 \
alpha:1.0]

#define UIColorFromRGBA(rgbValue, alphaValue) \
[UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0x0000FF))/255.0 \
alpha:alphaValue]
//--------------------------COLOR--------------------------

//--------------------------FONT--------------------------
#pragma mark - Font

#define UIFontWithNameAndSize(n, s)                 [UIFont fontWithName:n size:s]
#define UIFontWithSize(s)                           [UIFont fontWithName:@"HelveticaNeue" size:s]
#define UIBoldFontWithSize(s)                       [UIFont fontWithName:@"HelveticaNeue-Bold" size:s]
//--------------------------FONT--------------------------

//--------------------------FILE--------------------------
#define SetUserDefault(x,y) [[NSUserDefaults standardUserDefaults] setObject:x forKey:y];\
[[NSUserDefaults standardUserDefaults] synchronize]
#define GetUserDefault(x) [[NSUserDefaults standardUserDefaults] objectForKey:x]
//--------------------------FILE--------------------------

#endif

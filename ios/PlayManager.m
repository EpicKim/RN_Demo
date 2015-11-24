//
//  PlayManager.m
//  Movies
//
//  Created by wangk on 15/11/24.
//  Copyright © 2015年 Facebook. All rights reserved.
//

#import "PlayManager.h"
#import <UIKit/UIKit.h>
#import "AMMacro.h"
#import <MediaPlayer/MediaPlayer.h>

@implementation PlayManager

RCT_EXPORT_MODULE();

RCT_EXPORT_METHOD(printMyName){
  UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提交成功！"
                                                  message:nil
                                                 delegate:nil
                                        cancelButtonTitle:@"确定"
                                        otherButtonTitles:nil];
  RUN_ON_MAIN_THREAD(^{
    [alert show];
  });
}

RCT_EXPORT_METHOD(playMovie) {
  RUN_ON_MAIN_THREAD(^{
    UIWindow *window = [UIApplication sharedApplication].keyWindow;
    //视频文件路径
    NSString *videoPath = [[NSBundle mainBundle] pathForResource:@"葫芦娃" ofType:@"mov"];
    NSURL *videoPathUrl = [NSURL fileURLWithPath:videoPath];
    MPMoviePlayerViewController *playViewController = [[MPMoviePlayerViewController alloc] initWithContentURL:videoPathUrl];
    playViewController.view.frame = CGRectMake(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    
    MPMoviePlayerController *player = [playViewController moviePlayer];
    player.controlStyle = MPMovieControlStyleFullscreen;
    [player play];
    
    [window addSubview:playViewController.view];
    // 注册一个播放结束的通知
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(myMovieFinishedCallback:)
                                                 name:MPMoviePlayerPlaybackDidFinishNotification
                                               object:player];
  });
}

-(void)myMovieFinishedCallback:(NSNotification*)notify
{
  //视频播放对象
  MPMoviePlayerController* theMovie = [notify object];
  //销毁播放通知
  [[NSNotificationCenter defaultCenter] removeObserver:self
                                                  name:MPMoviePlayerPlaybackDidFinishNotification
                                                object:theMovie];
  [theMovie.view removeFromSuperview];
}
@end

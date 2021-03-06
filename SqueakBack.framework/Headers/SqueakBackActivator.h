//
//  SqueakBackActivator.h
//  SqueakBack
//
//  Created by Ray Fix on 7/29/15.
//  Copyright (c) 2015 Pelfunc, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * SQBSqueakBackComposerStartedNotification is posted when SqueakBack is activated.
 * You can subscribe to this notification if you need to do something special in 
 * preparation for handling SqueakBacks or simply want to track the event.
 */
extern NSString * __nonnull const SQBSqueakBackComposerStartedNotification;

/**
 * SQBSqueakBackComposerFinishedNotification is posted when SqueakBack is activated.
 * You can subscribe to this notification if there is any special cleanup you would
 * like to do after a SqueakBack has been composed. Network traffic may
 * happen after this notification is sent.
 */
extern NSString * __nonnull const SQBSqueakBackComposerFinishedNotification;

/**
 *  A block that creates a gesture used to activate SqueakBack.  Because the block takes
 *  a viewController as input, you can selectively disable SqueakBack activation 
 *  by returning nil.  You do not need to specify the target/selector of the 
 *  gesture recognizer you return.
 *
 *  The default activation block:
 *
 *  [Objective-C]
 *
 *  [SqueakBack instance].createActivationGestureBlock = ^(UIViewController* viewController) {
 *        UITapGestureRecognizer* tap = [[UITapGestureRecognizer alloc] init];
 *       tap.numberOfTapsRequired = 3;
 *       tap.numberOfTouchesRequired = 2;
 *      return tap;
 *    };
 *
 *  [Swift]
 *
 *  SqueakBack.instance().createActivationGestureBlock = { viewController in
 *       let tap = UITapGestureRecognizer()
 *       tap.numberOfTapsRequired = 3
 *       tap.numberOfTouchesRequired = 2
 *       return tap
 *   }
 */
typedef  UIGestureRecognizer* __nullable (^SQBCreateActivationGestureBlock)(UIViewController* __nonnull viewController);

@interface SqueakBack : NSObject

/**
 *  This is how you start SqueakBack.  Call from your AppDelegate.  
 *  Get an APIKey by registering your app at SqueakBack.com
 *  For many usages of SqueakBack, this is the only call you need to make.
 */
+ (void)startWithAPIKey:(nonnull NSString*)APIKey;

/**
 *  The singleton instance of the SqueakBack activator for doing custom
 *  configuration.
 */
+ (SqueakBack* __nonnull) instance;

/**
 *  Manually trigger a SqueakBack from a given view controller.
 */
- (void)activateFromViewController:(nonnull UIViewController*) viewController;

/**
 *  The APIKey supplied at startup. Returns nil before started.
 */
@property (nonatomic, copy, readonly) NSString* __nullable APIKey;

/**
 *  A block used to create a gesture to activate SqueakBack.  See above discussion.
 */
@property (nonatomic, copy, nullable) SQBCreateActivationGestureBlock createActivationGestureBlock;

/**
 *  When set SqueakBack YES will only initiate uploads iff WIFI is available.  
 */
@property (nonatomic) BOOL uploadOnWIFIOnly;

/**
 *  Output debugging.  Default is NO.
 */
@property (nonatomic) BOOL enableDebugMessages;


@end

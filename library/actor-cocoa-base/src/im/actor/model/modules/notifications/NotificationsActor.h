//
//  Generated by the J2ObjC translator.  DO NOT EDIT!
//  source: /Users/ex3ndr/Develop/actor-model/library/actor-cocoa-base/build/java/im/actor/model/modules/notifications/NotificationsActor.java
//

#ifndef _ImActorModelModulesNotificationsNotificationsActor_H_
#define _ImActorModelModulesNotificationsNotificationsActor_H_

#include "J2ObjC_header.h"
#include "im/actor/model/modules/utils/ModuleActor.h"

@class AMContentDescription;
@class AMPeer;
@class ImActorModelModulesModules;

@interface ImActorModelModulesNotificationsNotificationsActor : ImActorModelModulesUtilsModuleActor

#pragma mark Public

- (instancetype)initWithImActorModelModulesModules:(ImActorModelModulesModules *)messenger;

- (void)onAppHidden;

- (void)onAppVisible;

- (void)onConversationHiddenWithAMPeer:(AMPeer *)peer;

- (void)onConversationVisibleWithAMPeer:(AMPeer *)peer;

- (void)onDialogsHidden;

- (void)onDialogsVisible;

- (void)onMessagesReadWithAMPeer:(AMPeer *)peer
                        withLong:(jlong)fromDate;

- (void)onNewMessageWithAMPeer:(AMPeer *)peer
                       withInt:(jint)sender
                      withLong:(jlong)date
      withAMContentDescription:(AMContentDescription *)description_
                   withBoolean:(jboolean)hasCurrentUserMention;

- (void)onNotificationsPaused;

- (void)onNotificationsResumed;

- (void)onReceiveWithId:(id)message;

- (void)preStart;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_initWithImActorModelModulesModules_(ImActorModelModulesNotificationsNotificationsActor *self, ImActorModelModulesModules *messenger);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor *new_ImActorModelModulesNotificationsNotificationsActor_initWithImActorModelModulesModules_(ImActorModelModulesModules *messenger) NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor)

@interface ImActorModelModulesNotificationsNotificationsActor_NewMessage : NSObject

#pragma mark Public

- (instancetype)initWithAMPeer:(AMPeer *)peer
                       withInt:(jint)sender
                      withLong:(jlong)sortDate
      withAMContentDescription:(AMContentDescription *)contentDescription
                   withBoolean:(jboolean)hasCurrentUserMention;

- (AMContentDescription *)getContentDescription;

- (jboolean)getHasCurrentUserMention;

- (AMPeer *)getPeer;

- (jint)getSender;

- (jlong)getSortDate;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_NewMessage)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_NewMessage_initWithAMPeer_withInt_withLong_withAMContentDescription_withBoolean_(ImActorModelModulesNotificationsNotificationsActor_NewMessage *self, AMPeer *peer, jint sender, jlong sortDate, AMContentDescription *contentDescription, jboolean hasCurrentUserMention);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_NewMessage *new_ImActorModelModulesNotificationsNotificationsActor_NewMessage_initWithAMPeer_withInt_withLong_withAMContentDescription_withBoolean_(AMPeer *peer, jint sender, jlong sortDate, AMContentDescription *contentDescription, jboolean hasCurrentUserMention) NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_NewMessage)

@interface ImActorModelModulesNotificationsNotificationsActor_MessagesRead : NSObject

#pragma mark Public

- (instancetype)initWithAMPeer:(AMPeer *)peer
                      withLong:(jlong)fromDate;

- (jlong)getFromDate;

- (AMPeer *)getPeer;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_MessagesRead)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_MessagesRead_initWithAMPeer_withLong_(ImActorModelModulesNotificationsNotificationsActor_MessagesRead *self, AMPeer *peer, jlong fromDate);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_MessagesRead *new_ImActorModelModulesNotificationsNotificationsActor_MessagesRead_initWithAMPeer_withLong_(AMPeer *peer, jlong fromDate) NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_MessagesRead)

@interface ImActorModelModulesNotificationsNotificationsActor_OnConversationVisible : NSObject

#pragma mark Public

- (instancetype)initWithAMPeer:(AMPeer *)peer;

- (AMPeer *)getPeer;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_OnConversationVisible)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_OnConversationVisible_initWithAMPeer_(ImActorModelModulesNotificationsNotificationsActor_OnConversationVisible *self, AMPeer *peer);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_OnConversationVisible *new_ImActorModelModulesNotificationsNotificationsActor_OnConversationVisible_initWithAMPeer_(AMPeer *peer) NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_OnConversationVisible)

@interface ImActorModelModulesNotificationsNotificationsActor_OnConversationHidden : NSObject

#pragma mark Public

- (instancetype)initWithAMPeer:(AMPeer *)peer;

- (AMPeer *)getPeer;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_OnConversationHidden)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_OnConversationHidden_initWithAMPeer_(ImActorModelModulesNotificationsNotificationsActor_OnConversationHidden *self, AMPeer *peer);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_OnConversationHidden *new_ImActorModelModulesNotificationsNotificationsActor_OnConversationHidden_initWithAMPeer_(AMPeer *peer) NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_OnConversationHidden)

@interface ImActorModelModulesNotificationsNotificationsActor_OnAppVisible : NSObject

#pragma mark Public

- (instancetype)init;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_OnAppVisible)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_OnAppVisible_init(ImActorModelModulesNotificationsNotificationsActor_OnAppVisible *self);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_OnAppVisible *new_ImActorModelModulesNotificationsNotificationsActor_OnAppVisible_init() NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_OnAppVisible)

@interface ImActorModelModulesNotificationsNotificationsActor_OnAppHidden : NSObject

#pragma mark Public

- (instancetype)init;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_OnAppHidden)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_OnAppHidden_init(ImActorModelModulesNotificationsNotificationsActor_OnAppHidden *self);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_OnAppHidden *new_ImActorModelModulesNotificationsNotificationsActor_OnAppHidden_init() NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_OnAppHidden)

@interface ImActorModelModulesNotificationsNotificationsActor_OnDialogsVisible : NSObject

#pragma mark Public

- (instancetype)init;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_OnDialogsVisible)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_OnDialogsVisible_init(ImActorModelModulesNotificationsNotificationsActor_OnDialogsVisible *self);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_OnDialogsVisible *new_ImActorModelModulesNotificationsNotificationsActor_OnDialogsVisible_init() NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_OnDialogsVisible)

@interface ImActorModelModulesNotificationsNotificationsActor_OnDialogsHidden : NSObject

#pragma mark Public

- (instancetype)init;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_OnDialogsHidden)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_OnDialogsHidden_init(ImActorModelModulesNotificationsNotificationsActor_OnDialogsHidden *self);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_OnDialogsHidden *new_ImActorModelModulesNotificationsNotificationsActor_OnDialogsHidden_init() NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_OnDialogsHidden)

@interface ImActorModelModulesNotificationsNotificationsActor_PauseNotifications : NSObject

#pragma mark Public

- (instancetype)init;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_PauseNotifications)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_PauseNotifications_init(ImActorModelModulesNotificationsNotificationsActor_PauseNotifications *self);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_PauseNotifications *new_ImActorModelModulesNotificationsNotificationsActor_PauseNotifications_init() NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_PauseNotifications)

@interface ImActorModelModulesNotificationsNotificationsActor_ResumeNotifications : NSObject

#pragma mark Public

- (instancetype)init;

@end

J2OBJC_EMPTY_STATIC_INIT(ImActorModelModulesNotificationsNotificationsActor_ResumeNotifications)

FOUNDATION_EXPORT void ImActorModelModulesNotificationsNotificationsActor_ResumeNotifications_init(ImActorModelModulesNotificationsNotificationsActor_ResumeNotifications *self);

FOUNDATION_EXPORT ImActorModelModulesNotificationsNotificationsActor_ResumeNotifications *new_ImActorModelModulesNotificationsNotificationsActor_ResumeNotifications_init() NS_RETURNS_RETAINED;

J2OBJC_TYPE_LITERAL_HEADER(ImActorModelModulesNotificationsNotificationsActor_ResumeNotifications)

#endif // _ImActorModelModulesNotificationsNotificationsActor_H_

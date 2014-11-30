//
//  AMBMovingCharacter.h
//  CharacterTests
//
//  Created by Alex Taylor on 2014-11-20.
//  Copyright (c) 2014 Alex Taylor. All rights reserved.
//
//  A high-level superclass that handles moving sprites, like traffic and the player.

#import "AMBCharacter.h"

static const float TURN_BUFFER = 1; // attempt a turn every frame for this many seconds after initial keypress. this helps reduce the accuracy required to hit a corner just right.

@interface AMBMovingCharacter : AMBCharacter

@property (nonatomic) BOOL isMoving; // YES if the character is moving at speed; NO if it's not.

@property (nonatomic) CGFloat speedPointsPerSec;
@property (nonatomic) CGPoint direction;
@property (nonatomic) CGFloat pivotSpeed; // how long it takes the character to rotate 90 degrees

@property (nonatomic) CGFloat accelTimeSeconds; // how long it takes for the character to get up to speed; controls easing
@property (nonatomic) CGFloat decelTimeSeconds;

@property (readonly, nonatomic) BOOL requestedMoveEvent; // YES if a move event has been requested but not yet completed
@property (readonly, nonatomic) CGFloat requestedMoveEventDegrees;

@property (readonly, nonatomic) NSDictionary *currentTileProperties;


- (void)updateWithTimeSinceLastUpdate:(CFTimeInterval)delta;
- (void)startMoving;
- (void)stopMoving;
- (void)rotateByAngle:(CGFloat)degrees;
- (void)moveBy:(CGVector)targetOffset;
- (void)authorizeMoveEvent: (CGFloat)degrees;
- (void)adjustSpeedToTarget:(CGFloat)targetSpeed;


@end
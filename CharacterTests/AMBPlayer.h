//
//  XXXCharacter.h
//  CharacterTests
//
//  Created by Alex Taylor on 2014-07-06.
//  Copyright (c) 2014 Alex Taylor. All rights reserved.
//

#import <SpriteKit/SpriteKit.h>
#import "AMBMovingCharacter.h"
#import "AMBPatient.h"

typedef enum {
    AmbulanceIsOccupied,
    AmbulanceIsEmpty
} AmbulanceState;


@interface AMBPlayer : AMBMovingCharacter

@property (readonly, nonatomic) BOOL isMoving; // YES if the character is moving at speed; NO if it's not.

@property (readonly, nonatomic) float CHARACTER_MOVEMENT_POINTS_PER_SEC;
@property (readonly, nonatomic) float CHARACTER_TURN_DELAY; // builds in a small animated rotation; tweak this to change the "feel" of the turning.

@property CGFloat targetAngleRadians;
@property (readonly, nonatomic) CGPoint direction;

// controls easing
@property (readonly, nonatomic) float CHARACTER_MOVEMENT_ACCEL_TIME_SECS;
@property (readonly, nonatomic) float CHARACTER_MOVEMENT_DECEL_TIME_SECS;

@property AmbulanceState state;
@property AMBPatient *patient;

- (void)updateWithTimeSinceLastUpdate:(CFTimeInterval)delta;
- (void)startMoving;
- (void)stopMoving;
- (void)rotateByAngle:(CGFloat)degrees;
- (void)moveBy:(CGVector)targetOffset;
- (void)changeState:(AmbulanceState)newState;
- (BOOL)loadPatient:(AMBPatient *)patient;
- (BOOL)unloadPatient;
@end

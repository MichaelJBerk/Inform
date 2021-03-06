//
//  GlkPairWindow.h
//  CocoaGlk
//
//  Created by Andrew Hunter on 19/03/2005.
//  Copyright 2005 Andrew Hunter. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import <GlkView/GlkWindow.h>

//
// Representation of a Glk pair window
//
@interface GlkPairWindow : GlkWindow {
	// = GLK settings
	
	// The two windows that make up the pair
	GlkWindow* key;							// The key window is used to determine the size of this window (when fixed)
	GlkWindow* left;						// Left window is the 'original' window when splitting
	GlkWindow* right;						// Right window is the 'new' window when splitting
	
	// The size of the window
	unsigned size;
	
	// Arrangement options
	BOOL fixed;								// Proportional arrangement if NO
	BOOL horizontal;						// Vertical arrangement if NO
	BOOL above;								// NO if left is above/left of right, YES otherwise
	
	// = Custom settings
	float borderWidth;						// Width of the border
	BOOL inputBorder;						// YES if the border should only be drawn around windows that have requested input
	
	BOOL needsLayout;						// True if something has changed to require the windows to be layed out again
	NSRect borderSliver;					// The border sliver
}

// Setting the windows that make up this pair

@property (NS_NONATOMIC_IOSONLY, strong) GlkWindow *keyWindow;
@property (NS_NONATOMIC_IOSONLY, readonly, strong) GlkWindow *nonKeyWindow;
@property (NS_NONATOMIC_IOSONLY, strong) GlkWindow *leftWindow;
@property (NS_NONATOMIC_IOSONLY, strong) GlkWindow *rightWindow;

// Size and arrangement								// Proportional arrangement if NO					// Vertical arrangement if NO								// NO if left is above/left of right, YES otherwise

@property (NS_NONATOMIC_IOSONLY) unsigned int size;
@property (NS_NONATOMIC_IOSONLY) BOOL fixed;
@property (NS_NONATOMIC_IOSONLY) BOOL horizontal;
@property (NS_NONATOMIC_IOSONLY) BOOL above;

// Custom settings
- (void) setBorderWidth: (float) borderWidth;					// Width of the divider between windows (not drawn if < 2)
- (void) setInputBorder: (BOOL) inputBorder;					// Set to true to only draw the border if input is requested

@end

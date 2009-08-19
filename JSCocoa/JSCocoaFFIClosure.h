//
//  JSCocoaFFIClosure.h
//  JSCocoa
//
//  Created by Patrick Geiller on 29/07/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#if !TARGET_IPHONE_SIMULATOR && !TARGET_OS_IPHONE
#import <Cocoa/Cocoa.h>
#import <JavaScriptCore/JavaScriptCore.h>
#define MACOSX
#import <ffi/ffi.h>
#endif
#import "JSCocoaFFIArgument.h"

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#import "iPhone/ffi.h"
#import "iPhone/BurksPool.h"
#endif


@interface JSCocoaFFIClosure : NSObject {

	JSValueRef		jsFunction;
	// ##UNSURE This might cause a crash if we're registered in a non global context that will have been destroyed when we JSValueUnprotect the function
	JSContextRef	ctx;

	ffi_cif			cif;
	ffi_closure*	closure;
	ffi_type**		argTypes;
	
	NSMutableArray*	encodings;
	
	JSObjectRef		jsThisObject;
	
	BOOL			isObjC;
}

- (IMP)setJSFunction:(JSValueRef)fn inContext:(JSContextRef)ctx argumentEncodings:(NSMutableArray*)argumentEncodings objC:(BOOL)objC;
- (void*)functionPointer;
- (void)calledByClosureWithArgs:(void**)args returnValue:(void*)returnValue;

@end

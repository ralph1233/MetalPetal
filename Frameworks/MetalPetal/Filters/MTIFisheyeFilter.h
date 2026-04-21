//
//  MTIFisheyeFilter.h
//  MetalPetal
//

#if __has_include(<MetalPetal/MetalPetal.h>)
#import <MetalPetal/MTIFilter.h>
#else
#import "MTIFilter.h"
#endif

typedef NS_ENUM(NSInteger, MTIFisheyeStyle) {
    /// No distortion; output matches input.
    MTIFisheyeStyleNone = 0,
    /// Wide-angle style (matches legacy `fisheyeW` modifier 0.59).
    MTIFisheyeStyleWide = 1,
    /// Full fisheye (matches legacy `fisheyeF`); pixels outside the circle are opaque black.
    MTIFisheyeStyleFull = 2,
} NS_SWIFT_NAME(MTIFisheyeFilter.Style);

__attribute__((objc_subclassing_restricted))
@interface MTIFisheyeFilter : NSObject <MTIUnaryFilter>

@property (nonatomic, strong, nullable) MTIImage *inputImage;

/// Distortion style. Defaults to `MTIFisheyeStyleWide`.
@property (nonatomic) MTIFisheyeStyle style;

@end

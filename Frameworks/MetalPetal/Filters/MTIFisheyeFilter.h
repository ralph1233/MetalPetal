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
    /// Wide-angle barrel distortion via equidistant fisheye projection.
    /// Fills the whole rectangle, never black, lines bow outward from
    /// centre (Dazz-Cam-style wide lens).
    MTIFisheyeStyleWide = 1,
    /// True circular fisheye inscribed in the smaller side of the texture.
    /// Pixels outside the disc are opaque black; isotropic, so the disc
    /// stays a perfect circle regardless of the input's aspect ratio.
    MTIFisheyeStyleFull = 2,
} NS_SWIFT_NAME(MTIFisheyeFilter.Style);

__attribute__((objc_subclassing_restricted))
@interface MTIFisheyeFilter : NSObject <MTIUnaryFilter>

@property (nonatomic, strong, nullable) MTIImage *inputImage;

/// Distortion style. Defaults to `MTIFisheyeStyleWide`.
@property (nonatomic) MTIFisheyeStyle style;

@end

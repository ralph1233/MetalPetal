//
//  MTIFisheyeFilter.m
//  MetalPetal
//

#import "MTIFisheyeFilter.h"
#import "MTIComputePipelineKernel.h"
#import "MTIFunctionDescriptor.h"
#import "MTIImage.h"

@implementation MTIFisheyeFilter

@synthesize outputPixelFormat = _outputPixelFormat;

+ (MTIComputePipelineKernel *)kernel {
    static MTIComputePipelineKernel *kernel;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        kernel = [[MTIComputePipelineKernel alloc] initWithComputeFunctionDescriptor:[[MTIFunctionDescriptor alloc] initWithName:@"fisheyeEffect"]
                                                             alphaTypeHandlingRule:MTIAlphaTypeHandlingRule.passthroughAlphaTypeHandlingRule];
    });
    return kernel;
}

- (instancetype)init {
    if (self = [super init]) {
        _style = MTIFisheyeStyleWide;
    }
    return self;
}

- (MTIImage *)outputImage {
    if (!self.inputImage) {
        return nil;
    }
    return [self.class.kernel applyToInputImages:@[self.inputImage]
                                      parameters:@{@"fisheyeMode": @((int32_t)self.style)}
                         outputTextureDimensions:MTITextureDimensionsMake2DFromCGSize(self.inputImage.size)
                               outputPixelFormat:self.outputPixelFormat];
}

@end

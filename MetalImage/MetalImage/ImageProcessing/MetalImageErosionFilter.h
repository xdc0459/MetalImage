//
//  MetalImageErosionFilter.h
//  MetalImage
//
//  Created by Feng Stone on 2017/10/21.
//  Copyright © 2017年 fengshi. All rights reserved.
//

#import "MetalImageTwoPassTextureSamplingFilter.h"

// For each pixel, this sets it to the minimum value of the red channel in a rectangular neighborhood extending out dilationRadius pixels from the center.
// This extends out dark features, and is most commonly used with black-and-white thresholded images.

@interface MetalImageErosionFilter : MetalImageTwoPassTextureSamplingFilter

// Acceptable values for erosionRadius, which sets the distance in pixels to sample out from the center, are 1, 2, 3, and 4.
- (id)initWithRadius:(MTLUInt)erosionRadius;

@end

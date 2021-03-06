//
//  MetalImageDilationFilter.m
//  MetalImage
//
//  Created by Feng Stone on 2017/10/21.
//  Copyright © 2017年 fengshi. All rights reserved.
//

#import "MetalImageDilationFilter.h"

@implementation MetalImageDilationFilter

- (instancetype)init {
    return [self initWithRadius:1];
}

- (instancetype)initWithRadius:(MTLUInt)dilationRadius {
    
    MTLUInt supportedDilationRadius = MAX(MIN(dilationRadius, 4), 1);
    NSString *vertexFunctionName = [NSString stringWithFormat:@"vertex_DilationFilterRadius%d", supportedDilationRadius];
    NSString *fragmentFunctionName = [NSString stringWithFormat:@"fragment_DilationFilterRadius%d", supportedDilationRadius];
    if (self = [super initWithFirstStageVertexFunctionName:vertexFunctionName
                            firstStageFragmentFunctionName:fragmentFunctionName
                             secondStageVertexFunctionName:vertexFunctionName
                           secondStageFragmentFunctionName:fragmentFunctionName])
    {
        
    }
    
    return self;
}

@end

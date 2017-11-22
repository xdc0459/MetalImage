//
//  MetalImageColorBurnBlendFilter.m
//  MetalImage
//
//  Created by fengshi on 2017/9/9.
//  Copyright © 2017年 fengshi. All rights reserved.
//

#import "MetalImageColorBurnBlendFilter.h"

@implementation MetalImageColorBurnBlendFilter

- (id)init
{
    if (!(self = [super initWithFragmentFunctionName:@"fragment_colorBurnBlend"]))
    {
        return nil;
    }
    
    return self;
}

@end

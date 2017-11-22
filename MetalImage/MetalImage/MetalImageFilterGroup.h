//
//  MetalImageFilterGroup.h
//  MetalImage
//
//  Created by stonefeng on 2017/3/9.
//  Copyright © 2017年 fengshi. All rights reserved.
//

#import "MetalImageOutput.h"
#import "MetalImageFilter.h"

@interface MetalImageFilterGroup : MetalImageOutput<MetalImageInput>

@property(readwrite, nonatomic, strong) MetalImageOutput<MetalImageInput> *terminalFilter;
@property(readwrite, nonatomic, strong) NSArray *initialFilters;
@property (nonatomic, assign) MTLClearColor bgClearColor;

- (void)addFilter:(MetalImageOutput<MetalImageInput> *)filter;
- (void)removeFilter:(MetalImageOutput<MetalImageInput> *)filter;
- (void)removeAllFilters;
- (MetalImageOutput<MetalImageInput> *)filterAtIndex:(NSUInteger)filterIndex;
- (NSUInteger)filterCount;

@end

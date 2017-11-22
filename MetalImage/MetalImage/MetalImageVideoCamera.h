//
//  MetalImageVideoCamera.h
//  MetalImage
//
//  Created by stonefeng on 2017/3/1.
//  Copyright © 2017年 fengshi. All rights reserved.
//

#import "MetalImageOutput.h"
#import <AVFoundation/AVFoundation.h>
#import <UIKit/UIKit.h>

@interface MetalImageVideoCamera : MetalImageOutput {
    
@protected
    NSUInteger numberOfFramesCaptured;
    CGFloat totalFrameTimeDuringCapture;
    
    AVCaptureSession *_captureSession;
    AVCaptureDevice *_inputCamera;
    AVCaptureDeviceInput *videoInput;
    AVCaptureVideoDataOutput *videoOutput;
    
    BOOL capturePaused;
    MetalImageRotationMode outputRotation;
    dispatch_semaphore_t frameRenderingSemaphore;
}

/// prefer video pixel format. default is kCVPixelFormatType_420YpCbCr8BiPlanarFullRange if camera support.
/**
 you can set it to kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange, kCVPixelFormatType_32BGRA. System camera only support 3 mode now.
 */
@property (nonatomic, assign) OSType videoOutputPixelFormat;

/// This sets the frame rate of the camera (iOS 5 and above only)
/**
 Setting this to 0 or below will set the frame rate back to the default setting for a particular preset.
 */
@property (nonatomic, assign) int32_t frameRate;

/// The AVCaptureSession used to capture from the camera
@property (readonly, retain, nonatomic) AVCaptureSession *captureSession;

/// This enables the capture session preset to be changed on the fly
@property (readwrite, nonatomic, copy) NSString *captureSessionPreset;

/// This determines the rotation applied to the output image, based on the source material
@property (readwrite, nonatomic) UIInterfaceOrientation outputImageOrientation;
/// These properties determine whether or not the two camera orientations should be mirrored. By default, both are NO.
@property (readwrite, nonatomic) BOOL horizontallyMirrorFrontFacingCamera;
@property (readwrite, nonatomic) BOOL horizontallyMirrorRearFacingCamera;

- (id)initWithSessionPreset:(NSString *)sessionPreset cameraPosition:(AVCaptureDevicePosition)cameraPosition;

/// @name Manage the camera video stream

/** Start camera capturing
 */
- (void)startCameraCapture;

/** Stop camera capturing
 */
- (void)stopCameraCapture;

/** Pause camera capturing
 */
- (void)pauseCameraCapture;

/** Resume camera capturing
 */
- (void)resumeCameraCapture;
- (BOOL)isCameraRunning;

- (void)switchCameraDevice;
- (AVCaptureDevicePosition)cameraPosition;

- (void)updateOrientation;

/// Easy way to tell which cameras are present on device
+ (BOOL)isBackFacingCameraPresent;
+ (BOOL)isFrontFacingCameraPresent;

- (void)processVideoSampleBuffer:(CMSampleBufferRef)sampleBuffer;
@end

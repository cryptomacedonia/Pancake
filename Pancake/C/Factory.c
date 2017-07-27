//
//  Factory.c
//  Pancake
//
//  Created by mxa on 16.07.2017.
//  Copyright © 2017 mxa. All rights reserved.
//

#include "Factory.h"
#include "_Others.h"

AudioServerPlugInDriverInterface audioServerPlugInDriverInterface = {
    NULL,
    Pancake_QueryInterface,
    Pancake_AddRef,
    Pancake_Release,
    Pancake_Initialize,
    Pancake_CreateDevice,
    Pancake_DestroyDevice,
    Pancake_AddDeviceClient,
    Pancake_RemoveDeviceClient,
    Pancake_PerformDeviceConfigurationChange,
    Pancake_AbortDeviceConfigurationChange,
    Pancake_HasProperty,
    Pancake_IsPropertySettable,
    Pancake_GetPropertyDataSize,
    Pancake_GetPropertyData,
    Pancake_SetPropertyData,
    Pancake_StartIO,
    Pancake_StopIO,
    Pancake_GetZeroTimeStamp,
    Pancake_WillDoIOOperation,
    Pancake_BeginIOOperation,
    Pancake_DoIOOperation,
    Pancake_EndIOOperation
};

AudioServerPlugInDriverInterface *audioServerPlugInDriverInterfacePtr = &audioServerPlugInDriverInterface;
AudioServerPlugInDriverRef audioServerPlugInDriverRef = &audioServerPlugInDriverInterfacePtr;

void* Pancake_Create(CFAllocatorRef inAllocator, CFUUIDRef inRequestedTypeUUID)
{
    printf("\n\n\nhai world.\n\n\n");
    
    if(!CFEqual(inRequestedTypeUUID, kAudioServerPlugInTypeUUID)) {
        return NULL;
    }
    
    void *driverRef = audioServerPlugInDriverRef;
    
    return driverRef;
}


void CFPlugInDynamicRegister(CFPlugInRef bundle) {
    abort();
}



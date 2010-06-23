/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* DynamicSource implementation */

#include "sles_allinclusive.h"

static SLresult IDynamicSource_SetSource(SLDynamicSourceItf self, SLDataSource *pDataSource)
{
    if (NULL == pDataSource)
        return SL_RESULT_PARAMETER_INVALID;
    IDynamicSource *this = (IDynamicSource *) self;
// FIXME Full implementation of dynamic sources will need a lot more work.
// It requires validating the new source by itself, validating it with respect
// to a data sink if appropriate, terminating the current source, and connecting
// the new source. Note that all this must appear to app to be atomic, yet can actually
// involve several steps that may block.
#if 0
    DataLocatorFormat myDataSource;
    SLresult result;
    result = checkDataSource(pDataSource, &myDataSource);
    if (SL_RESULT_SUCCESS != result)
        return result;
#endif
    // need to lock the object, as a change to source can impact most of object
    IObject *thisObject = InterfaceToIObject(this);
    object_lock_exclusive(thisObject);
    // FIXME a bit of a simplification to say the least!
    this->mDataSource = pDataSource;
    object_unlock_exclusive(thisObject);
    return SL_RESULT_FEATURE_UNSUPPORTED;
}

static const struct SLDynamicSourceItf_ IDynamicSource_Itf = {
    IDynamicSource_SetSource
};

void IDynamicSource_init(void *self)
{
    IDynamicSource *this = (IDynamicSource *) self;
    this->mItf = &IDynamicSource_Itf;
    // mDataSource will be initialized later in CreateAudioPlayer etc.
}
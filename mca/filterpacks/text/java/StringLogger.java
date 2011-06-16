/*
 * Copyright (C) 2011 The Android Open Source Project
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


package android.filterpacks.text;

import android.filterfw.core.Filter;
import android.filterfw.core.FilterContext;
import android.filterfw.core.Frame;
import android.filterfw.core.FrameFormat;
import android.filterfw.core.JavaFrame;
import android.util.Log;

public class StringLogger extends Filter {

    public StringLogger(String name) {
        super(name);
    }

    @Override
    public String[] getInputNames() {
        return new String[] { "string" };
    }

    @Override
    public String[] getOutputNames() {
        return null;
    }

    @Override
    public boolean acceptsInputFormat(int index, FrameFormat format) {
        // TODO: Check meta-property ObjectClass
        return format.getBaseType() == FrameFormat.TYPE_OBJECT;
    }

    @Override
    public FrameFormat getOutputFormat(int index) {
        return null;
    }

    @Override
    public int process(FilterContext env) {
        Frame input = pullInput(0);
        String inputString = (String)input.getObjectValue();

        Log.i("StringLogger", inputString);

        return Filter.STATUS_WAIT_FOR_ALL_INPUTS;
    }

}
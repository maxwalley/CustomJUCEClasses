/*
  ==============================================================================

    ProgressBarV2.h
    Created: 20 Feb 2020 6:18:01pm
    Author:  Max Walley

  ==============================================================================
*/

#pragma once

#include "../../Mess/AudioFileStandardiser/JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ProgressBarV2    : public ProgressBar
{
    
    /*I want to make this progress bar not just work between 0 and 1 and to take more types than double*/
public:
    ProgressBarV2();
    ~ProgressBarV2();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ProgressBarV2)
};

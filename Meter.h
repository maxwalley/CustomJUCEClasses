/*
  ==============================================================================

    Meter.h
    Created: 18 Apr 2020 12:33:16am
    Author:  Max Walley

  ==============================================================================
*/

#pragma once

#include "../../Mess/AudioFileStandardiser/JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class Meter    : public AnimatedAppComponent
{
public:
    Meter();
    ~Meter();

    void paint (Graphics&) override;
    void resized() override;

    void setRange(float minValue, float maxValue);
    Range<float> getRange() const;
    
    void setCurrentValue(float newValue);
    float getCurrentValue() const;
    
private:
    
    Range<float> range;
    float currentVal;
    
    void update() override;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Meter)
};

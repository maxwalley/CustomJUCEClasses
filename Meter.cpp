/*
  ==============================================================================

    Meter.cpp
    Created: 18 Apr 2020 12:33:16am
    Author:  Max Walley

  ==============================================================================
*/

#include "../../Mess/AudioFileStandardiser/JuceLibraryCode/JuceHeader.h"
#include "Meter.h"

//==============================================================================
Meter::Meter()
{
    currentVal = 0;
}

Meter::~Meter()
{
    
}

void Meter::paint (Graphics& g)
{
    g.drawRect(getWidth()/3, 0, (getWidth()/3) * 2, getHeight());
}

void Meter::resized()
{

}

void Meter::setRange(float minValue, float maxValue)
{
    range.setStart(minValue);
    range.setEnd(maxValue);
}

Range<float> Meter::getRange() const
{
    return range;
}

void Meter::setCurrentValue(float newValue)
{
    currentVal = newValue;
}

float Meter::getCurrentValue() const
{
    return currentVal;
}

void Meter::update()
{
    
}

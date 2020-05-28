/*
  ==============================================================================

    ColourSelectorWithPresets.h
    Created: 26 Jan 2020 11:01:50pm
    Author:  Max Walley

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ColourSelectorWithPresets    : public Component,
                                     public Button::Listener,
                                     public ComboBox::Listener
{
public:
    ColourSelectorWithPresets(bool showPresetOptions);
    ~ColourSelectorWithPresets();

    void paint (Graphics&) override;
    void resized() override;
    
    void setPresetDirectory(File directory);
    
    void rescanDirectory();

private:
    
    void buttonClicked(Button* button) override;
    
    void mouseUp(const MouseEvent &event) override;
    
    void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
    
    void setPreset(File presetFile);
    
    Array<File> savedPresets;
    
    bool showPresets;
    
    ColourSelector selector;
    TextButton saveButton;

    Colour currentColour;
    
    TextButton openPreset;
    
    File presetDirectory;
    
    ComboBox availablePresets;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColourSelectorWithPresets)
};

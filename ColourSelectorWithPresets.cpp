/*
  ==============================================================================

    ColourSelectorWithPresets.cpp
    Created: 26 Jan 2020 11:01:50pm
    Author:  Max Walley

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "ColourSelectorWithPresets.h"

//==============================================================================
ColourSelectorWithPresets::ColourSelectorWithPresets(bool showPresetOptions) : saveButton("Save"), openPreset("Open Preset")
{
    showPresets = showPresetOptions;
    
    addAndMakeVisible(selector);
    selector.addMouseListener(this, true);
    
    addAndMakeVisible(saveButton);
    saveButton.addListener(this);
    
    addAndMakeVisible(openPreset);
    openPreset.addListener(this);
    
    addAndMakeVisible(availablePresets);
    availablePresets.addListener(this);
    availablePresets.setText("Select Preset");
}

ColourSelectorWithPresets::~ColourSelectorWithPresets()
{
}

void ColourSelectorWithPresets::paint (Graphics& g)
{
    
}

void ColourSelectorWithPresets::resized()
{
    if(showPresets == true)
    {
        selector.setBounds(0, 30, getWidth(), getHeight() - 30);
        saveButton.setBounds(0, 0, getWidth()/3, 30);
        openPreset.setBounds(getWidth()/3, 0, getWidth()/3, 30);
        availablePresets.setBounds((getWidth()/3) * 2, 0, getWidth()/3, 30);
    }
    else
    {
        selector.setBounds(0, 0, getWidth(), getHeight());
    }
}

void ColourSelectorWithPresets::setPresetDirectory(File directory)
{
    presetDirectory = directory;
    rescanDirectory();
}

void ColourSelectorWithPresets::rescanDirectory()
{
    availablePresets.clear();
    savedPresets.clear();
    
    savedPresets = presetDirectory.findChildFiles(2, true, "*.xml");
    
    for(int i = 0; i < savedPresets.size(); i++)
    {
        availablePresets.addItem(savedPresets[i].getFileName(), i + 1);
    }
}

void ColourSelectorWithPresets::buttonClicked(Button* button)
{
    if(button == &saveButton)
    {
        XmlElement preset("preset");
        
        preset.setAttribute("red", currentColour.getRed());
        preset.setAttribute("blue", currentColour.getBlue());
        preset.setAttribute("green", currentColour.getGreen());
        preset.setAttribute("alpha", currentColour.getAlpha());
        
        FileChooser chooser("Save Preset", File(), "*.xml", true);
        
        if(chooser.browseForFileToSave(true) == true)
        {
            File xmlFile = chooser.getResult();
            preset.writeTo(xmlFile);
        }
    }
    
    else if(button == &openPreset)
    {
        FileChooser chooser("Open Preset", File(), "*.xml", true);
        
        if(chooser.browseForFileToOpen() == true)
        {
            setPreset(chooser.getResult());
        }
    }
}

void ColourSelectorWithPresets::mouseUp(const MouseEvent &event)
{
    currentColour = selector.getCurrentColour();
}

void ColourSelectorWithPresets::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    if(comboBoxThatHasChanged == &availablePresets)
    {
        if(savedPresets.size() != 0)
        {
            setPreset(savedPresets[availablePresets.getSelectedId()]);
        }
    }
}

void ColourSelectorWithPresets::setPreset(File presetFile)
{
    std::unique_ptr<XmlElement> xml = XmlDocument::parse(presetFile);
    
    String redString = xml->getStringAttribute(StringRef("red"));
    String blueString = xml->getStringAttribute(StringRef("blue"));
    String greenString = xml->getStringAttribute(StringRef("green"));
    String alphaString = xml->getStringAttribute(StringRef("alpha"));
    
    selector.setCurrentColour(Colour(uint8(redString.getIntValue()), uint8(greenString.getIntValue()), uint8(blueString.getIntValue()), uint8(alphaString.getIntValue())));
}


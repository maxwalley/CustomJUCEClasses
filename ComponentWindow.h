/*
  ==============================================================================

    ComponentWindow.h
    Created: 16 Jan 2020 1:29:57pm
    Author:  Max Walley

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/** A window that holds a component. Almost exactly the same as the DocumentWindow class however, when the close button is pressed on this class the window will close. Sends an action message when the window is clicked or the mouse is released however to implement this the owned component must have this as a mouse listener
*/
class ComponentWindow    : public DocumentWindow,
                           public ActionBroadcaster
{
public:
    /**Constructor
     
     @param name            the name of the window
     @param backgroundColour            the background colour of the window
     @param requiredButtons         the buttons to put in the top left hand corner of the window
     
     @see DocumentWindow()
     */
    ComponentWindow(const String &name, Colour backgroundColour, int requiredButtons);
    
    /**Destructor*/
    ~ComponentWindow();


private:
    
    /**Implementation of the DocumentWindow method*/
    void closeButtonPressed() override;
    
    /**Implementation of the MouseListener method*/
    void mouseDown(const MouseEvent &event) override;
    
    /**Implementation of the MouseListener method*/
    void mouseUp(const MouseEvent &event) override;
    
    String windowName;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComponentWindow)
};

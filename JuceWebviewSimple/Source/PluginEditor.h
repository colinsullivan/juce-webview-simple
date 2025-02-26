/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include <juce_gui_extra/juce_gui_extra.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class JuceWebviewSimpleAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    JuceWebviewSimpleAudioProcessorEditor (JuceWebviewSimpleAudioProcessor&, const juce::WebBrowserComponent::Options&);
    ~JuceWebviewSimpleAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceWebviewSimpleAudioProcessor& audioProcessor;
    juce::WebBrowserComponent mWebComponent;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceWebviewSimpleAudioProcessorEditor)
};

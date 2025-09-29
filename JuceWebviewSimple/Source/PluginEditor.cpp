/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JuceWebviewSimpleAudioProcessorEditor::JuceWebviewSimpleAudioProcessorEditor (JuceWebviewSimpleAudioProcessor& p, const juce::WebBrowserComponent::Options& options)
    : AudioProcessorEditor (&p), audioProcessor (p), mWebComponent(options)
{
    
    addAndMakeVisible(mWebComponent);

    // Get the HTML file from the plugin's Resources directory
    auto pluginFile = juce::File::getSpecialLocation(juce::File::currentApplicationFile);
    auto htmlFile = pluginFile.getChildFile("Contents").getChildFile("Resources").getChildFile("document-mouseout-example.html");
    mWebComponent.goToURL(juce::URL(htmlFile).toString(false));
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

JuceWebviewSimpleAudioProcessorEditor::~JuceWebviewSimpleAudioProcessorEditor()
{
}

//==============================================================================
void JuceWebviewSimpleAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void JuceWebviewSimpleAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    mWebComponent.setSize(getWidth(), getHeight());
}

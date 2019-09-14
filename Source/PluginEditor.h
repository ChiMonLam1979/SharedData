#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Labels.h"
#include "GUIUpdater.h"

class SharedDataAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SharedDataAudioProcessorEditor (SharedDataAudioProcessor&);
    ~SharedDataAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

	void doSomething();
	void doSomethingElse();

private:

    SharedDataAudioProcessor& processor;

	State& state;

	GUIState guiState;

	GUIUpdater guiUpdater{ state, guiState };

	Labels labels { guiState };

	TextButton button1{ "Button One" };

	TextButton button2{ "Button Two" };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SharedDataAudioProcessorEditor)
};

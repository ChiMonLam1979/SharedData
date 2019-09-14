#include "PluginProcessor.h"
#include "PluginEditor.h"

SharedDataAudioProcessorEditor::SharedDataAudioProcessorEditor (SharedDataAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p), state(processor.myState)
{
    setSize (400, 300);

	addAndMakeVisible(button1);
	addAndMakeVisible(button2);
	addAndMakeVisible(labels);

	button1.onClick = [this] { doSomething(); };
	button2.onClick = [this] {doSomethingElse(); };
}

SharedDataAudioProcessorEditor::~SharedDataAudioProcessorEditor()
{
}

void SharedDataAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
}

void SharedDataAudioProcessorEditor::resized()
{
	auto window = getLocalBounds();

	auto topSection = window.removeFromTop(window.getHeight() / 2);

	auto bottomLeftCorner = window.removeFromLeft(window.getWidth() / 2);

	button1.setBounds(bottomLeftCorner);
	button2.setBounds(window);
	labels.setBounds(topSection);
}


void SharedDataAudioProcessorEditor::doSomething()
{
	for(auto i = 0; i < state.getVectorSize(); ++i)
	{
		auto value = state.getVectorValue(i);
		state.setVectorValue(i, --value);
	}
}

void SharedDataAudioProcessorEditor::doSomethingElse()
{
	for (auto i = 0; i < state.getVectorSize(); ++i)
	{
		auto value = state.getVectorValue(i);
		state.setVectorValue(i, ++value);
	}
}
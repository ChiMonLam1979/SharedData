#include "PluginProcessor.h"
#include "PluginEditor.h"

SharedDataAudioProcessor::SharedDataAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),treeState(*this, nullptr, "TreeState", createParameters())
#endif
{
	for(auto i = 0; i < myState.getVectorSize(); ++i)
	{
		myState.setVectorValue(i, i);
	}
}

AudioProcessorValueTreeState::ParameterLayout SharedDataAudioProcessor::createParameters()
{
	std::vector<std::unique_ptr<RangedAudioParameter>> parameters;

	return { parameters.begin(), parameters.end() };
}

SharedDataAudioProcessor::~SharedDataAudioProcessor()
{
}

const String SharedDataAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SharedDataAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SharedDataAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SharedDataAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SharedDataAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SharedDataAudioProcessor::getNumPrograms()
{
    return 1;
}

int SharedDataAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SharedDataAudioProcessor::setCurrentProgram (int index)
{
}

const String SharedDataAudioProcessor::getProgramName (int index)
{
    return {};
}

void SharedDataAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void SharedDataAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void SharedDataAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SharedDataAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SharedDataAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
    }
}

bool SharedDataAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SharedDataAudioProcessor::createEditor()
{
    return new SharedDataAudioProcessorEditor (*this);
}

void SharedDataAudioProcessor::getStateInformation (MemoryBlock& destData)
{
}

void SharedDataAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SharedDataAudioProcessor();
}

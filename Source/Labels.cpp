#include "Labels.h"

Labels::Labels(GUIState& guiState): guiState(guiState)
{
	for(auto i = 0; i < 3; ++i)
	{
		labels.push_back(std::make_unique<Label>("label" + String(i)));
		labels[i]->getTextValue().referTo(guiState.getVectorValue(i));
	}

	for (auto& label : labels)
	{
		label->setBorderSize(BorderSize<int>(20));
		label->setJustificationType(Justification::centred);
		label->setFont(Font(22.0f, Font::bold));
		addAndMakeVisible(label.get());
	}
}

void Labels::resized()
{
	auto area = getLocalBounds();
	auto width = getWidth() / int(labels.size());

	for (auto& label : labels)
	{
		label->setBounds(area.removeFromLeft(width));
	}
}

Labels::~Labels()
{
	
}
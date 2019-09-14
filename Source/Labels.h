#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "GUIState.h"

class Labels : public Component
{
public:

	Labels(GUIState& guiState);

	~Labels();

	void resized() override;

	std::vector<std::unique_ptr<Label>> labels;

private:

	GUIState& guiState;
};
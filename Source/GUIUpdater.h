#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "State.h"
#include "GUIState.h"

class GUIUpdater : Timer
{
public:

	GUIUpdater(State& state, GUIState& guiState);

	~GUIUpdater();

private:

	void timerCallback() override;

	State& state;

	GUIState& guiState;
};
#include "GUIUpdater.h"

GUIUpdater::GUIUpdater(State& state, GUIState& guiState) : state(state), guiState(guiState)
{
	startTimer(30);
}

GUIUpdater::~GUIUpdater()
{
	
}

void GUIUpdater::timerCallback()
{
	for(auto i = 0; i < state.getVectorSize(); ++i)
	{
		guiState.setVectorValue(i, state.getVectorValue(i));
	}
}
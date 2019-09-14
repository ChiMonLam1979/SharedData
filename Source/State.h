#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "VectorState.h"

class State
{
public:

	State(VectorState& vectorState);

	~State();

	int getVectorSize();

	int getVectorValue(int index);

	void setVectorValue(int index, int value);

private:

	VectorState& vectorState;

	CriticalSection objectLock;
};
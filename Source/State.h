#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "VectorState.h"

class State
{
public:

	int getVectorSize();

	int getVectorValue(int index);

	void setVectorValue(int index, int value);

private:

	VectorState vectorState;

	CriticalSection objectLock;
};
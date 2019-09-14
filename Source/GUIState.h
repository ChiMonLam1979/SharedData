#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class GUIState
{
public:

	int getVectorSize();

	Value getVectorValue(int index);

	void setVectorValue(int index, int value);

private:

	std::vector<Value> vectorValues{3};
};
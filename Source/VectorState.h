#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class VectorState
{
public:

	int getSize();

	int getValue(int index);

	void setValue(int index, int value);

private:

	std::vector<int> vector{ 0, 0, 0 };
};
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class VectorState
{
public:

	VectorState(int size);

	~VectorState();

	int getSize();

	int getValue(int index);

	void setValue(int index, int value);

private:

	std::vector<std::unique_ptr<std::atomic<int>>> vector;
};
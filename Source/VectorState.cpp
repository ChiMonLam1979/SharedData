#include "VectorState.h"

VectorState::VectorState(int size)
{
	for(auto i = 0; i < size; ++i)
	{
		vector.push_back(std::make_unique<std::atomic<int>>(0));
	}
}

VectorState::~VectorState()
{
	
}

int VectorState::getSize()
{
	return vector.size();
}

int VectorState::getValue(int index)
{
	return vector[index]->load();
}

void VectorState::setValue(int index, int value)
{
	vector[index]->store(value);
}
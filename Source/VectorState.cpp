#include "VectorState.h"

int VectorState::getSize()
{
	return vector.size();
}

int VectorState::getValue(int index)
{
	return vector[index];
}

void VectorState::setValue(int index, int value)
{
	vector[index] = value;
}
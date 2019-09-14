#include "GUIState.h"

int GUIState::getVectorSize()
{
	return vectorValues.size();
}

Value GUIState::getVectorValue(int index)
{
	return vectorValues[index];
}

void GUIState::setVectorValue(int index, int value)
{
	vectorValues[index] = value;
}
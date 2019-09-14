#include "State.h"


State::State(VectorState& vectorState) : vectorState(vectorState)
{
}

State::~State()
{
}

int State::getVectorSize()
{
	return vectorState.getSize();
}

int State::getVectorValue(int index)
{
	const ScopedLock scopedLock(objectLock);

	return vectorState.getValue(index);
}

void State::setVectorValue(int index, int value)
{
	const ScopedLock scopedLock(objectLock);

	vectorState.setValue(index, value);
}
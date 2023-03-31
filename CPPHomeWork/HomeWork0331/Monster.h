#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	Monster();
	void Update();

	inline int GetDir()
	{
		return Dir;
	}

	inline void PlusMinusDir()
	{
		Dir *= (-1);
	}

private:
	int Dir = 1;
};


#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen;
class Bullet
{
private:
	int2 BulletPos = int2(0, 0);

public:
	Bullet();

	inline void SetBulletPos(const int2& _Value)
	{
		BulletPos = _Value;
	}

	inline int2 GetBulletPos() const
	{
		return BulletPos;
	}

	void UpMove();
	
};


#include "Bullet.h"
#include "ConsoleGameScreen.h"

Bullet::Bullet()
{
	
}

void Bullet::BulletFire(bool _Fire)
{
	int2 BulletNextPos = { 0, 0 };
	if (true == _Fire)
	{
		BulletPos.Y -= 1;
		BulletNextPos = BulletPos;
		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(BulletPos, '+');

	}
}
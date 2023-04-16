#include "Item.h"
#include <GameEngineBase/GameEngineRandom.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include "player.h"

Item::Item() 
{
	RenderChar = '&';

	int X = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().X - 1);
	int Y = GameEngineRandom::MainRandom.RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().Y - 1);
	SetPos({X, Y});
}

Item::~Item() 
{
}

// 아이템은 플레이어를 모를까?
// 플레이어는 아이템을 알까?
// 아이템이 먹힐때는 플레이어와 아이템의 좌표가 같을때인데
// 아이템이 먹힌다면
// 아이템은 삭제되고, 플레이어의 붐파워는 증가.
// 플레이어의 좌표값은 어떻게 알수있을까?
// 플레이어에서 아이템의 좌표값을 받아서 아이템의 업데이트 함수를 호출?

// 아이템이 먹혔을때
void Item::Update()
{
	ConsoleGameObject::Update();

	int2 ItemPos = GetPos();
	
	if (false)
	{
		Death();
	}

}

//void Item::Update() 
//{
//	ConsoleGameObject::Update();
//	
//	if (&Player::GetPos == &Item::GetPos)
//	{
//		this->Death();
//		&Player::BombPowerUp;
//	}
//
//	//if (CurExpPower == MaxExpPower)
//	//{
//	//	Death();
//	//	// Off();
//	//}
//
//	//if (0 >= --BoomCount)
//	//{
//	//	CurExpPower++;
//	//}
//}
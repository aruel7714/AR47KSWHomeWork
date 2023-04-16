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

// �������� �÷��̾ �𸦱�?
// �÷��̾�� �������� �˱�?
// �������� �������� �÷��̾�� �������� ��ǥ�� �������ε�
// �������� �����ٸ�
// �������� �����ǰ�, �÷��̾��� ���Ŀ��� ����.
// �÷��̾��� ��ǥ���� ��� �˼�������?
// �÷��̾�� �������� ��ǥ���� �޾Ƽ� �������� ������Ʈ �Լ��� ȣ��?

// �������� ��������
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
#include "Head.h"
#include <conio.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "Body.h"
#include "Parts.h"

bool Head::IsPlay = true;

Head::Head() 
{
	RenderChar = '$';
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
}

Head::~Head() 
{
}

bool Head::IsBodyCheck(int2 _NextPos)
{
	std::list<ConsoleGameObject*>& BodyGroup
		= ConsoleObjectManager::GetGroup(1);

	for (ConsoleGameObject* Ptr : BodyGroup)
	{
		// 터질때가 있습니다.
		if (nullptr == Ptr)
		{
			continue;
		}

		int2 BodyPos = Ptr->GetPos();
		if (_NextPos == BodyPos)
		{
			Ptr->Death();
			return true;
		}
	}

	return false;
}

void Head::NewBodyCreateCheck(int2 _PrevPos)
{
	std::list<ConsoleGameObject*>& PartsGroup
		= ConsoleObjectManager::GetGroup(2);
}

// 화면바깥으로 못나가게 하세요. 
void Head::Update()
{
	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}


	if (0 == _kbhit())
	{
		// 가만히 있어도 플레이어는 움직인다.
		// SetPos(GetPos() + Dir);
		// IsBodyCheck(); 
		// NewBodyCreateCheck();
		return;
	}

	char Ch = _getch();

	int2 NextPos = { 0, 0 };
	int2 PrevPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		Dir = int2::Left;
		break;
	case 'd':
	case 'D':
		Dir = int2::Right;
		break;
	case 'w':
	case 'W':
		Dir = int2::Up;
		break;
	case 's':
	case 'S':
		Dir = int2::Down;
		break;
	case 'q':
	case 'Q':
		IsPlay = false;
		return;
	default:
		return;
	}

	SetPos(GetPos() + Dir);
	PrevPos.X = GetPos().X - Dir.X;
	PrevPos.Y = GetPos().Y - Dir.Y;
	if (true == IsBodyCheck(GetPos()))
	{
		ConsoleObjectManager::CreateConsoleObject<Parts>(2);
		NewBodyCreateCheck(PrevPos);
		ConsoleObjectManager::CreateConsoleObject<Body>(1);
	}
//	IsBodyCheck();
//	NewBodyCreateCheck();

	if (true == ConsoleGameScreen::GetMainScreen().IsScreenOver(GetPos()))
	{
		IsPlay = false;
	}



}

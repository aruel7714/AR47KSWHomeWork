#include "ShootingGame.h"

#include <iostream>

// 내가 만든건 ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// 게임이 시작하기 전에 준비한다.
	// 총알이 여러발 나가게 만드세요.

	// 시작하면 어차피 모든 총알은 발사되지 않았을것이므로 다 끈다.
	Bullet::AllOff();

	// 플레이어가 총알의 포인터를 알게 한다.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// 플레이어를 화면의 중앙에 위치시킨다.
	int2 ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	for (int i = 0; i < ArrMonsterCount; i++)
	{
		ArrMonster[i].SetPos({i + 3, 1});
	}

}

void ShootingGame::Collision()
{

	Bullet* BulletArr = Bullet::GetArrBullet();

	// 모든 총알과
	for (size_t BulletIndex = 0; BulletIndex < Bullet::ArrBulletCount; BulletIndex++)
	{
		Bullet& CurBullet = BulletArr[BulletIndex];

		if (false == CurBullet.IsUpdate())
		{
			continue;
		}

		for (size_t MonsterIndex = 0; MonsterIndex < ShootingGame::ArrMonsterCount; MonsterIndex++)
		{
			Monster& CurMonster = ArrMonster[MonsterIndex];

			if (false == CurMonster.IsUpdate())
			{
				continue;
			}

			if (CurMonster.GetPos() == CurBullet.GetPos())
			{
				CurMonster.Off();
				CurBullet.Off();
			}
		}
	}

}

void ShootingGame::MonsterEndCheck()
{
	// 1. 움직이게 한다.
	// 2. 끝에 어떠한 몬스터중 단 1개라도 닿았는지 확인한다.
	//    2-1. 왼쪽 끝을체크한다.
	//    2-2. 오른쪽 끝에 닿은걸 체크한다.
	//if (몬스터가 왼쪽 끝에 닿았다)
	//{
	//	int a = 0;
	//}
	// 3. 방향을 바꾼다.
	// 4. 내려도 본다.
	int i = 0;
	int2 CheckMonsterPos = { 0, 0 };
	
	int2 MonsterPos = { 0, 0 };

	// 이동하는 반복문
	/*for (int i = 0; i < ArrMonsterCount; i++)
	{
		MonsterPos = ArrMonster[i].GetPos();
		MonsterPos.X -= ArrMonster->GetDir();
		ArrMonster[i].SetPos(MonsterPos);
	}*/
	
	// Dir 부호 바꾸기
	// ArrMonster->PlusMinusDir();
	
	// 몬스터의 왼쪽부터 검사하여
	// 죽지않은 몬스터의 Pos값 받기
	//for (int i = 0; i < ArrMonsterCount; i++)
	//{
	//	if (true == ArrMonster[i].IsUpdate())
	//	{
	//		CheckMonsterPos = ArrMonster[i].GetPos();
	//		break;
	//	}
	//}

	//if (CheckMonsterPos.X == 0)
	//{
	//	ArrMonster->PlusMinusDir();
	//}

	//// 몬스터의 오른쪽부터 검사하여
	//// 죽지않은 몬스터의 Pos값 받기
	//for (int i = ArrMonsterCount - 1; i >= 0; i--)
	//{
	//	if (true == ArrMonster[i].IsUpdate())
	//	{
	//		CheckMonsterPos = ArrMonster[i].GetPos();
	//		break;
	//	}
	//}

	// Dir이 양수라면 왼쪽으로 이동하게 설정
	if (0 < ArrMonster->GetDir())
	{
		// 몬스터의 왼쪽부터 검사하여
		for (int i = 0; i < ArrMonsterCount; i++)
		{
			// 죽지않은 몬스터의 Pos값 받기
			if (true == ArrMonster[i].IsUpdate())
			{
				CheckMonsterPos = ArrMonster[i].GetPos();
				break;
			}
		}

		// 벽에 닿으면 Dir 부호 바꾸기
		if (CheckMonsterPos.X == 0)
		{
			ArrMonster->PlusMinusDir();
		}
		
	}
	// Dir이 음수라면 오른쪽으로 이동하게 설정
	else if (0 > ArrMonster->GetDir())
	{
		// 몬스터의 오른쪽부터 검사하여
		for (int i = ArrMonsterCount - 1; i >= 0; i--)
		{
			// 죽지않은 몬스터의 pos값 받기
			if (true == ArrMonster[i].IsUpdate())
			{
				CheckMonsterPos = ArrMonster[i].GetPos();
				break;
			}
		}

		if (CheckMonsterPos.X == ConsoleGameScreen::GetMainScreen().ScreenXSize - 1)
		{
			ArrMonster->PlusMinusDir();
		}
	}

	// 끝에 다다르면 y내리기
	/*if (CheckMonsterPos.X == 0 || CheckMonsterPos.X == ConsoleGameScreen::GetMainScreen().ScreenXSize - 1)
	{
		for (int i = 0; i < ArrMonsterCount; i++)
		{
			MonsterPos = ArrMonster[i].GetPos();
			MonsterPos.Y += 1;
			ArrMonster[i].SetPos(MonsterPos);
		}
	}*/

	// 이동!
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		MonsterPos = ArrMonster[i].GetPos();
		// 벽에 닿은 상태라면 y 이동
		if (CheckMonsterPos.X == 0 || CheckMonsterPos.X == ConsoleGameScreen::GetMainScreen().ScreenXSize - 1)
		{
			MonsterPos.Y += 1;
			ArrMonster[i].SetPos(MonsterPos);
			
		}
		// 그게 아니라면 x 이동
		else
		{
			MonsterPos.X -= ArrMonster->GetDir();
			ArrMonster[i].SetPos(MonsterPos);
		}
		
	}

}

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// 캐릭터 위치에 글자를 하나 띄운다.
		NewPlayer.Render();
		Bullet::AllRender();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Render();
		}

		MonsterEndCheck();
		Collision();

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
		for (size_t i = 0; i < ArrMonsterCount; i++)
		{
			ArrMonster[i].Update();
		}

	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}
#include "ShootingGame.h"

#include <iostream>

// ���� ����� ""
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"
#include "ConsoleGameScreen.h"

Player ShootingGame::NewPlayer;
Monster ShootingGame::ArrMonster[ShootingGame::ArrMonsterCount];

void ShootingGame::Loading() 
{
	// ������ �����ϱ� ���� �غ��Ѵ�.
	// �Ѿ��� ������ ������ ���弼��.

	// �����ϸ� ������ ��� �Ѿ��� �߻���� �ʾ������̹Ƿ� �� ����.
	Bullet::AllOff();

	// �÷��̾ �Ѿ��� �����͸� �˰� �Ѵ�.
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());

	// �÷��̾ ȭ���� �߾ӿ� ��ġ��Ų��.
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

	// ��� �Ѿ˰�
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
	// 1. �����̰� �Ѵ�.
	// 2. ���� ��� ������ �� 1���� ��Ҵ��� Ȯ���Ѵ�.
	//    2-1. ���� ����üũ�Ѵ�.
	//    2-2. ������ ���� ������ üũ�Ѵ�.
	//if (���Ͱ� ���� ���� ��Ҵ�)
	//{
	//	int a = 0;
	//}
	// 3. ������ �ٲ۴�.
	// 4. ������ ����.
	int i = 0;
	int2 CheckMonsterPos = { 0, 0 };
	int2 MonsterPos = { 0, 0 };

	// �̵��ϴ� �ݺ���
	/*for (int i = 0; i < ArrMonsterCount; i++)
	{
		MonsterPos = ArrMonster[i].GetPos();
		MonsterPos.X -= ArrMonster->GetDir();
		ArrMonster[i].SetPos(MonsterPos);
	}*/
	
	// Dir ��ȣ �ٲٱ�
	// ArrMonster->PlusMinusDir();
	
	// ������ ���ʺ��� �˻��Ͽ�
	// �������� ������ Pos�� �ޱ�
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

	

	//// ������ �����ʺ��� �˻��Ͽ�
	//// �������� ������ Pos�� �ޱ�
	//for (int i = ArrMonsterCount - 1; i >= 0; i--)
	//{
	//	if (true == ArrMonster[i].IsUpdate())
	//	{
	//		CheckMonsterPos = ArrMonster[i].GetPos();
	//		break;
	//	}
	//}

	// Dir�� ������ �������� �̵�
	if (0 < ArrMonster->GetDir())
	{
		for (int i = 0; i < ArrMonsterCount; i++)
		{
			if (true == ArrMonster[i].IsUpdate())
			{
				CheckMonsterPos = ArrMonster[i].GetPos();
				break;
			}
		}

		if (CheckMonsterPos.X == 0)
		{
			ArrMonster->PlusMinusDir();
		}
		
	}
	// Dir�� ������� ���������� �̵�
	if (0 > ArrMonster->GetDir())
	{
		for (int i = ArrMonsterCount - 1; i >= 0; i--)
		{
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
	for (int i = 0; i < ArrMonsterCount; i++)
	{
		MonsterPos = ArrMonster[i].GetPos();
		MonsterPos.X -= ArrMonster->GetDir();
		ArrMonster[i].SetPos(MonsterPos);
	}

	/*if (CheckMonsterPos.X == 0 || CheckMonsterPos.X == ConsoleGameScreen::GetMainScreen().ScreenXSize - 1)
	{
		for (int i = 0; i < ArrMonsterCount; i++)
		{
			MonsterPos = ArrMonster[i].GetPos();
			MonsterPos.Y += 1;
			ArrMonster[i].SetPos(MonsterPos);
		}
	}*/

	
	/*while (true)
	{
		if (i == ArrMonsterCount)
		{
			i = 0;
		}
		int2 MonsterPos = ArrMonster[i].GetPos();
		MonsterPos.X -= 1;
		ArrMonster[i].SetPos(MonsterPos);

	}*/
	
	
}

void ShootingGame::GameUpdate() 
{
	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		// ĳ���� ��ġ�� ���ڸ� �ϳ� ����.
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
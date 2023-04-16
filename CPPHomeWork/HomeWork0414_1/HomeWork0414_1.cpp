// HomeWork0407.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEngineConsole/ConsoleGameScreen.h>
#include <GameEngineConsole/ConsoleGameObject.h>
#include "Player.h"
#include "Bomb.h"
#include "Item.h"
#include <GameEngineConsole/ConsoleObjectManager.h>
#include "GameEnum.h"
#include <conio.h>

int main()
{
	GameEngineDebug::LeckCheck();

	int2 ScreenSize = { 20, 10 };
	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);
	// ��ĳ����
	// �������̽� ����
	// �� �����ӿ�ũ ���� ��� ������� ������Ʈ�� ������� �������̽��� 
	// ConsoleGameObject* NewPlayer = new Player();

	// 0�� �׷쿡 ���Ѵ�
	// CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
	// 1�� �׷���Ѵ�.
	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);

	ConsoleObjectManager::CreateConsoleObject<Item>(ObjectOrder::Item);

	// CreateConsoleObject<Monster>(2);


	while (Player::IsGameUpdate)
	{
		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();
		ConsoleObjectManager::ConsoleAllObjectRelease();
		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();
}


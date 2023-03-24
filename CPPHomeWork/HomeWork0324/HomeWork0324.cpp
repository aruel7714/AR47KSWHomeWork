// HomeWork0324.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
// 운영체제가 도와줄수밖에 없다.
#include <Windows.h>

// 숙제 0
// 상하좌우로 다 움직이게 해주세요.

// 숙제 1
// 잔상 지우기

// 숙제 2
// 화면 바깥으로 못나가게 하세요.

// 안해도 되는 숙제 
// 질문했을때 안받아줄겁니다.

// 숙제 3
// 장애물 만들고 배치하세요 당연히 플레이어는 거기로 못갑니다.

// 숙제 4
// 폭탄 f를 누를면 폭탄이 설치되고 눈에 보여야 합니다. 폭탄 @

// 숙제 5
// 일정시간이 지나고 폭탄이 터지면서
//     @
//     @
//     @
//  @@@@@@@
//     @
//     @
//     @

int main()
{
	const int ScreenYSize = 10;
	const int ScreenXSize = 20;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'o';
		}
	}

	

	// 정수를 정수로 나오면 실수는 버리고 정수의 값만 나옵니다.
	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;

	int blockCount = 5;
	srand(time(0));
	for (int i = 0; i < blockCount; i++)
	{
		int Xindex = rand() % 20;
		int Yindex = rand() % 10;

		if (Xindex == PlayerX && Yindex == PlayerY)
		{
			continue;
		}
		else
		{
			Arr[Yindex][Xindex] = 'x';
		}
	}

	while (true)
	{
		system("cls");

		Arr[PlayerY][PlayerX] = '*';

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}


		// 이건 내가 키를 눌렀다면 1
		// 아니라면 0을 리턴하는 함수고 정지하지 않습니다.
		// 키를 눌렀다는것을 체크해주는 함수
		if (0 == _kbhit())
		{
			// 0.5초간 멈춘다.
			Sleep(200);
			// 일부러 멈추게 만들겁니다.
			continue;
		}

		// 어떤키를 눌렀는지 알려주는 함수.
		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
			/*PlayerX -= 1;
			Arr[PlayerY][PlayerX + 1] = 'o';*/
			if (PlayerX == 0)
			{
				continue;
			}
			else
			{
				if (Arr[PlayerY][PlayerX - 1] == 'x')
				{
					continue;
				}
				else
				{
					PlayerX -= 1;
					Arr[PlayerY][PlayerX + 1] = 'o';
				}
			}
			break;
		case 'd':
		case 'D':
			//PlayerX += 1;
			if (PlayerX == ScreenXSize - 1)
			{
				continue;
			}
			else
			{
				if (Arr[PlayerY][PlayerX + 1] == 'x')
				{
					continue;
				}
				else
				{
					PlayerX += 1;
					Arr[PlayerY][PlayerX - 1] = 'o';
				}
			}
			break;
		case 'w':
		case 'W':
			//PlayerY -= 1;
			if (PlayerY == 0)
			{
				continue;
			}
			else
			{
				if (Arr[PlayerY - 1][PlayerX] == 'x')
				{
					continue;
				}
				else
				{
					PlayerY -= 1;
					Arr[PlayerY + 1][PlayerX] = 'o';
				}
				
			}
			break;
		case 's':
		case 'S':
			//PlayerY += 1;
			if (PlayerY == ScreenYSize - 1)
			{
				continue;
			}
			else
			{
				if (Arr[PlayerY + 1][PlayerX] == 'x')
				{
					continue;
				}
				else
				{
					PlayerY += 1;
					Arr[PlayerY - 1][PlayerX] = 'o';
				}
				
			}
			break;
		default:
			break;
		}

		Sleep(200);
	}


}

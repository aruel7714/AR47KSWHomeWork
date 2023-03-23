// 046_BytePadding.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// short 2바이트 정수형;

class Player
{
public:
    int value1;          // 4
    short value2;    // 
    __int64 value3;  // 8
    short value4;    // 
    char value5;

    // 8바이트 이하 가장큰 바이트의 자료형을 찾아요.
    // 4바이트
    // 먼저 4바이트를 할당했다고 쳐보자
    // 딱맞거나 들어갈수 있으면 그대로 픽스
    // 4바이트 할당한다.
    // char
    // 8바이트
};

int main()
{
    Player NewPlayer;

    //int* Ptr = &NewPlayer.Hp;

    __int64 address0 = (__int64)&NewPlayer.value1;
    __int64 address1 = (__int64)&NewPlayer.value2;
    __int64 address2 = (__int64)&NewPlayer.value3;
    __int64 address3 = (__int64)&NewPlayer.value4;
    __int64 address4 = (__int64)&NewPlayer.value5;

    

    int Size = sizeof(Player);

    int a = 0;

    //printf_s("%d", Size);

}

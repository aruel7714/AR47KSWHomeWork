// HomeWork0317.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string.h>

// 영어만 씁니다.

// 문자열을 넣어주면 글자 개수를 알아냅니다.
// 0을 포함할지 아닐지는 스스로 정하세요
int StringCount(const char* _String)
{
    int count = 0;
    int result = 0;
    
    char value = 0;

    while (_String[count] != 0)
    {
        value = _String[count++];

        result++;
    }
    return result;
}

int TrimDelete(char* _String)
{
    int countArg = 0;
    int countField = 0;

    char value = 0;

    char arr[1024] = " ";
    
    while (_String[countArg] != 0)
    {
        value = _String[countArg];
        if (_String[countArg] != ' ')
        {
            arr[countField] = _String[countArg];
            countField++;
        }
        countArg++;
    }
    
    int count = 0;
    while (_String[count] != 0)
    {
        _String[count] = arr[count];
        count++;
    }

    int a = 0;

    return 0;
}

int StringToInt(const char* _String)
{
    int arr[1024] = { 0 };

    int count = 0;

    char change = ' ';

    while (_String[count] != 0)
    {
        change = _String[count];
        arr[count] = (int)change - 48;

        count++;
    }

    int a = 0;

    return 4;
}

int main()
{
    int Return0 = StringCount("aaaa");
    int Return1 = StringCount("aaaa ggg sss");


    char Arr0[1024] = "a b c d e";
    char Arr1[1024] = "a    b c    d    e";
    char Arr2[1024] = "ab    cde    ";

    TrimDelete(Arr0);
    printf_s(Arr0);
    TrimDelete(Arr1);
    printf_s(Arr1);
    TrimDelete(Arr2);
    printf_s(Arr2);

    

    // 영어나 다른글자가 섞여 들어가있는것을 가정하지 않는다.
    int RValue0 = StringToInt("1111");
    int RValue1 = StringToInt("432");
    int RValue2 = StringToInt("4523312");
    int RValue3 = StringToInt("432231");
    

    std::cout << "Hello World!\n";
}

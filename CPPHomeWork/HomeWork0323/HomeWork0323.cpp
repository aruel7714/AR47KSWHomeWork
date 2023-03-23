#include <iostream>


class Number
{
private:
	int Value;
	int resultInt = 0;
	double resultDouble = 0;
	bool resultBool = false;

public:
	// 맴버 이니셜라이저.
	Number(int _Value)
		: Value(_Value)
	{

	}

	// 클래스가 연산자를 사용할수 있게 만들어주는 것.

	// 덧셈
	int operator+(int _Value)
	{
		resultInt = Value + _Value;
		return resultInt;
	}
	double operator+(double _Value)
	{
		resultDouble = Value + _Value;
		return resultDouble;
	}
	// 뺄셈
	int operator-(int _Value)
	{
		resultInt = Value - _Value;
		return resultInt;
	}
	double operator-(double _Value)
	{
		resultDouble = Value - _Value;
		return resultDouble;
	}
	// 곱셈
	int operator*(int _Value)
	{
		resultInt = Value * _Value;
		return resultInt;
	}
	double operator*(double _Value)
	{
		resultDouble = Value * _Value;
		return resultDouble;
	}
	// 나눗셈
	int operator/(int _Value)
	{
		resultInt = Value / _Value;
		return resultInt;
	}
	double operator/(double _Value)
	{
		resultDouble = Value / _Value;
		return resultDouble;
	}
	// 나머지
	int operator%(int _Value)
	{
		resultInt = Value % _Value;
		return resultInt;
	}

	// 작다
	bool operator<(int _Value)
	{
		if (Value < _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	bool operator<(double _Value)
	{
		if (Value < _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	// 작거나 같다
	bool operator<=(int _Value)
	{
		if (Value <= _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	bool operator<=(double _Value)
	{
		if (Value <= _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	// 크다
	bool operator>(int _Value)
	{
		if (Value > _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	bool operator>(double _Value)
	{
		if (Value > _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	// 크거나 같다
	bool operator>=(int _Value)
	{
		if (Value >= _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	bool operator>=(double _Value)
	{
		if (Value >= _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	// 같다
	bool operator==(int _Value)
	{
		if (Value == _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	bool operator==(double _Value)
	{
		if (Value == _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	// 같지 않다
	bool operator!=(int _Value)
	{
		if (Value != _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}
	bool operator!=(double _Value)
	{
		if (Value != _Value)
		{
			resultBool = true;
		}
		else
		{
			resultBool = false;
		}
		return resultBool;
	}

	// 시프트
	int operator<<(int _Value)
	{
		resultInt = Value << _Value;
		return resultInt;

	}
	int operator>>(int _Value)
	{
		resultInt = Value >> _Value;
		return resultInt;

	}

	// & 연산
	int operator&(int _Value)
	{
		resultInt = Value & _Value;
		return resultInt;
	}
	// | 연산
	int operator|(int _Value)
	{
		resultInt = Value | _Value;
		return resultInt;
	}
	// ^ 연산
	int operator^(int _Value)
	{
		resultInt = Value ^ _Value;
		return resultInt;
	}
	// ~ 연산
	int operator~()
	{
		resultInt = ~Value;
		return resultInt;
	}

	// 배열 연산자
	int operator[](size_t _Value)
	{
		//return *this + (sizeof(this) * _Value);

	}

	/*bool operator==(int _Value)
	{
		return false;
	}*/

	
};


int main()
{
	Number NewNumber = 10;

	// 연산자 겹지정 함수라고 부릅니다.
	/*NewNumber + 10;
	NewNumber.operator+(10);*/

	NewNumber + 10;
	NewNumber - 10;
	NewNumber * 10;
	NewNumber / 10;
	NewNumber % 10;
	NewNumber < 10;
	NewNumber <= 10;
	NewNumber > 10;
	NewNumber >= 10;
	NewNumber == 10;
	NewNumber != 10;
	NewNumber << 2;
	NewNumber >> 2;
	NewNumber & 15;
	NewNumber | 15;
	NewNumber ^ 15;
	~NewNumber;
	//int arr[5] = { 0,1,2,3,4 };
	//NewNumber[5];

	

}

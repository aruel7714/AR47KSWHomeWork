#pragma once

typedef int DataType;

// ���� :
class GameEngineArray
{
public:
	// delete Function
	GameEngineArray(const GameEngineArray& _Other) = delete;
	GameEngineArray(GameEngineArray&& _Other) noexcept = delete;
	GameEngineArray& operator=(GameEngineArray&& _Other) noexcept = delete;


	// constrcuter destructer
	GameEngineArray(size_t _Value)
		: ArrPtr(new DataType[_Value])
		, ArrCount(_Value)
	{
		// ArrPtr = new int[100];
	}

	~GameEngineArray()
	{
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
	}

	GameEngineArray& operator=(const GameEngineArray& _Other)
	{
		// ArrCount = _Other.ArrCount;
		// ArrPtr = _Other.ArrPtr;
		
		ArrCount = _Other.ArrCount;
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}
		ArrPtr = new DataType[_Other.ArrCount];
		for (size_t i = 0; i < _Other.ArrCount; i++)
		{
			ArrPtr[i] = _Other.ArrPtr[i];
		}
		
		return *this;
	}

	size_t Count()
	{
		return ArrCount;
	}

	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	void ReSize(int _Value)
	{
		// 20�� ����.
		// ���� ������ �Ẹ�ø� �����̴ϴ�.

		// ������ �Ҵ�� �迭�� �˰� �ִ°��� 
		// ���Ҹ� ����� �ȵȴ�.

		// ������ �ִ� ������ ������ �迭�� �����Ѵ��� �����ؾ� �Ѵ�.

		// ������ �ִ� �迭�� �Ȱ��� �迭�� �����.
		int* tempArr = new int[ArrCount];
		for (int i = 0; i < ArrCount; i++)
		{
			tempArr[i] = ArrPtr[i];
		}
		
		// ArrPtr ���迭 ����
		if (nullptr != ArrPtr)
		{
			delete[] ArrPtr;
			ArrPtr = nullptr;
		}

		// �ٽ� ���迭 �����
		ArrPtr = new DataType[_Value];
		ArrCount = _Value;

		for (int i = 0; i < ArrCount; i++)
		{
			ArrPtr[i] = tempArr[i];
		}

		if (nullptr != tempArr)
		{
			delete[] tempArr;
			tempArr = nullptr;
		}
	}

protected:

private:
	size_t ArrCount;
	DataType* ArrPtr = nullptr;

};


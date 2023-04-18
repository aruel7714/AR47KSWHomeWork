#pragma once
#include <GameEngineConsole/ConsoleGameObject.h>
#include <GameEngineBase/GameEngineDebug.h>

// 설명 :
class Parts : public ConsoleGameObject
{
public:
	// constrcuter destructer
	Parts();
	~Parts();

	// delete Function
	Parts(const Parts& _Other) = delete;
	Parts(Parts&& _Other) noexcept = delete;
	Parts& operator=(const Parts& _Other) = delete;
	Parts& operator=(Parts&& _Other) noexcept = delete;

	inline Parts* GetLast()
	{
		if (nullptr == Next)
		{
			return this;
		}

		return Next->GetLast();
	}

	inline Parts* GetNext() 
	{
		return Next;
	}

	inline void SetNext(Parts* _Next)
	{
		if (nullptr == _Next)
		{
			MsgBoxAssert("자신의 NextNode를 nullptr로 세팅하려고 했습니다.");
		}

		Next = _Next;
	}

	inline int2 GetPrevPos() 
	{
		return PrevPos;
	}


	inline void SetPos(const int2& _Value) override
	{
		PrevPos = GetPos();
		ConsoleGameObject::SetPos(_Value);
	}

	inline void SetRender()
	{
		Dir = GetPos() - PrevPos;
		if (Dir == int2::Left)
		{
			RenderChar = L'◀';
		}
		else if (Dir == int2::Right)
		{
			RenderChar = L'▶';
		}
		else if (Dir == int2::Up)
		{
			RenderChar = L'▲';
		}
		else if (Dir == int2::Down)
		{
			RenderChar = L'▼';
		}
	}

	void NextMove();

protected:
	void Update() override;

private:
	int2 Dir = int2::Zero;
	int2 PrevPos = int2::Zero;

	Parts* Prev;
	Parts* Next;
};


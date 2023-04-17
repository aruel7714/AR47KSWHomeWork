#pragma once
#include "Parts.h"

// ���� :
class Head : public Parts
{
public:
	// constrcuter destructer
	Head();
	~Head();

	// delete Function
	Head(const Head& _Other) = delete;
	Head(Head&& _Other) noexcept = delete;
	Head& operator=(const Head& _Other) = delete;
	Head& operator=(Head&& _Other) noexcept = delete;

	static bool IsPlay;

protected:
	void Update() override;
	bool IsBodyCheck(int2 _NextPos);
	void NewBodyCreateCheck(int2 _PrevPos);

private:
	int2 Dir = int2::Up;

};

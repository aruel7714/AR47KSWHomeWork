#include "Parts.h"

Parts::Parts() 
{
}

Parts::~Parts() 
{
}

void Parts::Update() 
{
	ConsoleGameObject::Update();
}

void Parts::NextMove()
{
	Parts* Next = GetNext();
	// SetRender();
	if (nullptr == Next)
	{
		return;
	}

	Next->SetPos(GetPrevPos());

	int2 Pos = GetPos();
	int2 NextPos = Next->GetPos();
	Dir = Pos - NextPos;

	if (Dir == int2::Left)
	{
		Next -> RenderChar = L'¢¸';
	}
	else if (Dir == int2::Right)
	{
		Next -> RenderChar = L'¢º';
	}
	else if (Dir == int2::Up)
	{
		Next -> RenderChar = L'¡ã';
	}
	else if (Dir == int2::Down)
	{
		Next -> RenderChar = L'¡å';
	}

	return Next->NextMove();
}
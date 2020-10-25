#pragma once
#include "olcConsoleGameEngine.h"

class ConsoleSetup : public olcConsoleGameEngine
{
public:
	CHAR_INFO* GetScreenBuffer()
	{
		return m_bufScreen;
	}

	void(*UpdateFunction)() = nullptr;

	void InitConsole(int width, int height, int dotSize)
	{
		ConstructConsole(
			width,
			height + 10,
			dotSize,
			dotSize);
	}

	virtual bool OnUserCreate()
	{
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		if (UpdateFunction != nullptr)
		{
			UpdateFunction();
		}

		return true;
	}
};
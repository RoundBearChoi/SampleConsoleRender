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
			height,
			dotSize,
			dotSize);
	}

	virtual bool OnUserCreate()
	{
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime)
	{
		Fill(0, 0, 128, 72, PIXEL_SOLID, FG_WHITE);

		if (UpdateFunction != nullptr)
		{
			UpdateFunction();
		}

		return true;
	}
};
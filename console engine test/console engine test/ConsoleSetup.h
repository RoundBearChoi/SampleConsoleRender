#pragma once
#include "olcConsoleGameEngine.h"
#include "Game.h"

namespace RB
{
	class ConsoleSetup : public olcConsoleGameEngine
	{
	public:
		Game game;

		void InitConsole()
		{
			ConstructConsole(
				game.specs.width,
				game.specs.height + 10,
				game.specs.dotSize,
				game.specs.dotSize);

			game.Init(m_bufScreen);

			Start();
		}

		virtual bool OnUserCreate()
		{
			return true;
		}

		virtual bool OnUserUpdate(float fElapsedTime)
		{
			game.Update();
			return true;
		}
	};
}
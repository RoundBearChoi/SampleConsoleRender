#pragma once
#include "Renderer.h"
#include "Specs.h"

namespace RB
{
	struct Game
	{
		Renderer renderer;
		Specs specs;

		void Init(CHAR_INFO* buffer)
		{
			renderer.buffer = buffer;
			renderer.specs = &specs;
		}

		void Update()
		{
			renderer.SetBackgroundColor(FG_WHITE);

			int xRows = 7;
			int yColumns = 7;

			for (int col = 0; col < yColumns; col++)
			{
				for (int row = 0; row < xRows; row++)
				{
					renderer.DrawDot(row, col, FG_GREEN);
				}
			}

			renderer.DrawDot(12, 12, FG_RED);

			renderer.StringOut(1, specs.height + 1, L"here's a string");
			renderer.StringOut(1, specs.height + 2, L"testing");
		}
	};
}
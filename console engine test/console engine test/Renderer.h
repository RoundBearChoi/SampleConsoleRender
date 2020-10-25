#pragma once
#include <string>
#include "Specs.h"

namespace RB
{
	struct Renderer
	{
		CHAR_INFO* buffer = nullptr;
		Specs* specs = nullptr;

		void SetBackgroundColor(short c = 0x2588)
		{
			FillBox(0, 0, specs->width, specs->height, PIXEL_SOLID, c);
		}

		void StringOut(int x, int y, std::wstring c, short col = 0x000F)
		{
			for (size_t i = 0; i < c.size(); i++)
			{
				buffer[y * specs->width + x + i].Char.UnicodeChar = c[i];
				buffer[y * specs->width + x + i].Attributes = col;
			}
		}

		void FillBox(int x1, int y1, int x2, int y2, short c = 0x2588, short col = 0x000F)
		{
			for (int x = x1; x < x2; x++)
			{
				for (int y = y1; y < y2; y++)
				{
					DrawOnScreen(x, y, c, col);
				}
			}
		}

		void DrawOnScreen(int x, int y, short c = 0x2588, short col = 0x000F)
		{
			if (x >= 0 && x < specs->width && y >= 0 && y < specs->height)
			{
				buffer[y * specs->width + x].Char.UnicodeChar = c;
				buffer[y * specs->width + x].Attributes = col;
			}
		}

		void DrawDot(int x, int y, short c = 0x2588)
		{
			FillBox(x, y, x + 1, y + 1, PIXEL_SOLID, c);
		}
	};
}
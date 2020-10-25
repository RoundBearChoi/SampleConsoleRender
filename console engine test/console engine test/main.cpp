#include "ConsoleSetup.h"

int width = 50;
int height = 30;
int dotSize = 20;
CHAR_INFO* buffer = nullptr;

void DrawOnScreen(int x, int y, short c = 0x2588, short col = 0x000F)
{
	if (x >= 0 && x < width && y >= 0 && y < height)
	{
		buffer[y * width + x].Char.UnicodeChar = c;
		buffer[y * width + x].Attributes = col;
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

void DrawDot(int x, int y, short c = 0x2588)
{
	FillBox(x, y, x + 1, y + 1, PIXEL_SOLID, c);
}

void StringOut(int x, int y, std::wstring c, short col = 0x000F)
{
	for (size_t i = 0; i < c.size(); i++)
	{
		buffer[y * width + x + i].Char.UnicodeChar = c[i];
		buffer[y * width + x + i].Attributes = col;
	}
}

void UpdateGame()
{
	FillBox(0, 0, width, height, PIXEL_SOLID, FG_WHITE);

	int xRows = 5;
	int yColumns = 5;

	for (int col = 0; col < yColumns; col++)
	{
		for (int row = 0; row < xRows; row++)
		{
			DrawDot(row, col, FG_GREEN);
		}
	}

	DrawDot(8, 8, FG_RED);
	StringOut(1, height + 1, L"here's a string..");
	StringOut(1, height + 2, L"testing..");
}

int main()
{
	ConsoleSetup setup;

	setup.InitConsole(
		width,
		height,
		dotSize);

	//should fix later
	buffer = setup.GetScreenBuffer();

	setup.UpdateFunction = &UpdateGame;

	setup.Start();
}
#include "ConsoleSetup.h"

int width = 128;
int height = 72;
int dotSize = 10;
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

void DrawDot(int x, int y)
{
	FillBox(x, y, x + 1, y + 1, PIXEL_SOLID, FG_CYAN);
}

void UpdateGame()
{
	int xRows = 10;
	int yColumns = 30;

	for (int col = 0; col < yColumns; col++)
	{
		for (int row = 0; row < xRows; row++)
		{
			DrawDot(row, col);
		}
	}

	DrawDot(20, 35);
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
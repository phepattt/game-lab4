#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<conio.h>
int x = 38, y = 20;
char ch = ' ';
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship()
{
	printf("       ");
}
void draw_ship()
{
	printf(" <-0-> ");
}
int main()
{
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a') {
				if (x > 0) {
					gotoxy(--x, y);
					draw_ship();
				}
				else gotoxy(0, 20);
			}
			if (ch == 'd') {
				if (x < 73) {
					gotoxy(x, y);
					printf(" ");
					gotoxy(++x, y);
					draw_ship();
				}
				else gotoxy(73, 20);
			}
			if (ch == 'w') {
				if (y > 0) {
					gotoxy(x, y);
					erase_ship();
					gotoxy(x, --y);
					draw_ship();
				}
				else gotoxy(x, 0);
			}
			if (ch == 's') {
				if (y < 30) {
					gotoxy(x, y);
					erase_ship();
					gotoxy(x, ++y);
					draw_ship();
				}
				else gotoxy(x, 30);
			}
			fflush(stdin);
		}
		Sleep(10);
	} while (ch != 'x');
	return 0;
}
#include <iostream>
#include <conio.h>

using namespace std;

#define VERTICAL_SHIFT   "\n\n\n\n\n"
#define HORIZONTAL_SHIFR "\t\t\t\t\t"

void PrintField(char field[]);
bool Proverka(char field[], int n);
void Move(char field[]);
char Win(char field[]);
char Nichia(char field[]);

int main()
{
	setlocale(LC_ALL, "ru");
	const int n = 9;
	char field[n] = {};
	PrintField(field);
}
bool Proverka(char field[],int n)
{
	return field[n] ? false : true;
}
char Win(char field[])
{
	if ((field[0] == '0' && field[1] == '0' && field[2] == '0') ||
		(field[3] == '0' && field[4] == '0' && field[5] == '0') ||
		(field[6] == '0' && field[7] == '0' && field[8] == '0') ||
		(field[0] == '0' && field[3] == '0' && field[6] == '0') ||
		(field[1] == '0' && field[4] == '0' && field[7] == '0') ||
		(field[2] == '0' && field[5] == '0' && field[8] == '0') ||
		(field[0] == '0' && field[4] == '0' && field[8] == '0') ||
		(field[2] == '0' && field[4] == '0' && field[6] == '0'))
	{
		return '0';
	}
	if ((field[0] == 'x' && field[1] == 'x' && field[2] == 'x') ||
		(field[3] == 'x' && field[4] == 'x' && field[5] == 'x') ||
		(field[6] == 'x' && field[7] == 'x' && field[8] == 'x') ||
		(field[0] == 'x' && field[3] == 'x' && field[6] == 'x') ||
		(field[1] == 'x' && field[4] == 'x' && field[7] == 'x') ||
		(field[2] == 'x' && field[5] == 'x' && field[8] == 'x') ||
		(field[0] == 'x' && field[4] == 'x' && field[8] == 'x') ||
		(field[2] == 'x' && field[4] == 'x' && field[6] == 'x'))
	{
		return 'x';
	}
	return field[0] != 0 && field[1] != 0 && field[2] != 0 && field[3] != 0 && field[4] != 0 && field[5] != 0 && field[6] != 0 && field[7] != 0 && field[8] != 0 ? 'p' : 0;	
}
void Move(char field[])
{
	static int ochered = 0;
	char key;
	do
	{
		if (ochered % 2 == 0)
		{
			cout << "Ходит игрок 1\n";
		}
		else
		{
			cout << "Ходит игрок 2\n";
		}
		key = _getch();
		if (key == 27)return;
		if (key < '1' || key > '9') cout << "Вы вышли за пределы поля, допустимые клавиши от 1 до 9\n";
		if (Proverka(field, key - 49)) {}
		else cout << "Эта клетка уже занята\n";

	} while (key < '1' || key > '9'|| Proverka(field, key - 49) == false);

	(ochered % 2 == 0) ? field[key - 49] = 'x' : field[key - 49] = '0';

	ochered += 1;

	PrintField(field);
}
void PrintField(char field[])
{
	system("cls");
	cout << VERTICAL_SHIFT;
	for (int i = 6; i >= 0; i -= 3)
	{
		cout << " ";
		cout << HORIZONTAL_SHIFR;
		for (int j = 0; j < 3; j++)
		{
			
			cout << field[i + j];
			if (j != 2)cout << "  | ";
		}
		cout << endl;
		cout << HORIZONTAL_SHIFR <<"--- ---  ---";
		cout << endl;
	}
	switch (Win(field))
	{
	case 'x':
	{
		cout << "ИГРОК 1 ВЫИГРАЛ, ПОЗДРАВЛЯЕМ!\n";
		system("pause");
		exit(0);
	}
	case '0':
	{
		cout << "ИГРОК 2 ВЫИГРАЛ, ПОЗДРАВЛЯЕМ!\n";
		system("pause");
		exit(0);
	}
	case 'p':
	{
		cout << "НИЧЬЯ, ПОЗДРАВЛЯЕМ!\n";
		system("pause");
		exit(0);
	}
	}
	Move(field);
}
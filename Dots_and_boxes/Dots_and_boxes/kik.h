#include <vector>
#include <iostream>

using namespace std;

#define HEIGTH 3
#define WIDTH 3

enum Gracz { GRACZ_1, GRACZ_2 };

struct Kartka
{
	vector<vector<char>> plansza;
	Gracz czyj_ruch = GRACZ_1;

	void incjalizacja();
	Gracz pobierzRuch();
	void wykonajRuch(int x, int y);
	void wypiszPlansze();
	void czyWygral(char znak, Gracz gracz);
	void wypiszEndboard();
};

void Kartka::incjalizacja()
{
	plansza.resize(HEIGTH);
	for (int i = 0; i < HEIGTH; i++)
	{
		plansza[i].resize(WIDTH);
	}

	for (int y = 0; y < HEIGTH; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			plansza[y][x] = ' ';
		}
	}
}

Gracz Kartka::pobierzRuch()
{
	printf("Obecnie trwa runda gracza: %i \n", czyj_ruch + 1);
	return czyj_ruch;
}

void Kartka::wykonajRuch(int x, int y)
{
	Gracz grajacy = czyj_ruch;

	if (plansza[y][x] == ' ')
	{
		if (grajacy == GRACZ_1)
		{
			plansza[y][x] = 'X';
			czyj_ruch = GRACZ_2;
		}
		else
		{
			plansza[y][x] = 'O';
			czyj_ruch = GRACZ_1;
		}
	}
	char temp = plansza[y][x];

	czyWygral(temp, grajacy);

	system("cls");
}

void Kartka::wypiszPlansze()
{
	printf("|   | 1 | 2 | 3 |\n-----------------\n");
	for (int i = 0; i < HEIGTH; i++)
	{
		printf("| %i | ", i + 1);
		for (int j = 0; j < WIDTH; j++)
		{
			printf("%c | ", plansza[i][j]);
		}
		printf("\n-----------------\n");
	}
}

void Kartka::czyWygral(char znak, Gracz gracz)
{
	for (int i = 0; i < 3; i++)
	{
		if (znak == plansza[0][i] && znak == plansza[1][i] && znak == plansza[2][i]) wypiszEndboard();
		else if (znak == plansza[i][0] && znak == plansza[i][1] && znak == plansza[i][2]) wypiszEndboard();
	}
	if (znak == plansza[0][0] && znak == plansza[1][1] && znak == plansza[2][2]) wypiszEndboard();
	else if (znak == plansza[2][0] && znak == plansza[1][1] && znak == plansza[0][2]) wypiszEndboard();
}

void Kartka::wypiszEndboard()
{
	system("cls");
	wypiszPlansze();
	printf("\nWygrales!");
	system("pause");
}
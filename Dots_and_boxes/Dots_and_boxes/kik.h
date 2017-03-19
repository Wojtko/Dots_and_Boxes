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
};

void Kartka::incjalizacja()
{
	plansza.resize(HEIGTH);
	for (int i = 0; i < HEIGTH; i++)
	{
		plansza[i].resize(WIDTH);
	}

	for (int i = 0; i < HEIGTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			plansza[i][j] = ' ';
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
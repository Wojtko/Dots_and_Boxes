#include <stdafx.h>
#include <iostream>
#include "kik.h"

using namespace std;

int main()
{
	Kartka gra;
	int x, y;

	gra.incjalizacja();

	for (;;)
	{
		gra.pobierzRuch();
		gra.wypiszPlansze();
		cout << "Podaj x: ";
		cin >> x;
		cout << "Podaj y: ";
		cin >> y;
		gra.wykonajRuch(x - 1, y - 1);
	}

	system("pause");
	return 0;
}
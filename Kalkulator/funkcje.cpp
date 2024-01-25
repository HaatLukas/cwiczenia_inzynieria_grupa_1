#pragma once
#include "funkcje.h"
#include <iostream>
#include <cmath>
#include "math.h"
#include <string>

using namespace std;

string logn(double liczba)
{
	return to_string(log(liczba));
}

string odcs(double tablica[], int dlugosc)
{
	double suma = 0;

	for (int i = 0; i < dlugosc; i++)
	{
		suma = suma + tablica[i];
	}

	double srednia = suma / (double)dlugosc;
	double odchylenie = 0;

	for (int i = 0; i < dlugosc; i++)
	{
		odchylenie = odchylenie + (tablica[i] - srednia);
	}
	odchylenie = odchylenie / double(dlugosc);
	odchylenie = sqrt(odchylenie);

	return to_string(odchylenie);

}

string exponentt(double liczba)
{
	return to_string(exp(liczba));
}

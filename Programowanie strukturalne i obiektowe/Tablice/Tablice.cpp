#include <iostream>

/*
Napisz funkcję w której wczytamy 5 liczb i wyświetlimy je w odwrotnej kolejności.
 */

void Zadanie1()
{
	int liczba0, liczba1, liczba2, liczba3, liczba4;
	std::cout << "Podaj 0 liczbe:\n";
	std::cin >> liczba0;
	std::cout << "Podaj 1 liczbe:\n";
	std::cin >> liczba1;
	std::cout << "Podaj 2 liczbe:\n";
	std::cin >> liczba2;
	std::cout << "Podaj 3 liczbe:\n";
	std::cin >> liczba3;
	std::cout << "Podaj 4 liczbe:\n";
	std::cin >> liczba4;

	std::cout << liczba4 << ", ";
	std::cout << liczba3 << ", ";
	std::cout << liczba2 << ", ";
	std::cout << liczba1 << ", ";
	std::cout << liczba0;
}

void Zadanie2()
{
	int liczby[5];
	std::cout << "Podaj 0 liczbe:\n";
	std::cin >> liczby[0];
	std::cout << "Podaj 1 liczbe:\n";
	std::cin >> liczby[1];
	std::cout << "Podaj 2 liczbe:\n";
	std::cin >> liczby[2];
	std::cout << "Podaj 3 liczbe:\n";
	std::cin >> liczby[3];
	std::cout << "Podaj 4 liczbe:\n";
	std::cin >> liczby[4];

	std::cout << liczby[4] << ", ";
	std::cout << liczby[3] << ", ";
	std::cout << liczby[2] << ", ";
	std::cout << liczby[1] << ", ";
	std::cout << liczby[0] << ", ";
}

void Zadanie3()
{
	const int rozmiar = 5;
	int liczby[rozmiar];
	std::cout << "Podaj 0 liczbe:\n";
	std::cin >> liczby[0];
	std::cout << "Podaj 1 liczbe:\n";
	std::cin >> liczby[1];
	std::cout << "Podaj 2 liczbe:\n";
	std::cin >> liczby[2];
	std::cout << "Podaj 3 liczbe:\n";
	std::cin >> liczby[3];
	std::cout << "Podaj 4 liczbe:\n";
	std::cin >> liczby[4];

	for (int i = 4; i >= 0; i--)
		std::cout << liczby[i] << ", ";
}

void Zadanie4()
{
	const int rozmiar = 5;
	int liczby[rozmiar];

	for (int i = 0; i < rozmiar; i++)
	{
		std::cout << "Podaj " << i <<" liczbe:\n";
		std::cin >> liczby[i];
	}

	for (int i = rozmiar - 1; i >= 0; i--)
	{
		std::cout << liczby[i] << ", ";
	}
}

/*
 Napisz program, który uzupełni tablicę liczbami pseudolosowymi,
 wyswietli jej zawartość oraz znajdzie wartość najwiekszą.
 */

void Zadanie5()
{
	const int ROZMIAR_TABLICY = 5;
	int tablicaLiczb[ROZMIAR_TABLICY];

	srand(time(NULL));

	for (int i=0; i<ROZMIAR_TABLICY; i++)
	{
		//zakres <0; 100>
		tablicaLiczb[i] = rand() % 101 ; // <0; RAND_MAX)
	}

	for (int i = 0; i < ROZMIAR_TABLICY; i++)
	{
		std::cout << tablicaLiczb[i] << ", ";
	}
	std::cout << "\n";

	//szukanie maksymalnej
	int max = tablicaLiczb[0];
	for (int i = 1; i < ROZMIAR_TABLICY; i++)
	{
		if (tablicaLiczb[i] > max)
			max = tablicaLiczb[i];
	}
	std::cout << "Maksymalna liczba to " << max << "\n";
}

int main()
{
	Zadanie5();
}

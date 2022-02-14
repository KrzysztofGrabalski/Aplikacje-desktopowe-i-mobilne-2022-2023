#include <iostream>
#include <math.h>

//definicja funkcji
/*
typZwracany nazwaFunkcji(parametry)
{

}
*/

void WyswietlPowitanie()
{
    std::cout << "Hello World!\n";
}

void PobierzWyswietlLiczbe()
{
    std::cout << "Give me a number:\n";
    int liczba;
    std::cin >> liczba;
    std::cout << "Podales liczbe " << liczba << "\n";
}

void WyswietlLiczbe(int numer)
{
    std::cout << "Your number is " << numer << "\n";
}

void TestFunkcjiParametryzowanej()
{
    int liczba;
    liczba = 2;

    //.......
    //std::cout << "Your number is " << liczba << "\n";
    WyswietlLiczbe(liczba);

    //.......

    int liczba2 = liczba * 3;

    //......

    //std::cout << "Your number is " << liczba2 << "\n";
    WyswietlLiczbe(liczba2);
}

int WartoscBezwzgledna(int numer)
{
    int a;
    a = numer;

    if (a < 0)
        a = a * (-1);
    return a;
}

void TestFunkcjiZwracajacejDane()
{
    int liczba;
    std::cout << "Podaj liczbe\n";
    std::cin >> liczba;

    int liczbaBezwzgledna;

    /*liczbaBezwzgledna = liczba;
    if (liczbaBezwzgledna < 0)
        liczbaBezwzgledna = liczbaBezwzgledna * (-1);*/

        //liczbaBezwzgledna = abs(liczba);
    liczbaBezwzgledna = WartoscBezwzgledna(liczba);

    //float pierwiastek = sqrt(liczba);
    //float potega = pow(3, 6); // 6^3

    std::cout << "Wartosc bezwzgledna " << liczbaBezwzgledna << "\n";
}

/*
Wyświetl wszystkie informacje zakodowane w numerze PESEL.
Numer pobierz od uzytkownika z klawiatury.
*/

//funkcja zwraca wartość liczbową dla danych znaków
int KonwertujZnakiNaLiczbe(char znakDziesiatek, char znakJednostek)
{
    int cyfraDziesiatek = (int)znakDziesiatek - 48;
    int cyfraJednostek = (int)znakJednostek - 48;

    int wynik = cyfraDziesiatek * 10 + cyfraJednostek;
    return wynik;
}

//funkcja sprawdza numer PESEL
// jako parametr przyjmuje numer PESEL
//zwraca wartość:
//* true - jeśli numer pesel jest prawidlowy
//* false - jeśli numer pesel jest nieprawidłowy
bool SprawdzNumerPesel(std::string numer)
{
    //poprawna długość łańcucha znaków
    if (numer.length() != 11)
        return false;

    //dozowlone znaki w numerze PESEL
    for (int i = 0; i < numer.length(); i++)
    {
        if (numer[i] < '0' || numer[i] > '9')
            return false;
    }

    int miesiac = KonwertujZnakiNaLiczbe(numer[2], numer[3]);

    if ( miesiac > 1  
        ||(miesiac > 12 && miesiac < 21) 
        || (miesiac > 32 && miesiac < 41) 
        || (miesiac > 52 && miesiac < 61)
        || (miesiac > 72 && miesiac < 81)
        || miesiac > 92)
        return false;

    int dzien = KonwertujZnakiNaLiczbe(numer[4], numer[5]);

    //.....

    return true;
}


//funkcja główna
void InformacjaNumerPesel()
{
    //Pobierz dane (PESEL)
    std::string numerPesel;
    std::cout << "Podaj numer PESEL\n";
    std::cin >> numerPesel;

    //if ( sprawdz poprawność numeru PESEL == true)
    //bool wynik = SprawdzNumerPesel(numerPesel);
    //if (wynik == true)
    if (SprawdzNumerPesel(numerPesel) == true)
    {
    //      odczytaj zakodowane dane w numerze PESEL
        std::cout << "Podany numer PESEL jest prawidlowy\n";
    }
    else
    {
    //      wyświetl informacje o błędzie
        std::cout << "Podany numer PESEL jest nieprawidlowy\n";
    }
    
}



void main()
{
    /*PobierzWyswietlLiczbe();

    int liczba;
    liczba = 5;

    {
        float liczba;
        //char liczba;
        liczba = 7;
        std::cout << liczba;
    }
    std::cout << liczba;

    PobierzWyswietlLiczbe();

    WyswietlPowitanie();
    PobierzWyswietlLiczbe(); */

    //TestFunkcjiParametryzowanej();
    //TestFunkcjiZwracajacejDane();
    InformacjaNumerPesel();

}



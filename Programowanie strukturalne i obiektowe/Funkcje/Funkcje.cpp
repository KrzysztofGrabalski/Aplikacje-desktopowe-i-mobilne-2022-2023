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

    if ( miesiac < 1  
        ||(miesiac > 12 && miesiac < 21) 
        || (miesiac > 32 && miesiac < 41) 
        || (miesiac > 52 && miesiac < 61)
        || (miesiac > 72 && miesiac < 81)
        || miesiac > 92)
        return false;

    int dzien = KonwertujZnakiNaLiczbe(numer[4], numer[5]);

    //wszystkie miesiące z 31 dniami
    if (dzien > 31)
        return false;

    if (dzien < 1)
        return false;

    //luty
    if (miesiac == 82 || miesiac == 2 || miesiac == 22 || miesiac == 42 || miesiac == 62)
    {
        //zostawiamy - dopiszemy
        //dla roku przestępnego
        if (dzien > 29)
            return false;

        //pozostałe lata
        //if (dzien > 28)
        //    return false;
    }
    //kwiecien
    if (miesiac == 86 || miesiac == 6 || miesiac == 26 || miesiac == 46 || miesiac == 66)
    {
        if (dzien > 30)
            return false;
    }

    //czerwiec
    if (miesiac == 84 || miesiac == 4 || miesiac == 24 || miesiac == 44 || miesiac == 64)
    {
        if (dzien > 30)
            return false;
    }

    //wrzesień
    if (miesiac == 89 || miesiac == 9 || miesiac == 29 || miesiac == 49 || miesiac == 69)
    {
        if (dzien > 30)
            return false;
    }

    //listopad
    if (miesiac == 91 || miesiac == 11 || miesiac == 31 || miesiac == 51 || miesiac == 71)
    {
        if (dzien > 30)
            return false;
    }


    int iloczyn0 = KonwertujZnakiNaLiczbe('0', numer[0]) * 1;
    int iloczyn1 = KonwertujZnakiNaLiczbe('0', numer[1]) * 3;
    int iloczyn2 = KonwertujZnakiNaLiczbe('0', numer[2]) * 7;
    int iloczyn3 = KonwertujZnakiNaLiczbe('0', numer[3]) * 9;
    int iloczyn4 = KonwertujZnakiNaLiczbe('0', numer[4]) * 1;
    int iloczyn5 = KonwertujZnakiNaLiczbe('0', numer[5]) * 3;
    int iloczyn6 = KonwertujZnakiNaLiczbe('0', numer[6]) * 7;
    int iloczyn7 = KonwertujZnakiNaLiczbe('0', numer[7]) * 9;
    int iloczyn8 = KonwertujZnakiNaLiczbe('0', numer[8]) * 1;
    int iloczyn9 = KonwertujZnakiNaLiczbe('0', numer[9]) * 3;

    int suma = iloczyn0 + iloczyn1 + iloczyn2 + iloczyn3 + iloczyn4 + iloczyn5 + iloczyn6 + iloczyn7 + iloczyn8 + iloczyn9;
    int reszta_z_dzielenia = suma % 10;
    int obliczonaCyfraKontrolna;
    if (reszta_z_dzielenia == 0)
        obliczonaCyfraKontrolna = 0;
    else
        obliczonaCyfraKontrolna = 10 - reszta_z_dzielenia;

    int cyfraKontrolna = KonwertujZnakiNaLiczbe('0', numer[10]);
    if (obliczonaCyfraKontrolna != cyfraKontrolna)
        return false;

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



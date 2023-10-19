// Lab_3_Inzynieria.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

int AA[10] = { 4,5,-2,3,-6,4,-111,1,9,11 };

int* BB = new int[5];
 
int main()
{
    for (int a = 0; a < 10; a++)
    {
        std::cout << "Podaj liczbe " << a << " : "<<  std::endl;
        std::cin >> AA[a];
    }

    int i = 0;
    for (auto liczba : AA)
    {
        if (liczba < 0)
        {
            BB[i] = liczba;
            i++;
        }
    }

    std::cout << "Ujemne liczby to: " << std::endl;

    
    for (int j=0;j<i;j++ )
    {
        std::cout << BB[j] << "  ";
    }
    std::cout << "Liczb ujemnych jest " << i << std::endl;

}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

#include <iostream>


float naZwykleMile(double km) {
    return km * 1.6;
}

float naMorskie(double km) {
    return km * 1.8;
}

int main() {
    int size = 10;
    int AA[size];
    int negC = 0;

    for (int i = 0; i < size; i++) 
    {
        std::cin >> AA[i];

        if (AA[i] < 0)
        {
            negC++;
        }
    }

    int *BB = new int[negC];
    int idx = 0;

    for (int i = 0; i < size; i++)
    {
        if (AA[i] < 0)
        {
            BB[idx++] = AA[i];
        }
    }
    std::cout << "\nLiczby ujemne:\n";

    for (int i = 0; i < negC; i++)
    {
        std::cout << BB[i] << " ";
    }

    std::cout << "\nLiczba liczb ujemnych: " << negC << "\n";
    std::cout << "Liczba pominietych liczb: " << (size - negC) << "\n\n";

    double km;

    std::cout << "Podaj ile kilometrow zamienic:\n>";
    std::cin >> km;

    std::cout << "\nLiczba km: " << km << "\n";
    std::cout << "Liczba mila ladowa: " << naZwykleMile(km) << "\n";
    std::cout << "Liczba mila morska: " << naMorskie(km) << "\n";

    return 0;
}

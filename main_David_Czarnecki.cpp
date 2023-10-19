#include <iostream>

float changeValueToLandMile(double km);
float changeValueToNautMile(double km);

int main() {
    int size = 10;
    int AA[size];
    int negNumCount = 0;

    for (int i = 0; i < size; i++) {
        std::cin >> AA[i];

        if (AA[i] < 0)
            negNumCount++;
    }

    int *BB = new int[negNumCount];
    int index = 0;

    for (int i = 0; i < size; i++)
        if (AA[i] < 0)
            BB[index++] = AA[i];

    std::cout << "\nLiczby ujemne:\n";

    for (int i = 0; i < negNumCount; i++)
        std::cout << "\t" << BB[i] << "\n";

    std::cout << "\nLiczba liczb ujemnych: " << negNumCount << "\n";
    std::cout << "Liczba pominietych liczb: " << (size - negNumCount) << "\n\n";

    double km;

    std::cin >> km;

    std::cout << "\nLiczba km: " << km << "\n";
    std::cout << "Liczba mila ladowa: " << changeValueToLandMile(km) << "\n";
    std::cout << "Liczba mila morska: " << changeValueToNautMile(km) << "\n";

    return 0;
}

float changeValueToLandMile(double km) {
    return km * 1.6;
}

float changeValueToNautMile(double km) {
    return km * 1.8;
}

#include <iostream>


double Na_Mile(const double& liczba)
{
	double Mile = liczba * 1.609;
	return Mile;
}


double Na_Mile_Morskie(const double& liczba)
{
	double Mile = liczba * 1.85166;
	return Mile;
}

int main()
{
	double km;
	std::cout << "Poda ilosc km " << std::endl;
	std::cin >> km;
	std::cout << "Liczba km:  " << km << std::endl;
	std::cout << "Mile ladowe: " << Na_Mile(km) << std::endl;
	std::cout << "Mile morskie: " << Na_Mile_Morskie(km) << std::endl;
}
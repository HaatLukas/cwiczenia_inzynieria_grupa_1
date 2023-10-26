#include <iostream>
#include "Testowanie.h"
#include <stdlib.h> 

int main()
{
    GUI::NowaGra();
}

bool GUI::CzyPlanszaIstnieje()
{
    return bPlanszaIstnieje;
}

bool GUI::NowaGra()
{
    if (CzyPlanszaIstnieje() == true)
    {
        return false;
    }
    else
    {
        
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 10; j = j + 2)
            {
                if (i % 2 == 0)
                {
                    plansza[i][j+1] = 1;
                }
                else
                {
                    plansza[i][j] = 1;
                }
            }
        }

        system("Color 0A");

        for (int i = 6; i < 10; i++)
        {
            for (int j = 1; j < 10; j = j + 2)
            {
                if (i%2==0)
                {
                    plansza[i][j] = 1;
                }
                else
                {
                    plansza[i][j+1] = 1;
                }
            
            }
        }
    }

    PokazPlansze();
    return true;
}

void GUI::PokazPlansze()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << plansza[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}

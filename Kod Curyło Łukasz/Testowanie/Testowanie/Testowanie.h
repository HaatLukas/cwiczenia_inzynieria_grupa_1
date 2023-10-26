#pragma once
class GUI
{
public:

    static bool CzyPlanszaIstnieje();

    static bool NowaGra();

    static void PokazPlansze();
protected:
    static int plansza[10][10];

private:
    static bool bPlanszaIstnieje;
};

bool GUI::bPlanszaIstnieje = false;
int GUI::plansza[10][10] = { 0 };
#include <iostream>
#include <stdlib.h>
#include <string>
#include <ctime>
#include "People.h"

using namespace std;

People::People()
{
    name = "";
    health = "";
    treatment = 0;
    living = true;
}
People::People(string inName, string inHealth, int inTreatment)
{
    name = inName;
    health = inHealth;
    treatment = inTreatment;
    living = People::setTreatment(treatment);
}

string People::getName()
{
    return name;
}
void People::setName(string inName)
{
    name = inName;
}

string People::getHealth()
{
    return health;
}
void People::setHealth(string inHealth)
{
    health = inHealth;
}

int People::getTreatment()
{
    return treatment;
}
bool People::setTreatment(int inTreatment)
{
    srand((unsigned)time(0));
    treatment = inTreatment;
    switch(inTreatment)
    {
        case 1: //rest
            if((rand() % 10 + 1) <= 3)//30% chance of death
            {
                return false;
            }
            else
            {
                return true;
            }
            break;
        case 2: //press on
            if((rand() % 10 + 1) <= 7)//70% chance of death
            {
                return false;
            }
            else
            {
                return true;
            }
            break;
        case 3: //medkit
            return rand() % 1;//50% chance of death
            break;
        default:
            return true;
            break;
    }
}
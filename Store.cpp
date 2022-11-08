#include <iostream>
#include <string>
#include "Store.h"

using namespace std;

Store::Store()
{
    storeName = "";
    markup = 0.0;
}
Store::Store(string inStoreName, double inMarkup)
{
    storeName = inStoreName;
    markup = inMarkup;
}

string Store::getStoreName()
{
    return storeName;
}
void Store::setStoreName(string inStoreName)
{
    storeName = inStoreName;
}

double Store::getMarkup()
{
    return markup;
}
void Store::setMarkup(double inMarkup)
{
    markup = inMarkup;
}

double Store::getOxenPrice()
{
    return 40 + (40*markup);
}
double Store::getFoodPrice()
{
    return 0.5 + (0.5*markup);
}
double Store::getBulletsPrice()
{
    return 2 + (2*markup);
}
double Store::getWagonPartsPrice()
{
    return 20 + (20*markup);
}
double Store::getMedkitPrice()
{
    return 25 + (25*markup);
}
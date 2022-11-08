#include <iostream>
#include <stdlib.h>
#include <string>
#include "Stats.h"

using namespace std;

Stats::Stats()
{
    month = 0;
    day = 0;
    milesTravelled = 0;
    distToNext = 0;
    food = 0;
    bullets = 0;
    cash = 0;
}
Stats::Stats(int inMonth, int inDay, int inMiles, int inDist, int inFood, int inBullets, int inCash)
{
    month = inMonth;
    day = inDay;
    milesTravelled = inMiles;
    distToNext = inDist;
    food = inFood;
    bullets = inBullets;
    cash = inCash;
}

string Stats::getDate()
{
    return to_string(month) + "-" + to_string(day) + "-1847";
}
double Stats::getMonth()
{
    return month;
}
void Stats::setMonth(int inMonth)
{
    month = inMonth;
}
double Stats::getDay()
{
    return day;
}
void Stats::setDay(int inDay)
{
    day = inDay;
}
void Stats::addDays(int inDays)
{
    switch(month)//changes months if days max out
    {
        case(3 || 5 || 7 || 8 || 10):
            if((day + inDays) > 31)
            {
                month++;
                day = ((day + inDays) - 31);
            }
            else
            {
                day += inDays;
            }
            break;
        default:
            if((day + inDays) > 30)
            {
                month++;
                day = ((day + inDays) - 30);
            }
            else
            {
                day += inDays;
            }
            break;
    }
}

int Stats::getMiles()
{
    return milesTravelled;
}
void Stats::setMiles(int inMiles)
{
    milesTravelled = inMiles;
}

int Stats::getDist()
{
    return distToNext;
}
void Stats::setDist(int inDist)
{
    distToNext = inDist;
}

int Stats::getFood()
{
    return food;
}
void Stats::setFood(int inFood)
{
    food = inFood;
}

int Stats::getBullets()
{
    return bullets;
}
void Stats::setBullets(int inBullets)
{
    bullets = inBullets;
}

int Stats::getCash()
{
    return cash;
}
void Stats::setCash(int inCash)
{
    cash = inCash;
}